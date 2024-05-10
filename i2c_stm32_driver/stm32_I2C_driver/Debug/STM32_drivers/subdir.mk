################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_drivers/RCC_clock_configuration.c \
../STM32_drivers/stm32_f103c6_I2C_driver.c \
../STM32_drivers/stm32_f103c6_gpio_driver.c 

OBJS += \
./STM32_drivers/RCC_clock_configuration.o \
./STM32_drivers/stm32_f103c6_I2C_driver.o \
./STM32_drivers/stm32_f103c6_gpio_driver.o 

C_DEPS += \
./STM32_drivers/RCC_clock_configuration.d \
./STM32_drivers/stm32_f103c6_I2C_driver.d \
./STM32_drivers/stm32_f103c6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_drivers/%.o STM32_drivers/%.su STM32_drivers/%.cyclo: ../STM32_drivers/%.c STM32_drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/ks embedded system ass/unit 8 interfacing/I2C/i2c_lecture/stm32_I2C_driver/HAL/inc" -I"D:/ks embedded system ass/unit 8 interfacing/I2C/i2c_lecture/stm32_I2C_driver/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32_drivers

clean-STM32_drivers:
	-$(RM) ./STM32_drivers/RCC_clock_configuration.cyclo ./STM32_drivers/RCC_clock_configuration.d ./STM32_drivers/RCC_clock_configuration.o ./STM32_drivers/RCC_clock_configuration.su ./STM32_drivers/stm32_f103c6_I2C_driver.cyclo ./STM32_drivers/stm32_f103c6_I2C_driver.d ./STM32_drivers/stm32_f103c6_I2C_driver.o ./STM32_drivers/stm32_f103c6_I2C_driver.su ./STM32_drivers/stm32_f103c6_gpio_driver.cyclo ./STM32_drivers/stm32_f103c6_gpio_driver.d ./STM32_drivers/stm32_f103c6_gpio_driver.o ./STM32_drivers/stm32_f103c6_gpio_driver.su

.PHONY: clean-STM32_drivers

