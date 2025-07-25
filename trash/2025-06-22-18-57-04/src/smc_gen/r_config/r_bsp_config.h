/* Generated configuration header file - do not edit */
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
* File Name    : r_bsp_config_reference.h
* Device(s)    : RX26T
* Description  : The file r_bsp_config.h is used to configure your BSP. r_bsp_config.h should be included
*                somewhere in your package so that the r_bsp code has access to it. This file (r_bsp_config_reference.h)
*                is just a reference file that the user can use to make their own r_bsp_config.h file.
************************************************************************************************************************
* History : DD.MM.YYYY Version   Description
*         : 28.02.2023 1.00      First Release
*         : 26.04.2023 1.01      Modified comment.
***********************************************************************************************************************/
#ifndef R_BSP_CONFIG_REF_HEADER_FILE
#define R_BSP_CONFIG_REF_HEADER_FILE

/***********************************************************************************************************************
Configuration Options
***********************************************************************************************************************/

/* NOTE:
   The default settings are the same as when using MCK-RX26T.
   Change to the settings for the user board.
*/

/* Start up select
   0 = Enable BSP startup program.
   1 = Disable BSP startup program. (e.g. Using user startup program.)
   NOTE: This setting is available only when using CCRX. */
#define BSP_CFG_STARTUP_DISABLE (0)

/* Enter the product part number for your MCU. This information will be used to obtain information about your MCU such 
   as package and memory size.
   To help parse this information, the part number will be defined using multiple macros.
   R 5 F 52 6T E A D FP
   | | | |  |  | | | |  Macro Name                             Description
   | | | |  |  | | | |__BSP_CFG_MCU_PART_PACKAGE             = Package type, number of pins, and pin pitch
   | | | |  |  | | |____not used                             = Products with wide temperature range
   | | | |  |  | |______BSP_CFG_MCU_PART_FUNCTION            = PGA differential input,
   | | | |  |  |                                               Encryption module and USB module included/not included
   | | | |  |  |________BSP_CFG_MCU_PART_MEMORY_SIZE         = ROM, RAM, and Data Flash Capacity
   | | | |  |___________BSP_CFG_MCU_PART_GROUP               = Group name
   | | | |______________BSP_CFG_MCU_PART_SERIES              = Series name
   | | |________________BSP_CFG_MCU_PART_MEMORY_TYPE         = Type of memory (Flash, ROMless)
   | |__________________not used                             = Renesas MCU
   |____________________not used                             = Renesas semiconductor product.
*/

/* Package type. Set the macro definition based on values below:
   Character(s) = Value for macro = Package Type/Number of Pins/Pin Pitch
   FP           = 0x0             = LFQFP/100/0.50
   FN           = 0x1             = LFQFP/80/0.50
   FM           = 0x8             = LFQFP/64/0.50
   FL           = 0x6             = LFQFP/48/0.50
   ND           = 0x5             = HWQFN/64/0.50
   NE           = 0x7             = HWQFN/48/0.50
*/
#define BSP_CFG_MCU_PART_PACKAGE        (0x0) /* Generated value. Do not edit this manually */

/* Whether PGA differential input, Encryption and USB are included or not.
   Character(s) = Value for macro = Description
   A            = 0xA             = Only CAN 2.0 protocol supported, without TSIP-Lite
   B            = 0xB             = Only CAN 2.0 protocol supported, with TSIP-Lite
   C            = 0xC             = CAN FD protocol supported, without TSIP-Lite
   D            = 0xD             = CAN FD protocol supported, with TSIP-Lite
*/
#define BSP_CFG_MCU_PART_FUNCTION   (0xC) /* Generated value. Do not edit this manually */

/* ROM, RAM, and Data Flash Capacity.
   Character(s) = Value for macro = ROM Size/Ram Size/Data Flash Size
   F            = 0xF             = 512KB/64KB/16KB
   B            = 0xB             = 256KB/64KB/16KB
   A            = 0xA             = 256KB/48KB/16KB
   9            = 0x9             = 128KB/64KB/16KB
   8            = 0x8             = 128KB/48KB/16KB
*/
#define BSP_CFG_MCU_PART_MEMORY_SIZE    (0xF) /* Generated value. Do not edit this manually */

/* Group name.
   Character(s) = Description
   6T           = RX26T Group
*/
#define BSP_CFG_MCU_PART_GROUP          "RX26T" /* Generated value. Do not edit this manually */

/* Series name.
   Character(s) = Description
   52           = RX200 Series
*/
#define BSP_CFG_MCU_PART_SERIES         "RX200" /* Generated value. Do not edit this manually */

