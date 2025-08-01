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
			LED_Blue_Toggle();
		}
	}
}

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan)
{
	if(hcan == can_msg.hcan)
	{
		LED_Green_Toggle();
		CAN_SendMessage(&can_msg);
	}
}

