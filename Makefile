# The Makefile Makefile
MAKE=make
EMU=qemu-system-x86_64

# -- Flags --
EMU_FLAGS = -monitor tcp:localhost:5555,server,nowait

default: build-all

# ///////////////////////////////////////////////////////////////////////////
# general targets ////////////////////////////////////////////////////////////

# Meta target to build everything
build-all: prep preloader loader loader-uefi kernel64 os-iso

# Prepares directories
prep:
	mkdir -p build
	mkdir -p cdrom/sys

# Cleans everything from all projects
clean-all:
	$(MAKE) -C ./bstrapper/legacy/loader clean
	$(MAKE) -C ./bstrapper/legacy/preloader clean
	$(MAKE) -C ./bstrapper/uefi clean
	$(MAKE) -C ./stdlib clean
	$(MAKE) -C ./kernel clean
	rm -rf build
	rm -rf cdrom/sys

# Creates an operating system ISO from built files
os-iso: prep
	echo Preparing ISO image...
	cp ./bstrapper/legacy/preloader/build/preloader ./cdrom/sys/preloader.bin
	cp ./bstrapper/legacy/loader/build/loader ./cdrom/sys/loader.bin
	cp ./bstrapper/uefi/loader.efi ./cdrom/sys/loader.efi
	cp ./kernel/build/kernel64.bin ./cdrom/sys/kernel64.bin
	grub-mkrescue -o build/OS.iso cdrom

# Reloads submodules
git-sync:
	git submodule update --recursive --remote

kernel64:
	$(MAKE) -C ./kernel

# ///////////////////////////////////////////////////////////////////////////
# legacy targets ////////////////////////////////////////////////////////////
run-legacy: build-all qemu-legacy

qemu-legacy:
	$(EMU) -m 256 -cpu Westmere -name "OS Development Emulator" -cdrom build/OS.iso

preloader:
	$(MAKE) -C ./bstrapper/legacy/preloader

loader:
	$(MAKE) -C ./bstrapper/legacy/loader

# ///////////////////////////////////////////////////////////////////////////
# uefi targets //////////////////////////////////////////////////////////////
run-uefi: build-all qemu-uefi

qemu-uefi:
	$(EMU) -m 512 -cpu Westmere -name "OS Development Emulator (UEFI)" -cdrom build/OS.iso \
		-bios /usr/share/OVMF/OVMF_CODE.fd \
		$(EMU_FLAGS)

loader-uefi:
	$(MAKE) -C ./bstrapper/uefi