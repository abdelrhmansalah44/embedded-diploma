################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/MYRTOS_FIFO.c \
../RTOS/cortexM_os_porting.c \
../RTOS/schedular.c 

OBJS += \
./RTOS/MYRTOS_FIFO.o \
./RTOS/cortexM_os_porting.o \
./RTOS/schedular.o 

C_DEPS += \
./RTOS/MYRTOS_FIFO.d \
./RTOS/cortexM_os_porting.d \
./RTOS/schedular.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/%.o RTOS/%.su RTOS/%.cyclo: ../RTOS/%.c RTOS/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"D:/ks embedded system ass/unit15 RTOS/ABDO_RTOS1/CMSIS" -I"D:/ks embedded system ass/unit15 RTOS/ABDO_RTOS1/RTOS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-RTOS

clean-RTOS:
	-$(RM) ./RTOS/MYRTOS_FIFO.cyclo ./RTOS/MYRTOS_FIFO.d ./RTOS/MYRTOS_FIFO.o ./RTOS/MYRTOS_FIFO.su ./RTOS/cortexM_os_porting.cyclo ./RTOS/cortexM_os_porting.d ./RTOS/cortexM_os_porting.o ./RTOS/cortexM_os_porting.su ./RTOS/schedular.cyclo ./RTOS/schedular.d ./RTOS/schedular.o ./RTOS/schedular.su

.PHONY: clean-RTOS

