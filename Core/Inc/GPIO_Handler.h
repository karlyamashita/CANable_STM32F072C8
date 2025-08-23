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
 * GPIO_Handler.h
 *
 *  Created on: Jul 30, 2025
 *      Author: karl.yamashita
 */

#ifndef INC_GPIO_HANDLER_H_
#define INC_GPIO_HANDLER_H_


void LED_Green_Toggle(void);
void LED_Blue_Toggle(void);
void LED_InnomakerStatus(void);
void LED_Green(bool state);
void LED_Blue(bool state);
void LED_Green_Off(void);
void LED_Blue_Off(void);

#endif /* INC_GPIO_HANDLER_H_ */