/* Memory type.
   Character(s) = Value for macro = Description
   F            = 0x0             = Flash memory version
*/
#define BSP_CFG_MCU_PART_MEMORY_TYPE    (0x0) /* Generated value. Do not edit this manually */

/* Whether to use 1 stack or 2. RX MCUs have the ability to use 2 stacks: an interrupt stack and a user stack.
 * When using 2 stacks the user stack will be used during normal user code. When an interrupt occurs the CPU
 * will automatically shift to using the interrupt stack. Having 2 stacks can make it easier to figure out how
 * much stack space to allocate since the user does not have to worry about always having enough room on the
 * user stack for if-and-when an interrupt occurs. Some users will not want 2 stacks though because it is not
 * needed in all applications and can lead to wasted RAM (i.e. space in between stacks that is not used).
 * If only 1 stack is used then the interrupt stack is the one that will be used. If 1 stack is chosen then
 * the user may want to remove the 'SU' section from the linker sections to remove any linker warnings.
 *
 * 0 = Use 1 stack. Disable user stack. User stack size set below will be ignored.
 * 1 = Use 2 stacks. User stack and interrupt stack will both be used.
 * NOTE: This setting is available only when using CCRX and GNUC.
 *       This is invalid when using Renesas RTOS with CCRX.
 */
#define BSP_CFG_USER_STACK_ENABLE       (1)

/* If only 1 stack is chosen using BSP_CFG_USER_STACK_ENABLE then no RAM will be allocated for the user stack. */
#if BSP_CFG_USER_STACK_ENABLE == 1
/* User Stack size in bytes.
 * NOTE: This setting is available only when using CCRX and GNUC.
 *       This is invalid when using Renesas RTOS with CCRX. */
#define BSP_CFG_USTACK_BYTES            (0x1000)
#endif

/* Interrupt Stack size in bytes.
   NOTE: This setting is available only when using CCRX and GNUC. */
#define BSP_CFG_ISTACK_BYTES            (0x400)

/* Heap size in bytes.
   To disable the heap you must follow these steps:
   1) Set this macro (BSP_CFG_HEAP_BYTES) to 0.
   2) Set the macro BSP_CFG_IO_LIB_ENABLE to 0.
   3) Disable stdio from being built into the project library. This is done by going into the Renesas RX Toolchain 
      settings and choosing the Standard Library section. After that choose 'Contents' in e2 studio.
      This will present a list of modules that can be included. Uncheck the box for stdio.h.
   NOTE: This setting is available only when using CCRX and GNUC. */
#define BSP_CFG_HEAP_BYTES              (0x400)

/* Initializes C input & output library functions.
   0 = Disable I/O library initialization in resetprg.c. If you are not using stdio then use this value.
   1 = Enable I/O library initialization in resetprg.c. This is default and needed if you are using stdio.
   NOTE: This setting is available only when using CCRX. */
#define BSP_CFG_IO_LIB_ENABLE           (1)

/* If desired the user may redirect the stdio charget() and/or charput() functions to their own respective functions
   by enabling below and providing and replacing the my_sw_... function names with the names of their own functions. */
#define BSP_CFG_USER_CHARGET_ENABLED    (0)
#define BSP_CFG_USER_CHARGET_FUNCTION     my_sw_charget_function

#define BSP_CFG_USER_CHARPUT_ENABLED    (0)
#define BSP_CFG_USER_CHARPUT_FUNCTION     my_sw_charput_function

/* After reset MCU will operate in Supervisor mode. To switch to User mode, set this macro to '1'. For more information
   on the differences between these 2 modes see the CPU >> Processor Mode section of your MCU's hardware manual.
   0 = Stay in Supervisor mode.
   1 = Switch to User mode.
   NOTE: This is invalid when using Renesas RTOS with CCRX.
*/
#define BSP_CFG_RUN_IN_USER_MODE        (0)

/* Set your desired ID code. NOTE, leave at the default (all 0xFF's) if you do not wish to use an ID code. If you set 
   this value and program it into the MCU then you will need to remember the ID code because the debugger will ask for 
   it when trying to connect. Note that the E1/E20 will ignore the ID code when programming the MCU during debugging.
   If you set this value and then forget it then you can clear the ID code by connecting up in serial boot mode using 
   FDT. The ID Code is 16 bytes long. The macro below define the ID Code in 4-byte sections. */
/* Lowest 4-byte section, address 0x00120050. From MSB to LSB: ID code 4, ID code 3, ID code 2, ID code 1/Control Code.
 */
