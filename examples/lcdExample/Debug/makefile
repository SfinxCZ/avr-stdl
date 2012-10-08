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
lcdExample.lss \

FLASH_IMAGE += \
lcdExample.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: lcdExample.elf secondary-outputs

dependents:
	-cd /home/stiborek/work/avr/avr-stdl/libs/lcd/Debug && $(MAKE) clean all

# Tool invocations
lcdExample.elf: $(OBJS) $(USER_OBJS) /home/stiborek/work/avr/avr-stdl/libs/lcd/Debug/liblcd.a
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lcdExample.map -L"/home/stiborek/work/avr/avr-stdl/libs/lcd/Debug" -mmcu=atmega32 -o "lcdExample.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lcdExample.lss: lcdExample.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lcdExample.elf  >"lcdExample.lss"
	@echo 'Finished building: $@'
	@echo ' '

lcdExample.hex: lcdExample.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex lcdExample.elf  "lcdExample.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lcdExample.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 lcdExample.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) lcdExample.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:
/home/stiborek/work/avr/avr-stdl/libs/lcd/Debug/liblcd.a:

-include ../makefile.targets
