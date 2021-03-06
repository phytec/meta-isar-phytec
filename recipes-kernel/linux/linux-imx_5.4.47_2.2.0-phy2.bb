# Copyright (C) 2019 PHYTEC Messtechnik GmbH,
# Author: Teresa Remmet <t.remmet@phytec.de>
# Adopted to Isar: Anton Mikanovich <amikan@ilbers.de>

inherit phygittag
inherit buildinfo
inherit fsl-vivante-kernel-driver-handler
include linux-common.inc

BRANCH = "v5.4.47_2.2.0-phy"
GIT_URL = "git://git.phytec.de/${PN}"
SRC_URI += "${GIT_URL};branch=${BRANCH}"
PR = "${INC_PR}.0"

LINUX_VERSION_EXTENSION = "-isar"

# NOTE: PV must be in the format "x.y.z-.*". It cannot begin with a 'v'.
# NOTE: Keep version in filename in sync with commit id!
SRCREV = "b292e2e1d9b447aa0d06410476de852b9a9ee5fa"

SRC_URI += "file://0001-arm64-dts-imx8mn-phyboard-polis-Fix-typo-in-Makefile.patch"

S = "${WORKDIR}/git"

KERNEL_DEFCONFIG = "imx_v8_defconfig imx8_phytec_distro.config imx8_phytec_platform.config"

COMPATIBLE_MACHINE  = "^("
COMPATIBLE_MACHINE .= "phyboard-polaris-imx8m-3"
COMPATIBLE_MACHINE .= "|phyboard-polis-imx8mm-3"
COMPATIBLE_MACHINE .= "|phyboard-polis-imx8mn-1"
COMPATIBLE_MACHINE .= "|phyboard-pollux-imx8mp-1"
COMPATIBLE_MACHINE .= "|phygate-tauri-imx8mm-1"
COMPATIBLE_MACHINE .= "|phygate-tauri-imx8mm-2"
COMPATIBLE_MACHINE .= ")$"
