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
 * Target  : WeActF405 — iNav 9
 * Motor timer mapping (STM32F405 AF table):
 *   PB8 = TIM4_CH3  (AF2)   Motor 1
 *   PB5 = TIM3_CH2  (AF2)   Motor 2
 *   PB4 = TIM3_CH1  (AF2)   Motor 3
 *   PB3 = TIM2_CH2  (AF1)   Motor 4
 *
 * DMA streams (for DSHOT):
 *   TIM4_CH3 → DMA1 Stream 7 Ch2
 *   TIM3_CH2 → DMA1 Stream 5 Ch5
 *   TIM3_CH1 → DMA1 Stream 4 Ch5
 *   TIM2_CH2 → DMA1 Stream 6 Ch3
 *
 * PA8 = TIM1_CH1 — NOT used for motor, free for I2C3_SCL (AF4)
 * PC9 = TIM3_CH4 — defined here as LED strip if needed, else skip
 */

#include <stdint.h>

#include "platform.h"
#include "drivers/bus.h"
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"
#include "drivers/light_led.h"

/* ---------------------------------------------------------------
 * timerHardware[] — the ONLY place that maps pins to timers.
 * Order = Motor output port order (M1..M4), then extras.
 * DEF_TIM(timer, channel, pin, usage_flags, output_flags, dma_req)
 * --------------------------------------------------------------- */
timerHardware_t timerHardware[] = {
    // ---- MOTORS (Quad X) ----
    // Matches CLI: timer_output_mode 0-3 MOTORS
    DEF_TIM(TIM4, CH3, PB8, TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR, 0, 0),  // M1 DMA1_ST7_CH2
    DEF_TIM(TIM3, CH2, PB5, TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR, 0, 0),  // M2 DMA1_ST5_CH5
    DEF_TIM(TIM3, CH1, PB4, TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR, 0, 0),  // M3 DMA1_ST4_CH5
    DEF_TIM(TIM2, CH2, PB3, TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR, 0, 0),  // M4 DMA1_ST6_CH3

    // ---- PPM / Serial RX input (PA3 = UART2_RX, but TIM5_CH4 also ok for PPM) ----
    // Uncomment if PPM receiver needed on a spare pin:
    // DEF_TIM(TIM5, CH1, PA0, TIM_USE_PPM, 0, 0),

    // ---- LED Strip (optional — comment out if not used) ----
    // DEF_TIM(TIM1, CH1, PA8, TIM_USE_LED, 0, 0),
    // NOTE: PA8 is used as I2C3_SCL — DO NOT enable LED strip on PA8!
    //       If you want LED strip, use a different pin e.g. PA0 (TIM5_CH1).
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
