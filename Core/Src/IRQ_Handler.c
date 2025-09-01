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
 * IRQ_Handler.c
 *
 *  Created on: Jul 30, 2025
 *      Author: karl.yamashita
 */


#include "main.h"


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	HAL_StatusTypeDef hal_status;
	CanRxMsgTypeDef *ptr;

	if(hcan == can_msg.hcan)
	{
		ptr = &can_msg.rxQueue[can_msg.rxPtr.index_IN];
		hal_status = HAL_CAN_GetRxMessage(can_msg.hcan, CAN_RX_FIFO0, &ptr->header, ptr->data);
		if(hal_status == HAL_OK)
		{
			RingBuff_Ptr_Input(&can_msg.rxPtr, can_msg.rxQueueSize);
			TimerCallbackRepetitionStart(&timerCallback, LED_Blue_Toggle, 20, 2); // blip LED
			can_msg.rxCounter += 1;
		}
	}
}

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan)
{
	if(hcan == can_msg.hcan)
	{
		TimerCallbackRepetitionStart(&timerCallback, LED_Green_Toggle, 20, 2); // blip LED
		CAN_SendMessage(&can_msg);
	}
}

void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan)
{
	Nop();
}

#ifdef INNOMAKER_USB2CAN
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	int i = 0;
	uint32_t size = 0;

	if(huart == uart1_msg.huart)
	{
		size = UART_DMA_GetSize(&uart1_msg, Size);

		for(i = 0; i < size; i++)
		{
			uart1_msg.dma.circularBuffer[uart1_msg.dma.circularPtr.index_IN] = uart1_msg.dma.dma_data[uart1_msg.dma.dmaPtr.index_IN];
			RingBuff_Ptr_Input(&uart1_msg.dma.circularPtr, UART_DMA_CIRCULAR_SIZE);
			RingBuff_Ptr_Input(&uart1_msg.dma.dmaPtr, UART_DMA_BUFFER_SIZE);
		}
	}
	// repeat for other UART ports using (else if)
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == uart1_msg.huart)
	{
		uart1_msg.tx.txPending = false;
		UART_DMA_SendMessage(&uart1_msg);
	}
	// repeat for other UART ports using (else if)
}

#endif
