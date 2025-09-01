## CANable_STM32F072C8 CAN bus interface
> [!NOTE]This CANable_STM32F072C8 interface project is based off my original project that uses a ST STM32F4-Discovery kit. Check the wiki for more info https://github.com/karlyamashita/CANable_USB_CAN/wiki

> Read the wiki for more information on the original project and the CAN-X CAN bus analyzer software at this link https://github.com/karlyamashita/USB_to_CAN/wiki

---
### Supported CAN bus interfaces
CANable_STM32F072C8 CAN bus interface source code for use with STM32F072C8. The code works with the following adapters

* FYSETC
    * https://amzn.to/3HpTOA6
* Jhoinrch
    * https://amzn.to/45cS3PZ
* P_CAN 0.7e ( the name on the PCB )
    * https://www.aliexpress.us/item/3256806155920255.html 
* CANAble V1.0 Pro
    * https://www.aliexpress.us/item/3256808639155688.html
* InnoMaker USB2CAN
    * Waiting for support. 

### FDCAN support
These devices do not support FDCAN. I am working on CANable_STM32G431xx project to support the STM32G431 and STm32G0Bx series.

---
### Documentation
Check out the wiki for more information https://github.com/karlyamashita/CANable__STM32F072C8/wiki

### CAN bus analyzer software
[CAN-X CDC](https://github.com/karlyamashita/CAN-X) has been updated to work with these devices. There are some pending issues but so far sending and receiving CAN messages works.
