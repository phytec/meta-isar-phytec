# Copyright (C) 2014-2015 PHYTEC Messtechnik GmbH,
# Author: Stefan Mueller-Klieser <s.mueller-klieser@phytec.de>
# Adopted to Isar: Anton Mikanovich <amikan@ilbers.de>

DESCRIPTION = "Linux Kernel Phytec common base"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM ?= "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

require recipes-kernel/linux/linux-custom.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/linux-common:"
SRC_URI_append = " \
  ${@bb.utils.contains('DISTRO_FEATURES', 'virtualization', 'file://lxc.cfg', '', d)} \
  ${@bb.utils.contains('DISTRO_FEATURES', 'virtualization', 'file://docker.cfg', '', d)} \
  ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'file://systemd.cfg', '', d)} \
  ${@bb.utils.contains('DEBUG_BUILD', '1', 'file://debugging.cfg', '', d)} \
  file://no-inird.cfg \
"

INC_PR = "r0"

KBUILD_DEPENDS += "lzop, lz4"
PATCHTOOL = "git"

def get_oftree(d):
    kdt = d.getVar('DTB_FILES', '')
    if not kdt:
        return ''
    return os.path.basename(kdt.split()[0])

KERNEL_IMAGE_NAME = "${KERNEL_FILE}-${PN}-${PV}-${PR}-${MACHINE}${IMAGE_VERSION_SUFFIX}"
FIRST_DTS = "${@get_oftree(d)}"
do_deploy_deb_append() {
    install -d ${DEPLOY_DIR_IMAGE}
    install -m 644 ${B}/${KERNEL_BUILD_DIR}/.config ${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGE_NAME}.config
    ln -sf ${KERNEL_IMAGE_NAME}.config ${DEPLOY_DIR_IMAGE}/${KERNEL_FILE}.config
    ln -sf ${FIRST_DTS} ${DEPLOY_DIR_IMAGE}/oftree
}
