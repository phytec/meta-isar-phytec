inherit dpkg-raw

# Prebuild u-boot image for test WIC generation
SRC_URI_mx8 = "file://imx-boot"

PROVIDES += "virtual/bootloader"
PROVIDES += "imx-boot"

do_dpkg_build() {
}

do_deploy_deb() {
    mkdir -p ${DEPLOY_DIR_IMAGE}
    cp ${WORKDIR}/imx-boot ${DEPLOY_DIR_IMAGE}/
}
