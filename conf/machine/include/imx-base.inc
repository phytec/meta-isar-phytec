# Provides the i.MX common settings

require conf/machine/include/utilities.inc

# Set specific make target and binary suffix
IMX_DEFAULT_BOOTLOADER = "u-boot-fslc"
IMX_DEFAULT_BOOTLOADER_mx8 = "u-boot-imx"

PREFERRED_PROVIDER_u-boot ??= "${IMX_DEFAULT_BOOTLOADER}"
PREFERRED_PROVIDER_virtual/bootloader ??= "${IMX_DEFAULT_BOOTLOADER}"

PREFERRED_PROVIDER_u-boot-mxsboot-native ??= "u-boot-fslc-mxsboot-native"

UBOOT_BINARY ?= "u-boot.${UBOOT_SUFFIX}"
UBOOT_MAKE_TARGET ?= "u-boot.${UBOOT_SUFFIX}"
UBOOT_MAKE_TARGET_mxs ?= "u-boot.sb"
UBOOT_MAKE_TARGET_mx8 ?= ""

UBOOT_SUFFIX ?= "imx"
UBOOT_SUFFIX_mxs ?= "sb"
UBOOT_SUFFIX_mx8 ?= "bin"

UBOOT_ENTRYPOINT_mxs = "0x40008000"
UBOOT_ENTRYPOINT_mx51  = "0x90008000"
UBOOT_ENTRYPOINT_mx53  = "0x70008000"
UBOOT_ENTRYPOINT_mx6  = "0x10008000"
UBOOT_ENTRYPOINT_mx6sl = "0x80008000"
UBOOT_ENTRYPOINT_mx6sll = "0x80008000"
UBOOT_ENTRYPOINT_mx6sx = "0x80008000"
UBOOT_ENTRYPOINT_mx6ul  = "0x10008000"
UBOOT_ENTRYPOINT_mx6ull  = "0x10008000"
UBOOT_ENTRYPOINT_mx7 = "0x80008000"
UBOOT_ENTRYPOINT_mx7ulp = "0x60008000"
UBOOT_ENTRYPOINT_mx8mm  = "0x40480000"
UBOOT_ENTRYPOINT_mx8mn  = "0x40480000"
UBOOT_ENTRYPOINT_mx8mq  = "0x40480000"
UBOOT_ENTRYPOINT_vf = "0x80008000"

PREFERRED_PROVIDER_virtual/xserver = "xserver-xorg"
XSERVER_DRIVER                  = "xf86-video-fbdev"
XSERVER_DRIVER_imxgpu2d         = "xf86-video-imx-vivante"
XSERVER_DRIVER_vf               = "xf86-video-modesetting"
XSERVER_DRIVER_append_mx8       = " xf86-video-modesetting"
XSERVER_DRIVER_use-mainline-bsp = "xf86-video-armada"
XSERVER = "xserver-xorg \
           xf86-input-evdev \
           ${XSERVER_DRIVER}"

# Ship kernel modules
MACHINE_EXTRA_RRECOMMENDS = "kernel-modules"

# Firmware
MACHINE_FIRMWARE ?= ""
MACHINE_FIRMWARE_append_mx25 = " firmware-imx-sdma-imx25"
MACHINE_FIRMWARE_append_mx7d = " linux-firmware-imx-sdma-imx7d firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6 = " linux-firmware-imx-sdma-imx6q"
MACHINE_FIRMWARE_append_mx6q = " firmware-imx-vpu-imx6q"
MACHINE_FIRMWARE_append_mx6dl = " firmware-imx-vpu-imx6d firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6sl = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6sll = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6ull = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx53 = " firmware-imx-vpu-imx53 firmware-imx-sdma-imx53"
MACHINE_FIRMWARE_append_mx51 = " firmware-imx-vpu-imx51 firmware-imx-sdma-imx51"
MACHINE_FIRMWARE_append_mx8qxp = " firmware-imx-vpu-imx8qxp"
MACHINE_FIRMWARE_append_use-mainline-bsp = " linux-firmware-imx-sdma-imx6q linux-firmware-imx-sdma-imx7d firmware-imx-vpu-imx6q firmware-imx-vpu-imx6d"

# FIXME: Needs addition of firmware-imx of official BSPs
#MACHINE_FIRMWARE_append_mx27 = " firmware-imx-vpu-imx27"

MACHINE_EXTRA_RRECOMMENDS += "${MACHINE_FIRMWARE}"

# Extra audio support
MACHINE_EXTRA_RRECOMMENDS_append_mx6 = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx7 = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx8 = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"

# Extra QCA Wi-Fi & BTE driver and firmware
MACHINE_EXTRA_RRECOMMENDS_append = " ${@bb.utils.contains('MACHINE_FEATURES', 'qca6174', 'packagegroup-fsl-qca6174', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append = " ${@bb.utils.contains('MACHINE_FEATURES', 'qca9377', 'packagegroup-fsl-qca9377', '', d)}"

# Extra udev rules
MACHINE_EXTRA_RRECOMMENDS += "udev-rules-imx"

# GStreamer 1.0 plugins
MACHINE_GSTREAMER_1_0_PLUGIN ?= ""
MACHINE_GSTREAMER_1_0_PLUGIN_mx6dl ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6q ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6sl ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6sx ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6ul ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6ull ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx7d ?= "gstreamer1.0-plugins-imx-meta"

# Determines if the SoC has support for Vivante kernel driver
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT        = "0"
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT_imxgpu = "1"

# Handle Vivante kernel driver setting:
#   0 - machine does not have Vivante GPU driver support
#   1 - machine has Vivante GPU driver support
MACHINE_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT ?= "${SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT}"

# Graphics libraries
PREFERRED_PROVIDER_virtual/egl      ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl    ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1 ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2 ?= "mesa"

