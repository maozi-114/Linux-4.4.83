#
# Makefile for the Hynitron touchscreen driver (CST1xx)
#

obj-$(CONFIG_TOUCHSCREEN_HYNITRON_CST1XX) += hyn_ts.o

hyn_ts-objs := hyn_core.o
hyn_ts-objs += hyn_lib/hyn_i2c.o
hyn_ts-objs += hyn_lib/hyn_spi.o
hyn_ts-objs += hyn_lib/hyn_gesture.o
hyn_ts-objs += hyn_lib/hyn_prox.o
hyn_ts-objs += hyn_lib/hyn_fs_node.o
hyn_ts-objs += hyn_lib/hyn_tool.o
hyn_ts-objs += hyn_lib/hyn_ts_ext.o
hyn_ts-objs += hyn_chips/hyn_cst1xx.o

ccflags-y += -I$(src)
ccflags-y += -I$(src)/hyn_lib
ccflags-y += -I$(src)/hyn_chips
