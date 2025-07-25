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
* File Name        : r_cg_port.h
* Version          : 1.0.10
* Device(s)        : R5F526TFCxFP
* Description      : General header file for PORT peripheral.
***********************************************************************************************************************/

#ifndef PORT_H
#define PORT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Port Direction Register (PDR)
*/
/* Pmn Direction Control (B7 - B0) */
#define _00_Pm0_MODE_INPUT      (0x00U) /* Pm0 as input */
#define _01_Pm0_MODE_OUTPUT     (0x01U) /* Pm0 as output */
#define _00_Pm1_MODE_INPUT      (0x00U) /* Pm1 as input */
#define _02_Pm1_MODE_OUTPUT     (0x02U) /* Pm1 as output */
#define _00_Pm2_MODE_INPUT      (0x00U) /* Pm2 as input */
#define _04_Pm2_MODE_OUTPUT     (0x04U) /* Pm2 as output */
#define _00_Pm3_MODE_INPUT      (0x00U) /* Pm3 as input */
#define _08_Pm3_MODE_OUTPUT     (0x08U) /* Pm3 as output */
#define _00_Pm4_MODE_INPUT      (0x00U) /* Pm4 as input */
#define _10_Pm4_MODE_OUTPUT     (0x10U) /* Pm4 as output */
#define _00_Pm5_MODE_INPUT      (0x00U) /* Pm5 as input */
#define _20_Pm5_MODE_OUTPUT     (0x20U) /* Pm5 as output */
#define _00_Pm6_MODE_INPUT      (0x00U) /* Pm6 as input */
#define _40_Pm6_MODE_OUTPUT     (0x40U) /* Pm6 as output */
#define _00_Pm7_MODE_INPUT      (0x00U) /* Pm7 as input */
#define _80_Pm7_MODE_OUTPUT     (0x80U) /* Pm7 as output */

/*
    Port Output Data Register (PODR)
*/
/* Pmn Output Data Store (B7 - B0) */
#define _00_Pm0_OUTPUT_0        (0x00U) /* output low at B0 */
#define _01_Pm0_OUTPUT_1        (0x01U) /* output high at B0 */
#define _00_Pm1_OUTPUT_0        (0x00U) /* output low at B1 */
#define _02_Pm1_OUTPUT_1        (0x02U) /* output high at B1 */
#define _00_Pm2_OUTPUT_0        (0x00U) /* output low at B2 */
#define _04_Pm2_OUTPUT_1        (0x04U) /* output high at B2 */
#define _00_Pm3_OUTPUT_0        (0x00U) /* output low at B3 */
#define _08_Pm3_OUTPUT_1        (0x08U) /* output high at B3 */
#define _00_Pm4_OUTPUT_0        (0x00U) /* output low at B4 */
#define _10_Pm4_OUTPUT_1        (0x10U) /* output high at B4 */
#define _00_Pm5_OUTPUT_0        (0x00U) /* output low at B5 */
#define _20_Pm5_OUTPUT_1        (0x20U) /* output high at B5 */
#define _00_Pm6_OUTPUT_0        (0x00U) /* output low at B6 */
#define _40_Pm6_OUTPUT_1        (0x40U) /* output high at B6 */
#define _00_Pm7_OUTPUT_0        (0x00U) /* output low at B7 */
#define _80_Pm7_OUTPUT_1        (0x80U) /* output high at B7 */

/*
Port Mode Register (PMR)
*/
/* Pmn Pin Mode Control (B7 -B0) */
#define _00_Pm0_PIN_GPIO        (0x00U) /* Pm0 as general I/O pin */
#define _00_Pm1_PIN_GPIO        (0x00U) /* Pm1 as general I/O pin */
#define _00_Pm2_PIN_GPIO        (0x00U) /* Pm2 as general I/O pin */
#define _00_Pm3_PIN_GPIO        (0x00U) /* Pm3 as general I/O pin */
#define _00_Pm4_PIN_GPIO        (0x00U) /* Pm4 as general I/O pin */
#define _00_Pm5_PIN_GPIO        (0x00U) /* Pm5 as general I/O pin */
#define _00_Pm6_PIN_GPIO        (0x00U) /* Pm6 as general I/O pin */
#define _00_Pm7_PIN_GPIO        (0x00U) /* Pm7 as general I/O pin */

