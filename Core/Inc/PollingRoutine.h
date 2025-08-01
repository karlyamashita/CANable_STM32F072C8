/*
 * PollingRoutine.h
 *
 *  Created on: Oct 24, 2023
 *      Author: karl.yamashita
 *
 *
 *      Template
 */

#ifndef INC_POLLINGROUTINE_H_
#define INC_POLLINGROUTINE_H_


/*

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <ctype.h>
#define Nop() asm(" NOP ")

// most commonly used. Uncomment if needed.
//#include "ErrorStatus.h"
//#include "RingBuffer.h"
//#include "UART_DMA_Idle_Circular_Drv_STM32.h"
//#include "StringManip.h"
//#include "TimerCallback.h"

#include "PollingRoutine.h"

*/
#ifndef __weak
#define __weak __attribute__((weak))
#endif

void PollingInit(void);
void PollingRoutine(void);

void USB_Parse(USB_MsgStruct *msg) ;
void CAN_Parse(CAN_MsgStruct *msg);

void CAN_BTR_Get(CAN_MsgStruct *hcan);
int CAN_BTR_Set(CAN_MsgStruct *hcan, uint8_t *data);
void APB1_Frequency_Get(void);
void SendStringInfo(uint8_t cmd, char *msg);

#endif /* INC_POLLINGROUTINE_H_ */
