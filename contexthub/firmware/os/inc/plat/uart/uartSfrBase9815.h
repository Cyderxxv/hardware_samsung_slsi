/*----------------------------------------------------------------------------
 *      Exynos SoC  -  UART
 *----------------------------------------------------------------------------
 *      Name:    uartSfrBase9815.h
 *      Purpose: To expose I2C driver functions
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

#ifndef __UART_SFR_BASE9815_H__
#define __UART_SFR_BASE9815_H__

#include <csp_common.h>

    UartInfoType mUartInfo[UART_CHANNEL_MAX] = {
        {UART0_BASE_ADDRESS, UART_STATE_CLOSE}, // UART0_CHUB
        {UART1_BASE_ADDRESS, UART_STATE_CLOSE}, // UART1_CHUB
        {UART2_BASE_ADDRESS, UART_STATE_CLOSE}, // UART2_CHUB
    };

#endif

