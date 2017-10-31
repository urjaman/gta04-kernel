#!/bin/bash
# this is on an ARM host, adjust if cross compiling
set -e
set -x
if [ ! -e .config ]; then
	cp dora-config .config
	make oldconfig
fi
make menuconfig
LOADADDR=0x80008000 make uImage -j3
make modules dtbs -j3
rm -rf M
mkdir M
INSTALL_MOD_PATH=$(pwd)/M make modules_install
rm M/lib/modules/*/{build,source,modules.*dep*}
mkdir M/boot
cp arch/arm/boot/uImage M/boot/uImage4
cp arch/arm/boot/dts/omap3-pandora-*.dtb M/boot
tar --owner=root --group=root -czf pandora-kernel4.tar.gz -C M boot lib
