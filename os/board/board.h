/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for STMicroelectronics STM32F4-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_INVERTER
#define BOARD_NAME                  "NEPTUN_TTT_3-PHASE_INVERTER"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0U
#endif

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000U
#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
#define STM32_VDD                   300U

/*
 * MCU type as defined in the ST header.
 */
#define STM32F407xx

/*
 * IO pins assignments.
 */
#define GPIOA_BUTTON                0U
#define GPIOA_PIN1                  1U
#define GPIOA_PIN2                  2U
#define GPIOA_PIN3                  3U
#define GPIOA_LRCK                  4U
#define GPIOA_SPC                   5U
#define GPIOA_SDO                   6U
#define GPIOA_SDI                   7U
#define GPIOA_PIN8                  8U
#define GPIOA_VBUS_FS               9U
#define GPIOA_OTG_FS_ID             10U
#define GPIOA_OTG_FS_DM             11U
#define GPIOA_OTG_FS_DP             12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_PIN15                 15U

#define GPIOB_PIN0                  0U
#define GPIOB_PIN1                  1U
#define GPIOB_PIN2                  2U
#define GPIOB_SWO                   3U
#define GPIOB_PIN4                  4U
#define GPIOB_PIN5                  5U
#define GPIOB_SCL                   6U
#define GPIOB_PIN7                  7U
#define GPIOB_PIN8                  8U
#define GPIOB_SDA                   9U
#define GPIOB_CLK_IN                10U
#define GPIOB_PIN11                 11U
#define GPIOB_PIN12                 12U
#define GPIOB_PIN13                 13U
#define GPIOB_PIN14                 14U
#define GPIOB_PIN15                 15U

#define GPIOC_OTG_FS_POWER_ON       0U
#define GPIOC_PIN1                  1U
#define GPIOC_PIN2                  2U
#define GPIOC_PDM_OUT               3U
#define GPIOC_PIN4                  4U
#define GPIOC_PIN5                  5U
#define GPIOC_U_L                   6U
#define GPIOC_V_L                   7U
#define GPIOC_W_L                   8U
#define GPIOC_PIN9                  9U
#define GPIOC_SCLK                  10U
#define GPIOC_PIN11                 11U
#define GPIOC_SDIN                  12U
#define GPIOC_PIN13                 13U
#define GPIOC_PIN14                 14U
#define GPIOC_PIN15                 15U

#define GPIOD_PIN0                  0U
#define GPIOD_PIN1                  1U
#define GPIOD_PIN2                  2U
#define GPIOD_PIN3                  3U
#define GPIOD_RESET                 4U
#define GPIOD_OVER_CURRENT          5U
#define GPIOD_PIN6                  6U
#define GPIOD_PIN7                  7U
#define GPIOD_PIN8                  8U
#define GPIOD_PIN9                  9U
#define GPIOD_PIN10                 10U
#define GPIOD_PIN11                 11U
#define GPIOD_U_H                   12U
#define GPIOD_V_H                   13U
#define GPIOD_W_H                   14U
#define GPIOD_LED6                  15U

#define GPIOE_INT1                  0U
#define GPIOE_INT2                  1U
#define GPIOE_PIN2                  2U
#define GPIOE_CS_SPI                3U
#define GPIOE_PIN4                  4U
#define GPIOE_PIN5                  5U
#define GPIOE_PIN6                  6U
#define GPIOE_PIN7                  7U
#define GPIOE_PIN8                  8U
#define GPIOE_PIN9                  9U
#define GPIOE_PIN10                 10U
#define GPIOE_PIN11                 11U
#define GPIOE_PIN12                 12U
#define GPIOE_PIN13                 13U
#define GPIOE_PIN14                 14U
#define GPIOE_PIN15                 15U

