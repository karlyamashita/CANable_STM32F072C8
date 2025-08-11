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
	HAL_GPIO_TogglePin(LED_B0_GPIO_Port, LED_B0_Pin); // Jhoinrch
}

// RX
void LED_Blue_Toggle(void)
{
	HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
	HAL_GPIO_TogglePin(LED_B1_GPIO_Port, LED_B1_Pin); // Jhoinrch
}

void LED_Green(bool state)
{
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO) || defined (JHOINRCH)
	if(state)
	{
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_RESET); // On
		HAL_GPIO_WritePin(LED_B0_GPIO_Port, LED_B0_Pin, GPIO_PIN_RESET); // On // Jhoinrch
	}
	else
	{
		HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_SET); // Off
		HAL_GPIO_WritePin(LED_B0_GPIO_Port, LED_B0_Pin, GPIO_PIN_SET); // Off // Jhoinrch
	}
#endif
}

void LED_Blue(bool state)
{
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO) || defined (JHOINRCH)
	if(state)
	{
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET); // On
		HAL_GPIO_WritePin(LED_B1_GPIO_Port, LED_B1_Pin, GPIO_PIN_RESET); // On // Jhoinrch
	}
	else
	{
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET); // Off
		HAL_GPIO_WritePin(LED_B1_GPIO_Port, LED_B1_Pin, GPIO_PIN_SET); // Off // Jhoinrch
	}
#endif
}

void LED_Green_Off(void)
{
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO) || defined (JHOINRCH)
	HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_SET); // Off
	HAL_GPIO_WritePin(LED_B0_GPIO_Port, LED_B0_Pin, GPIO_PIN_SET); // Off // Off // Jhoinrch
#else
	HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, GPIO_PIN_RESET); // Off
#endif
}

void LED_Blue_Off(void)
{
#if defined (P_CAN_07e) || defined (CANABLE_V1_0_PRO) || defined (JHOINRCH)
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET); // Off
	HAL_GPIO_WritePin(LED_B1_GPIO_Port, LED_B1_Pin, GPIO_PIN_SET); // Off // Off // Jhoinrch
#else
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET); // Off
#endif
}


