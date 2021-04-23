inherit dpkg-raw

# Prebuild barebox image for test WIC generation
SRC_URI_mx6 = "file://barebox.bin"

PROVIDES += "barebox"

do_dpkg_build() {
}

do_deploy_deb() {
    mkdir -p ${DEPLOY_DIR_IMAGE}
    cp ${WORKDIR}/barebox.bin ${DEPLOY_DIR_IMAGE}/
}