#define GPIOF_PIN0                  0U
#define GPIOF_PIN1                  1U
#define GPIOF_PIN2                  2U
#define GPIOF_PIN3                  3U
#define GPIOF_PIN4                  4U
#define GPIOF_PIN5                  5U
#define GPIOF_PIN6                  6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_PIN10                 10U
#define GPIOF_PIN11                 11U
#define GPIOF_PIN12                 12U
#define GPIOF_PIN13                 13U
#define GPIOF_PIN14                 14U
#define GPIOF_PIN15                 15U

#define GPIOG_PIN0                  0U
#define GPIOG_PIN1                  1U
#define GPIOG_PIN2                  2U
#define GPIOG_PIN3                  3U
#define GPIOG_PIN4                  4U
#define GPIOG_PIN5                  5U
#define GPIOG_PIN6                  6U
#define GPIOG_PIN7                  7U
#define GPIOG_PIN8                  8U
#define GPIOG_PIN9                  9U
#define GPIOG_PIN10                 10U
#define GPIOG_PIN11                 11U
#define GPIOG_PIN12                 12U
#define GPIOG_PIN13                 13U
#define GPIOG_PIN14                 14U
#define GPIOG_PIN15                 15U

#define GPIOH_OSC_IN                0U
#define GPIOH_OSC_OUT               1U
#define GPIOH_PIN2                  2U
#define GPIOH_PIN3                  3U
#define GPIOH_PIN4                  4U
#define GPIOH_PIN5                  5U
#define GPIOH_PIN6                  6U
#define GPIOH_PIN7                  7U
#define GPIOH_PIN8                  8U
#define GPIOH_PIN9                  9U
#define GPIOH_PIN10                 10U
#define GPIOH_PIN11                 11U
#define GPIOH_PIN12                 12U
#define GPIOH_PIN13                 13U
#define GPIOH_PIN14                 14U
#define GPIOH_PIN15                 15U

#define GPIOI_PIN0                  0U
#define GPIOI_PIN1                  1U
#define GPIOI_PIN2                  2U
#define GPIOI_PIN3                  3U
#define GPIOI_PIN4                  4U
#define GPIOI_PIN5                  5U
#define GPIOI_PIN6                  6U
#define GPIOI_PIN7                  7U
#define GPIOI_PIN8                  8U
#define GPIOI_PIN9                  9U
#define GPIOI_PIN10                 10U
#define GPIOI_PIN11                 11U
#define GPIOI_PIN12                 12U
#define GPIOI_PIN13                 13U
#define GPIOI_PIN14                 14U
#define GPIOI_PIN15                 15U

/*
 * IO lines assignments.
 */
#define LINE_BUTTON                 PAL_LINE(GPIOA, 0U)
#define LINE_LRCK                   PAL_LINE(GPIOA, 4U)
#define LINE_SPC                    PAL_LINE(GPIOA, 5U)
#define LINE_SDO                    PAL_LINE(GPIOA, 6U)
#define LINE_SDI                    PAL_LINE(GPIOA, 7U)
#define LINE_VBUS_FS                PAL_LINE(GPIOA, 9U)
#define LINE_OTG_FS_ID              PAL_LINE(GPIOA, 10U)
#define LINE_OTG_FS_DM              PAL_LINE(GPIOA, 11U)
#define LINE_OTG_FS_DP              PAL_LINE(GPIOA, 12U)
#define LINE_SWDIO                  PAL_LINE(GPIOA, 13U)
#define LINE_SWCLK                  PAL_LINE(GPIOA, 14U)

#define LINE_SWO                    PAL_LINE(GPIOB, 3U)
#define LINE_SCL                    PAL_LINE(GPIOB, 6U)
#define LINE_SDA                    PAL_LINE(GPIOB, 9U)
#define LINE_CLK_IN                 PAL_LINE(GPIOB, 10U)

