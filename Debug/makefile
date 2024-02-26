################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xip/subdir.mk
-include utilities/subdir.mk
-include usb/phy/subdir.mk
-include usb/device/source/ehci/subdir.mk
-include usb/device/source/subdir.mk
-include usb/dcd/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/timer/subdir.mk
-include component/osa/subdir.mk
-include component/lists/subdir.mk
-include component/gpio/subdir.mk
-include board/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := evkmimxrt1020_dev_hid_mouse_lite_bm
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: evkmimxrt1020_dev_hid_mouse_lite_bm.axf

# Tool invocations
evkmimxrt1020_dev_hid_mouse_lite_bm.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -no-warn-rwx-segments -Xlinker -Map="evkmimxrt1020_dev_hid_mouse_lite_bm.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -T evkmimxrt1020_dev_hid_mouse_lite_bm_Debug.ld -o "evkmimxrt1020_dev_hid_mouse_lite_bm.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) evkmimxrt1020_dev_hid_mouse_lite_bm.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "evkmimxrt1020_dev_hid_mouse_lite_bm.axf"; # arm-none-eabi-objcopy -v -O binary "evkmimxrt1020_dev_hid_mouse_lite_bm.axf" "evkmimxrt1020_dev_hid_mouse_lite_bm.bin" ; # checksum -p MIMXRT1021xxxxx -d "evkmimxrt1020_dev_hid_mouse_lite_bm.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