PREFERRED_PROVIDER_virtual/egl_imxgpu        ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgl_imxgpu3d    ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_imxgpu3d ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles2_imxgpu3d ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libg2d            ?= "imx-gpu-g2d"
PREFERRED_PROVIDER_virtual/libg2d_imxdpu     ?= "imx-dpu-g2d"

PREFERRED_VERSION_weston_mx6 ?= "5.0.0.imx"
PREFERRED_VERSION_weston_mx7 ?= "5.0.0.imx"
PREFERRED_VERSION_weston_mx8 ?= "5.0.0.imx"

PREFERRED_VERSION_wayland-protocols_mx6 ?= "1.17.imx"
PREFERRED_VERSION_wayland-protocols_mx7 ?= "1.17.imx"
PREFERRED_VERSION_wayland-protocols_mx8 ?= "1.17.imx"

# Use i.MX libdrm Version
PREFERRED_VERSION_libdrm_mx6 ?= "2.4.91.imx"
PREFERRED_VERSION_libdrm_mx7 ?= "2.4.91.imx"
PREFERRED_VERSION_libdrm_mx8 ?= "2.4.91.imx"

# Use i.MX optee Version
PREFERRED_VERSION_optee-os_mx8     ?= "3.2.0.imx"
PREFERRED_VERSION_optee-client_mx8 ?= "3.2.0.imx"
PREFERRED_VERSION_optee-test_mx8   ?= "3.2.0.imx"

# Handle default kernel
IMX_DEFAULT_KERNEL = "linux-imx"
IMX_DEFAULT_KERNEL_mxs = "linux-fslc"
IMX_DEFAULT_KERNEL_mx5 = "linux-fslc"
IMX_DEFAULT_KERNEL_mx6 = "linux-fslc-imx"
IMX_DEFAULT_KERNEL_mx7 = "linux-fslc-imx"
IMX_DEFAULT_KERNEL_mx8 = "linux-imx"
IMX_DEFAULT_KERNEL_mx7ulp = "linux-imx"
IMX_DEFAULT_KERNEL_mx6sll = "linux-imx"
IMX_DEFAULT_KERNEL_mx6ul = "linux-fslc-imx"
IMX_DEFAULT_KERNEL_mx6ull = "linux-fslc-imx"
IMX_DEFAULT_KERNEL_use-mainline-bsp = "linux-fslc"

PREFERRED_PROVIDER_virtual/kernel ??= "${IMX_DEFAULT_KERNEL}"

SOC_DEFAULT_IMAGE_FSTYPES = "wic.bmap wic.gz"
SOC_DEFAULT_IMAGE_FSTYPES_mxs = "uboot-mxsboot-sdcard wic.gz"

# Do not update fstab file when using wic images
WIC_CREATE_EXTRA_ARGS ?= "--no-fstab-update"

OPTEE_BOOT_IMAGE         = "uTee"
OPTEE_BOOT_IMAGE_aarch64 = ""

IMAGE_FSTYPES ?= "${SOC_DEFAULT_IMAGE_FSTYPES}"

IMAGE_BOOT_FILES ?= " \
    ${KERNEL_IMAGETYPE} \
    ${@make_dtb_boot_files(d)} \
    ${@bb.utils.contains('MACHINE_FEATURES', 'optee', '${OPTEE_BOOT_IMAGE}', '', d)} \
"

### wic default support
OPTEE_WKS_FILE_DEPENDS         = "optee-os"
OPTEE_WKS_FILE_DEPENDS_aarch64 = ""

WKS_FILE_DEPENDS ?= " \
    virtual/bootloader \
    \
    ${@bb.utils.contains('MACHINE_FEATURES', 'optee', '${OPTEE_WKS_FILE_DEPENDS}', '', d)} \
"

WKS_FILE_DEPENDS_append_mx8 = " imx-boot "

IMAGER_BUILD_DEPS += "${WKS_FILE_DEPENDS}"

SOC_DEFAULT_WKS_FILE ?= "imx-uboot-bootpart.wks.in"
SOC_DEFAULT_WKS_FILE_mx8 ?= "imx-imx-boot-bootpart.wks.in"
SOC_DEFAULT_WKS_FILE_mxs ?= "imx-uboot-mxs-bootpart.wks.in"

WKS_FILE ?= "${SOC_DEFAULT_WKS_FILE}"

# Certain machines override the default fsl u-boot with the
# fslc u-boot. To restore the fsl u-boot, add use-fsl-bsp like this:
#   MACHINEOVERRIDES_prepend_imx6ulevk = "use-fsl-bsp:"
UBOOT_MAKE_TARGET_use-fsl-bsp_mx6 = "u-boot.imx"
UBOOT_SUFFIX_use-fsl-bsp_mx6 = "imx"
SPL_BINARY_use-fsl-bsp_mx6 = ""
WKS_FILE_use-fsl-bsp_mx6 = "imx-uboot-bootpart.wks.in"
UBOOT_MAKE_TARGET_use-fsl-bsp_mx7 = "u-boot.imx"
UBOOT_SUFFIX_use-fsl-bsp_mx7 = "imx"
SPL_BINARY_use-fsl-bsp_mx7 = ""
WKS_FILE_use-fsl-bsp_mx7 = "imx-uboot-bootpart.wks.in"

MACHINE_SERIAL = "ttymxc0"
MACHINE_SERIAL_mxs = "ttyAMA0"
BAUDRATE_TTY = "115200"

KERNEL_IMAGETYPE = "zImage"
KERNEL_IMAGETYPE_aarch64 = "Image"

MACHINE_FEATURES = "usbgadget usbhost vfat alsa touchscreen"

# Add the ability to specify _imx machines
OVERRIDES =. "imx:"
