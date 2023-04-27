/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7FF7
#define PRODUCT_ID      0x3D14
#define DEVICE_VER      0x0001
#define MANUFACTURER    flamwenco
#define PRODUCT         pi0ii040

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { 28, 27, 20, 18 }
#define MATRIX_COL_PINS { 21, 3, 4, 5, 2, 1, 0, 15, 14, 13, 12, 11 }

#define DIODE_DIRECTION COL2ROW

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