#define BSP_CFG_ID_CODE_LONG_1          (0xFFFFFFFF)
/* 2nd ID Code section, address 0x00120054. From MSB to LSB: ID code 8, ID code 7, ID code 6, ID code 5. */
#define BSP_CFG_ID_CODE_LONG_2          (0xFFFFFFFF)
/* 3rd ID Code section, address 0x00120058. From MSB to LSB: ID code 12, ID code 11, ID code 10, ID code 9. */
#define BSP_CFG_ID_CODE_LONG_3          (0xFFFFFFFF)
/* 4th ID Code section, address 0x0012005C. From MSB to LSB: ID code 16, ID code 15, ID code 14, ID code 13. */
#define BSP_CFG_ID_CODE_LONG_4          (0xFFFFFFFF)

/* Select ID code protection.
   0 = ID code protection is disabled.
   1 = ID code protection is enabled.
*/
#define BSP_CFG_ID_CODE_ENABLE          (0)

/* Select whether to enables or disables the protection of block erasure commands.
   0 = Execution of block erasure commands is permitted after a reset. (default)
   1 = Execution of block erasure commands is prohibited after a reset.
   NOTE: This is invalid when ID code protection(BSP_CFG_ID_CODE_ENABLE) is enabled.
 */
#define BSP_CFG_BLOCK_ERASE_CMD_PROTECT_ENABLE (0)

/* Select whether to enables or disables the protection of programming commands.
   0 = Execution of programming commands is permitted after a reset. (default)
   1 = Execution of programming commands is prohibited after a reset.
   NOTE: This is invalid when ID code protection(BSP_CFG_ID_CODE_ENABLE) is enabled.
 */
#define BSP_CFG_PROGRAM_CMD_PROTECT_ENABLE     (0)

/* Select whether to enables or disables the protection of read commands.
   0 = Execution of read commands is permitted after a reset. (default)
   1 = Execution of read commands is prohibited after a reset.
   NOTE: This is invalid when ID code protection(BSP_CFG_ID_CODE_ENABLE) is enabled.
 */
#define BSP_CFG_READ_CMD_PROTECT_ENABLE        (0)

/* Select whether to enables or disables the connection of serial programmer.
   0 = Connection of a serial programmer is prohibited after a reset.
   1 = Connection of a serial programmer is permitted after a reset. (default)
*/
#define BSP_CFG_SERIAL_PROGRAMMER_CONECT_ENABLE   (1)

/* Select whether to oscillate the Main Clock Oscillator.
   0 = Stop Oscillating the Main Clock.
   1 = Enable oscillating the Main Clock. (default)
*/
#define BSP_CFG_MAIN_CLOCK_OSCILLATE_ENABLE    (0) /* Generated value. Do not edit this manually */

/* Select whether to oscillate the High Speed On-Chip Oscillator (HOCO).
   0 = Stop Oscillating the HOCO. (default)
   1 = Enable Oscillating the HOCO.
*/
#define BSP_CFG_HOCO_OSCILLATE_ENABLE          (1) /* Generated value. Do not edit this manually */

/* Select whether to oscillate the Low Speed On-Chip Oscillator (LOCO).
   0 = Stop Oscillating the LOCO. (default)
   1 = Enable Oscillating the LOCO.
*/
#define BSP_CFG_LOCO_OSCILLATE_ENABLE          (0) /* Generated value. Do not edit this manually */

/* Select whether to oscillate the IWDT-Dedicated On-Chip Oscillator (IWDT).
   0 = Stop Oscillating the IWDT Clock. (default)
   1 = Enable Oscillating the IWDT Clock.
*/
#define BSP_CFG_IWDT_CLOCK_OSCILLATE_ENABLE    (0) /* Generated value. Do not edit this manually */

/* Clock source select (CKSEL).
   0 = Low Speed On-Chip Oscillator  (LOCO)
   1 = High Speed On-Chip Oscillator (HOCO)
   2 = Main Clock Oscillator
   3 = Sub-Clock Oscillator                   (N/A for RX26T)
   4 = PLL Circuit
*/
#define BSP_CFG_CLOCK_SOURCE            (4) /* Generated value. Do not edit this manually */

/* Main clock Oscillator Switching (MOSEL).
   0 = Resonator
   1 = External clock input
*/
#define BSP_CFG_MAIN_CLOCK_SOURCE       (0) /* Generated value. Do not edit this manually */

