inherit dpkg-raw

# Prebuild barebox image for test WIC generation
SRC_URI_mx6 = "file://barebox.bin"

# Barebox v2019.01.0
# from BSP-Yocto-i.MX6UL-PD19.1.0
# Mon Mar 8 15:42:23 UTC 2021 2019.01.0-bsp-yocto-i.mx6ul-pd19.1.0
PV_mx6 = "2019.01.0-phy4"
PR_mx6 = "r7.0"

PROVIDES += "barebox"

do_dpkg_build() {
}

do_deploy_deb() {
    mkdir -p ${DEPLOY_DIR_IMAGE}
    cp ${WORKDIR}/barebox.bin ${DEPLOY_DIR_IMAGE}/
}
