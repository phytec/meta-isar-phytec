# Copyright (C) 2019 PHYTEC Messtechnik GmbH,
# Author: Teresa Remmet <t.remmet@phytec.de>
# Adopted to Isar: Anton Mikanovich <amikan@ilbers.de>

inherit phygittag
inherit buildinfo
inherit fsl-vivante-kernel-driver-handler
include linux-common.inc

BRANCH = "v5.10.72_2.2.0-phy"
GIT_URL = "git://git.phytec.de/${PN}"
SRC_URI += "${GIT_URL};branch=${BRANCH}"
PR = "${INC_PR}.0"

# Fix for make dtbs_install issue
SRC_URI += "file://0001-dtbsinstall-fix-installing-DT-overlays.patch"

#Disable LVDS 1 on pollux board for HDMI to work
SRC_URI += "file://0001-Disable-LVDS-1-on-pollux.patch"

#Disable HDMI Audio on pollux board
SRC_URI += "file://0001-Deactivate-HDMI-Audio.patch"

LINUX_VERSION_EXTENSION = "-isar"

# NOTE: PV must be in the format "x.y.z-.*". It cannot begin with a 'v'.
# NOTE: Keep version in filename in sync with commit id!
SRCREV = "9a950ff6e47215a00c91ca7ee146ec855076a21c"

S = "${WORKDIR}/git"

KERNEL_DEFCONFIG = "imx_v8_defconfig imx8_phytec_distro.config imx8_phytec_platform.config"

COMPATIBLE_MACHINE  = "^("
COMPATIBLE_MACHINE .= "phyboard-polaris-imx8m-3"
COMPATIBLE_MACHINE .= "|phyboard-polis-imx8mm-4"
COMPATIBLE_MACHINE .= "|phyboard-pollux-imx8mp-3"
COMPATIBLE_MACHINE .= "|phygate-tauri-imx8mm-1"
COMPATIBLE_MACHINE .= "|phygate-tauri-imx8mm-2"
COMPATIBLE_MACHINE .= ")$"
