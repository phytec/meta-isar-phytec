# Copyright (C) 2017 PHYTEC Messtechnik GmbH,
# Author: Stefan Riedmueller <s.riedmueller@phytec.de>
# Adopted to Isar: Anton Mikanovich <amikan@ilbers.de>

inherit phygittag
inherit buildinfo
include linux-common.inc

GIT_URL = "git://github.com/phytec/linux-phytec.git"
SRC_URI += "${GIT_URL};branch=${BRANCH}"
PR = "${INC_PR}.0"

# Fix for make dtbs_install issue
SRC_URI += "file://0001-dtbsinstall-fix-installing-DT-overlays.patch"

LINUX_VERSION_EXTENSION = "-isar"

# NOTE: PV must be in the format "x.y.z-.*". It cannot begin with a 'v'.
# NOTE: Keep version in filename in sync with commit id!
SRCREV = "a23e41360faa195dd1e6e16b4a9485710f9af08a"

S = "${WORKDIR}/git"

KERNEL_DEFCONFIG = "imx_v6_v7_defconfig imx6_phytec_distro.config imx6_phytec_machine.config imx6_phytec_platform.config"

COMPATIBLE_MACHINE = "phyboard-segin-imx6ul-2"
COMPATIBLE_MACHINE .= "|phyboard-segin-imx6ul-3"
COMPATIBLE_MACHINE .= "|phyboard-segin-imx6ul-4"
COMPATIBLE_MACHINE .= "|phyboard-segin-imx6ul-5"
COMPATIBLE_MACHINE .= "|phyboard-segin-imx6ul-6"
COMPATIBLE_MACHINE .= "|phyboard-segin-imx6ul-7"
