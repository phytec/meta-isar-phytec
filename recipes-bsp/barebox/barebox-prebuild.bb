inherit dpkg-raw

# Prebuild barebox image for test WIC generation
SRC_URI_mx6 = "file://barebox.bin"

# Barebox v2021.04.0-phy6
# from BSP-Yocto-Ampliphy-i.MX6UL-PD21.2.1
PV_mx6 = "2021.04.0"

PROVIDES += "barebox"

do_dpkg_build() {
}

do_deploy_deb() {
    mkdir -p ${DEPLOY_DIR_IMAGE}
    cp ${WORKDIR}/barebox.bin ${DEPLOY_DIR_IMAGE}/
}
