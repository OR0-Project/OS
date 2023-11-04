# OS Project

This Readme is a summary of important information.

To read extended documentation, run `mkdocs serve` in the root of this repository to view the OS documentation.

If your system does not have mkdocs, you can install it by following their instructions [here](https://www.mkdocs.org/getting-started/).

## Dev Requirements

OS: Linux / Windows (WSL)

Packages (Debian): `gcc nasm grub-pc-bin grub-efi-amd64-bin qemu-system-x86 python3 python3-pip build-essential xorriso mtools`

### WSL specifics

You can develop for this OS using Windows Subsystem for Linux (wsl) on Windows hosts.

To do this, you need the following:
 - A WSL distro. Ubuntu has been tested and works great.
 - An X server for QEMU output. You can grab VcXSrv from [here](https://sourceforge.net/projects/vcxsrv/).

When the above is satisfied, you can work on the OS as you would under Linux.

## How to build

Run `make -j$(nproc)`.

The default build procedure will generate an ISO for you at `build/OS.iso`.

## How to test
The current testing methodology is to simply build and test the operating system each time a new change is introduced.

It's also recommended to test the OS on real hardware from time to time, since virtualized environments do not reflect real world hardware and conditions.

### Virtualized
To test, simply run `make qemu-legacy` (for legacy boot) and `make qemu-uefi` (for uefi boot).

This target will open a QEMU window, where you can test the operating system.

If you want to use VirtualBox or another hypervisor, simply select `build/OS.iso` manually, and rerun the VM each time you rebuild the OS.

### On real hardware

Running this OS on real hardware is not hard, and simply requires you to have removable media (such as a USB).

Installing the operating system on a hard drive is currently not supported.

#### Creating a USB Drive (Windows)
On Windows, you can use a tool called [Rufus](https://rufus.ie/) to burn ISO images to a USB flash drive.

Run Rufus and burn the `build/OS.iso` image to a USB flash drive. Leave all settings as is.

#### Burning a disc

Simply burn `build/OS.iso` using any off the shelf tool.