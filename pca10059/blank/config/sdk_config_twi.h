/**
 * Copyright (c) 2017 - 2020, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */



#ifndef SDK_CONFIG_TWI_H
#define SDK_CONFIG_TWI_H

/* ---------------------------------------------------------- */
/* twi related from twi_sensor/.../sdk_config.h */

// <e> NRFX_TWIM_ENABLED - nrfx_twim - TWIM peripheral driver
//==========================================================
#ifndef NRFX_TWIM_ENABLED
#define NRFX_TWIM_ENABLED 1
#endif
// <q> NRFX_TWIM0_ENABLED  - Enable TWIM0 instance


#ifndef NRFX_TWIM0_ENABLED
#define NRFX_TWIM0_ENABLED 0
#endif

// <q> NRFX_TWIM1_ENABLED  - Enable TWIM1 instance


#ifndef NRFX_TWIM1_ENABLED
#define NRFX_TWIM1_ENABLED 0
#endif

// <o> NRFX_TWIM_DEFAULT_CONFIG_FREQUENCY  - Frequency

// <26738688=> 100k
// <67108864=> 250k
// <104857600=> 400k

#ifndef NRFX_TWIM_DEFAULT_CONFIG_FREQUENCY
#define NRFX_TWIM_DEFAULT_CONFIG_FREQUENCY 26738688
#endif

// <q> NRFX_TWIM_DEFAULT_CONFIG_HOLD_BUS_UNINIT  - Enables bus holding after uninit


#ifndef NRFX_TWIM_DEFAULT_CONFIG_HOLD_BUS_UNINIT
#define NRFX_TWIM_DEFAULT_CONFIG_HOLD_BUS_UNINIT 0
#endif

// <o> NRFX_TWIM_DEFAULT_CONFIG_IRQ_PRIORITY  - Interrupt priority

// <0=> 0 (highest)
// <1=> 1
// <2=> 2
// <3=> 3
// <4=> 4
// <5=> 5
// <6=> 6
// <7=> 7

#ifndef NRFX_TWIM_DEFAULT_CONFIG_IRQ_PRIORITY
#define NRFX_TWIM_DEFAULT_CONFIG_IRQ_PRIORITY 6
#endif

// <e> NRFX_TWIM_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRFX_TWIM_CONFIG_LOG_ENABLED
#define NRFX_TWIM_CONFIG_LOG_ENABLED 0
#endif
// <o> NRFX_TWIM_CONFIG_LOG_LEVEL  - Default Severity level

// <0=> Off
// <1=> Error
// <2=> Warning
// <3=> Info
// <4=> Debug

#ifndef NRFX_TWIM_CONFIG_LOG_LEVEL
#define NRFX_TWIM_CONFIG_LOG_LEVEL 3
#endif

// <o> NRFX_TWIM_CONFIG_INFO_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef NRFX_TWIM_CONFIG_INFO_COLOR
#define NRFX_TWIM_CONFIG_INFO_COLOR 0
#endif

// <o> NRFX_TWIM_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef NRFX_TWIM_CONFIG_DEBUG_COLOR
#define NRFX_TWIM_CONFIG_DEBUG_COLOR 0
#endif

// </e>

// </e>

// <e> NRFX_TWI_ENABLED - nrfx_twi - TWI peripheral driver
//==========================================================
#ifndef NRFX_TWI_ENABLED
#define NRFX_TWI_ENABLED 1
#endif
// <q> NRFX_TWI0_ENABLED  - Enable TWI0 instance


#ifndef NRFX_TWI0_ENABLED
#define NRFX_TWI0_ENABLED 0
#endif

// <q> NRFX_TWI1_ENABLED  - Enable TWI1 instance


#ifndef NRFX_TWI1_ENABLED
#define NRFX_TWI1_ENABLED 0
#endif

// <o> NRFX_TWI_DEFAULT_CONFIG_FREQUENCY  - Frequency

// <26738688=> 100k
// <67108864=> 250k
// <104857600=> 400k

