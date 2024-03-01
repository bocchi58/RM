################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/configration.c \
../source/lcd.c \
../source/mouse.c \
../source/semihost_hardfault.c \
../source/spi.c \
../source/touch.c \
../source/usb_device_ch9.c \
../source/usb_device_descriptor.c \
../source/usb_device_hid.c 

C_DEPS += \
./source/configration.d \
./source/lcd.d \
./source/mouse.d \
./source/semihost_hardfault.d \
./source/spi.d \
./source/touch.d \
./source/usb_device_ch9.d \
./source/usb_device_descriptor.d \
./source/usb_device_hid.d 

OBJS += \
./source/configration.o \
./source/lcd.o \
./source/mouse.o \
./source/semihost_hardfault.o \
./source/spi.o \
./source/touch.o \
./source/usb_device_ch9.o \
./source/usb_device_descriptor.o \
./source/usb_device_hid.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDATA_SECTION_IS_CACHEABLE=0 -D_DEBUG=1 -DCPU_MIMXRT1021DAG5A -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DUSB_STACK_BM -DFSL_OSA_BM_TASK_ENABLE=0 -DFSL_OSA_BM_TIMER_CONFIG=0 -DMCUXPRESSO_SDK -DSDK_OS_BAREMETAL -DCPU_MIMXRT1021DAG5A_cm7 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\86155\Desktop\x\workspace\mouse\component\timer" -I"C:\Users\86155\Desktop\x\workspace\mouse\drivers" -I"C:\Users\86155\Desktop\x\workspace\mouse\usb\device\source\ehci" -I"C:\Users\86155\Desktop\x\workspace\mouse\usb\include" -I"C:\Users\86155\Desktop\x\workspace\mouse\usb\phy" -I"C:\Users\86155\Desktop\x\workspace\mouse\utilities" -I"C:\Users\86155\Desktop\x\workspace\mouse\usb\dcd" -I"C:\Users\86155\Desktop\x\workspace\mouse\component\lists" -I"C:\Users\86155\Desktop\x\workspace\mouse\component\uart" -I"C:\Users\86155\Desktop\x\workspace\mouse\device" -I"C:\Users\86155\Desktop\x\workspace\mouse\xip" -I"C:\Users\86155\Desktop\x\workspace\mouse\usb\device\include" -I"C:\Users\86155\Desktop\x\workspace\mouse\usb\device\source" -I"C:\Users\86155\Desktop\x\workspace\mouse\component\osa" -I"C:\Users\86155\Desktop\x\workspace\mouse\CMSIS" -I"C:\Users\86155\Desktop\x\workspace\mouse\component\gpio" -I"C:\Users\86155\Desktop\x\workspace\mouse\source" -I"C:\Users\86155\Desktop\x\workspace\mouse\board" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/configration.d ./source/configration.o ./source/lcd.d ./source/lcd.o ./source/mouse.d ./source/mouse.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/spi.d ./source/spi.o ./source/touch.d ./source/touch.o ./source/usb_device_ch9.d ./source/usb_device_ch9.o ./source/usb_device_descriptor.d ./source/usb_device_descriptor.o ./source/usb_device_hid.d ./source/usb_device_hid.o

.PHONY: clean-source