/*
    Open Drain Control Register 0 (ODR0)
*/
/* Pmn Output Type Select (Pm0 to Pm3) */
#define _00_Pm0_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _01_Pm0_NCH_OPEN_DRAIN  (0x01U) /* N-channel open-drain output */
#define _00_Pm1_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _04_Pm1_NCH_OPEN_DRAIN  (0x04U) /* N-channel open-drain output */
#define _00_Pm2_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _10_Pm2_NCH_OPEN_DRAIN  (0x10U) /* N-channel open-drain output */
#define _00_Pm3_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _40_Pm3_NCH_OPEN_DRAIN  (0x40U) /* N-channel open-drain output */

/*
    Open Drain Control Register 1 (ODR1)
*/
/* Pmn Output Type Select (Pm4 to Pm7) */
#define _00_Pm4_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _01_Pm4_NCH_OPEN_DRAIN  (0x01U) /* N-channel open-drain output */
#define _00_Pm5_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _04_Pm5_NCH_OPEN_DRAIN  (0x04U) /* N-channel open-drain output */
#define _00_Pm6_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _10_Pm6_NCH_OPEN_DRAIN  (0x10U) /* N-channel open-drain output */
#define _00_Pm7_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _40_Pm7_NCH_OPEN_DRAIN  (0x40U) /* N-channel open-drain output */

/*
    Pull-Up Control Register (PCR)
*/
/* Pmn Input Pull-Up Resistor Control (B7 - B0) */
#define _00_Pm0_PULLUP_OFF      (0x00U) /* Pm0 pull-up resistor not connected */
#define _01_Pm0_PULLUP_ON       (0x01U) /* Pm0 pull-up resistor connected */
#define _00_Pm1_PULLUP_OFF      (0x00U) /* Pm1 pull-up resistor not connected */
#define _02_Pm1_PULLUP_ON       (0x02U) /* Pm1 pull-up resistor connected */
#define _00_Pm2_PULLUP_OFF      (0x00U) /* Pm2 Pull-up resistor not connected */
#define _04_Pm2_PULLUP_ON       (0x04U) /* Pm2 pull-up resistor connected */
#define _00_Pm3_PULLUP_OFF      (0x00U) /* Pm3 pull-up resistor not connected */
#define _08_Pm3_PULLUP_ON       (0x08U) /* Pm3 pull-up resistor connected */
#define _00_Pm4_PULLUP_OFF      (0x00U) /* Pm4 pull-up resistor not connected */
#define _10_Pm4_PULLUP_ON       (0x10U) /* Pm4 pull-up resistor connected */
#define _00_Pm5_PULLUP_OFF      (0x00U) /* Pm5 pull-up resistor not connected */
#define _20_Pm5_PULLUP_ON       (0x20U) /* Pm5 pull-up resistor connected */
#define _00_Pm6_PULLUP_OFF      (0x00U) /* Pm6 pull-up resistor not connected */
#define _40_Pm6_PULLUP_ON       (0x40U) /* Pm6 pull-up resistor connected */
#define _00_Pm7_PULLUP_OFF      (0x00U) /* Pm7 pull-up resistor not connected */
#define _80_Pm7_PULLUP_ON       (0x80U) /* Pm7 pull-up resistor connected */

/*
Drive Capacity Control Register (DSCR)
*/
/* Pmn Drive Capacity Control (B7 - B0) */
#define _00_Pm0_HIDRV_OFF       (0x00U) /* Pm0 Normal drive output */
#define _01_Pm0_HIDRV_ON        (0x01U) /* Pm0 High-drive output */
#define _00_Pm1_HIDRV_OFF       (0x00U) /* Pm1 Normal drive output */
#define _02_Pm1_HIDRV_ON        (0x02U) /* Pm1 High-drive output */
#define _00_Pm2_HIDRV_OFF       (0x00U) /* Pm2 Normal drive output */
#define _04_Pm2_HIDRV_ON        (0x04U) /* Pm2 High-drive output */
#define _00_Pm3_HIDRV_OFF       (0x00U) /* Pm3 Normal drive output */
#define _08_Pm3_HIDRV_ON        (0x08U) /* Pm3 High-drive output */
#define _00_Pm4_HIDRV_OFF       (0x00U) /* Pm4 Normal drive output */
#define _10_Pm4_HIDRV_ON        (0x10U) /* Pm4 High-drive output */
#define _00_Pm5_HIDRV_OFF       (0x00U) /* Pm5 Normal drive output */
#define _20_Pm5_HIDRV_ON        (0x20U) /* Pm5 High-drive output */
#define _00_Pm6_HIDRV_OFF       (0x00U) /* Pm6 Normal drive output */
#define _40_Pm6_HIDRV_ON        (0x40U) /* Pm6 High-drive output */
#define _00_Pm7_HIDRV_OFF       (0x00U) /* Pm7 Normal drive output */
#define _80_Pm7_HIDRV_ON        (0x80U) /* Pm7 High-drive output */

