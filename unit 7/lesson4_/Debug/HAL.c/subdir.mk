################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL.c/keypad.c \
../HAL.c/lcd.c 

OBJS += \
./HAL.c/keypad.o \
./HAL.c/lcd.o 

C_DEPS += \
./HAL.c/keypad.d \
./HAL.c/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL.c/%.o HAL.c/%.su HAL.c/%.cyclo: ../HAL.c/%.c HAL.c/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/ks embedded system ass/unit 7/lesson4/lecture lab/Inc" -I"D:/ks embedded system ass/unit 7/lesson4/lecture lab/stm32_f103c6_drivers.c/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2e-c

clean-HAL-2e-c:
	-$(RM) ./HAL.c/keypad.cyclo ./HAL.c/keypad.d ./HAL.c/keypad.o ./HAL.c/keypad.su ./HAL.c/lcd.cyclo ./HAL.c/lcd.d ./HAL.c/lcd.o ./HAL.c/lcd.su

.PHONY: clean-HAL-2e-c

