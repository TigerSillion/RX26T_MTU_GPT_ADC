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
* File Name        : Config_POE.c
* Component Version: 1.11.0
* Device(s)        : R5F526TFCxFP
* Description      : This file implements device driver for Config_POE.
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
#include "Config_POE.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_POE_Create
* Description  : This function initializes the POE3 module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_POE_Create(void)
{
    /* Please assign MTIOC3D pin */
    /* Please assign MTIOC4A pin */
    /* Please assign MTIOC4C pin */
    /* Please assign MTIOC4B pin */
    /* Please assign MTIOC4D pin */

    /* Set MTU / GPT pin select */
    POE.M3SELR.BYTE = _01_POE_MTU3BPIN_P71 | _00_POE_MTU3DPIN_NOPIN_SET;
    POE.M4SELR1.BYTE = _00_POE_MTU4APIN_NOPIN_SET | _00_POE_MTU4CPIN_NOPIN_SET;
    POE.M4SELR2.BYTE = _00_POE_MTU4BPIN_NOPIN_SET | _00_POE_MTU4DPIN_NOPIN_SET;

    /* Active levels setting of the MTU and GPT outputs */
    POE.ALR1.WORD = _0001_POE_MTIOC3B_HIGH | _0002_POE_MTIOC3D_HIGH | _0004_POE_MTIOC4A_HIGH | 
                    _0008_POE_MTIOC4C_HIGH | _0010_POE_MTIOC4B_HIGH | _0020_POE_MTIOC4D_HIGH | 
                    _0080_POE_MTU34_ACTLEL_ENABLE;

    /* Output level control setting */
    POE.OCSR1.WORD = _0000_POE_OIE1_DISABLE | _0200_POE_OCE1_ENABLE;
    POE.OCSR2.WORD = _0000_POE_OCE2_DISABLE;
    POE.OCSR3.WORD = _0000_POE_OCE3_DISABLE;
    POE.OCSR4.WORD = _0000_POE_OCE4_DISABLE;
    POE.OCSR5.WORD = _0000_POE_OCE5_DISABLE;

    /* Port output enable control setting */
    POE.POECR2.WORD = _0100_POE_MTU4BDZE_ENABLE | _0200_POE_MTU4ACZE_ENABLE | _0400_POE_MTU3BDZE_ENABLE | 
                      _0000_POE_POECR2_CLEAR;

    /* Set extend the control conditions for MTU3 and MTU4 */
    POE.POECR4.WORD = _0002_POE_IC1ADDMT34ZE_ENABLE;

    /* Set mask of POE0# signal */
    POE.IMCR0.BYTE = _00_POE_NO_MASK;

    /* Input level control/status for POE0# */
    POE.ICSR1.WORD = _0000_POE_POE0M_SEL_DEFAULT | _0000_POE_PIE1_DISABLE | _0000_POE_POE0_INV_DISABLE;

    /* Input level control/status for POE8# */
    POE.ICSR3.WORD = _0000_POE_POE8E_DISABLE;

    /* Input level control/status for POE10# */
    POE.ICSR4.WORD = _0000_POE_POE10E_DISABLE;

    /* Input level control/status for POE11# */
    POE.ICSR5.WORD = _0000_POE_POE11E_DISABLE;

    /* Input level control/status for POE12# */
    POE.ICSR7.WORD = _0000_POE_POE12E_DISABLE;

    /* Input level control/status for POE9# */
    POE.ICSR8.WORD = _0000_POE_POE9E_DISABLE;

    /* Stopped oscillation detection control setting */
    POE.ICSR6.WORD = _0000_POE_OSTSTE_DISABLE;

    /* Set POE0# pin */
    MPC.P70PFS.BYTE = 0x07U;
    PORT7.PMR.BYTE |= 0x01U;

    R_Config_POE_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_POE_Start
* Description  : This function starts the POE3 module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_POE_Start(void)
{
}

/***********************************************************************************************************************
* Function Name: R_Config_POE_Stop
* Description  : This function stops the POE3 module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_POE_Stop(void)
{
    /* Clear POE0F flag */
    if (1U == POE.ICSR1.BIT.POE0F)
    {
        POE.ICSR1.BIT.POE0F = 0U;
    }

    /* Clear POE4F flag */
    if (1U == POE.ICSR2.BIT.POE4F)
    {
        POE.ICSR2.BIT.POE4F = 0U;
    }

    /* Clear POE8F flag */
    if (1U == POE.ICSR3.BIT.POE8F)
    {
        POE.ICSR3.BIT.POE8F = 0U;
    }

    /* Clear POE9F flag */
    if (1U == POE.ICSR8.BIT.POE9F)
    {
        POE.ICSR8.BIT.POE9F = 0U;
    }

    /* Clear POE10F flag */
    if (1U == POE.ICSR4.BIT.POE10F)
    {
        POE.ICSR4.BIT.POE10F = 0U;
    }

    /* Clear POE11F flag */
    if (1U == POE.ICSR5.BIT.POE11F)
    {
        POE.ICSR5.BIT.POE11F = 0U;
    }

    /* Clear POE12F flag */
    if (1U == POE.ICSR7.BIT.POE12F)
    {
        POE.ICSR7.BIT.POE12F = 0U;
    }

    /* Clear output short flag 1 */
    if (1U == POE.OCSR1.BIT.OSF1)
    {
        POE.OCSR1.BIT.OSF1 = 0U;
    }

    /* Clear output short flag 2 */
    if (1U == POE.OCSR2.BIT.OSF2)
    {
        POE.OCSR2.BIT.OSF2 = 0U;
    }

    /* Clear output short flag 3 */
    if (1U == POE.OCSR3.BIT.OSF3)
    {
        POE.OCSR3.BIT.OSF3 = 0U;
    }

    /* Clear output short flag 4 */
    if (1U == POE.OCSR4.BIT.OSF4)
    {
        POE.OCSR4.BIT.OSF4 = 0U;
    }

    /* Clear output short flag 5 */
    if (1U == POE.OCSR5.BIT.OSF5)
    {
        POE.OCSR5.BIT.OSF5 = 0U;
    }

    /* Clear OSTST High-Impedance flag */
    if (1U == POE.ICSR6.BIT.OSTSTF)
    {
        POE.ICSR6.BIT.OSTSTF = 0U;
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
