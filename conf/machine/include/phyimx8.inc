# Common settings for PHYTEC's i.MX8 boards

DISTRO_ARCH ?= "arm64"

# Wic
EXTERNAL_KERNEL_DEVICETREE ??= ""
IMAGE_BOOT_FILES += "oftree ${EXTERNAL_KERNEL_DEVICETREE} bootenv.txt"
IMAGER_BUILD_DEPS += "phytec-bootenv"
WKS_FILE_mx8 ?= "imx8-sdimage.wks"
WKS_FILE_mx8m ?= "imx8m-sdimage.wks"
WKS_FILE_mx8mn ?= "imx8mn-sdimage.wks"
WKS_FILE_mx8mp ?= "imx8mn-sdimage.wks"

# Default images to build
IMAGE_FSTYPES_mx8 = "wic tar.gz"
