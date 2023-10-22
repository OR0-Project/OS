# kernel make file

CC = gcc
C_FLAGS = -Wall -fno-pie -m32 -ffreestanding -nostdlib
ASM = nasm


# targets
default: all

prep:
	python3 ./prep.py

clean:
	rm -rf ./build
	rm -rf ./cdrom/sys/kernel*
	rm -rf ./obj

all: kernel-iso

iso-test: all
	echo Running QEMU...
	qemu-system-x86_64 -m 256 -cdrom build/os.iso -cpu Westmere


# kernel artifacts
kernel-iso: build/kernel
	echo Preparing ISO image...
	cp build/kernel cdrom/sys/kernel_ia64.bin
	grub-mkrescue -o build/os.iso cdrom

build/kernel: prep multiboot.o kernel.o main.o 
	ld -m elf_i386 -n -o build/kernel obj/multiboot.o obj/kernel.o obj/kern/kutil.o obj/kern/kmem.o obj/util/string.o obj/dev/console.o obj/io/port.o obj/arch/x86/cpuid.o obj/arch/x86/timer.o obj/main.o -T src/kernel.ld


# objects
main.o: obj/dev/console.o obj/io/port.o obj/kern/kutil.o obj/kern/kmem.o obj/util/string.o obj/arch/x86/cpuid.o obj/arch/x86/timer.o
	$(CC) -c src/main.c -o obj/main.o $(CFLAGS)

obj/kern/kutil.o:
	$(CC) -c src/kern/kutil.c -o obj/kern/kutil.o $(CFLAGS)

obj/kern/kmem.o:
	$(CC) -c src/kern/kmem.c -o obj/kern/kmem.o $(CFLAGS)

obj/dev/console.o:
	$(CC) -c src/dev/console.c -o obj/dev/console.o $(CFLAGS)

obj/io/port.o:
	$(CC) -c src/io/port.c -o obj/io/port.o $(CFLAGS)

obj/util/string.o:
	$(CC) -c src/util/string.c -o obj/util/string.o $(CFLAGS)

# x86 specific objects
obj/arch/x86/cpuid.o:
	$(CC) -c src/arch/x86/cpuid.c -o obj/arch/x86/cpuid.o $(CFLAGS)

obj/arch/x86/timer.o:
	$(CC) -c src/arch/x86/timer.c -o obj/arch/x86/timer.o $(CFLAGS)

# Assembler stuff
kernel.o:
	$(ASM) -f elf src/kernel.asm -o obj/kernel.o

multiboot.o:
	$(ASM) -f elf src/multiboot.asm -o obj/multiboot.o
