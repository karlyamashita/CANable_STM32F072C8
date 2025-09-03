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


// Standard ASCII characters
#define CMD_ACK 0x06
#define CMD_NAK 0x15


// custom defines
#define CMD_MESSAGE 0x80 // Send CAN message

#define CMD_INFO 0x90 // N/A
#define CMD_CAN_BTR 0x91 // send back the CAN BTC value to PC
#define CMD_VERSION 0x92 // send back version to PC
#define CMD_HARDWARE 0x93 // send back hardware type to PC
#define CMD_FREQUENCY 0x94 // send back the APB1 clock frequency to PC

#define CMD_BAUD 0x95 // set baud

#define CMD_UID 0xEF // Get the 96 bit UID
