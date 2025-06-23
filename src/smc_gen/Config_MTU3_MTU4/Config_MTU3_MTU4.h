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
* File Name        : Config_MTU3_MTU4.h
* Component Version: 1.11.0
* Device(s)        : R5F526TFCxFP
* Description      : This file implements device driver for Config_MTU3_MTU4.
***********************************************************************************************************************/

#ifndef CFG_Config_MTU3_MTU4_H
#define CFG_Config_MTU3_MTU4_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_mtu3.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define MTU3_PCLK_COUNTER_DIVISION      (1)
#define _003C_3TCNT_VALUE               (0x003CU) /* MTU3.TCNT value */
#define _EA60_TCDRA_VALUE               (0xEA60U) /* MTU.TCDRA value */
#define _000A_3TGRB_VALUE               (0x000AU) /* MTU3.TGRB value */
#define _7530_4TGRA_VALUE               (0x7530U) /* MTU4.TGRA value */
#define _7530_4TGRB_VALUE               (0x7530U) /* MTU4.TGRB value */
/* Timer A/D Converter Start Request Cycle Set Registers A value */
#define _2EE0_TADCORA_VALUE             (0x2EE0U) /* MTU4.TADCORA value */
/* Timer A/D Converter Start Request Cycle Set Buffer Registers A value */
#define _2EE0_TADCOBRA_VALUE            (0x2EE0U) /* MTU4.TADCOBRA value */
/* Timer A/D Converter Start Request Cycle Set Registers B value */
#define _BB80_TADCORB_VALUE             (0xBB80U) /* MTU4.TADCORB value */
/* Timer A/D Converter Start Request Cycle Set Buffer Registers B value */
#define _BB80_TADCOBRB_VALUE            (0xBB80U) /* MTU4.TADCOBRB value */
#define _EA61_SUM_VALUE                 (0xEA61U) /* Timer General Register (TGR) value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_MTU3_MTU4_Create(void);
void R_Config_MTU3_MTU4_Create_UserInit(void);
void R_Config_MTU3_MTU4_Start(void);
void R_Config_MTU3_MTU4_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
