/* arch/arm/mach-msm/keypad-urushi.c
 *
 * Copyright (C) [2010] Sony Ericsson Mobile Communications AB.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2, as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#include <linux/mfd/pmic8058.h>
#include "board-semc_mogami-keypad.h"

static const unsigned int pm8xxx_keymap[] = {
	KEY(0, 0, KEY_BACK),
	KEY(0, 1, KEY_HOME),
	KEY(0, 2, KEY_MENU),
	KEY(0, 3, KEY_VOLUMEUP),
	KEY(0, 4, KEY_VOLUMEDOWN),
};

static struct matrix_keymap_data pm8xxx_keymap_data = {
	.keymap_size	= ARRAY_SIZE(pm8xxx_keymap),
	.keymap		= pm8xxx_keymap,
};

static struct pm8xxx_keypad_platform_data pm8xxx_keypad_data = {
	.input_name		= PM8058_KEYPAD_DEV,
	.input_phys_device	= PM8058_KEYPAD_PHYS,
	.num_rows		= 1,
	.num_cols		= 7,
	.rows_gpio_start	= PM8058_GPIO_PM_TO_SYS(8),
	.cols_gpio_start	= PM8058_GPIO_PM_TO_SYS(0),
	.debounce_ms		= 10,
	.scan_delay_ms		= 2,
	.row_hold_ns		= 122000,
	.wakeup			= 1,
	.keymap_data		= &pm8xxx_keymap_data,
};

struct pm8xxx_keypad_platform_data *pm8xxx_keypad_pdata(void)
{
	return &pm8xxx_keypad_data;
}
