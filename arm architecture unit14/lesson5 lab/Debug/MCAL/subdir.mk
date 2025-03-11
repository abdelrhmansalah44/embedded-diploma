################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTI.c \
../MCAL/GPIO.c 

OBJS += \
./MCAL/EXTI.o \
./MCAL/GPIO.o 

C_DEPS += \
./MCAL/EXTI.d \
./MCAL/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ks embedded system ass/arm architecture unit 14/arm architecture unit14/lesson5 lab/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/EXTI.cyclo ./MCAL/EXTI.d ./MCAL/EXTI.o ./MCAL/EXTI.su ./MCAL/GPIO.cyclo ./MCAL/GPIO.d ./MCAL/GPIO.o ./MCAL/GPIO.su

.PHONY: clean-MCAL

