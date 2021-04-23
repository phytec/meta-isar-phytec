# Common settings for phytecs imx6ul boards

require conf/machine/include/utilities.inc

DISTRO_ARCH = "armhf"

MACHINE_SERIAL ?= "ttymxc0"
BAUDRATE_TTY ?= "115200"

# Kernel
PREFERRED_PROVIDER_virtual/kernel ?= "linux-mainline"
KERNEL_IMAGETYPE ?= "zImage"
KERNEL_NAME ?= "mainline"
PREFERRED_VERSION_linux-mainline ?= "4.14.93%"

OVERRIDES .= ":mx6:mx6ul"

OVERRIDES .= ":armv7ve"

# cpu feature overwrite support
OVERRIDES .= ":imxpxp"

OVERRIDES .= ":imxfbdev:imxpxp"

MACHINE_FEATURES = "apm usbgadget usbhost vfat"

QT_QPA_PLATFORM ?= "linuxfb"

#WIC
IMAGE_BOOT_FILES = "zImage oftree ${@make_dtb_boot_files(d)}"
WKS_FILE_mx6ul ?= "imx6-sdimage.wks"

IMAGER_BUILD_DEPS += "barebox"

# default images to build
#IMAGE_TYPE ?= "targz-img"
#IMAGE_TYPE ?= "wic-img"

# Use the expected value of the ubifs filesystem's volume name in the kernel
UBI_VOLNAME = "root"
# The biggest NANDs on current modules are 1GB. With current partition layout,
# this sums up to 7943 LEBs available for the ubifs
MKUBIFS_ARGS := "-F -m 2048 -e 126976 -c 7943"
UBINIZE_ARGS = "-m 2048 -p 128KiB -s 2048 -O 2048"
IMAGE_TYPE ?= "ubi-fs-img"