/* Clock configuration options.
   The input clock frequency is specified and then the system clocks are set by specifying the multipliers used. The
   multiplier settings are used to set the clock registers in resetprg.c. If a 24MHz clock is used and the
   ICLK is 120MHz, PCLKA is 120MHz, PCLKB is 60MHz, PCLKC is 120MHz, PCLKD is 60MHz, FCLK is 60MHz, CANFD Clock is 60MHz,
   and then the settings would be:

   BSP_CFG_XTAL_HZ  = 10000000
   BSP_CFG_PLL_DIV  = 1        (no division)
   BSP_CFG_PLL_MUL  = 24.0     (10MHz x 24.0 = 240MHz)
   BSP_CFG_ICK_DIV  = 2      : System Clock (ICLK)        = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_ICK_DIV)   = 120MHz
   BSP_CFG_PCKA_DIV = 2      : Peripheral Clock A (PCLKA) = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_PCKA_DIV)  = 120MHz
   BSP_CFG_PCKB_DIV = 4      : Peripheral Clock B (PCLKB) = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_PCKB_DIV)  = 60MHz
   BSP_CFG_PCKC_DIV = 2      : Peripheral Clock C (PCLKC) = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_PCKC_DIV)  = 120MHz
   BSP_CFG_PCKD_DIV = 4      : Peripheral Clock D (PCLKD) = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_PCKD_DIV)  = 60MHz
   BSP_CFG_FCK_DIV  = 4      : Flash IF Clock (FCLK)      = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_FCK_DIV)   = 60MHz
   BSP_CFG_CFDCK_DIV = 4     : CANFD Clock (CANFDCLK)     = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_CFDCK_DIV) = 60MHz
*/

/* Input clock frequency in Hz (XTAL or EXTAL). */
#define BSP_CFG_XTAL_HZ                 (10000000) /* Generated value. Do not edit this manually */

/* The HOCO can operate at several different frequencies. Choose which one using the macro below.
   Available frequency settings:
   0 = 16MHz (default)
   1 = 18MHz
   2 = 20MHz
*/
#define BSP_CFG_HOCO_FREQUENCY          (0) /* Generated value. Do not edit this manually */

/* PLL clock source (PLLSRCSEL). Choose which clock source to input to the PLL circuit.
   Available clock sources:
   0 = Main clock (default)
   1 = HOCO
*/
#define BSP_CFG_PLL_SRC                 (1) /* Generated value. Do not edit this manually */

/* PLL Input Frequency Division Ratio Select (PLIDIV).
   Available divisors = /1 (no division), /2, /3
*/
#define BSP_CFG_PLL_DIV                 (1) /* Generated value. Do not edit this manually */

/* PLL Frequency Multiplication Factor Select (STC).
   Available multipliers = x10.0 to x30.0 in 0.5 increments (e.g. 10.0, 10.5, 11.0, 11.5, ..., 29.0, 29.5, 30.0)
*/
#define BSP_CFG_PLL_MUL                 (15.0) /* Generated value. Do not edit this manually */

/* System Clock Divider (ICK).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_ICK_DIV                 (2) /* Generated value. Do not edit this manually */

/* Peripheral Module Clock A Divider (PCKA).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_PCKA_DIV                (2) /* Generated value. Do not edit this manually */

/* Peripheral Module Clock B Divider (PCKB).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_PCKB_DIV                (4) /* Generated value. Do not edit this manually */

/* Peripheral Module Clock C Divider (PCKC).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_PCKC_DIV                (2) /* Generated value. Do not edit this manually */

/* Peripheral Module Clock D Divider (PCKD).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_PCKD_DIV                (4) /* Generated value. Do not edit this manually */

/* Flash IF Clock Divider (FCK).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_FCK_DIV                 (4) /* Generated value. Do not edit this manually */

/* CANFD Clock Divider Select (CANFDCLK).
   Available divisors = /2, /4, /8
*/
#define BSP_CFG_CFDCK_DIV               (4) /* Generated value. Do not edit this manually */

/* Main Clock Oscillator Wait Time (MOSCWTCR).
   The value of MOSCWTCR register required for correspondence with the waiting time required to secure stable 
   oscillation by the main clock oscillator is obtained by using the maximum frequency for fLOCO in the formula below.

   BSP_CFG_MOSC_WAIT_TIME > (tMAINOSC * (fLOCO_max) + 16)/32
   (tMAINOSC: main clock oscillation stabilization time; fLOCO_max: maximum frequency for fLOCO)

   If tMAINOSC is 9.98 ms and fLOCO_max is 264 kHz (the period is 1/3.78 us), the formula gives 
   BSP_CFG_MOSC_WAIT_TIME > (9.98 ms * (264 kHZ) + 16)/32 = 82.83, so set the BSP_CFG_MOSC_WAIT_TIME to 83(53h).

   NOTE: The waiting time is not required when an external clock signal is input for the main clock oscillator.
         Set the BSP_CFG_MOSC_WAIT_TIME to 00h.
*/
#define BSP_CFG_MOSC_WAIT_TIME          (0x53) /* Generated value. Do not edit this manually */

