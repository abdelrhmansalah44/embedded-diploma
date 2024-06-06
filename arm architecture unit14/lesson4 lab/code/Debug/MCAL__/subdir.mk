################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL__/EXTI.c \
../MCAL__/GPIO.c 

OBJS += \
./MCAL__/EXTI.o \
./MCAL__/GPIO.o 

C_DEPS += \
./MCAL__/EXTI.d \
./MCAL__/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL__/%.o MCAL__/%.su MCAL__/%.cyclo: ../MCAL__/%.c MCAL__/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"D:/ks embedded system ass/arm architecture unit 14/lesson3 labs/code/MCAL__/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL__

clean-MCAL__:
	-$(RM) ./MCAL__/EXTI.cyclo ./MCAL__/EXTI.d ./MCAL__/EXTI.o ./MCAL__/EXTI.su ./MCAL__/GPIO.cyclo ./MCAL__/GPIO.d ./MCAL__/GPIO.o ./MCAL__/GPIO.su

.PHONY: clean-MCAL__