#define LINE_OTG_FS_POWER_ON        PAL_LINE(GPIOC, 0U)
#define LINE_PDM_OUT                PAL_LINE(GPIOC, 3U)
#define LINE_U_L                    PAL_LINE(GPIOC, 6U)
#define LINE_V_L                    PAL_LINE(GPIOC, 7U)
#define LINE_W_L                    PAL_LINE(GPIOC, 8U)
#define LINE_SCLK                   PAL_LINE(GPIOC, 10U)
#define LINE_SDIN                   PAL_LINE(GPIOC, 12U)

#define LINE_RESET                  PAL_LINE(GPIOD, 4U)
#define LINE_OVER_CURRENT           PAL_LINE(GPIOD, 5U)
#define LINE_U_H                    PAL_LINE(GPIOD, 12U)
#define LINE_V_H                    PAL_LINE(GPIOD, 13U)
#define LINE_W_H                    PAL_LINE(GPIOD, 14U)
#define LINE_LED6                   PAL_LINE(GPIOD, 15U)

#define LINE_INT1                   PAL_LINE(GPIOE, 0U)
#define LINE_INT2                   PAL_LINE(GPIOE, 1U)
#define LINE_CS_SPI                 PAL_LINE(GPIOE, 3U)


#define LINE_OSC_IN                 PAL_LINE(GPIOH, 0U)
#define LINE_OSC_OUT                PAL_LINE(GPIOH, 1U)


/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 * All input with pull-up except:
 * PA0  - BUTTON                    (input floating).
 * PA4  - LRCK                      (alternate 6).
 * PA5  - SPC                       (alternate 5).
 * PA6  - SDO                       (alternate 5).
 * PA7  - SDI                       (alternate 5).
 * PA9  - VBUS_FS                   (input floating).
 * PA10 - OTG_FS_ID                 (alternate 10).
 * PA11 - OTG_FS_DM                 (alternate 10).
 * PA12 - OTG_FS_DP                 (alternate 10).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIOA_BUTTON)        |  \
                                     PIN_MODE_ALTERNATE(GPIOA_LRCK)      |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SPC)       |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SDO)       |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SDI)       |  \
                                     PIN_MODE_INPUT(GPIOA_VBUS_FS)       |  \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_ID) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DM) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_OTG_FS_DP) |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO)     |  \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_BUTTON)    |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_LRCK)      |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SPC)       |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SDO)       |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SDI)       |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_VBUS_FS)   |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_ID) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_DM) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_OTG_FS_DP) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO)     |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_HIGH(GPIOA_BUTTON)       |  \
                                     PIN_OSPEED_HIGH(GPIOA_LRCK)         |  \
                                     PIN_OSPEED_MEDIUM(GPIOA_SPC)        |  \
                                     PIN_OSPEED_MEDIUM(GPIOA_SDO)        |  \
                                     PIN_OSPEED_MEDIUM(GPIOA_SDI)        |  \
                                     PIN_OSPEED_HIGH(GPIOA_VBUS_FS)      |  \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_ID)    |  \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_DM)    |  \
                                     PIN_OSPEED_HIGH(GPIOA_OTG_FS_DP)    |  \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO)        |  \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_FLOATING(GPIOA_BUTTON)    |  \
                                     PIN_PUPDR_FLOATING(GPIOA_LRCK)      |  \
                                     PIN_PUPDR_FLOATING(GPIOA_SPC)       |  \
                                     PIN_PUPDR_FLOATING(GPIOA_SDO)       |  \
                                     PIN_PUPDR_FLOATING(GPIOA_SDI)       |  \
                                     PIN_PUPDR_FLOATING(GPIOA_VBUS_FS)   |  \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_ID) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_DM) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_OTG_FS_DP) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_SWDIO)     |  \
                                     PIN_PUPDR_FLOATING(GPIOA_SWCLK))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_BUTTON)          |  \
                                     PIN_ODR_HIGH(GPIOA_LRCK)            |  \
                                     PIN_ODR_HIGH(GPIOA_SPC)             |  \
                                     PIN_ODR_HIGH(GPIOA_SDO)             |  \
                                     PIN_ODR_HIGH(GPIOA_SDI)             |  \
                                     PIN_ODR_HIGH(GPIOA_VBUS_FS)         |  \
                                     PIN_ODR_HIGH(GPIOA_OTG_FS_ID)       |  \
                                     PIN_ODR_HIGH(GPIOA_OTG_FS_DM)       |  \
                                     PIN_ODR_HIGH(GPIOA_OTG_FS_DP)       |  \
                                     PIN_ODR_HIGH(GPIOA_SWDIO)           |  \
                                     PIN_ODR_HIGH(GPIOA_SWCLK))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_LRCK, 6)          |  \
                                     PIN_AFIO_AF(GPIOA_SPC, 5)           |  \
                                     PIN_AFIO_AF(GPIOA_SDO, 5)           |  \
                                     PIN_AFIO_AF(GPIOA_SDI, 5))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_OTG_FS_ID, 10)    |  \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DM, 10)    |  \
                                     PIN_AFIO_AF(GPIOA_OTG_FS_DP, 10)    |  \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0)         |  \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0))