/* Configure WDT and IWDT settings.
   OFS0 - Option Function Select Register 0
       b31:b29 Reserved When reading, these bits return the value written by the user. The write value should be 1.
       b28     WDTRSTIRQS - WDT Reset Interrupt Request - What to do on underflow (0=take interrupt, 1=reset MCU)
       b27:b26 WDTRPSS   - WDT Window Start Position Select - (0=25%, 1=50%, 2=75%, 3=100%,don't use)
       b25:b24 WDTRPES   - WDT Window End Position Select - (0=75%, 1=50%, 2=25%, 3=0%,don't use)
       b23:b20 WDTCKS    - WDT Clock Frequency Division Ratio - (1=PCLKB/4, 4=PCLKB/64, 0xF=PCLKB/128, 6=PCLKB/256,
                                                                 7=PCLKB/2048, 8=PCLKB/8192)
       b19:b18 WDTTOPS   - WDT Timeout Period Select (0=1024 cycles, 1=4096, 2=8192, 3=16384)
       b17     WDTSTRT   - WDT Start Mode Select - (0=auto-start after reset, 1=halt after reset)
       b16:b15 Reserved (set to 1)
       b14     IWDTSLCSTP - IWDT Sleep Mode Count Stop Control - (0=can't stop count, 1=stop w/some low power modes)
       b13     Reserved (set to 1)
       b12     IWDTRSTIRQS - IWDT Reset Interrupt Request - What to do on underflow (0=take interrupt, 1=reset MCU)
       b11:b10 IWDTRPSS - IWDT Window Start Position Select - (0=25%, 1=50%, 2=75%, 3=100%,don't use)
       b9:b8   IWDTRPES - IWDT Window End Position Select - (0=75%, 1=50%, 2=25%, 3=0%,don't use)
       b7:b4   IWDTCKS - IWDT Clock Frequency Division Ratio - (0=none, 2=/16, 3 = /32, 4=/64, 0xF=/128, 5=/256)
       b3:b2   IWDTTOPS - IWDT Timeout Period Select - (0=1024 cycles, 1=4096, 2=8192, 3=16384)
       b1      IWDTSTRT - IWDT Start Mode Select - (0=auto-start after reset, 1=halt after reset)
       b0      Reserved (set to 1)
   Default value is 0xFFFFFFFF.
*/
#define BSP_CFG_OFS0_REG_VALUE  (0xFFFFFFFF) /* Generated value. Do not edit this manually */

/* Configure whether voltage detection 0 circuit and HOCO are enabled after reset.
   OFS1 - Option Function Select Register 1
       b31:b9 Reserved (set to 1)
       b8     HOCOEN - Enable/disable HOCO oscillation after a reset (0=enable, 1=disable)
       b7:b3  Reserved When reading, these bits return the value written by the user. The write value should be 1.
       b2     LVDAS - Voltage Detection 0 circuit start (1=monitoring disabled)
       b1:b0  VDSEL - Voltage Detection 0 level select (2=2.83V, 3=4.22V)
       NOTE: If HOCO oscillation is enabled by OFS1.HOCOEN, HOCO frequency is 16MHz.
             BSP_CFG_HOCO_FREQUENCY should be default value.
   Default value is 0xFFFFFFFF.
*/
#define BSP_CFG_OFS1_REG_VALUE  (0xFFFFFFFF) /* Generated value. Do not edit this manually */

/* Trusted memory is facility to prevent the reading of blocks 8 and 9 and blocks 30 and 31 (in dual mode) in 
   the code flash memory by third party software. This feature is disabled by default.
   TMEF - TM Enable Flag Register
       b31     Reserved (set to 1)
       b30:b28 TMEFDB - Dual-Bank TM Enable - 000: The TM function in the address range from FFEE 0000h to 
                                                   FFEE FFFFh is enabled in dual mode.
                                            - 111: The TM function in the address range from FFEE 0000h to 
                                                   FFEE FFFFh is disabled in dual mode.
       b27     Reserved (set to 1)
       b26:b24 TMEF   - TM Enable - 000: TM function is enabled.
                                  - 111: TM function is disabled.
       b23:b0  Reserved (set to 1)
       NOTE: If the dual bank function has not been incorporated in a device,
             TMEFDB bits [b30:b28] are reserved area.
   Default value is 0xFFFFFFFF.
*/
#define BSP_CFG_TRUSTED_MODE_FUNCTION  (0xFFFFFFFF)

