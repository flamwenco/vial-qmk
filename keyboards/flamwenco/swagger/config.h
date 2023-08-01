// Copyright 2023 Dan Muckerman (@Flamwenco)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE

#define RGBLIGHT_LED_MAP { 0, 1, 4, 5, 2, 3, 6, 7 }