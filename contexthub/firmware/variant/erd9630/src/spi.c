/*----------------------------------------------------------------------------
 *      ERD  -  SPI
 *----------------------------------------------------------------------------
 *      Name:    spi.c
 *      Purpose: Initialize SPI ports
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

#include <spiBoard.h>
#include <plat/spi/spi.h>
#include <spiDrv.h>
#include <usi.h>
#include <cmu.h>

static const spi_device_t mSpiDevConf[] = {
    [0] = {
        .m_portId=0,
        .m_EnAutoCS = 0,
        .m_OpMode = SPI_MASTER,
        .m_TargetSPICLK = 8000000,
        .m_OpClock=8000000,
        .m_ChWidth=SPI_BYTE,
        .m_BusWidth=SPI_BYTE,
#ifdef DEF_IF_INTERRUPT_MODE
        .m_RxTransferMode=SPI_INTERRUPT_MODE,
        .m_TxTransferMode=SPI_INTERRUPT_MODE,
#else
       .m_RxTransferMode=SPI_POLLING_MODE,
       .m_TxTransferMode=SPI_POLLING_MODE,
#endif
        .m_loopback=0,     // self loopback mode
        .m_FBClkSel = SPI_PHASE_DELAY90,
        .m_CPOL = SPI_ACTIVE_LOW,//Active low
        .m_CPHA = SPI_FORMAT_B,//Format B
    },
};

void spiBoardInit(void)
{
    int i, num;
    uint32_t portNum;
    uint32_t inputClock, clockDivider;
    CmuIpType   spiType;

    num = sizeof(mSpiDevConf)/sizeof(spi_device_t);
    for(i=0; i<num; i++){
        portNum = mSpiDevConf[i].m_portId;
        if(usiOpen(portNum, USI_PROTOCOL_SPI))
            CSP_PRINTF_ERROR("\nERROR spiBoardInit!!!\n");
        spiSetDeviceInfo(i, &mSpiDevConf[i]);

        /* Set divider value of USI based on SPI operation clock */
        if      (portNum == SPI_CHUB0)  spiType=CMU_CLK_CHUB_USI00;
        else if (portNum == SPI_CHUB1)  spiType=CMU_CLK_CHUB_USI01;
        else if (portNum == SPI_CHUB2)  spiType=CMU_CLK_CHUB_USI01;
        else if (portNum == SPI_CMGP0)  spiType=CMU_CLK_CMGP_USI00;
        else if (portNum == SPI_CMGP1)  spiType=CMU_CLK_CMGP_USI01;
        else if (portNum == SPI_CMGP2)  spiType=CMU_CLK_CMGP_USI02;
        else if (portNum == SPI_CMGP3)  spiType=CMU_CLK_CMGP_USI03;

        inputClock = cmuGetSpeed(spiType);
        clockDivider = inputClock / (mSpiDevConf[i].m_OpClock*4) - 1;
        cmuSetDivider(spiType, clockDivider);
    }
}
