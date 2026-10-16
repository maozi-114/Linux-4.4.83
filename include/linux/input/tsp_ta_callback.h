/*
 * Minimal compatibility shim for the Zinitix BT541 touchscreen driver.
 *
 * The original Samsung driver depends on the Samsung "TSP TA callback"
 * framework.  The SL8541E (Spreadtrum) 4.4.83 tree does not provide it,
 * so we supply a minimal definition.  The callback path is disabled via
 * USE_TSP_TA_CALLBACKS not being defined, therefore only the type
 * declaration is required for compilation.
 */

#ifndef _LINUX_TSP_TA_CALLBACK_H
#define _LINUX_TSP_TA_CALLBACK_H

struct tsp_callbacks {
	void (*inform_charger)(struct tsp_callbacks *cb, int status);
};

#endif /* _LINUX_TSP_TA_CALLBACK_H */
