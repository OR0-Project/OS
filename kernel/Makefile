# OS Makefile

CC=gcc
CFLAGS=-Wall -fno-pie -m64 -ffreestanding -nostdlib
ASM=nasm

default: all

prep:
	./prep.sh

clean:
	rm -rf ./build
	rm -rf ./cdrom/sys/kernel*
	rm -rf ./obj

all: build/kernel kernel-iso

# Test stuff
iso-test:
	echo Running QEMU...
	qemu-system-x86_64 -m 256 -cdrom build/os.iso

iso-test-build: all iso-test

# Kernel artifacts
kernel-iso:
	echo Preparing ISO image...
	cp build/kernel cdrom/sys/kernel_ia64.bin
	grub-mkrescue -o build/os.iso cdrom

build/kernel: prep multiboot.o kernel.o main.o 
	ld -n -o build/kernel obj/multiboot.o obj/kernel.o obj/util/string.o obj/io/console.o obj/main.o -T src/kernel.ld

main.o: obj/io/console.o obj/util/string.o
	$(CC) -c src/main.c -o obj/main.o $(CFLAGS)

# Includes
obj/io/console.o:
	$(CC) -c src/io/console.c -o obj/io/console.o $(CFLAGS)

obj/util/string.o:
	$(CC) -c src/util/string.c -o obj/util/string.o $(CFLAGS)

# Assembler stuff
kernel.o:
	$(ASM) -f elf64 src/kernel.asm -o obj/kernel.o

multiboot.o:
	$(ASM) -f elf64 src/multiboot.asm -o obj/multiboot.o