/*
 * GPIOB setup:
 * All input with pull-up except:
 * PB3  - SWO                       (alternate 0).
 * PB6  - SCL                       (alternate 4).
 * PB9  - SDA                       (alternate 4).
 * PB10 - CLK_IN                    (input pullup).

 */
#define VAL_GPIOB_MODER             (PIN_MODE_ALTERNATE(GPIOB_SWO)      |  \
                                     PIN_MODE_ALTERNATE(GPIOB_SCL)      |  \
                                     PIN_MODE_ALTERNATE(GPIOB_SDA)      |  \
                                     PIN_MODE_INPUT(GPIOB_CLK_IN))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_SWO)      |  \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_SCL)     |  \
                                     PIN_OTYPE_OPENDRAIN(GPIOB_SDA)     |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_CLK_IN))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_HIGH(GPIOB_SWO)         |  \
                                     PIN_OSPEED_HIGH(GPIOB_SCL)         |  \
                                     PIN_OSPEED_HIGH(GPIOB_SDA)         |  \
                                     PIN_OSPEED_HIGH(GPIOB_CLK_IN))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(GPIOB_SWO)      |  \
                                     PIN_PUPDR_FLOATING(GPIOB_SCL)      |  \
                                     PIN_PUPDR_FLOATING(GPIOB_SDA)      |  \
                                     PIN_PUPDR_PULLUP(GPIOB_CLK_IN))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_SWO)            |  \
                                     PIN_ODR_HIGH(GPIOB_SCL)            |  \
                                     PIN_ODR_HIGH(GPIOB_SDA)            |  \
                                     PIN_ODR_HIGH(GPIOB_CLK_IN))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_SWO, 0)          |  \
                                     PIN_AFIO_AF(GPIOB_SCL, 4))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_SDA, 4)          |  \
                                     PIN_AFIO_AF(GPIOB_CLK_IN, 0))

