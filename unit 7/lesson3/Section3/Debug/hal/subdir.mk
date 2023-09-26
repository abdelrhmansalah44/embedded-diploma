################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/keypad.c \
../hal/lcd.c 

OBJS += \
./hal/keypad.o \
./hal/lcd.o 

C_DEPS += \
./hal/keypad.d \
./hal/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
hal/%.o hal/%.su hal/%.cyclo: ../hal/%.c hal/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"D:/ks embedded system ass/unit 7/lesson3/Section3/hal/inc" -I"D:/ks embedded system ass/unit 7/lesson3/Section3/stm32_f103c6_drivers_/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-hal

clean-hal:
	-$(RM) ./hal/keypad.cyclo ./hal/keypad.d ./hal/keypad.o ./hal/keypad.su ./hal/lcd.cyclo ./hal/lcd.d ./hal/lcd.o ./hal/lcd.su

.PHONY: clean-hal