#ifndef NRFX_TWI_DEFAULT_CONFIG_FREQUENCY
#define NRFX_TWI_DEFAULT_CONFIG_FREQUENCY 26738688
#endif

// <q> NRFX_TWI_DEFAULT_CONFIG_HOLD_BUS_UNINIT  - Enables bus holding after uninit


#ifndef NRFX_TWI_DEFAULT_CONFIG_HOLD_BUS_UNINIT
#define NRFX_TWI_DEFAULT_CONFIG_HOLD_BUS_UNINIT 0
#endif

// <o> NRFX_TWI_DEFAULT_CONFIG_IRQ_PRIORITY  - Interrupt priority

// <0=> 0 (highest)
// <1=> 1
// <2=> 2
// <3=> 3
// <4=> 4
// <5=> 5
// <6=> 6
// <7=> 7

#ifndef NRFX_TWI_DEFAULT_CONFIG_IRQ_PRIORITY
#define NRFX_TWI_DEFAULT_CONFIG_IRQ_PRIORITY 6
#endif

// <e> NRFX_TWI_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRFX_TWI_CONFIG_LOG_ENABLED
#define NRFX_TWI_CONFIG_LOG_ENABLED 0
#endif
// <o> NRFX_TWI_CONFIG_LOG_LEVEL  - Default Severity level

// <0=> Off
// <1=> Error
// <2=> Warning
// <3=> Info
// <4=> Debug

#ifndef NRFX_TWI_CONFIG_LOG_LEVEL
#define NRFX_TWI_CONFIG_LOG_LEVEL 3
#endif

// <o> NRFX_TWI_CONFIG_INFO_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef NRFX_TWI_CONFIG_INFO_COLOR
#define NRFX_TWI_CONFIG_INFO_COLOR 0
#endif

// <o> NRFX_TWI_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef NRFX_TWI_CONFIG_DEBUG_COLOR
#define NRFX_TWI_CONFIG_DEBUG_COLOR 0
#endif

// </e>

// </e>

/* ---------------------------------------------------------- */
/* after the uart_config_debug_color */

// <e> TWI_ENABLED - nrf_drv_twi - TWI/TWIM peripheral driver - legacy layer
//==========================================================
#ifndef TWI_ENABLED
#define TWI_ENABLED 1
#endif
// <o> TWI_DEFAULT_CONFIG_FREQUENCY  - Frequency

// <26738688=> 100k
// <67108864=> 250k
// <104857600=> 400k

#ifndef TWI_DEFAULT_CONFIG_FREQUENCY
#define TWI_DEFAULT_CONFIG_FREQUENCY 26738688
#endif

// <q> TWI_DEFAULT_CONFIG_CLR_BUS_INIT  - Enables bus clearing procedure during init


#ifndef TWI_DEFAULT_CONFIG_CLR_BUS_INIT
#define TWI_DEFAULT_CONFIG_CLR_BUS_INIT 0
#endif

// <q> TWI_DEFAULT_CONFIG_HOLD_BUS_UNINIT  - Enables bus holding after uninit


#ifndef TWI_DEFAULT_CONFIG_HOLD_BUS_UNINIT
#define TWI_DEFAULT_CONFIG_HOLD_BUS_UNINIT 0
#endif

// <o> TWI_DEFAULT_CONFIG_IRQ_PRIORITY  - Interrupt priority


// <i> Priorities 0,2 (nRF51) and 0,1,4,5 (nRF52) are reserved for SoftDevice
// <0=> 0 (highest)
// <1=> 1
// <2=> 2
// <3=> 3
// <4=> 4
// <5=> 5
// <6=> 6
// <7=> 7

#ifndef TWI_DEFAULT_CONFIG_IRQ_PRIORITY
#define TWI_DEFAULT_CONFIG_IRQ_PRIORITY 6
#endif

// <e> TWI0_ENABLED - Enable TWI0 instance
//==========================================================
#ifndef TWI0_ENABLED
#define TWI0_ENABLED 1
#endif
// <q> TWI0_USE_EASY_DMA  - Use EasyDMA (if present)


#ifndef TWI0_USE_EASY_DMA
#define TWI0_USE_EASY_DMA 1
#endif