/*
 * GPIOC setup:
 * All input with pull-up except:
  * PC0  - OTG_FS_POWER_ON           (output pushpull maximum).
  * PC3  - PDM_OUT                   (input pullup).
  * PC6  - GPIOC_U_L                 (alternate 2).
  * PC7  - GPIOC_V_L                 (alternate 2).
  * PC8  - GPIOC_W_L                 (alternate 2).
  * PC10 - SCLK                      (alternate 6).
  * PC12 - SDIN                      (alternate 6).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_OUTPUT(GPIOC_OTG_FS_POWER_ON) | \
                                     PIN_MODE_INPUT(GPIOC_PDM_OUT)          | \
                                     PIN_MODE_ALTERNATE(GPIOC_U_L)          | \
                                     PIN_MODE_ALTERNATE(GPIOC_V_L)          | \
                                     PIN_MODE_ALTERNATE(GPIOC_W_L)          | \
                                     PIN_MODE_ALTERNATE(GPIOC_SCLK)         | \
                                     PIN_MODE_ALTERNATE(GPIOC_SDIN))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_OTG_FS_POWER_ON) | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PDM_OUT)      | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SCLK)         | \
                                     PIN_OTYPE_PUSHPULL(GPIOC_SDIN))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_HIGH(GPIOC_OTG_FS_POWER_ON) | \
                                     PIN_OSPEED_HIGH(GPIOC_PDM_OUT)         | \
                                     PIN_OSPEED_HIGH(GPIOC_U_L)             | \
                                     PIN_OSPEED_HIGH(GPIOC_V_L)             | \
                                     PIN_OSPEED_HIGH(GPIOC_W_L)             | \
                                     PIN_OSPEED_HIGH(GPIOC_SCLK)            | \
                                     PIN_OSPEED_HIGH(GPIOC_SDIN))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_FLOATING(GPIOC_OTG_FS_POWER_ON) | \
                                     PIN_PUPDR_PULLUP(GPIOC_PDM_OUT)        | \
                                     PIN_PUPDR_FLOATING(GPIOC_SCLK)         | \
                                     PIN_PUPDR_FLOATING(GPIOC_SDIN))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(GPIOC_OTG_FS_POWER_ON)    | \
                                     PIN_ODR_HIGH(GPIOC_PDM_OUT)            | \
                                     PIN_ODR_HIGH(GPIOC_SCLK)               | \
                                     PIN_ODR_HIGH(GPIOC_SDIN))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_OTG_FS_POWER_ON, 0)  | \
                                     PIN_AFIO_AF(GPIOC_PDM_OUT, 0)          | \
                                     PIN_AFIO_AF(GPIOC_U_L, 2)              | \
                                     PIN_AFIO_AF(GPIOC_V_L, 2))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_W_L, 2)              | \
                                     PIN_AFIO_AF(GPIOC_SCLK, 6)             | \
                                     PIN_AFIO_AF(GPIOC_SDIN, 6))

/*
 * GPIOD setup:
 * All input with pull-up except:
 * PD4  - RESET                     (output pushpull maximum).
 * PD5  - OVER_CURRENT              (input floating).
 * PD12 - GPIOD_U_H                 (alternate 2).
 * PD13 - GPIOD_V_H                 (alternate 2).
 * PD14 - GPIOD_W_H                 (alternate 2).
 * PD15 - GPIOD_LED6                (input).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_OUTPUT(GPIOD_RESET)           | \
                                     PIN_MODE_INPUT(GPIOD_OVER_CURRENT)     | \
                                     PIN_MODE_ALTERNATE(GPIOD_U_H)          | \
                                     PIN_MODE_ALTERNATE(GPIOD_V_H)          | \
                                     PIN_MODE_ALTERNATE(GPIOD_W_H)          | \
                                     PIN_MODE_OUTPUT(GPIOD_LED6))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_RESET)        | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_OVER_CURRENT) | \
                                     PIN_OTYPE_PUSHPULL(GPIOD_LED6))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_HIGH(GPIOD_RESET)           | \
                                     PIN_OSPEED_HIGH(GPIOD_OVER_CURRENT)    | \
                                     PIN_OSPEED_HIGH(GPIOD_U_H)             | \
                                     PIN_OSPEED_HIGH(GPIOD_V_H)             | \
                                     PIN_OSPEED_HIGH(GPIOD_W_H)             | \
                                     PIN_OSPEED_HIGH(GPIOD_LED6))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_FLOATING(GPIOD_RESET)        | \
                                     PIN_PUPDR_FLOATING(GPIOD_OVER_CURRENT) | \
                                     PIN_PUPDR_FLOATING(GPIOD_LED6))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_RESET)              | \
                                     PIN_ODR_HIGH(GPIOD_OVER_CURRENT)       | \
                                     PIN_ODR_LOW(GPIOD_LED6))
#define VAL_GPIOD_AFRL              0x00000000
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_U_H, 2)             | \
                                     PIN_AFIO_AF(GPIOD_V_H, 2)             | \
                                     PIN_AFIO_AF(GPIOD_W_H, 2))

/*
 * GPIOE setup:
 * All input with pull-up except:
 * PE0  - INT1                      (input floating).
 * PE1  - INT2                      (input floating).
 * PE3  - CS_SPI                    (output pushpull maximum).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(GPIOE_INT1)            | \
                                     PIN_MODE_INPUT(GPIOE_INT2)            | \
                                     PIN_MODE_OUTPUT(GPIOE_CS_SPI))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_INT1)        | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_INT2)        | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_CS_SPI))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_HIGH(GPIOE_INT1)           | \
                                     PIN_OSPEED_HIGH(GPIOE_INT2)           | \
                                     PIN_OSPEED_HIGH(GPIOE_CS_SPI))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_FLOATING(GPIOE_INT1)        | \
                                     PIN_PUPDR_FLOATING(GPIOE_INT2)        | \
                                     PIN_PUPDR_FLOATING(GPIOE_CS_SPI))
#define VAL_GPIOE_ODR               (PIN_ODR_HIGH(GPIOE_INT1)              | \
                                     PIN_ODR_HIGH(GPIOE_INT2)              | \
                                     PIN_ODR_HIGH(GPIOE_CS_SPI))
#define VAL_GPIOE_AFRL              0x00000000
#define VAL_GPIOE_AFRH              0x00000000

/*
 * GPIOF setup:
 * All input with pull-up except:
 */
