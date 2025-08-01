/*
 * GPIO_Handler.h
 *
 *  Created on: Jul 30, 2025
 *      Author: karl.yamashita
 */

#ifndef INC_GPIO_HANDLER_H_
#define INC_GPIO_HANDLER_H_


typedef struct
{
	bool led_can_activity_disable;
	bool led_soh_disable;
}GPIO_t;

void LED_SOH_Toggle(void);
void LED_CAN_Activity(void);


#endif /* INC_GPIO_HANDLER_H_ */
