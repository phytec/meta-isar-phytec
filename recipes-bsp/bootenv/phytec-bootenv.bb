SUMMARY = "Provides machine depended external environment for u-boot on i.MX8M PHYTEC hardware"

inherit dpkg-raw

SRC_URI = " \
        file://bootenv.txt \
"

do_dpkg_build() {
}

do_deploy_deb() {
    install -d ${DEPLOY_DIR_IMAGE}
    install -m 0644 ${WORKDIR}/bootenv.txt ${DEPLOY_DIR_IMAGE}
}
