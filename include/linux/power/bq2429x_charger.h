/*
 * Definitions for BQ24296/7 battery charger.
 */
#ifndef BQ24296_H
#define BQ24296_H
#include <linux/power_supply.h>

/* I2C register define */
#define INPUT_SOURCE_CONTROL_REGISTER		0x00
#define POWER_ON_CONFIGURATION_REGISTER		0x01
#define CHARGE_CURRENT_CONTROL_REGISTER		0x02
#define PRE_CHARGE_TERMINATION_CURRENT_CONTROL_REGISTER		0x03
#define CHARGE_VOLTAGE_CONTROL_REGISTER		0x04
#define TERMINATION_TIMER_CONTROL_REGISTER		0x05
#define THERMAL_REGULATION_CONTROL_REGISTER		0x06
#define MISC_OPERATION_CONTROL_REGISTER		0x07
#define SYSTEM_STATS_REGISTER		0x08
#define FAULT_STATS_REGISTER		0x09
#define VENDOR_STATS_REGISTER		0x0A

/* input source control register value */
#define EN_HIZ_ENABLE	 1
#define EN_HIZ_DISABLE	 0
#define EN_HIZ_OFFSET	 7
#define EN_HIZ_MASK	 1

#define IINLIM_100MA		0
#define IINLIM_150MA		1
#define IINLIM_500MA		2
#define IINLIM_900MA		3
#define IINLIM_1200MA		4
#define IINLIM_1500MA		5
#define IINLIM_2000MA		6
#define IINLIM_3000MA		7
#define IINLIM_OFFSET		0
#define IINLIM_MASK		7

/* power-on configuration register value */
#define WATCHDOG_RESET	0x40

#define REGISTER_RESET_ENABLE	 1
#define REGISTER_RESET_DISABLE	 0
#define REGISTER_RESET_OFFSET	 7
#define REGISTER_RESET_MASK	 1

/* Charge Mode Config */
#define CHARGE_MODE_CONFIG_CHARGE_DISABLE	0x00
#define CHARGE_MODE_CONFIG_CHARGE_BATTERY	0x01
#define CHARGE_MODE_CONFIG_OTG_OUTPUT		0x02
#define CHARGE_MODE_CONFIG_OFFSET		4
#define CHARGE_MODE_CONFIG_MASK		0x03

#define SYS_MIN_OFFSET		1
#define SYS_MIN_MASK		0x7

/* OTG Mode Current Config */
#define OTG_MODE_CURRENT_CONFIG_500MA		0x00
#define OTG_MODE_CURRENT_CONFIG_1300MA	0x01
#define OTG_MODE_CURRENT_CONFIG_OFFSET	0
#define OTG_MODE_CURRENT_CONFIG_MASK		0x01

/* charge current limit register value */
#define CHARGE_CURRENT_64MA		0x01
#define CHARGE_CURRENT_128MA		0x02
#define CHARGE_CURRENT_256MA		0x04
#define CHARGE_CURRENT_512MA		0x08
#define CHARGE_CURRENT_1024MA		0x10
#define CHARGE_CURRENT_1536MA		0x18
#define CHARGE_CURRENT_2048MA		0x20
#define CHARGE_CURRENT_OFFSET		2
#define CHARGE_CURRENT_MASK		0x3f

/* Pre-Charge/Termination Current Control Register value */
/* Pre-Charge Current Limit */
#define PRE_CHARGE_CURRENT_LIMIT_128MA		0x00
#define PRE_CHARGE_CURRENT_LIMIT_256MA		0x01
#define PRE_CHARGE_CURRENT_LIMIT_OFFSET		4
#define PRE_CHARGE_CURRENT_LIMIT_MASK		0x0f
/* Termination Current Limit */
#define TERMINATION_CURRENT_LIMIT_128MA		0x00
#define TERMINATION_CURRENT_LIMIT_256MA		0x01
#define TERMINATION_CURRENT_LIMIT_OFFSET		0
#define TERMINATION_CURRENT_LIMIT_MASK		0x0f

/* Charge Termination/Timer control register value */
#define WATCHDOG_DISABLE		0
#define WATCHDOG_40S		1
#define WATCHDOG_80S		2
#define WATCHDOG_160S		3
#define WATCHDOG_OFFSET		4
#define WATCHDOG_MASK		3

/* boost voltage/thermal regulation register */
#define BOOSTV_OFFSET	4
#define BOOSTV_MASK	0xf

/* misc operation control register value */
#define DPDM_ENABLE	 1
#define DPDM_DISABLE	 0
#define DPDM_OFFSET	 7
#define DPDM_MASK	 1

/* system status register value */
#define VBUS_UNKNOWN		0
#define VBUS_USB_HOST		1
#define VBUS_ADAPTER_PORT		2
#define VBUS_OTG		3
#define VBUS_OFFSET		6
#define VBUS_MASK		3

#define CHRG_NO_CHARGING		0
#define CHRG_PRE_CHARGE		1
#define CHRG_FAST_CHARGE		2
#define CHRG_CHRGE_DONE		3
#define CHRG_OFFSET		4
#define CHRG_MASK		3

#define DPM_STAT	0x08
#define PG_STAT		0x04
#define THERM_STAT	0x02
#define VSYS_STAT	0x01

/* fault status register value */

#define WATCHDOG_FAULT	0x80
#define OTG_FAULT	0x40
#define CHRG_FAULT_OFFSET	4
#define CHRG_FAULT_MASK	0x3
#define BAT_FAULT	0x08
#define NTC_FAULT_OFFSET	0
#define NTC_FAULT_MASK	0x3

/* vendor status register value */
/* #define CHIP_BQ24190		0
#define CHIP_BQ24191		1
#define CHIP_BQ24192		2
#define CHIP_BQ24192I		3
#define CHIP_BQ24190_DEBUG		4
#define CHIP_BQ24192_DEBUG		5 */
#define CHIP_BQ24296		1
#define CHIP_BQ24297		3
#define CHIP_OFFSET		5
#define CHIP_MASK		7

#define BQ24296_CHG_COMPELET       0x03
#define BQ24296_NO_CHG             0x00

#define BQ24296_DC_CHG             0x02
#define BQ24296_USB_CHG            0x01

struct bq24296_platform_data {
	unsigned int otg_usb_pin;
	unsigned int chg_irq_pin;
	unsigned int psel_pin;
	int (*irq_init)(void);
};

struct bq24296_board {
	unsigned int otg_usb_pin;
	unsigned int chg_irq_pin;
	unsigned int chg_irq;
	unsigned int dc_det_pin;
	unsigned int psel_pin;
	unsigned int chg_current[3];
};

#endif


