################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KEY_PAD_DRIVER/KEYPAD.c 

OBJS += \
./KEY_PAD_DRIVER/KEYPAD.o 

C_DEPS += \
./KEY_PAD_DRIVER/KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
KEY_PAD_DRIVER/%.o: ../KEY_PAD_DRIVER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -gdwarf-2 -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


