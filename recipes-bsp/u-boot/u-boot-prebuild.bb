inherit dpkg-raw

# Prebuild u-boot image for test WIC generation
SRC_URI_mx8 = "file://imx-boot"

# U-Boot v2021.04_2.2.0-phy5 (based on NXP tag lf-5.10.72-2.2.0)
# from BSP-Yocto-NXP-i.MX8MM-PD22.1.0
PV_mx8mm = "2021.04"

# U-Boot 2022.07-rc2 (mainline c387e62)
# from 	BSP-Yocto-Ampliphy-i.MX8MP-master
PV_mx8mp = "2022.07-rc2"

PROVIDES += "virtual/bootloader"
PROVIDES += "imx-boot"

do_dpkg_build() {
}

do_deploy_deb() {
    mkdir -p ${DEPLOY_DIR_IMAGE}
    cp ${WORKDIR}/imx-boot ${DEPLOY_DIR_IMAGE}/
}
