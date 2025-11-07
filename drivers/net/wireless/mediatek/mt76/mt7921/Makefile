# SPDX-License-Identifier: ISC

# Common (bus-independent) objects
mt7921-common-y := mac.o mcu.o main.o init.o debugfs.o
# Trace optional; disable initially on 5.4 if incompatibilities arise
mt7921-common-$(CONFIG_MT76_TRACE) += trace.o
# Testmode optional
mt7921-common-$(CONFIG_MT7921_TESTMODE) += testmode.o
# ACPI SAR optional
mt7921-common-$(CONFIG_MT7921_ACPI_SAR) += acpi_sar.o

# Bus variants
mt7921e-y := pci.o pci_mac.o pci_mcu.o dma.o
mt7921s-y := sdio.o sdio_mac.o sdio_mcu.o
mt7921u-y := usb.o usb_mac.o

obj-$(CONFIG_MT7921_COMMON) += mt7921-common.o
obj-$(CONFIG_MT7921E)      += mt7921e.o
obj-$(CONFIG_MT7921S)      += mt7921s.o
obj-$(CONFIG_MT7921U)      += mt7921u.o

# Include path for trace (if kept)
CFLAGS_trace.o := -I$(src)