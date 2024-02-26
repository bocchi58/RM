/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v15.0
processor: MIMXRT1021xxxxx
package_id: MIMXRT1021DAG5A
mcu_data: ksdk2_0
processor_version: 15.0.1
board: MIMXRT1020-EVK
external_user_signals: {}
pin_labels:
- {pin_num: '96', pin_signal: GPIO_AD_B0_12, label: 'ENET_RXER/U11[20]/J19[4]', identifier: ENET_RXER;ADC1}
power_domains: {NVCC_GPIO: '3.3'}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_xbara.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '105', peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_06, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: '101', peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_07, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: '79', peripheral: GPIO1, signal: 'gpio_io, 27', pin_signal: GPIO_AD_B1_11, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100,
    drive_strength: R0_4, pull_keeper_select: Pull, pull_keeper_enable: Enable, pull_up_down_config: Pull_Up_47K_Ohm, hysteresis_enable: Disable}
  - {pin_num: '96', peripheral: ADC1, signal: 'IN, 0', pin_signal: GPIO_AD_B0_12, identifier: ADC1}
  - {pin_num: '96', peripheral: GPIO1, signal: 'gpio_io, 12', pin_signal: GPIO_AD_B0_12}
  - {pin_num: '123', peripheral: LPSPI4, signal: PCS0, pin_signal: GPIO_EMC_33}
  - {pin_num: '122', peripheral: LPSPI4, signal: SDO, pin_signal: GPIO_EMC_34}
  - {pin_num: '121', peripheral: LPSPI4, signal: SDI, pin_signal: GPIO_EMC_35}
  - {pin_num: '124', peripheral: LPSPI4, signal: SCK, pin_signal: GPIO_EMC_32}
  - {pin_num: '120', peripheral: LPSPI4, signal: PCS1, pin_signal: GPIO_EMC_36}
  - {pin_num: '128', peripheral: ADC_ETC, signal: 'XBAR1_COCO, 0', pin_signal: GPIO_EMC_28, identifier: ''}
  - {pin_num: '13', peripheral: GPIO2, signal: 'gpio_io, 05', pin_signal: GPIO_EMC_05}
  - {pin_num: '10', peripheral: TMR1, signal: 'TIMER_INPUT, 0', pin_signal: GPIO_EMC_07, identifier: ''}
  - {pin_num: '8', peripheral: TMR1, signal: 'TIMER_INPUT, 1', pin_signal: GPIO_EMC_09}
  - {pin_num: '117', peripheral: GPIO3, signal: 'gpio_io, 07', pin_signal: GPIO_EMC_39}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           
  CLOCK_EnableClock(kCLOCK_Xbar1);            

  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_LPUART1_TX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_LPUART1_RX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_GPIO1_IO12, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_GPIO1_IO27, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_05_GPIO2_IO05, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_07_XBAR1_INOUT07, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_09_XBAR1_INOUT09, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_28_XBAR1_INOUT18, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_LPSPI4_SCK, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_33_LPSPI4_PCS0, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_34_LPSPI4_SDO, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_35_LPSPI4_SDI, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_36_LPSPI4_PCS1, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_GPIO3_IO07, 0U); 
  IOMUXC_GPR->GPR6 = ((IOMUXC_GPR->GPR6 &
    (~(IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL_MASK | IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL_MASK | IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7_MASK | IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9_MASK | IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18_MASK))) 
      | IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL(0x01U) 
      | IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL(0x01U) 
      | IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7(0x00U) 
      | IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9(0x00U) 
      | IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18(0x01U) 
    );
  XBARA_SetSignalsConnection(XBARA, kXBARA1_InputIomuxXbarInout07, kXBARA1_OutputQtimer1Tmr0); 
  XBARA_SetSignalsConnection(XBARA, kXBARA1_InputIomuxXbarInout09, kXBARA1_OutputQtimer1Tmr1); 
  XBARA_SetSignalsConnection(XBARA, kXBARA1_InputAdcEtc1Coco0, kXBARA1_OutputIomuxXbarInout18); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_06_LPUART1_TX, 0x10B0U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_07_LPUART1_RX, 0x10B0U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_11_GPIO1_IO27, 0x70A0U); 
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
