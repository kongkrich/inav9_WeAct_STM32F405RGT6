/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV. If not, see <http://www.gnu.org/licenses/>.
 *
 * ================================================================
 * Target  : WeActF405 — iNav 9
 *
 * Pin summary:
 *   IMU      : SPI2  PB13(SCK)/PC2(MISO)/PC3(MOSI)  CS=PB12
 *   SD Card  : SPI1  PA5(SCK)/PA6(MISO)/PA7(MOSI)  CS=PA4
 *   GPS      : UART1 PB6(TX)/PB7(RX)
 *   Receiver : UART2 PA2(TX)/PA3(RX) — IBUS
 *   Spare    : UART3 PA9(TX)/PA10(RX)
 *   I2C2     : PB10(SCL)/PB11(SDA)
 *              BMP085 + HMC5883/QMC5883/AK8963 + VL53L0X + OLED
 *   Motors   : PB8(M1)/PB5(M2)/PB4(M3)/PB3(M4)
 *   VBAT     : PC4 (ADC1)
 *   CURRENT  : PC5 (ADC2)
 *   LED      : PA13
 *   BEEPER   : PB9
 * ================================================================
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER         "S405"
#define USBD_PRODUCT_STRING             "WeActF405"

#define LED0                            PA13
#define BEEPER                          PB9
#define BEEPER_INVERTED

#define USE_SPI
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN                    PA5
#define SPI1_MISO_PIN                   PA6
#define SPI1_MOSI_PIN                   PA7

#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN                    PB13
#define SPI2_MISO_PIN                   PC2
#define SPI2_MOSI_PIN                   PC3

#define USE_IMU_MPU9250
#define MPU9250_CS_PIN                  PB12
#define MPU9250_SPI_BUS                 BUS_SPI2
#define IMU_MPU9250_ALIGN               CW0_DEG

#define USE_IMU_MPU6500
#define MPU6500_CS_PIN               	PB12
#define MPU6500_SPI_BUS              	BUS_SPI2
#define IMU_MPU6500_ALIGN            	CW0_DEG

#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN                    PC10
#define SPI3_MISO_PIN                   PC11
#define SPI3_MOSI_PIN                   PC12

#define USE_SDCARD
#define USE_SDCARD_SPI
#define SDCARD_SPI_BUS                  BUS_SPI1
#define SDCARD_CS_PIN                   PA4
#define SDCARD_DETECT_PIN               NONE

#define USE_VCP

#define USE_UART1
#define UART1_TX_PIN                    PB6
#define UART1_RX_PIN                    PB7

#define USE_UART2
#define UART2_TX_PIN                    PA2
#define UART2_RX_PIN                    PA3

#define USE_UART3
#define UART3_TX_PIN                    PA9
#define UART3_RX_PIN                    PA10

#define SERIAL_PORT_COUNT               4

#define USE_I2C
#define USE_I2C_DEVICE_2
#define I2C2_SCL                        PB10
#define I2C2_SDA                        PB11
#define I2C_DEVICE                      I2CDEV_2
#define DEFAULT_I2C_BUS                 BUS_I2C2

#define USE_BARO
#define BARO_I2C_BUS                    BUS_I2C2
#define USE_BARO_BMP085
#define USE_BARO_BMP280
#define USE_BARO_MS5611
#define USE_BARO_DPS310

#define USE_MAG
#define MAG_I2C_BUS                     BUS_I2C2
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883
#define USE_MAG_AK8963
#define USE_MAG_AK8975

#define USE_RANGEFINDER
#define RANGEFINDER_I2C_BUS             BUS_I2C2
#define USE_RANGEFINDER_VL53L0X

#define USE_DASHBOARD
#define USE_OLED_SSD1306
#define DASHBOARD_I2C_BUS               BUS_I2C2
#define DASHBOARD_I2C_ADDR              0x3C

#define TEMPERATURE_I2C_BUS             BUS_I2C2
#define PITOT_I2C_BUS                   BUS_I2C2

#define USE_DSHOT
#define ENABLE_DSHOT_DMAR
#define MAX_PWM_OUTPUT_PORTS            4
#define TARGET_MOTOR_COUNT              4

#define USE_ADC
#define ADC_CHANNEL_1_PIN               PC4
#define ADC_CHANNEL_2_PIN               PC5
#define VBAT_ADC_CHANNEL                ADC_CHN_1
#define CURRENT_METER_ADC_CHANNEL       ADC_CHN_2
#define VBAT_SCALE_DEFAULT              440

#define SERIALRX_PROVIDER               SERIALRX_IBUS
#define SERIALRX_UART                   SERIAL_PORT_USART2
#define MAG_ALIGN_DEFAULT               CW270_DEG_FLIP
#define DEFAULT_TIMEZONE_OFFSET_MINUTES 420

#define DEFAULT_FEATURES                (FEATURE_TX_PROF_SEL | FEATURE_BLACKBOX | FEATURE_GPS | FEATURE_VBAT | FEATURE_AIRMODE)
#define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT
#define DEFAULT_RX_FEATURE              FEATURE_RX_SERIAL

#define TARGET_IO_PORTA                 0xffff
#define TARGET_IO_PORTB                 0xffff
#define TARGET_IO_PORTC                 0xffff
#define TARGET_IO_PORTD                 0xffff
