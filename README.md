# OS Project

Readme stuff.

## Dev Requirements

OS: Linux
Packages: gcc, nasm, grub-pc-bin, qemu-system-x86_64, python3

## How to build

CD to `kernel/` and run `make -j$(nproc)`.

The default build procedure will generate an ISO for you at `build/os.iso`.

## How to test
The current testing methodology is to simply build and test the operating system each time a new change is introduced.

It's also recommended to test the OS on real hardware from time to time, since virtualized environments do not reflect real world hardware and conditions.

### Virtualized
To test, simply run `make iso-test` to test without building, `make iso-test-build` to build & test at the same time.

The test will open a QEMU window, where you can test the operating system.

If you want to use VirtualBox or another hypervisor, simply select `os.iso` manually, and rerun the VM each time a change is introduced.

### On real hardware

Running this OS on real hardware is not hard, and simply requires you to have removable media (such as a USB).

Installing the operating system on a hard drive is currently not supported.

UEFI is also not supported. You must use a system which has UEFI CSM or legacy BIOS boot.

#### Creating a USB Drive (Windows)
On Windows, you can use a tool called [Rufus](https://rufus.ie/) to burn ISO images to a USB flash drive.

Run Rufus and burn the `os.iso` image to a USB flash drive. Leave all settings as is.

#### Burning a disc

Simply burn `os.iso` using any off the shelf tool.