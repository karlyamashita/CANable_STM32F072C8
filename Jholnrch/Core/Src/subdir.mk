################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/CAN_Buffer.c \
../Core/Src/CAN_Filter.c \
../Core/Src/CAN_Mode.c \
../Core/Src/GPIO_Handler.c \
../Core/Src/IRQ_Handler.c \
../Core/Src/PollingRoutine.c \
../Core/Src/RingBuffer.c \
../Core/Src/TimerCallback.c \
../Core/Src/USB_Buffer.c \
../Core/Src/UsbAndCanConvert.c \
../Core/Src/main.c \
../Core/Src/stm32f0xx_hal_msp.c \
../Core/Src/stm32f0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f0xx.c 

OBJS += \
./Core/Src/CAN_Buffer.o \
./Core/Src/CAN_Filter.o \
./Core/Src/CAN_Mode.o \
./Core/Src/GPIO_Handler.o \
./Core/Src/IRQ_Handler.o \
./Core/Src/PollingRoutine.o \
./Core/Src/RingBuffer.o \
./Core/Src/TimerCallback.o \
./Core/Src/USB_Buffer.o \
./Core/Src/UsbAndCanConvert.o \
./Core/Src/main.o \
./Core/Src/stm32f0xx_hal_msp.o \
./Core/Src/stm32f0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f0xx.o 

C_DEPS += \
./Core/Src/CAN_Buffer.d \
./Core/Src/CAN_Filter.d \
./Core/Src/CAN_Mode.d \
./Core/Src/GPIO_Handler.d \
./Core/Src/IRQ_Handler.d \
./Core/Src/PollingRoutine.d \
./Core/Src/RingBuffer.d \
./Core/Src/TimerCallback.d \
./Core/Src/USB_Buffer.d \
./Core/Src/UsbAndCanConvert.d \
./Core/Src/main.d \
./Core/Src/stm32f0xx_hal_msp.d \
./Core/Src/stm32f0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F072xB -DCANABLE_V1_0_PRO -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/CAN_Buffer.cyclo ./Core/Src/CAN_Buffer.d ./Core/Src/CAN_Buffer.o ./Core/Src/CAN_Buffer.su ./Core/Src/CAN_Filter.cyclo ./Core/Src/CAN_Filter.d ./Core/Src/CAN_Filter.o ./Core/Src/CAN_Filter.su ./Core/Src/CAN_Mode.cyclo ./Core/Src/CAN_Mode.d ./Core/Src/CAN_Mode.o ./Core/Src/CAN_Mode.su ./Core/Src/GPIO_Handler.cyclo ./Core/Src/GPIO_Handler.d ./Core/Src/GPIO_Handler.o ./Core/Src/GPIO_Handler.su ./Core/Src/IRQ_Handler.cyclo ./Core/Src/IRQ_Handler.d ./Core/Src/IRQ_Handler.o ./Core/Src/IRQ_Handler.su ./Core/Src/PollingRoutine.cyclo ./Core/Src/PollingRoutine.d ./Core/Src/PollingRoutine.o ./Core/Src/PollingRoutine.su ./Core/Src/RingBuffer.cyclo ./Core/Src/RingBuffer.d ./Core/Src/RingBuffer.o ./Core/Src/RingBuffer.su ./Core/Src/TimerCallback.cyclo ./Core/Src/TimerCallback.d ./Core/Src/TimerCallback.o ./Core/Src/TimerCallback.su ./Core/Src/USB_Buffer.cyclo ./Core/Src/USB_Buffer.d ./Core/Src/USB_Buffer.o ./Core/Src/USB_Buffer.su ./Core/Src/UsbAndCanConvert.cyclo ./Core/Src/UsbAndCanConvert.d ./Core/Src/UsbAndCanConvert.o ./Core/Src/UsbAndCanConvert.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f0xx_hal_msp.cyclo ./Core/Src/stm32f0xx_hal_msp.d ./Core/Src/stm32f0xx_hal_msp.o ./Core/Src/stm32f0xx_hal_msp.su ./Core/Src/stm32f0xx_it.cyclo ./Core/Src/stm32f0xx_it.d ./Core/Src/stm32f0xx_it.o ./Core/Src/stm32f0xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f0xx.cyclo ./Core/Src/system_stm32f0xx.d ./Core/Src/system_stm32f0xx.o ./Core/Src/system_stm32f0xx.su

.PHONY: clean-Core-2f-Src

