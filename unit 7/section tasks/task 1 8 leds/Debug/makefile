################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
task18leds.lss \

FLASH_IMAGE += \
task18leds.hex \

EEPROM_IMAGE += \
task18leds.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: task18leds.elf secondary-outputs

# Tool invocations
task18leds.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,task18leds.map -mmcu=atmega32 -o "task18leds.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

task18leds.lss: task18leds.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S task18leds.elf  >"task18leds.lss"
	@echo 'Finished building: $@'
	@echo ' '

task18leds.hex: task18leds.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex task18leds.elf  "task18leds.hex"
	@echo 'Finished building: $@'
	@echo ' '

task18leds.eep: task18leds.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex task18leds.elf  "task18leds.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: task18leds.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 task18leds.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) task18leds.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
