# Common settings for phytecs imx6ul boards

DISTRO_ARCH = "armhf"

MACHINE_SERIAL ?= "ttymxc0"
BAUDRATE_TTY ?= "115200"

# Kernel
PREFERRED_PROVIDER_virtual/kernel ?= "linux-mainline"
KERNEL_NAME ?= "mainline"
PREFERRED_VERSION_linux-mainline ?= "4.14.93%"

# cpu feature overwrite support
OVERRIDES .= ":imxpxp"

OVERRIDES .= ":imxfbdev:imxpxp"

MACHINE_FEATURES = "apm usbgadget usbhost vfat"

QT_QPA_PLATFORM ?= "linuxfb"

# default images to build
IMAGE_TYPE ?= "targz-img"
