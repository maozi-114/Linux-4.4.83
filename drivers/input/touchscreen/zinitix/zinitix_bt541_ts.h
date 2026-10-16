/*
 *
 * Zinitix bt532 touch driver
 *
 * Copyright (C) 2013 Samsung Electronics Co.Ltd
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 */


#ifndef _LINUX_BT541_TS_H
#define _LINUX_BT541_TS_H

#define TS_DRVIER_VERSION	"1.0.18_1"

#define BT541_TS_DEVICE		"bt541_ts_device"

/*
 * SL8541E (GM01) port: the 4.4.83 input-event-codes.h stops at
 * ABS_MT_TOOL_Y (0x3d) and does not define ABS_MT_PALM.  Provide it
 * here so the driver's palm-touch reporting path compiles.
 */
#ifndef ABS_MT_PALM
#define ABS_MT_PALM		0x3e
#endif

#include <linux/input/tsp_ta_callback.h>

/*
 * SL8541E (GM01) port: single firmware image, no Samsung project macros.
 * The DT node on this platform only carries the generic Zinitix properties
 * (zinitix,x_resolution / y_resolution / page_size / orientation / irq-gpio
 * / pname), so the "fortuna" multi-firmware / touch-key path is not used.
 */
#include "a3c_fw.h"
#define CONFIG_DATE "1124"
#define TSP_TYPE_COUNT	1

/* #define GLOVE_MODE */
#define SUPPORTED_PALM_TOUCH

 /*Test Mode (Monitoring Raw Data) */
#define SEC_DND_N_COUNT			2
#define SEC_DND_U_COUNT			4
#define SEC_DND_FREQUENCY		44 /* 400khz */
#define SEC_PDND_N_COUNT		16
#define SEC_PDND_U_COUNT		32
#define SEC_PDND_FREQUENCY		44


#define zinitix_debug_msg(fmt, args...) \
	do { \
		if (m_ts_debug_mode) \
			printk(KERN_INFO "bt541_ts[%-18s:%5d] " fmt, \
					__func__, __LINE__, ## args); \
	} while (0);

#define zinitix_printk(fmt, args...) \
	do { \
		printk(KERN_INFO "bt541_ts[%-18s:%5d] " fmt, \
				__func__, __LINE__, ## args); \
	} while (0);

#define bt541_err(fmt) \
	do { \
		pr_err("bt541_ts : %s " fmt, __func__); \
	} while (0);

struct bt541_ts_platform_data {
	int		gpio_int;
	//u32		gpio_scl;
	//u32		gpio_sda;
	//u32		gpio_ldo_en;
	u32		tsp_irq;
#ifdef SUPPORTED_TOUCH_KEY_LED
	int		gpio_keyled;
#endif
	int		tsp_vendor1;
	int		tsp_vendor2;
	int		tsp_en_gpio;
	u32		tsp_supply_type;
	//int (*tsp_power)(int on);
	u16		x_resolution;
	u16		y_resolution;
	u16		page_size;
	u8		orientation;
	const char      *pname;
#ifdef USE_TSP_TA_CALLBACKS
	void (*register_cb) (struct tsp_callbacks *);
	struct tsp_callbacks callbacks;
#endif
	
};

#endif /* LINUX_BT541_TS_H */
