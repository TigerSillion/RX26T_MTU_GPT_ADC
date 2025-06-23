/***********************************************************************
*
*  FILE        : RX26T_MTU_GPT_ADC.c
*  DATE        : 2025-06-21
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"
#include <stdio.h>

void main(void);

extern uint8_t AD_done_flag;
extern uint8_t AD_done_flag_AD0;
volatile uint16_t adc_buf_crest[100];
volatile uint16_t adc_buf_ADI[100];
//volatile uint16_t adc_buf_trough[100]
//volatile uint16_t adc_buf_ADGROUPA[100]

void main(void)
{
	//R_Config_CMT0_Start();
	R_Config_DA0_Start();
	R_Config_MTU3_MTU4_Start();
	R_Config_S12AD0_Start();
	//int8_t i;
	printf("Hello main 26T \r\n");
	while(1)
	{
    if (AD_done_flag)
    {
    	AD_done_flag = 0;
        for (int j = 0; j < 100; j++)
        {
            float voltage = (adc_buf_crest[j] / 4095.0f) * 3.3f;
            printf("crest[%d] = %.3f V\n", j, voltage);
        }
      //  break; // 只打印一次
    }

    if (AD_done_flag_AD0)
    {
    		AD_done_flag_AD0 = 0;
        for (int j = 0; j < 100; j++)
        {
            float voltage = (adc_buf_ADI[j] / 4095.0f) * 3.3f;
            printf("adc_buf_ADI[%d] = %.3f V\n", j, voltage);
        }
      //  break; // 只打印一次
    }

	}
}
