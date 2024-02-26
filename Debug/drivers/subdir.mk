################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_adc.c \
../drivers/fsl_adc_etc.c \
../drivers/fsl_cache.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_enc.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpspi.c \
../drivers/fsl_lpuart.c \
../drivers/fsl_pit.c \
../drivers/fsl_qtmr.c \
../drivers/fsl_xbara.c 

C_DEPS += \
./drivers/fsl_adc.d \
./drivers/fsl_adc_etc.d \
./drivers/fsl_cache.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_enc.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpspi.d \
./drivers/fsl_lpuart.d \
./drivers/fsl_pit.d \
./drivers/fsl_qtmr.d \
./drivers/fsl_xbara.d 

OBJS += \
./drivers/fsl_adc.o \
./drivers/fsl_adc_etc.o \
./drivers/fsl_cache.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_enc.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpspi.o \
./drivers/fsl_lpuart.o \
./drivers/fsl_pit.o \
./drivers/fsl_qtmr.o \
./drivers/fsl_xbara.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDATA_SECTION_IS_CACHEABLE=0 -D_DEBUG=1 -DCPU_MIMXRT1021DAG5A -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DUSB_STACK_BM -DFSL_OSA_BM_TASK_ENABLE=0 -DFSL_OSA_BM_TIMER_CONFIG=0 -DMCUXPRESSO_SDK -DSDK_OS_BAREMETAL -DCPU_MIMXRT1021DAG5A_cm7 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\component\timer" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\drivers" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\usb\device\source\ehci" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\usb\include" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\usb\phy" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\utilities" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\usb\dcd" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\component\lists" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\component\uart" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\device" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\xip" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\usb\device\include" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\usb\device\source" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\component\osa" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\CMSIS" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\component\gpio" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\source" -I"C:\Users\86155\Documents\MCUXpressoIDE_11.9.0_2144\workspace\evkmimxrt1020_dev_hid_mouse_lite_bm\board" -O0 -fno-common -g3 -gdwarf-4 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_adc.d ./drivers/fsl_adc.o ./drivers/fsl_adc_etc.d ./drivers/fsl_adc_etc.o ./drivers/fsl_cache.d ./drivers/fsl_cache.o ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_enc.d ./drivers/fsl_enc.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_lpspi.d ./drivers/fsl_lpspi.o ./drivers/fsl_lpuart.d ./drivers/fsl_lpuart.o ./drivers/fsl_pit.d ./drivers/fsl_pit.o ./drivers/fsl_qtmr.d ./drivers/fsl_qtmr.o ./drivers/fsl_xbara.d ./drivers/fsl_xbara.o

.PHONY: clean-drivers

