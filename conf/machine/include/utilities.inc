### Machine definition file utilities

def make_dtb_boot_files(d):
    # Generate IMAGE_BOOT_FILES entries for device tree files listed in
    # DTB_FILES.
    # Use only the basename for dtb files:
    alldtbs = d.getVar('DTB_FILES')

    def transform(dtb):
        if not (dtb.endswith('dtb') or dtb.endswith('dtbo')):
            # eg: whatever/bcm2708-rpi-b.dtb has:
            #     DEPLOYDIR file: bcm2708-rpi-b.dtb
            #     destination: bcm2708-rpi-b.dtb
            bb.error("DTB_FILES entry %s is not a .dtb or .dtbo file." % (dtb) )
        return os.path.basename(dtb)

    return ' '.join([transform(dtb) for dtb in alldtbs.split() if dtb])
