inherit dpkg-raw

# Prebuild u-boot image for test WIC generation
SRC_URI_mx8 = "file://imx-boot"

# U-Boot v2021.04_2.2.0-phy5 (based on NXP tag lf-5.10.72-2.2.0)
# from BSP-Yocto-NXP-i.MX8MM-PD22.1.0
PV_mx8mm = "2021.04"

# Unknown U-boot version from original SD card:
# Built : 18:54:44, Nov  2 2020   v2.2(release):rel_imx_5.4.47_2.2.0-0-gc949a888e
PV_mx8mp = "1.0"

PROVIDES += "virtual/bootloader"
PROVIDES += "imx-boot"

do_dpkg_build() {
}

do_deploy_deb() {
    mkdir -p ${DEPLOY_DIR_IMAGE}
    cp ${WORKDIR}/imx-boot ${DEPLOY_DIR_IMAGE}/
}
