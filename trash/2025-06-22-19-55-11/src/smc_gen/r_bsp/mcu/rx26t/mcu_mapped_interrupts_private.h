/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : mcu_mapped_interrupts_private.h
* Description  : This module contains macros used for mapping interrupts.
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 28.02.2023 1.00     First Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Multiple inclusion prevention macro */
#ifndef MCU_MAPPED_INTERRUPTS_PRIVATE_H
#define MCU_MAPPED_INTERRUPTS_PRIVATE_H

/* These macros are calculated values for x % 8. These macros are used when preprocessor arithmetic cannot be used.
 * For example, 'IEN0'-'IEN7' needs to be defined for a macro based on 'vector_number % 8' but preprocessor arithmetic
 * is only evaluated at compile-time when it is used in a preprocessor conditional. For this reason the calculated
 * value of 'vector_number % 8' must be calculated before compile-time.
 */
#define BSP_PRV_CALC_208_MOD_8               0
#define BSP_PRV_CALC_209_MOD_8               1
#define BSP_PRV_CALC_210_MOD_8               2
#define BSP_PRV_CALC_211_MOD_8               3
#define BSP_PRV_CALC_212_MOD_8               4
#define BSP_PRV_CALC_213_MOD_8               5
#define BSP_PRV_CALC_214_MOD_8               6
#define BSP_PRV_CALC_215_MOD_8               7
#define BSP_PRV_CALC_216_MOD_8               0
#define BSP_PRV_CALC_217_MOD_8               1
#define BSP_PRV_CALC_218_MOD_8               2
#define BSP_PRV_CALC_219_MOD_8               3
#define BSP_PRV_CALC_220_MOD_8               4
#define BSP_PRV_CALC_221_MOD_8               5
#define BSP_PRV_CALC_222_MOD_8               6
#define BSP_PRV_CALC_223_MOD_8               7
#define BSP_PRV_CALC_224_MOD_8               0
#define BSP_PRV_CALC_225_MOD_8               1
#define BSP_PRV_CALC_226_MOD_8               2
#define BSP_PRV_CALC_227_MOD_8               3
#define BSP_PRV_CALC_228_MOD_8               4
#define BSP_PRV_CALC_229_MOD_8               5
#define BSP_PRV_CALC_230_MOD_8               6
#define BSP_PRV_CALC_231_MOD_8               7
#define BSP_PRV_CALC_232_MOD_8               0
#define BSP_PRV_CALC_233_MOD_8               1
#define BSP_PRV_CALC_234_MOD_8               2
#define BSP_PRV_CALC_235_MOD_8               3
#define BSP_PRV_CALC_236_MOD_8               4
#define BSP_PRV_CALC_237_MOD_8               5
#define BSP_PRV_CALC_238_MOD_8               6
#define BSP_PRV_CALC_239_MOD_8               7
#define BSP_PRV_CALC_240_MOD_8               0
#define BSP_PRV_CALC_241_MOD_8               1
#define BSP_PRV_CALC_242_MOD_8               2
#define BSP_PRV_CALC_243_MOD_8               3
#define BSP_PRV_CALC_244_MOD_8               4
#define BSP_PRV_CALC_245_MOD_8               5
#define BSP_PRV_CALC_246_MOD_8               6
#define BSP_PRV_CALC_247_MOD_8               7
#define BSP_PRV_CALC_248_MOD_8               0
#define BSP_PRV_CALC_249_MOD_8               1
#define BSP_PRV_CALC_250_MOD_8               2
#define BSP_PRV_CALC_251_MOD_8               3
#define BSP_PRV_CALC_252_MOD_8               4
#define BSP_PRV_CALC_253_MOD_8               5
#define BSP_PRV_CALC_254_MOD_8               6
#define BSP_PRV_CALC_255_MOD_8               7

