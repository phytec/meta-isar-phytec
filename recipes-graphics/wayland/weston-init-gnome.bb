DESCRIPTION = "Startup script and systemd unit file for the Weston Wayland compositor"
MAINTAINER = "isar-users <isar-users@googlegroups.com>"

inherit dpkg-raw

PV = "1.0"

DEBIAN_DEPENDS = "weston, plymouth"

FILESEXTRAPATHS_prepend += "${THISDIR}/weston-init:"

SRC_URI = "file://weston.service \
           file://weston.ini \
           file://weston.config \
           file://postinst \
           file://profile \
           file://71-weston-drm.rules"

do_install () {
	install -d -m 0775 ${D}/lib/systemd/system
	install -m 0644 ${WORKDIR}/weston.service ${D}/lib/systemd/system/
	install -d -m 0775 ${D}/etc/xdg/weston
	install -m 0644 ${WORKDIR}/weston.ini ${D}/etc/xdg/weston/
	install -d -m 0775 ${D}/etc/default
	install -m 0644 ${WORKDIR}/weston.config ${D}/etc/default/weston

	install -Dm0755 ${WORKDIR}/profile ${D}/etc/profile.d/weston.sh

        install -d -m 0775 ${D}/etc/udev/rules.d
        install -m 0644 ${WORKDIR}/71-weston-drm.rules \
            ${D}/etc/udev/rules.d/71-weston-drm.rules
}