/* Configure FAW register is used to set the write protection flag and boot area select flag 
   for setting the flash access window startaddress and flash access window end address.
   FAW - Flash Access Window Setting Register
       b31      BTFLG - Boot Area Select Flag - 0: FFFF 8000h to FFFF BFFFh are used as the boot area
                                              - 1: FFFF C000h to FFFF FFFFh are used as the boot area
       b30:b28  Reserved - When reading, these bits return the value written by the user.The write value should be 1.
       b27:b16  FAWE - Flash Access Window End Address - Flash access window end address
       b15      FSPR - Access Window Protection Flag - 0: With protection (P/E disabled)
                                                     - 1: Without protection (P/E enabled)
       b14:b12  Reserved - When reading, these bits return the value written by the user.The write value should be 1.
       b11:b0   FAWS - Flash Access Window Start Address - Flash access window start address 
       NOTE: Once 0 is written to this bit, the bit can never be restored to 1.
             Therefore, the access window and the BTFLG bit never be set again or the TM function 
             never be disabled once it has been enabled.
             Exercise extra caution when handling the FSPR bit.
   Default value is 0xFFFFFFFF.
*/
#define BSP_CFG_FAW_REG_VALUE  (0xFFFFFFFF)

/* The ROM code protection register is a function to prohibit reading from or programming to the flash memory
   when the flash programmer is used during off-board programming.
   ROMCODE - ROM Code Protection Register
       b31:b0  ROM Code - 0000 0000h: ROM code protection enabled (ROM code protection 1).
                          0000 0001h: ROM code protection enabled (ROM code protection 2).
                          Other than above: ROM code protection disabled.
       Note: The ROMCODE register should be set in 32-bit units.
   Default value is 0xFFFFFFFF.
*/
#define BSP_CFG_ROMCODE_REG_VALUE  (0xFFFFFFFF)

/* Select the bank mode of dual-bank function of the code flash memory.
   0 = Dual mode.
   1 = Linear mode. (default)
   NOTE: If the dual bank function has been incorporated in a device, select the bank mode in this macro.
         Default setting of the bank mode is linear mode.
         If the dual bank function has not been incorporated in a device, this macro should be 1.
*/
#define BSP_CFG_CODE_FLASH_BANK_MODE    (1)

/* Select the startup bank of the program when dual bank function is in dual mode.
   0 = The address range of bank 1 from FFF80000h to FFFBFFFFh and bank 0 from FFFC0000h to FFFFFFFFh. (default)
   1 = The address range of bank 1 from FFFC0000h to FFFFFFFFh and bank 0 from FFF80000h to FFFBFFFFh.
   NOTE: If the dual bank function has been incorporated in a device, select the start bank in this macro.
         Default setting of the start bank is bank0.
         If the dual bank function has not been incorporated in a device, this macro should be 0.
*/
#define BSP_CFG_CODE_FLASH_START_BANK   (0)

/* This macro lets other modules no if a RTOS is being used.
   0 = RTOS is not used.
   1 = FreeRTOS is used.
   2 = embOS is used.(This is not available.)
   3 = MicroC_OS is used.(This is not available.)
   4 = Renesas ITRON OS (RI600V4 or RI600PX) is used.
   5 = Azure RTOS is used.
*/
#define BSP_CFG_RTOS_USED               (0)

/* This macro is used to select which Renesas ITRON OS.
   0 = RI600V4 is used.
   1 = RI600PX is used.
*/
#define BSP_CFG_RENESAS_RTOS_USED       (0)

/* This macro is used to select which CMT channel used for system timer of RTOS.
 * The setting of this macro is only valid if the macro BSP_CFG_RTOS_USED is set to a value other than 0. */
#if BSP_CFG_RTOS_USED != 0
/* Setting value.
 * 0      = CMT channel 0 used for system timer of RTOS (recommended to be used for RTOS).
 * 1      = CMT channel 1 used for system timer of RTOS.
 * 2      = CMT channel 2 used for system timer of RTOS.
 * 3      = CMT channel 3 used for system timer of RTOS.
 * Others = Invalid.
 * NOTE: This is invalid when using Renesas RTOS with CCRX.
 */
#define BSP_CFG_RTOS_SYSTEM_TIMER       (0)
#endif

