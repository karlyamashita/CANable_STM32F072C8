


// Standard ASCII characters
#define CMD_ACK 0x06
#define CMD_NAK 0x15

// custom defines
#define CMD_MESSAGE 0x80 // Send CAN message

#define CMD_CAN_MODE 0x30 // CAN Normal/Loopback/Silent mode

#define CMD_CAN_ACTIVITY_LED 0x40 // enable/disable LED activity
#define CMD_SOH_ACTIVITY_LED 0x41 // enable/disable SOH led

#define CMD_INFO 0x90 // PC is requesting for information
#define CMD_CAN_BTR 0x91 // send back the CAN BTC value to PC
#define CMD_VERSION 0x92 // send back version to PC
#define CMD_HARDWARE 0x93 // send back hardware type to PC
#define CMD_FREQUENCY 0x94 // send back the APB1 clock frequency to PC

#define CMD_BAUD 0x95 // set baud
