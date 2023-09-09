/*----------------------------------------------------------------------------
 *      Exynos SoC  -  CMU
 *----------------------------------------------------------------------------
 *      Name:    cmu6315.h
 *      Purpose: To expose CMU APIs and define macros
 *      Rev.:    V1.00
 *----------------------------------------------------------------------------
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CMU6315_H__
#define __CMU6315_H__

typedef enum {
    CMU_CLK_NOC = 0,
    CMU_CLK_PERI,
    CMU_CLK_RCO,
    CMU_CLK_OSCCLK,
    CMU_CLK_RTCCLK,
    CMU_CLK_OUTPUT_CPU,

    CMU_CLK_TIMER,

    CMU_CLK_CHUB_BUS,

    CMU_CLK_CHUB_I2C,
    CMU_CLK_CHUB_SPI_I2C0,
    CMU_CLK_CHUB_SPI_I2C1,
    CMU_CLK_CHUB_I3C,
    CMU_CLK_CHUB_USI00,
    CMU_CLK_CHUB_USI01,
    CMU_CLK_CHUB_USI02,
    CMU_CLK_CHUB_USI03,

    CMU_CLK_CHUB_SPI_MS_CTRL,

    CMU_CLK_I2C,
    CMU_CLK_I2C00 = CMU_CLK_I2C,
    CMU_CLK_I2C01,
    CMU_CLK_I2C02,
    CMU_CLK_I2C03,
    CMU_CLK_I2C04,
    CMU_CLK_I2C05,
    CMU_CLK_I2C06,
    CMU_CLK_I2C07,

    CMU_MAX_IP_TYPE
} CmuIpType;

typedef enum {
    CMU_HWACG_IP_CM4 = 0,
    CMU_HWACG_IP_GPIO,
    CMU_HWACG_IP_I2C_CHUB00,
    CMU_HWACG_IP_PDMA,
    CMU_HWACG_IP_PWM,
    CMU_HWACG_IP_TIMER,
    CMU_HWACG_IP_USI_CHUB00,
    CMU_HWACG_IP_WDT,
    CMU_HWACG_IP_SERIAL_LIF_BCLK,
    CMU_HWACG_IP_DMAILBOX,
    CMU_HWACG_IP_HPM,

    CMU_HWACG_MAX_IP_TYPE
} CmuHwacgIpType;

// Constant values of clocks =============
#define RTC_FREQ                32768 // 32.768Khz
#define XTAL_FREQ               26000000 // 26Mhz
#define OSCCLK_RCO_FREQ         24576000 // 24.576Mhz
#define CLK_RCO_FREQ            49152000 // 49.152Mhz
#define HFRCO_FREQ              393216000 // 393.216Mhz
#define CMGP_PLL_FREQ           400000000 // 393.216Mhz

#define CHUB_MAIN_CLK           HFRCO_FREQ
/*
#define OSCCLK_CHUB
#define CLKALIVE_CHUB_NOC
#define CLKALIVE_CHUB_PERI
#define CLKALIVE_CHUB_RCO
#define RTCCLK_CHUB
*/

#endif

