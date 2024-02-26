#include "fsl_qtmr.h"
#include "fsl_gpio.h"
#include "fsl_common.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "peripherals.h"
#include "fsl_qtmr.h"

#define TMR1_PERIPHERAL   TMR1
#define TMR1_CHANNEL_A    kQTMR_Channel_0
#define TMR1_CHANNEL_B    kQTMR_Channel_1

//全局变量
uint16_t g_AdcConversionDoneFlag_Y;
uint16_t g_AdcConversionValue_Y;
uint16_t g_AdcInterruptCounter_Y;

uint16_t g_AdcConversionDoneFlag_X;
uint16_t g_AdcConversionValue_X;
uint16_t g_AdcInterruptCounter_X;


//采集双轴电位器的数据  ADC
void ADC1_IRQHandler(void)
{
	g_AdcConversionDoneFlag_X = true;
    /* Read conversion result to clear the conversion completed flag. */
	g_AdcConversionValue_X = ADC_GetChannelConversionValue(ADC1, 0U);
	g_AdcInterruptCounter_X++;
    SDK_ISR_EXIT_BARRIER;
    g_AdcConversionDoneFlag_X = false;
    ADC_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH0_CONTROL_GROUP, &ADC1_channels_config[0]);
}
void ADC_ETC_ERROR_IRQ_IRQHandler(void)
{
	g_AdcConversionDoneFlag_Y = true;
	/* Read conversion result to clear the conversion completed flag. */
	g_AdcInterruptCounter_Y++;
	g_AdcConversionValue_Y = ADC_ETC_GetADCConversionValue(ADC_ETC_PERIPHERAL, ADC_ETC_ADC_ETC_TG,0U);
	SDK_ISR_EXIT_BARRIER;
	g_AdcConversionDoneFlag_Y = false;
	ADC_ETC_SetTriggerConfig(ADC_ETC_PERIPHERAL, ADC_ETC_ADC_ETC_TG, &ADC_ETC_trigger_config[ADC_ETC_ADC_ETC]);
}

volatile uint32_t g_EncoderCount = 0;

//采集旋钮的数据  Encoder_A Encoder_B Encoder_C
void TMR1_IRQHandler(void)
{
    /* Disable interrupts for Timer 1 channel A */
    QTMR_DisableInterrupts(TMR1_PERIPHERAL, TMR1_CHANNEL_A, kQTMR_EdgeInterruptEnable);

    uint32_t status = QTMR_GetStatus(TMR1_PERIPHERAL, TMR1_CHANNEL_A);

    if (status & kQTMR_EdgeFlag)
    {
        /* Increment or decrement the count based on the direction */
        if (GPIO_PinRead(GPIO2, 7) == 1) // Assuming A phase connected to GPIO2 pin 7
        {
            g_EncoderCount++;
        }
        else
        {
            g_EncoderCount--;
        }

        /* Clear the interrupt flag */
        QTMR_ClearStatusFlags(TMR1_PERIPHERAL, TMR1_CHANNEL_A, kQTMR_EdgeFlag);
    }

    /* Re-enable interrupts for Timer 1 channel A */
    QTMR_EnableInterrupts(TMR1_PERIPHERAL, TMR1_CHANNEL_A, kQTMR_EdgeInterruptEnable);
}


//电阻式触摸屏 SPI4


