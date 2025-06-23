/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_MTU3_MTU4_user.c
* Component Version: 1.11.0
* Device(s)        : R5F526TFCxFP
* Description      : This file implements device driver for Config_MTU3_MTU4.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_MTU3_MTU4.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_smc_entry.h"
#include "Config_CMT0.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern volatile uint16_t adc_buf_crest[100];
uint8_t i;
uint8_t AD_done_flag;
extern  volatile uint16_t index;

extern volatile uint16_t adc_buf_ADI[100];
uint8_t i_AD0;
uint8_t AD_done_flag_AD0;

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU3_MTU4_Create_UserInit
* Description  : This function adds user code after initializing the MTU3 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU3_MTU4_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_MTU3_MTU4_tgia3_interrupt
* Description  : This function is TGIA3 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_MTU3_TGIA3
#pragma interrupt r_Config_MTU3_MTU4_tgia3_interrupt(vect=VECT(MTU3,TGIA3),fint)
#else
#pragma interrupt r_Config_MTU3_MTU4_tgia3_interrupt(vect=VECT(MTU3,TGIA3))
#endif
static void r_Config_MTU3_MTU4_tgia3_interrupt(void)
{
    /* Start user code for r_Config_MTU3_MTU4_tgia3_interrupt. Do not edit comment generated here */


    if (i < 99)
    {
        adc_buf_crest[i++] = S12AD.ADDBLDRA;
        adc_buf_crest[i++] = S12AD.ADDBLDRB;
    }
    else
    {

    	AD_done_flag = 1;
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_MTU3_MTU4_tgib3_interrupt
* Description  : This function is TGIB3 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_MTU3_TGIB3
#pragma interrupt r_Config_MTU3_MTU4_tgib3_interrupt(vect=VECT(MTU3,TGIB3),fint)
#else
#pragma interrupt r_Config_MTU3_MTU4_tgib3_interrupt(vect=VECT(MTU3,TGIB3))
#endif
static void r_Config_MTU3_MTU4_tgib3_interrupt(void)
{
    /* Start user code for r_Config_MTU3_MTU4_tgib3_interrupt. Do not edit comment generated here */
	R_Config_CMT0_Stop();
	index =0 ;
	R_Config_CMT0_Start();
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_MTU3_MTU4_c4_tciv4_interrupt
* Description  : This function is TCIV4 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_MTU4_TCIV4
#pragma interrupt r_Config_MTU3_MTU4_c4_tciv4_interrupt(vect=VECT(MTU4,TCIV4),fint)
#else
#pragma interrupt r_Config_MTU3_MTU4_c4_tciv4_interrupt(vect=VECT(MTU4,TCIV4))
#endif
static void r_Config_MTU3_MTU4_c4_tciv4_interrupt(void)
{
    /* Start user code for r_Config_MTU3_MTU4_c4_tciv4_interrupt. Do not edit comment generated here */
    if (i_AD0 < 99)
    {
        adc_buf_ADI[i_AD0++] = S12AD.ADDBLDRA;
        adc_buf_ADI[i_AD0++] = S12AD.ADDBLDRB;
    }
    else
    {

    	AD_done_flag_AD0 = 1;
    }

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
