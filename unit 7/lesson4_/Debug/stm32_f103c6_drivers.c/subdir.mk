################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_drivers.c/stm32_f103c6_EXTI_driver.c \
../stm32_f103c6_drivers.c/stm32_f103c6_gpio_driver.c 

OBJS += \
./stm32_f103c6_drivers.c/stm32_f103c6_EXTI_driver.o \
./stm32_f103c6_drivers.c/stm32_f103c6_gpio_driver.o 

C_DEPS += \
./stm32_f103c6_drivers.c/stm32_f103c6_EXTI_driver.d \
./stm32_f103c6_drivers.c/stm32_f103c6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_drivers.c/%.o stm32_f103c6_drivers.c/%.su stm32_f103c6_drivers.c/%.cyclo: ../stm32_f103c6_drivers.c/%.c stm32_f103c6_drivers.c/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"D:/ks embedded system ass/unit 7/lesson4/lecture lab/Inc" -I"D:/ks embedded system ass/unit 7/lesson4/lecture lab/stm32_f103c6_drivers.c/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm32_f103c6_drivers-2e-c

clean-stm32_f103c6_drivers-2e-c:
	-$(RM) ./stm32_f103c6_drivers.c/stm32_f103c6_EXTI_driver.cyclo ./stm32_f103c6_drivers.c/stm32_f103c6_EXTI_driver.d ./stm32_f103c6_drivers.c/stm32_f103c6_EXTI_driver.o ./stm32_f103c6_drivers.c/stm32_f103c6_EXTI_driver.su ./stm32_f103c6_drivers.c/stm32_f103c6_gpio_driver.cyclo ./stm32_f103c6_drivers.c/stm32_f103c6_gpio_driver.d ./stm32_f103c6_drivers.c/stm32_f103c6_gpio_driver.o ./stm32_f103c6_drivers.c/stm32_f103c6_gpio_driver.su

.PHONY: clean-stm32_f103c6_drivers-2e-c

