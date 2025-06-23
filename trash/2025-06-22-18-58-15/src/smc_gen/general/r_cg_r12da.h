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
* File Name        : r_cg_r12da.h
* Version          : 1.0.10
* Device(s)        : R5F526TFCxFP
* Description      : General header file for R12DA peripheral.
***********************************************************************************************************************/

#ifndef DA_H
#define DA_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    D/A Control Register (DACR)
*/
/* D/A Enable (DAE) */
#define _00_DA_DISABLE              (0x00U) /* D/A conversion of channels 0 and 1 is controlled individually */
#define _20_DA_ENABLE               (0x20U) /* D/A conversion of channels 0 and 1 is enabled collectively */
/* D/A Output Enable 0 (DAOE0) */
#define _00_DA0_DISABLE             (0x00U) /* Analog output of channel 0 (DA0) is disabled */
#define _40_DA0_ENABLE              (0x40U) /* D/A conversion of channel 0 is enabled
                                               Analog output of channel 0 (DA0) is enabled */
/* D/A Output Enable 1 (DAOE1) */
#define _00_DA1_DISABLE             (0x00U) /* Analog output of channel 1 (DA1) is disabled */
#define _80_DA1_ENABLE              (0x80U) /* D/A conversion of channel 1 is enabled
                                               Analog output of channel 1 (DA1) is enabled */
/* DACR default value */
#define _1F_DA_DACR_DEFAULT         (0x1FU) /* Write default value of DACR */

/*
    DADRm Format Select Register (DADPR)
*/
/* DADRm Format Select (DPSEL) */
#define _00_DA_DPSEL_R              (0x00U) /* Data is right-justified. */
#define _80_DA_DPSEL_L              (0x80U) /* Data is left-justified. */

/*
    D/A-A/D Synchronous Start Control Register (DAADSCR)
*/
/* D/A-A/D Synchronous Conversion (DAADST) */
#define _00_DA_DAADSYNC_DISABLE     (0x00U) /* 12-bit D/A converter operation does not synchronize
                                               with 12-bit A/D converter operation */
#define _80_DA_DAADSYNC_ENABLE      (0x80U) /* 12-bit D/A converter operation synchronizes
                                               with 12-bit A/D converter operation */

/*
    D/A Destination Select Register (DADSELR)
 */
/* DA0 pin output enable (OUTDA0) */
#define _00_DA_OUTDA0_DISABLE       (0x00U) /* Does not output the channel 0 analog voltage from the DA0 pin */
#define _01_DA_OUTDA0_ENABLE        (0x01U) /* Output the channel 0 analog voltage from the DA0 pin */
/* DA1 pin output enable (OUTDA1) */
#define _00_DA_OUTDA1_DISABLE       (0x00U) /* Does not output the channel 1 analog voltage from the DA1 pin */
#define _02_DA_OUTDA1_ENABLE        (0x02U) /* Output the channel 1 analog voltage from the DA1 pin */
/* Reference voltage output enable (OUTREF0) */
#define _00_DA_OUTREF0_DISABLE      (0x00U) /* Does not use the channel 0 analog voltage
                                               as a reference voltage for the comparator C */
#define _04_DA_OUTREF0_ENABLE       (0x04U) /* Use the channel 0 analog voltage
                                               as a reference voltage for the comparator C */
/* Reference voltage output enable (OUTREF1) */
#define _00_DA_OUTREF1_DISABLE      (0x00U) /* Does not use the channel 1 analog voltage
                                               as a reference voltage for the comparator C */
#define _08_DA_OUTREF1_ENABLE       (0x08U) /* Use the channel 0 analog voltage as
                                               a reference voltage for the comparator C */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