#define VAL_GPIOF_MODER             0x00000000
#define VAL_GPIOF_OTYPER            0x00000000
#define VAL_GPIOF_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOF_PUPDR             0xFFFFFFFF
#define VAL_GPIOF_ODR               0xFFFFFFFF
#define VAL_GPIOF_AFRL              0x00000000
#define VAL_GPIOF_AFRH              0x00000000

/*
 * GPIOG setup:
 * All input with pull-up except:
 */
#define VAL_GPIOG_MODER             0x00000000
#define VAL_GPIOG_OTYPER            0x00000000
#define VAL_GPIOG_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOG_PUPDR             0xFFFFFFFF
#define VAL_GPIOG_ODR               0xFFFFFFFF
#define VAL_GPIOG_AFRL              0x00000000
#define VAL_GPIOG_AFRH              0x00000000

/*
 * Port H setup.
 * All input with pull-up except:
 * PH0 - OSC_IN                     (input floating).
 * PH1 - OSC_OUT                    (input floating).
 */
#define VAL_GPIOH_MODER             (PIN_MODE_INPUT(GPIOH_OSC_IN)       | \
                                     PIN_MODE_INPUT(GPIOH_OSC_OUT))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN)   | \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_HIGH(GPIOH_OSC_IN)      | \
                                     PIN_OSPEED_HIGH(GPIOH_OSC_OUT))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN)   | \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT))
#define VAL_GPIOH_ODR               (PIN_ODR_HIGH(GPIOH_OSC_IN)         | \
                                     PIN_ODR_HIGH(GPIOH_OSC_OUT))
#define VAL_GPIOH_AFRL              0x00000000
#define VAL_GPIOH_AFRH              0x00000000

/*
 * GPIOI setup:
 * All input with pull-up except:
 */
#define VAL_GPIOI_MODER             0x00000000
#define VAL_GPIOI_OTYPER            0x00000000
#define VAL_GPIOI_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOI_PUPDR             0xFFFFFFFF
#define VAL_GPIOI_ODR               0xFFFFFFFF
#define VAL_GPIOI_AFRL              0x00000000
#define VAL_GPIOI_AFRH              0x00000000


#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