/* Interrupt A interrupts are also defined even though there is only 1 select register. */
#define BSP_PRV_INT_A_SELECT_208        ICU.SLIAR208.BYTE
#define BSP_PRV_INT_A_SELECT_209        ICU.SLIAR209.BYTE
#define BSP_PRV_INT_A_SELECT_210        ICU.SLIAR210.BYTE
#define BSP_PRV_INT_A_SELECT_211        ICU.SLIAR211.BYTE
#define BSP_PRV_INT_A_SELECT_212        ICU.SLIAR212.BYTE
#define BSP_PRV_INT_A_SELECT_213        ICU.SLIAR213.BYTE
#define BSP_PRV_INT_A_SELECT_214        ICU.SLIAR214.BYTE
#define BSP_PRV_INT_A_SELECT_215        ICU.SLIAR215.BYTE
#define BSP_PRV_INT_A_SELECT_216        ICU.SLIAR216.BYTE
#define BSP_PRV_INT_A_SELECT_217        ICU.SLIAR217.BYTE
#define BSP_PRV_INT_A_SELECT_218        ICU.SLIAR218.BYTE
#define BSP_PRV_INT_A_SELECT_219        ICU.SLIAR219.BYTE
#define BSP_PRV_INT_A_SELECT_220        ICU.SLIAR220.BYTE
#define BSP_PRV_INT_A_SELECT_221        ICU.SLIAR221.BYTE
#define BSP_PRV_INT_A_SELECT_222        ICU.SLIAR222.BYTE
#define BSP_PRV_INT_A_SELECT_223        ICU.SLIAR223.BYTE
#define BSP_PRV_INT_A_SELECT_224        ICU.SLIAR224.BYTE
#define BSP_PRV_INT_A_SELECT_225        ICU.SLIAR225.BYTE
#define BSP_PRV_INT_A_SELECT_226        ICU.SLIAR226.BYTE
#define BSP_PRV_INT_A_SELECT_227        ICU.SLIAR227.BYTE
#define BSP_PRV_INT_A_SELECT_228        ICU.SLIAR228.BYTE
#define BSP_PRV_INT_A_SELECT_229        ICU.SLIAR229.BYTE
#define BSP_PRV_INT_A_SELECT_230        ICU.SLIAR230.BYTE
#define BSP_PRV_INT_A_SELECT_231        ICU.SLIAR231.BYTE
#define BSP_PRV_INT_A_SELECT_232        ICU.SLIAR232.BYTE
#define BSP_PRV_INT_A_SELECT_233        ICU.SLIAR233.BYTE
#define BSP_PRV_INT_A_SELECT_234        ICU.SLIAR234.BYTE
#define BSP_PRV_INT_A_SELECT_235        ICU.SLIAR235.BYTE
#define BSP_PRV_INT_A_SELECT_236        ICU.SLIAR236.BYTE
#define BSP_PRV_INT_A_SELECT_237        ICU.SLIAR237.BYTE
#define BSP_PRV_INT_A_SELECT_238        ICU.SLIAR238.BYTE
#define BSP_PRV_INT_A_SELECT_239        ICU.SLIAR239.BYTE
#define BSP_PRV_INT_A_SELECT_240        ICU.SLIAR240.BYTE
#define BSP_PRV_INT_A_SELECT_241        ICU.SLIAR241.BYTE
#define BSP_PRV_INT_A_SELECT_242        ICU.SLIAR242.BYTE
#define BSP_PRV_INT_A_SELECT_243        ICU.SLIAR243.BYTE
#define BSP_PRV_INT_A_SELECT_244        ICU.SLIAR244.BYTE
#define BSP_PRV_INT_A_SELECT_245        ICU.SLIAR245.BYTE
#define BSP_PRV_INT_A_SELECT_246        ICU.SLIAR246.BYTE
#define BSP_PRV_INT_A_SELECT_247        ICU.SLIAR247.BYTE
#define BSP_PRV_INT_A_SELECT_248        ICU.SLIAR248.BYTE
#define BSP_PRV_INT_A_SELECT_249        ICU.SLIAR249.BYTE
#define BSP_PRV_INT_A_SELECT_250        ICU.SLIAR250.BYTE
#define BSP_PRV_INT_A_SELECT_251        ICU.SLIAR251.BYTE
#define BSP_PRV_INT_A_SELECT_252        ICU.SLIAR252.BYTE
#define BSP_PRV_INT_A_SELECT_253        ICU.SLIAR253.BYTE
#define BSP_PRV_INT_A_SELECT_254        ICU.SLIAR254.BYTE
#define BSP_PRV_INT_A_SELECT_255        ICU.SLIAR255.BYTE

/* Start and end of Interrupt A vectors. */
#define BSP_PRV_A_INT_VECTOR_START           (208)
#define BSP_PRV_A_INT_VECTOR_END             (255)

/* Start and end of Interrupt A select registers. */
#define BSP_PRV_SLIAR_START                  (208)
#define BSP_PRV_SLIAR_END                    (255)

/* Starting IER register for mapped interrupts. This is used for calculating the IER register based on the
 * given vector number.
 */
#define BSP_PRV_MAP_INT_IER_START            (0x1A)

/* These are used in function-like macros to expand to letters. */
#define BSP_PRV_A   A

/* Test to see if chosen vector is valid for a mapped interrupt. */
#define BSP_PRV_VALID_MAP_INT(x, y)          (((y + 0) >= BSP_PRV_ ## x ## _INT_VECTOR_START) && \
                                              ((y + 0) <= BSP_PRV_ ## x ## _INT_VECTOR_END))

/* Calculation for getting IER register. */
#define BSP_PRIV_CALC_IER_REG(x)             (((x - BSP_PRV_A_INT_VECTOR_START)/8) + BSP_PRV_MAP_INT_IER_START)

/* These macros generate the macros needed to use the function-like macros from iodefine.h */
#define BSP_PRV_IR(x, y)       _BSP_PRV_IR(x, y)
#define _BSP_PRV_IR(x, y)      IR_PERI ## x ## _INT ## x ## y
#define BSP_PRV_DTCE(x, y)     _BSP_PRV_DTCE(x, y)
#define _BSP_PRV_DTCE(x, y)    DTCE_PERI ## x ## _INT ## x ## y
#define BSP_PRV_IPR(x, y)      _BSP_PRV_IPR(x, y)
#define _BSP_PRV_IPR(x, y)     IPR_PERI ## x ## _INT ## x ## y
#define BSP_PRV_VECT(x, y)     _BSP_PRV_VECT(x, y)
#define _BSP_PRV_VECT(x, y)    VECT_PERI ## x ## _INT ## x ## y

#define BSP_PRV_IEN(x)         _BSP_PRV_IEN(x)
#define _BSP_PRV_IEN(x)        __BSP_PRV_IEN(BSP_PRV_CALC_ ## x ## _MOD_8)
#define __BSP_PRV_IEN(x)       ___BSP_PRV_IEN(x)
#define ___BSP_PRV_IEN(x)      IEN ## x

/* Chooses the correct interrupt select register. */
#define BSP_PRV_INT_SELECT(x, y)         _BSP_PRV_INT_SELECT(x, y)
#define _BSP_PRV_INT_SELECT(x, y)        BSP_PRV_INT_ ## x ## _SELECT_ ## y

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/

#endif /* MCU_MAPPED_INTERRUPTS_PRIVATE_H */