// </e>

// <e> TWI1_ENABLED - Enable TWI1 instance
//==========================================================
#ifndef TWI1_ENABLED
#define TWI1_ENABLED 0
#endif
// <q> TWI1_USE_EASY_DMA  - Use EasyDMA (if present)


#ifndef TWI1_USE_EASY_DMA
#define TWI1_USE_EASY_DMA 0
#endif

// </e>

// </e>

/* ---------------------------------------------------------- */
/* after timer_config_debug_color */

// <e> TWIS_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef TWIS_CONFIG_LOG_ENABLED
#define TWIS_CONFIG_LOG_ENABLED 0
#endif
// <o> TWIS_CONFIG_LOG_LEVEL  - Default Severity level

// <0=> Off
// <1=> Error
// <2=> Warning
// <3=> Info
// <4=> Debug

#ifndef TWIS_CONFIG_LOG_LEVEL
#define TWIS_CONFIG_LOG_LEVEL 3
#endif

// <o> TWIS_CONFIG_INFO_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef TWIS_CONFIG_INFO_COLOR
#define TWIS_CONFIG_INFO_COLOR 0
#endif

// <o> TWIS_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef TWIS_CONFIG_DEBUG_COLOR
#define TWIS_CONFIG_DEBUG_COLOR 0
#endif

// </e>

// <e> TWI_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef TWI_CONFIG_LOG_ENABLED
#define TWI_CONFIG_LOG_ENABLED 0
#endif
// <o> TWI_CONFIG_LOG_LEVEL  - Default Severity level

// <0=> Off
// <1=> Error
// <2=> Warning
// <3=> Info
// <4=> Debug

#ifndef TWI_CONFIG_LOG_LEVEL
#define TWI_CONFIG_LOG_LEVEL 3
#endif

// <o> TWI_CONFIG_INFO_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef TWI_CONFIG_INFO_COLOR
#define TWI_CONFIG_INFO_COLOR 0
#endif

// <o> TWI_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef TWI_CONFIG_DEBUG_COLOR
#define TWI_CONFIG_DEBUG_COLOR 0
#endif

// </e>

/* ---------------------------------------------------------- */
/* after sortlist_config_debug_color */

// <e> NRF_TWI_SENSOR_CONFIG_LOG_ENABLED - Enables logging in the module.
//==========================================================
#ifndef NRF_TWI_SENSOR_CONFIG_LOG_ENABLED
#define NRF_TWI_SENSOR_CONFIG_LOG_ENABLED 0
#endif
// <o> NRF_TWI_SENSOR_CONFIG_LOG_LEVEL  - Default Severity level

// <0=> Off
// <1=> Error
// <2=> Warning
// <3=> Info
// <4=> Debug

#ifndef NRF_TWI_SENSOR_CONFIG_LOG_LEVEL
#define NRF_TWI_SENSOR_CONFIG_LOG_LEVEL 3
#endif

// <o> NRF_TWI_SENSOR_CONFIG_INFO_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef NRF_TWI_SENSOR_CONFIG_INFO_COLOR
#define NRF_TWI_SENSOR_CONFIG_INFO_COLOR 0
#endif

// <o> NRF_TWI_SENSOR_CONFIG_DEBUG_COLOR  - ANSI escape code prefix.

// <0=> Default
// <1=> Black
// <2=> Red
// <3=> Green
// <4=> Yellow
// <5=> Blue
// <6=> Magenta
// <7=> Cyan
// <8=> White

#ifndef NRF_TWI_SENSOR_CONFIG_DEBUG_COLOR
#define NRF_TWI_SENSOR_CONFIG_DEBUG_COLOR 0
#endif

// </e>

/* ---------------------------------------------------------- */
/* slip copied from peripheral/usbd_ble_uart */

// <q> SLIP_ENABLED  - slip - SLIP encoding and decoding

#ifndef SLIP_ENABLED
#define SLIP_ENABLED 1
#endif

/* ---------------------------------------------------------- */

#endif //SDK_CONFIG_TWI_H


