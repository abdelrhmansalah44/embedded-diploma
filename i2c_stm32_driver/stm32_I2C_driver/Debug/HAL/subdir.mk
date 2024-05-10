################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_EEPROM_slave.c 

OBJS += \
./HAL/I2C_EEPROM_slave.o 

C_DEPS += \
./HAL/I2C_EEPROM_slave.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o HAL/%.su HAL/%.cyclo: ../HAL/%.c HAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/ks embedded system ass/unit 8 interfacing/I2C/i2c_lecture/stm32_I2C_driver/HAL/inc" -I"D:/ks embedded system ass/unit 8 interfacing/I2C/i2c_lecture/stm32_I2C_driver/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL

clean-HAL:
	-$(RM) ./HAL/I2C_EEPROM_slave.cyclo ./HAL/I2C_EEPROM_slave.d ./HAL/I2C_EEPROM_slave.o ./HAL/I2C_EEPROM_slave.su

.PHONY: clean-HAL