/*
     Drive Capacity Control Register 2 (DSCR2)
*/
/* Pmn Drive Capacity Control 2 (B7 - B0) */
#define _00_Pm0_LARGECUR_OFF    (0x00U) /* Pm0 Normal drive/high-drive output */
#define _01_Pm0_LARGECUR_ON     (0x01U) /* Pm0 Large current output */
#define _00_Pm1_LARGECUR_OFF    (0x00U) /* Pm1 Normal drive/high-drive output */
#define _02_Pm1_LARGECUR_ON     (0x02U) /* Pm1 Large current output */
#define _00_Pm2_LARGECUR_OFF    (0x00U) /* Pm2 Normal drive/high-drive output */
#define _04_Pm2_LARGECUR_ON     (0x04U) /* Pm2 Large current output */
#define _00_Pm3_LARGECUR_OFF    (0x00U) /* Pm3 Normal drive/high-drive output */
#define _08_Pm3_LARGECUR_ON     (0x08U) /* Pm3 Large current output */
#define _00_Pm4_LARGECUR_OFF    (0x00U) /* Pm4 Normal drive/high-drive output */
#define _10_Pm4_LARGECUR_ON     (0x10U) /* Pm4 Large current output */
#define _00_Pm5_LARGECUR_OFF    (0x00U) /* Pm5 Normal drive/high-drive output */
#define _20_Pm5_LARGECUR_ON     (0x20U) /* Pm5 Large current output */
#define _00_Pm6_LARGECUR_OFF    (0x00U) /* Pm6 Normal drive/high-drive output */
#define _40_Pm6_LARGECUR_ON     (0x40U) /* Pm6 Large current output */
#define _00_Pm7_LARGECUR_OFF    (0x00U) /* Pm7 Normal drive/high-drive output */
#define _80_Pm7_LARGECUR_ON     (0x80U) /* Pm7 Large current output */

/*
    Port Output Retention Setting Register 1 (POHSR1)
*/
/* Port n Output Retention Control (PnHLD) */
#define _0001_P0HLD_RETAINED    (0x0001U) /* Port 0 output retained */
#define _0002_P1HLD_RETAINED    (0x0002U) /* Port 1 output retained */
#define _0004_P2HLD_RETAINED    (0x0004U) /* Port 2 output retained */
#define _0008_P3HLD_RETAINED    (0x0008U) /* Port 3 output retained */
#define _0010_P4HLD_RETAINED    (0x0010U) /* Port 4 output retained */
#define _0020_P5HLD_RETAINED    (0x0020U) /* Port 5 output retained */
#define _0040_P6HLD_RETAINED    (0x0040U) /* Port 6 output retained */
#define _0080_P7HLD_RETAINED    (0x0080U) /* Port 7 output retained */
#define _0100_P8HLD_RETAINED    (0x0100U) /* Port 8 output retained */
#define _0200_P9HLD_RETAINED    (0x0200U) /* Port 9 output retained */
#define _0400_PAHLD_RETAINED    (0x0400U) /* Port A output retained */
#define _0800_PBHLD_RETAINED    (0x0800U) /* Port B output retained */
#define _2000_PDHLD_RETAINED    (0x2000U) /* Port D output retained */
#define _4000_PEHLD_RETAINED    (0x4000U) /* Port E output retained */

/*
    Port Output Retention Setting Register 2 (POHSR2)
*/
/* Port N Output Retention Control (PNHLD) */
#define _0080_PNHLD_RETAINED    (0x0080U) /* Port N output retained */

/*
    General-purpose Input/Output Pin Select Extension Register (GPSEXT)
*/
/* EMLE Pin Function Select (GPSEMLE) */
#define _01_EMLE_PIN_UNUSE      (0x01U) /* A function other than EMLE is selected */
/* MD Pin Function Select (GPSMD) */
#define _02_FINED_PIN_UNUSE     (0x02U) /* The MD/FINED function is not selected */

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
