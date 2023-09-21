################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include LCD_DRIVER/subdir.mk
-include KEY_PAD_DRIVER/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
LCD_KEYPAD_DRIVERS.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: LCD_KEYPAD_DRIVERS.elf secondary-outputs

# Tool invocations
LCD_KEYPAD_DRIVERS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -gdwarf-2 -Wl,-Map,LCD_KEYPAD_DRIVERS.map -mmcu=atmega32 -o "LCD_KEYPAD_DRIVERS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD_KEYPAD_DRIVERS.lss: LCD_KEYPAD_DRIVERS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD_KEYPAD_DRIVERS.elf  >"LCD_KEYPAD_DRIVERS.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD_KEYPAD_DRIVERS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LCD_KEYPAD_DRIVERS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD_KEYPAD_DRIVERS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
