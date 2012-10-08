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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
blinkLed.lss \

FLASH_IMAGE += \
blinkLed.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: blinkLed.elf secondary-outputs

# Tool invocations
blinkLed.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,blinkLed.map -mmcu=atmega32 -o "blinkLed.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

blinkLed.lss: blinkLed.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S blinkLed.elf  >"blinkLed.lss"
	@echo 'Finished building: $@'
	@echo ' '

blinkLed.hex: blinkLed.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex blinkLed.elf  "blinkLed.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: blinkLed.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 blinkLed.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) blinkLed.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
