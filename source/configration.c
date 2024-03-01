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


////采集双轴电位器的数据  ADC
//void ADC1_IRQHandler(void)
//{
//	g_AdcConversionDoneFlag_X = true;
//    /* Read conversion result to clear the conversion completed flag. */
//	g_AdcConversionValue_X = ADC_GetChannelConversionValue(ADC1, 0U);
//	g_AdcInterruptCounter_X++;
//    SDK_ISR_EXIT_BARRIER;
//    g_AdcConversionDoneFlag_X = false;
//    ADC_SetChannelConfig(ADC1_PERIPHERAL, ADC1_CH0_CONTROL_GROUP, &ADC1_channels_config[0]);
//}

//采集双轴电位器的数据 TMR输入捕获模式
float Freqency; // 频率
float Duty_Cycle;//占空比
void TMR2_IRQHandler(void)
{
	uint32_t risingEdgeTime; //上升沿的时间戳
	uint32_t fallingEdgeTime; //下降沿的时间戳
	uint32_t current_risingEdgeTime; //当前上升沿的时间戳，用于计算周期
	uint32_t hightime;
	uint32_t period; //周期
	// 失能 Timer2 channel 0 的中断
	QTMR_DisableInterrupts(TMR2_PERIPHERAL, TMR2_CHANNEL_0_CHANNEL, kQTMR_EdgeInterruptEnable);

	uint32_t status = QTMR_GetStatus(TMR1_PERIPHERAL, TMR1_CHANNEL_A);
	if (status & kQTMR_EdgeFlag)
	{
		if(GPIO_PinRead(GPIO2, 28) == 1) //是个上升沿
		{
			current_risingEdgeTime = QTMR_GetCurrentTimerCount(TMR2_PERIPHERAL, TMR2_CHANNEL_0_CHANNEL);
			period = current_risingEdgeTime - risingEdgeTime;
			risingEdgeTime = current_risingEdgeTime;
		}else{
			fallingEdgeTime= QTMR_GetCurrentTimerCount(TMR2_PERIPHERAL, TMR2_CHANNEL_0_CHANNEL);
			hightime = current_risingEdgeTime - fallingEdgeTime;
		}


		Duty_Cycle = 1.0 * hightime / period;//计算占空比
		Freqency = 1.0 / period;

		QTMR_ClearStatusFlags(TMR1_PERIPHERAL, TMR1_CHANNEL_A, kQTMR_EdgeFlag);
	}
    // 重新使能 Timer 2 channel 0 的中断
	QTMR_EnableInterrupts(TMR2_PERIPHERAL, TMR2_CHANNEL_0_CHANNEL, kQTMR_EdgeInterruptEnable);
}


uint32_t g_EncoderCount = 0;
uint32_t g_encoder = 0;
//采集旋钮的数据  Encoder_A Encoder_B Encoder_C
void TMR1_IRQHandler(void)
{
    /* Disable interrupts for Timer 1 channel A */
    QTMR_DisableInterrupts(TMR1_PERIPHERAL, TMR1_CHANNEL_A, kQTMR_EdgeInterruptEnable);

    uint32_t status = QTMR_GetStatus(TMR1_PERIPHERAL, TMR1_CHANNEL_A);

    //判断定时器溢出

    if (status & kQTMR_EdgeFlag)
    {
        //判断方向
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


