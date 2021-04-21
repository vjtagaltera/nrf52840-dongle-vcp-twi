/**
 * Copyright (c) 2015 - 2020, Nordic Semiconductor ASA
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
/** @file
 * @defgroup tw_sensor_example main.c
 * @{
 * @ingroup nrf_twi_example
 * @brief TWI Sensor Example main file.
 *
 * This file contains the source code for a sample application using TWI.
 *
 */

#include <stdio.h>
#include "boards.h"
#include "app_util_platform.h"
#include "app_error.h"
#include "nrf_drv_twi.h"
#include "nrf_delay.h"


#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

/* TWI instance ID. */
#define TWI_INSTANCE_ID     0

/* Common addresses definition for temperature sensor. */
#define LM75B_ADDR          (0x90U >> 1)

#define LM75B_REG_TEMP      0x00U
#define LM75B_REG_CONF      0x01U
#define LM75B_REG_THYST     0x02U
#define LM75B_REG_TOS       0x03U

/* Mode for LM75B. */
#define NORMAL_MODE 0U

#define ARDUINO_SCL_PIN  (45)   /* p1.13 */
#define ARDUINO_SDA_PIN  (42)   /* p1.10 */

#define ARDUINO_2_SCL_PIN  (2)  /* p0.2 */
#define ARDUINO_2_SDA_PIN  (47) /* p1.15 */

#define ARDUINO_3_SCL_PIN  (31)
#define ARDUINO_3_SDA_PIN  (29)

/* Indicates if operation on TWI has ended. */
static volatile uint8_t m_twi_xfer_done = 0;

/* TWI instance. */
static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(TWI_INSTANCE_ID);

/* Buffer for samples read from temperature sensor. */
static uint8_t m_sample;

/* -------------------------------------- */
extern void log_wait_ms(uint32_t ms);

static uint8_t m_mode_ok = 0;

static void wait_xfer_done_ms(uint32_t ms)
{
    if ( ms < 4 ) ms = 4;
    if ( ms > 1000 ) ms = 1000;
    ms /= 2;
    while ( ms ) {
        if ( m_twi_xfer_done == 1 )
            break;
        log_wait_ms(2);
        ms --;
    }
}
/* -------------------------------------- */

/**
 * @brief Function for setting active mode on MMA7660 accelerometer.
 */
void LM75B_set_mode(void)
{
    ret_code_t err_code;
    uint8_t ok_cnt = 0;

    NRF_LOG_INFO(" mode setting ... ");
    log_wait_ms(2);


    /* Writing to LM75B_REG_CONF "0" set temperature sensor in NORMAL mode. */
    uint8_t reg[2] = {LM75B_REG_CONF, NORMAL_MODE};
    m_twi_xfer_done = 0;
    err_code = nrf_drv_twi_tx(&m_twi, LM75B_ADDR, reg, sizeof(reg), false);
    APP_ERROR_CHECK(err_code);
    /*while (m_xfer_done == false);*/

    wait_xfer_done_ms(1000);
    if ( m_twi_xfer_done == 1 ) ok_cnt ++;

    /* Writing to pointer byte. */
    reg[0] = LM75B_REG_TEMP;
    m_twi_xfer_done = 0;
    err_code = nrf_drv_twi_tx(&m_twi, LM75B_ADDR, reg, 1, false);
    APP_ERROR_CHECK(err_code);

    /*while (m_xfer_done == false);*/
    wait_xfer_done_ms(1000);
    if ( m_twi_xfer_done == 1 ) ok_cnt ++;

    if (ok_cnt >= 2) m_mode_ok = 1;
    else NRF_LOG_WARNING(" failed mode setting. ");
}

/**
 * @brief Function for handling data from temperature sensor.
 *
 * @param[in] temp          Temperature in Celsius degrees read from sensor.
 */
__STATIC_INLINE void data_handler(uint8_t temp)
{
    static uint32_t count = 0;
    NRF_LOG_INFO("Temperature: %d Celsius degrees. count %u.", temp, ++count);
}

/**
 * @brief TWI events handler.
 */
void twi_handler(nrf_drv_twi_evt_t const * p_event, void * p_context)
{
    switch (p_event->type)
    {
        case NRF_DRV_TWI_EVT_DONE:
            if (p_event->xfer_desc.type == NRF_DRV_TWI_XFER_RX)
            {
                data_handler(m_sample);
            }
            m_twi_xfer_done = 1;
            break;
        default:
            NRF_LOG_WARNING("TWI event unknown type %d", p_event->type);
            m_twi_xfer_done = 2;
            break;
    }
}

/**
 * @brief UART initialization.
 */
void twi_init (void)
{
    ret_code_t err_code;

    const nrf_drv_twi_config_t twi_lm75b_config = {
       .scl                = ARDUINO_SCL_PIN,
       .sda                = ARDUINO_SDA_PIN,
       .frequency          = NRF_DRV_TWI_FREQ_100K,
       .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
       .clear_bus_init     = false
    };

    err_code = nrf_drv_twi_init(&m_twi, &twi_lm75b_config, twi_handler, NULL);
    APP_ERROR_CHECK(err_code);

    nrf_drv_twi_enable(&m_twi);
}

/**
 * @brief Function for reading data from temperature sensor.
 */
void LM75B_read_sensor_data()
{
    if ( m_mode_ok == 0 ) {
        LM75B_set_mode();
    }
    if ( m_mode_ok == 0 ) {
        return;
    }

    m_twi_xfer_done = 0;

    /* Read 1 byte from the specified address - skip 3 bits dedicated for fractional part of temperature. */
    ret_code_t err_code = nrf_drv_twi_rx(&m_twi, LM75B_ADDR, &m_sample, sizeof(m_sample));
    /*APP_ERROR_CHECK(err_code);*//*this fails with busy when wire is just connected*/

#if 0 /* set to 1 to avoid the busy error code 17 */
    wait_xfer_done_ms(200);
    if (m_twi_xfer_done != 1) {
        m_mode_ok = 0;
        NRF_LOG_WARNING(" failed data reading xfer event %u. ", m_twi_xfer_done);
    }
#endif
    if ( err_code != NRF_SUCCESS ) {
        m_mode_ok = 0;
        NRF_LOG_WARNING(" failed data reading err code %d. ", err_code);
        NRF_LOG_WARNING(" error: %s", nrf_strerror_get(err_code));

#if 0
        /* slow down. after ~2 seconds, the error code 17 goes away, sometimes. */
        m_twi_xfer_done = 0;
        wait_xfer_done_ms(200);
#else
        /* attempt to clear the error code 17 */
        nrf_drv_twi_disable(&m_twi);
        nrf_drv_twi_uninit(&m_twi);
        m_twi_xfer_done = 0;
        wait_xfer_done_ms(20);
        twi_init();
#endif
    }
}

/**
 * @brief Function for main application entry.
 */
#if 0
int main(void)
{
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    NRF_LOG_INFO("\r\nTWI sensor example started.");
    NRF_LOG_FLUSH();
    twi_init();
    LM75B_set_mode();
    NRF_LOG_INFO("TWI sensor mode set.");
    NRF_LOG_FLUSH();

    while (true)
    {
        nrf_delay_ms(500);

        do
        {
            __WFE();
        }while (m_xfer_done == false);

        read_sensor_data();
        NRF_LOG_FLUSH();
    }
}
#endif

/** @} */
