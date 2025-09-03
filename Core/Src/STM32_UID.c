/*
 * STM32_UID.c
 *
 *  Created on: Sep 3, 2025
 *      Author: codek
 */


#include "main.h"


STM32_UID_t stm32_uid = {0};


int STM32_UID_Get(char *retStr)
{
	int status = NO_ERROR;

	STM32_UID(&stm32_uid);

	sprintf(retStr, "0x%08lX%08lX%08lX", stm32_uid.high, (uint32_t) (stm32_uid.low >> 32), (uint32_t) stm32_uid.low);

	return status;
}


void STM32_UID(STM32_UID_t *msg)
{
	msg->UID_t.uid_0 = HAL_GetUIDw0();
	msg->UID_t.uid_1 = HAL_GetUIDw1();
	msg->UID_t.uid_2 = HAL_GetUIDw2();
}


