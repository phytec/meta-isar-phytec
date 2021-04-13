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

# default images to build
#IMAGE_TYPE ?= "targz-img"
IMAGE_TYPE ?= "wic-img"
