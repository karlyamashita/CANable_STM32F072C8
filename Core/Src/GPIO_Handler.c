/*
 * GPIO_Handler.c
 *
 *  Created on: Jul 30, 2025
 *      Author: karl.yamashita
 */


#include "main.h"

// TX
void LED_Green_Toggle(void)
{
	HAL_GPIO_TogglePin(LED_0_GPIO_Port, LED_0_Pin);
}

// RX
void LED_Blue_Toggle(void)
{
	HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
}

void LED_Green(bool state)
{
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO)
	if(state)
	{
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_RESET); // On
	}
	else
	{
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_SET); // Off
	}
#endif
}

void LED_Blue(bool state)
{
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO)
	if(state)
	{
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET); // On
	}
	else
	{
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET); // Off
	}
#endif
}

void LED_Green_Off(void)
{
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO)
	HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_SET); // Off
#else
	HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_RESET); // Off
#endif
}

void LED_Blue_Off(void)
{
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO)
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET); // Off
#else
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET); // Off
#endif
}


