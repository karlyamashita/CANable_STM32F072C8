/*
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 Karl Yamashita
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
 */

/*
 * PollingRoutine.c
 *
 *  Created on: Oct 24, 2023
 *      Author: karl.yamashita
 *
 *
 *      Template for projects.
 *
 *      The object of this PollingRoutine.c/h files is to not have to write code in main.c which already has a lot of generated code.
 *      It is cumbersome having to scroll through all the generated code for your own code and having to find a USER CODE section so your code is not erased when CubeMX re-generates code.
 *      
 *      Direction: Call PollingInit before the main while loop. Call PollingRoutine from within the main while loop
 * 
 *      Example;
        // USER CODE BEGIN WHILE
        PollingInit();
        while (1)
        {
            PollingRoutine();
            // USER CODE END WHILE

            // USER CODE BEGIN 3
        }
        // USER CODE END 3

		P_CAN 0.7e module
		LED Green on PA0,
		LED Blue on PA1, both active low.

 */


#include "main.h"



#ifdef FYSETC_UCAN
const char* Hardware = "FYSETC UCAN";
#endif
#ifdef P_CAN_07e
const char* Hardware = "P_CAN 0.7e";
#endif
#ifdef CANABLE_V1_0_PRO
const char* Hardware = "CANable V1.0 Pro";
#endif
const char* Version = "v3.0.1"; // FW version


#define CAN_RX_QUEUE_SIZE 8
#define CAN_TX_QUEUE_SIZE 8
CanRxMsgTypeDef canRxQueue[CAN_RX_QUEUE_SIZE] = {0};
CanTxMsgTypeDef canTxQueue[CAN_TX_QUEUE_SIZE] = {0};

CAN_MsgStruct can_msg =
{
	.hcan = &hcan,
	.rxQueue = canRxQueue,
	.txQueue = canTxQueue,
	.rxQueueSize = CAN_RX_QUEUE_SIZE,
	.txQueueSize = CAN_TX_QUEUE_SIZE,
	.rxPtr = {0},
	.txPtr = {0}
};

#define USB_QUEUE_SIZE 12
USB_Data_t usbRxQueue[USB_QUEUE_SIZE] = {0};
USB_Data_t usbTxQueue[USB_QUEUE_SIZE] = {0};

USB_MsgStruct usb_msg =
{
	.rxQueue = usbRxQueue,
	.rxQueueSize = USB_QUEUE_SIZE,
	.txQueue = usbTxQueue,
	.txQueueSize = USB_QUEUE_SIZE
};

void PollingInit(void)
{
	CAN_SetFilter(&can_msg);

	// blink the green LED 3 times to indicate it is up and running.
	TimerCallbackRegisterOnly(&timerCallback, LED_Green_Toggle);
	TimerCallbackRepetitionStart(&timerCallback, LED_Green_Toggle, 100, 6);
	TimerCallbackRegister2nd(&timerCallback, LED_Green_Toggle, LED_Green_Off); // be sure LED goes to off state

	TimerCallbackRegisterOnly(&timerCallback, LED_Blue_Toggle);
	TimerCallbackRepetitionStart(&timerCallback, LED_Blue_Toggle, 100, 6);
	TimerCallbackRegister2nd(&timerCallback, LED_Blue_Toggle, LED_Blue_Off); // be sure LED goes to off state
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO) || defined (JHOINRCH)
	LED_Green(false);
	LED_Blue(false);
#endif
}

void PollingRoutine(void)
{
    TimerCallbackPoll(&timerCallback);

    USB_Parse(&usb_msg);
    CAN_Parse(&can_msg);

    USB_SendMessage(&usb_msg);
}

/*
 * Description: USB message:<id><na><na><size><data>...
 */
