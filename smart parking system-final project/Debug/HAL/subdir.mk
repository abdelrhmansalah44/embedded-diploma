################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/PIR.c \
../HAL/Servo_Motor.c \
../HAL/keypad.c \
../HAL/lcd.c \
../HAL/led.c 

OBJS += \
./HAL/PIR.o \
./HAL/Servo_Motor.o \
./HAL/keypad.o \
./HAL/lcd.o \
./HAL/led.o 

C_DEPS += \
./HAL/PIR.d \
./HAL/Servo_Motor.d \
./HAL/keypad.d \
./HAL/lcd.d \
./HAL/led.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su HAL/%.cyclo: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/ks embedded system ass/unit 11 final project/smart parking system-final project/App/inc" -I"D:/ks embedded system ass/unit 11 final project/smart parking system-final project/HAL/inc" -I"D:/ks embedded system ass/unit 11 final project/smart parking system-final project/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/PIR.cyclo ./HAL/PIR.d ./HAL/PIR.o ./HAL/PIR.su ./HAL/Servo_Motor.cyclo ./HAL/Servo_Motor.d ./HAL/Servo_Motor.o ./HAL/Servo_Motor.su ./HAL/keypad.cyclo ./HAL/keypad.d ./HAL/keypad.o ./HAL/keypad.su ./HAL/lcd.cyclo ./HAL/lcd.d ./HAL/lcd.o ./HAL/lcd.su ./HAL/led.cyclo ./HAL/led.d ./HAL/led.o ./HAL/led.su

.PHONY: clean-HAL