/* By default modules will use global locks found in mcu_locks.c. If the user is using a RTOS and would rather use its
   locking mechanisms then they can change this macro.
   NOTE: If '1' is chosen for this macro then the user must also change the next macro 'BSP_CFG_USER_LOCKING_TYPE'.
   0 = Use default locking (non-RTOS)
   1 = Use user defined locking mechanism.
*/
#define BSP_CFG_USER_LOCKING_ENABLED    (0)

/* If the user decides to use their own locking mechanism with FIT modules then they will need to redefine the typedef
   that is used for the locks. If the user is using a RTOS then they would likely redefine the typedef to be 
   a semaphore/mutex type of their RTOS. Use the macro below to set the type that will be used for the locks.
   NOTE: If BSP_CFG_USER_LOCKING_ENABLED == 0 then this typedef is ignored.
   NOTE: Do not surround the type with parentheses '(' ')'.
*/
#define BSP_CFG_USER_LOCKING_TYPE       bsp_lock_t

/* If the user decides to use their own locking mechanism with FIT modules then they will need to define the functions
   that will handle the locking and unlocking. These functions should be defined below.
   If BSP_CFG_USER_LOCKING_ENABLED is != 0:
   R_BSP_HardwareLock(mcu_lock_t hw_index) will call BSP_CFG_USER_LOCKING_HW_LOCK_FUNCTION(mcu_lock_t hw_index)
   R_BSP_HardwareUnlock(mcu_lock_t hw_index) will call BSP_CFG_USER_LOCKING_HW_UNLOCK_FUNCTION(mcu_lock_t hw_index)
       NOTE:With these functions the index into the array holding the global hardware locks is passed as the parameter.
   R_BSP_SoftwareLock(BSP_CFG_USER_LOCKING_TYPE * plock) will call 
   BSP_CFG_USER_LOCKING_SW_LOCK_FUNCTION(BSP_CFG_USER_LOCKING_TYPE * plock)
   R_BSP_SoftwareUnlock(BSP_CFG_USER_LOCKING_TYPE * plock) will call 
   BSP_CFG_USER_LOCKING_SW_UNLOCK_FUNCTION(BSP_CFG_USER_LOCKING_TYPE * plock)
       NOTE:With these functions the actual address of the lock to use is passed as the parameter.
   NOTE: These functions must return a boolean. If lock was obtained or released successfully then return true. Else, 
         return false.
   NOTE: If BSP_CFG_USER_LOCKING_ENABLED == 0 then this typedef is ignored.
   NOTE: Do not surround the type with parentheses '(' ')'.
*/
#define BSP_CFG_USER_LOCKING_HW_LOCK_FUNCTION      my_hw_locking_function
#define BSP_CFG_USER_LOCKING_HW_UNLOCK_FUNCTION    my_hw_unlocking_function
#define BSP_CFG_USER_LOCKING_SW_LOCK_FUNCTION      my_sw_locking_function
#define BSP_CFG_USER_LOCKING_SW_UNLOCK_FUNCTION    my_sw_unlocking_function

/* If the user would like to determine if a warm start reset has occurred, then they may enable one or more of the
   following callback definitions AND provide a call back function name for the respective callback
   function (to be defined by the user). Setting BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED = 1 will result
   in a callback to the user defined my_sw_warmstart_prec_function just prior to the initialization of the C
   runtime environment by resetprg.
   Setting BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED = 1 will result in a callback to the user defined
   my_sw_warmstart_postc_function just after the initialization of the C runtime environment by resetprg.
*/
#define BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_PRE_C_FUNCTION     my_sw_warmstart_prec_function

#define BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_POST_C_FUNCTION    my_sw_warmstart_postc_function

/* By default FIT modules will check input parameters to be valid. This is helpful during development but some users
   will want to disable this for production code. The reason for this would be to save execution time and code space.
   This macro is a global setting for enabling or disabling parameter checking. Each FIT module will also have its
   own local macro for this same purpose. By default the local macros will take the global value from here though
   they can be overridden. Therefore, the local setting has priority over this global setting. Disabling parameter
   checking should only used when inputs are known to be good and the increase in speed or decrease in code space is 
   needed.
   0 = Global setting for parameter checking is disabled.
   1 = Global setting for parameter checking is enabled (Default).
*/
#define BSP_CFG_PARAM_CHECKING_ENABLE               (1)

/* This macro is used to define the voltage that is supplied to the MCU (Vcc). This macro is defined in millivolts.
   Please change the value according to the supplied voltage level.
   For example, when supplying 3.3 V, please set the value to 3300.
   NOTE: Set values appropriate for the user system.
*/
#define BSP_CFG_MCU_VCC_MV                          (5000) /* Generated value. Do not edit this manually */

