# It's a known bug that readdir() in glibc 2.28+ fails in 64-bit QEMU emulating 32-bit guest, which leads to update-mime-database silently producing empty MIME cache. See https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=945828 for details.

inherit dpkg-raw

DESCRIPTION = "Systemd service to reconfigure shared-mime-info"
MAINTAINER = "isar-users <isar-users@googlegroups.com>"
DEBIAN_DEPENDS = "shared-mime-info, systemd"

SRC_URI = "file://postinst \
           file://reconfigure-mime-database.service \
           file://reconfigure-mime-database.sh"

do_install[cleandirs] = "${D}/lib/systemd/system \
                         ${D}/usr/sbin"
do_install() {
    install -v -m 644 "${WORKDIR}/reconfigure-mime-database.service" "${D}/lib/systemd/system/reconfigure-mime-database.service"
    install -v -m 755 "${WORKDIR}/reconfigure-mime-database.sh" "${D}/usr/sbin/reconfigure-mime-database.sh"
}
