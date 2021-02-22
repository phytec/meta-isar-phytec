DESCRIPTION = "Startup script and systemd unit file for the Weston Wayland compositor"
MAINTAINER = "isar-users <isar-users@googlegroups.com>"

inherit dpkg-raw

PV = "1.0"

DEBIAN_DEPENDS = "weston, plymouth"

SRC_URI = "file://weston.service \
           file://weston.ini \
           file://weston.config \
           file://postinst"

do_install () {
	install -d -m 0775 ${D}/lib/systemd/system
	install -m 0644 ${WORKDIR}/weston.service ${D}/lib/systemd/system/
	install -d -m 0775 ${D}/etc/xdg/weston
	install -m 0644 ${WORKDIR}/weston.ini ${D}/etc/xdg/weston/
	install -d -m 0775 ${D}/etc/default
	install -m 0644 ${WORKDIR}/weston.config ${D}/etc/default/weston
}
