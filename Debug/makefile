################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F3xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
zadanie_cv8.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
zadanie_cv8.list \

OBJCOPY_BIN += \
zadanie_cv8.bin \


# All Target
all: zadanie_cv8.elf secondary-outputs

# Tool invocations
zadanie_cv8.elf: $(OBJS) $(USER_OBJS) C:\Users\Frixys\Documents\GitHub\zadanie_cv8\STM32F303K8TX_FLASH.ld
	arm-none-eabi-gcc -o "zadanie_cv8.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Frixys\Documents\GitHub\zadanie_cv8\STM32F303K8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="zadanie_cv8.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

zadanie_cv8.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "zadanie_cv8.list"
	@echo 'Finished building: $@'
	@echo ' '

zadanie_cv8.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "zadanie_cv8.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
