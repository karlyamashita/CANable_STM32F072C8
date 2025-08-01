/*
 * GPIO_Handler.c
 *
 *  Created on: Jul 30, 2025
 *      Author: karl.yamashita
 */


#include "main.h"


void LED_SOH_Toggle(void)
{
	HAL_GPIO_TogglePin(LED_0_GPIO_Port, LED_0_Pin);
}

void LED_CAN_Activity(void)
{
	HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
}