void USB_Parse(USB_MsgStruct *msg)
{
	int status = -1;
	USB_Data_t usbData = {0};

	if(USB_DataAvailable(msg))
	{
		switch(msg->msgToParse->Status.id)
		{
		case CMD_MESSAGE:
			USB_to_CAN_Send(&can_msg, msg->msgToParse->Status.data);
			break;
		case CMD_BAUD:
			status = CAN_BTR_Set(&can_msg, msg->msgToParse->Status.data);
			break;
		case CMD_HARDWARE:
			SendStringInfo(CMD_HARDWARE, (char*)Hardware);
			status = -1;
			break;
		case CMD_VERSION:
			SendStringInfo(CMD_VERSION, (char*)Version);
			status = -1;
			break;
		case CMD_FREQUENCY:
			APB1_Frequency_Get();
			status = -1;
			break;
		case CMD_CAN_BTR:
			CAN_BTR_Get(&can_msg);
			status = -1;
			break;
		case CMD_CAN_MODE:
			status = CAN_Mode_Set(msg->msgToParse->Status.data);
			break;
		default:
			status = 1;
			break;
		}

		if(status == -1) // do not ACK/NAK
		{
			return;
		}
		else if(status != 0)
		{
			usbData.Status.id = CMD_NAK; // NAK PC
		}
		else
		{
			usbData.Status.id = CMD_ACK; // ACK PC
		}

		USB_AddTxBuffer(&usb_msg, &usbData);
	}
}

void CAN_Parse(CAN_MsgStruct *msg)
{
	if(CAN_DataAvailable(msg))
	{
		CAN_to_USB_Send(msg, CAN1_NODE);
		memset(msg->msgToParse->data, 0, 8); // clear the data buffer at this queue index
	}
}

void CAN_BTR_Get(CAN_MsgStruct *msg)
{
	USB_Data_t usb_data = {0};
	uint32_t btrValue = READ_REG(msg->hcan->Instance->BTR);

	usb_data.Status.id = CMD_CAN_BTR;
	usb_data.Status.data[0] = btrValue >> 24 & 0xFF;
	usb_data.Status.data[1] = btrValue >> 16 & 0xFF;
	usb_data.Status.data[2] = btrValue >> 8 & 0xFF;
	usb_data.Status.data[3] = btrValue & 0xFF;

	usb_data.Status.size = 4;

	USB_AddTxBuffer(&usb_msg, &usb_data);
}

void APB1_Frequency_Get(void)
{
	uint32_t freq;
	char str[16] = {0};
	freq = HAL_RCC_GetPCLK1Freq();

	sprintf(str, "%ld", freq);
	SendStringInfo(CMD_FREQUENCY, str);
}

int CAN_BTR_Set(CAN_MsgStruct *msg, uint8_t *data)
{
	HAL_StatusTypeDef hal_status;
	uint32_t btrValue = 0;

	btrValue = data[0] << 24 | data[1] << 16 | data[2] << 8 | data[3]; // parse the BTR data

	// some of these snippets were copied from HAL_CAN_Init()
	HAL_CAN_DeInit(msg->hcan);

	if (msg->hcan->State == HAL_CAN_STATE_RESET)
	{
		/* Init the low level hardware: CLOCK, NVIC */
		HAL_CAN_MspInit(msg->hcan);
	}

	/* Set the bit timing register */
	WRITE_REG(msg->hcan->Instance->BTR, (uint32_t)(btrValue));

	/* Initialize the error code */
	msg->hcan->ErrorCode = HAL_CAN_ERROR_NONE;

	/* Initialize the CAN state */
	msg->hcan->State = HAL_CAN_STATE_READY;

	hal_status = HAL_CAN_Start(msg->hcan); // start the CAN module

	return hal_status;
}

void SendStringInfo(uint8_t cmd, char *msg)
{
	USB_Data_t usb_data = {0};

	sprintf((char*)usb_data.Status.data, "%s\r\n", msg);

	usb_data.Status.id = cmd;
	usb_data.Status.size = strlen((char*)usb_data.Status.data);

	USB_AddTxBuffer(&usb_msg, &usb_data);
}

