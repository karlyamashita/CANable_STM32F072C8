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
 * CAN_Mode.c
 *
 *  Created on: Jul 31, 2025
 *      Author: karl.yamashita
 */


#include "main.h"

int CAN_Mode_Set(uint8_t *data)
{
	HAL_StatusTypeDef hal_status;
	uint32_t mode;

	hal_status = HAL_CAN_DeInit(&hcan);
	if(hal_status != HAL_OK)
	{
		return hal_status;
	}

	if(data[0] == 0)
	{
		mode = CAN_MODE_NORMAL;
	}
	else if(data[0] == 1)
	{
		mode = CAN_MODE_LOOPBACK;
	}
	else if(data[0] == 2)
	{
		mode = CAN_MODE_SILENT;
	}
	else if(data[0] == 2)
	{
		mode = CAN_MODE_SILENT_LOOPBACK;
	}

	hcan.Instance = CAN;
	hcan.Init.Prescaler = 6;
	hcan.Init.Mode = mode;
	hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan.Init.TimeSeg1 = CAN_BS1_10TQ;
	hcan.Init.TimeSeg2 = CAN_BS2_5TQ;
	hcan.Init.TimeTriggeredMode = DISABLE;
	hcan.Init.AutoBusOff = DISABLE;
	hcan.Init.AutoWakeUp = DISABLE;
	hcan.Init.AutoRetransmission = DISABLE;
	hcan.Init.ReceiveFifoLocked = DISABLE;
	hcan.Init.TransmitFifoPriority = DISABLE;

	hal_status = HAL_CAN_Init(&hcan);
	if(hal_status != HAL_OK)
	{
		return hal_status;
	}

	hal_status = HAL_CAN_Start(&hcan); // start the CAN module

	return hal_status;
}
