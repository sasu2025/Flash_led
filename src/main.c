/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : S32K3XX
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/* Including necessary configuration files. */
#include "Mcal.h"
#include "Siul2_Port_Ip_Cfg.h"
#include "Siul2_Port_Ip.h"
#include "Siul2_Dio_Ip.h"

volatile int exit_code = 0;
/* User includes */
void TestDelay(uint32 delay);
void TestDelay(uint32 delay)
{
    static volatile uint32 DelayTimer = 0;
    while(DelayTimer<delay)
    {
        DelayTimer++;
    }
    DelayTimer=0;
}


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your code here */
    /* Initialize all pins using the Port driver */
	 Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

#if 0
    for(;;)
    {
        //if(exit_code != 0)
        {
         //   break;
        }

        Siul2_Dio_Ip_TogglePins(GREEN_LED_PORT,1<<GREEN_LED_PIN);
        TestDelay(4800000);
        Siul2_Dio_Ip_TogglePins(GREEN_LED_PORT,0<<GREEN_LED_PIN);
    }
#endif

#if 1
    while (1)
    {
        Siul2_Dio_Ip_WritePin(GREEN_LED_PORT, GREEN_LED_PIN, 1U);
        TestDelay(4800000);
        Siul2_Dio_Ip_WritePin(GREEN_LED_PORT, GREEN_LED_PIN, 0U);
        TestDelay(4800000);
    }

    //Exit_Example(TRUE);
#endif
    return exit_code;
}

/** @} */
