/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define BOARD_INFO_NAME "BTT SKR CR-6"

//
// EEPROM
//
/* I2C */
#define IIC_EEPROM_SDA       PB7
#define IIC_EEPROM_SCL       PB6

#define I2C_EEPROM
#define MARLIN_EEPROM_SIZE 0x1000                 // 4KB
#define E2END                (MARLIN_EEPROM_SIZE - 1) // 2KB

#define X_MIN_PIN          PC0
// #define X_MAX_PIN          PA7
#define Y_MIN_PIN          PC1

//
// Steppers
//
#define X_ENABLE_PIN        PB14
#define X_STEP_PIN          PB13
#define X_DIR_PIN           PB12

#define Y_ENABLE_PIN        PB11
#define Y_STEP_PIN          PB10
#define Y_DIR_PIN           PB2

//#define Z_ENABLE_PIN        PA0
#define Z_ENABLE_PIN        PB1
#define Z_STEP_PIN          PB0
#define Z_DIR_PIN           PC5

#define E0_ENABLE_PIN       PD2
#define E0_STEP_PIN         PB3
#define E0_DIR_PIN          PB4

#ifdef BLTOUCH
  #error "Not supported"
#elif ENABLED(FIX_MOUNTED_PROBE)
  #define Z_MIN_PIN        PC14
  #define COM_PIN          PA1//PA1
#else
  #error "Not supported"
#endif

//
// Release PB4 (Z_STEP_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

//
// Temperature Sensors
//
#define TEMP_0_PIN         PA0   // TH1
#define TEMP_BED_PIN       PC3   // TB1

#define HEATER_0_PIN       PC8   // HEATER1
#define HEATER_BED_PIN     PC9   // HOT BED

#define FAN_PIN            PC6   // FAN
#define FAN_SOFT_PWM

#define CONTROLLER_FAN_PIN  PC7

#if ENABLED(CR10_STOCKDISPLAY)

    #define BTN_ENC            PA15
    #define BTN_EN1            PA9
    #define BTN_EN2            PA10

    #define LCD_PINS_RS        PB8
    #define LCD_PINS_ENABLE    PB15
    #define LCD_PINS_D4        PB9

    #define BEEPER_PIN          PB5

#endif

//
// USB connect control
//
#define USB_CONNECT_PIN    PA14
#define USB_CONNECT_INVERTING false

#define LED_CONTROL_PIN    PA13
#define FIL_RUNOUT_PIN     PC15

#define OPTO_SWITCH_PIN    PC2

#define HAS_ONBOARD_SD

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION ONBOARD
#endif

#define ON_BOARD_SPI_DEVICE 1    // SPI1
#define ONBOARD_SD_CS_PIN  PA4   // Chip select for "System" SD card
/* SD card detect */
#define SD_DETECT_PIN      PC4
#define NEOPIXEL_PIN       PA8     

/**
 * TMC2209 stepper drivers
 * Hardware serial communication ports.
 */
#if HAS_TMC220x

  //
  // TMC2208 mode
  //
  // #define TMC2208_STANDALONE

  #define X_HARDWARE_SERIAL  MSerial4
  #define Y_HARDWARE_SERIAL  MSerial4
  #define Z_HARDWARE_SERIAL  MSerial4
  #define E0_HARDWARE_SERIAL MSerial4

  //
  // TMC2208 Software serial
  //
  // #define HAVE_SW_SERIAL

  // Reduce baud rate to improve software serial reliability
  // #define TMC_BAUD_RATE 19200

#endif