/* Allow initialization of auto-generated peripheral initialization code by Smart Configurator tool.
   When not using the Smart Configurator, set the value of BSP_CFG_CONFIGURATOR_SELECT to 0.
   0 = Disabled (default)
   1 = Smart Configurator initialization code used
*/
#define BSP_CFG_CONFIGURATOR_SELECT                 (1) /* Generated value. Do not edit this manually */

/* Version number of Smart Configurator.
   This macro definition is updated by Smart Configurator.
*/
#define BSP_CFG_CONFIGURATOR_VERSION                (2180) /* Generated value. Do not edit this manually */

/* For some BSP functions, it is necessary to ensure that, while these functions are executing, interrupts from other 
   FIT modules do not occur. By controlling the IPL, these functions disable interrupts that are at or below the 
   specified interrupt priority level.
   This macro sets the IPL. Range is 0x0 - 0xF.
   Please set this macro more than IPR for other FIT module interrupts.
   The default value is 0xF (maximum value).
   Don't change if there is no special processing with higher priority than all fit modules.
*/
#define BSP_CFG_FIT_IPL_MAX                         (0xF)

/* Software Interrupt (SWINT).
   0 = Software interrupt is not used.
   1 = Software interrupt is used.
   NOTE: When this macro is set to 1, the software interrupt is initialized in bsp startup routine. 
*/
#define BSP_CFG_SWINT_UNIT1_ENABLE    (0)
#define BSP_CFG_SWINT_UNIT2_ENABLE    (0)

/* Software Interrupt Task Buffer Number.
   For software interrupt, this value is number of buffering user tasks.
   So user can increase this value if user system would have many software interrupt tasks
   and user system has enough buffer. This value requires 9 byte per task.
   NOTE: This setting is common to all units. It can not be set individually. 
         The maximum value is 254.
*/
#define BSP_CFG_SWINT_TASK_BUFFER_NUMBER     (8)

/* Initial value of the software interrupt priority.
   For software interrupt, this value is interrupt priority. Range is 0x0 - 0xF.
   NOTE: This setting is common to all units. It can not be set individually. 
         Please be careful that this setting is the initial value of the interrupt priority register(IPR).
         It is possible to dynamically change the IPR.
*/
#define BSP_CFG_SWINT_IPR_INITIAL_VALUE     (0x1)

/* This macro is used for serial terminal on the board selected by smart configurator.
   0 = SCI UART Terminal is disabled.
   1 = SCI UART Terminal is enabled.
*/
#define BSP_CFG_SCI_UART_TERMINAL_ENABLE         (0)

/* This macro is channel number for serial terminal.
*/
#define BSP_CFG_SCI_UART_TERMINAL_CHANNEL        (11)

/* This macro is bit-rate for serial terminal.
*/
#define BSP_CFG_SCI_UART_TERMINAL_BITRATE        (115200)

/* This macro is interrupt priority for serial terminal.
   0(low) - 15(high)
*/
#define BSP_CFG_SCI_UART_TERMINAL_INTERRUPT_PRIORITY   (15)

/* This macro is used for C++ project and updated by Smart Configurator.
   0 = This project is a C project.(Not a C++ project).
   1 = This project is a C++ project.
*/
#define BSP_CFG_CPLUSPLUS             (0) /* Generated value. Do not edit this manually */

/* Select whether to enable initilize function for TFU (fixed-point numbers).
   0 = Initialize function for TFU is disabled. (default)
   1 = Initialize function for TFU is enabled.
*/
#define BSP_CFG_TFU_INITIALIZE_ENABLE            (0)

/* Select the unit and format setting of the input values in fixed-point sincos operations.
   0 = Unit of turn, Q1.31 format (default)
   1 = Unit of radians, Q3.29 format
*/
#define BSP_CFG_TFU_SINCOS_INPUT_UNIT_FORMAT     (0)

/* Select the format setting of the output values in fixed-point sincos operations.
   0 = Q1.31 (default)
   1 = Q2.30
   2 = Q3.29
*/
#define BSP_CFG_TFU_SINCOS_OUTPUT_FORMAT         (0)

/* Select the output format setting of output values of atan calculations in fixed-point atanhypot_k operations.
   0 = Unit of turn, Q1.31 format (default)
   1 = Unit of radians, Q3.29 format
*/
#define BSP_CFG_TFU_ATAN_OUTPUT_UNIT_FORMAT      (0)

#endif /* R_BSP_CONFIG_REF_HEADER_FILE */

