# kernel make file

CC = gcc
ASM = nasm
LINK = ld

C_FLAGS = -Wall -fno-pie -m32 -ffreestanding -nostdlib -Iinc -c -lgcc
ASM_FLAGS = -f elf
LINK_FLAGS = -m elf_i386 -n


# targets
default: all

prep:
	python3 ./prep.py

clean:
	rm -rf ./build
	rm -rf ./cdrom/sys/kernel*
	rm -rf ./obj

all: kernel-iso

iso-test: clean all
	echo Running QEMU...
	qemu-system-x86_64 -m 256 -cdrom build/os.iso -cpu Westmere


# kernel artifacts
kernel-iso: build/kernel
	echo Preparing ISO image...
	cp build/kernel cdrom/sys/kernel_ia64.bin
	grub-mkrescue -o build/os.iso cdrom

build/kernel: prep multiboot.o kernel.o main.o 
	$(LINK) $(LINK_FLAGS) -o build/kernel obj/multiboot.o obj/kernel.o obj/kern/kutil.o obj/kern/kmem.o obj/util/string.o obj/dev/console.o obj/io/port.o obj/arch/x86/cpuid.o obj/arch/x86/msr.o obj/arch/x86/timer.o obj/main.o -T src/kernel.ld


# objects
main.o: obj/dev/console.o obj/io/port.o obj/kern/kutil.o obj/kern/kmem.o obj/util/string.o obj/arch/x86/cpuid.o obj/arch/x86/msr.o obj/arch/x86/timer.o
	$(CC) src/main.c -o obj/main.o $(C_FLAGS)

obj/kern/kutil.o:
	$(CC) src/kern/kutil.c -o obj/kern/kutil.o $(C_FLAGS)

obj/kern/kmem.o:
	$(CC) src/kern/kmem.c -o obj/kern/kmem.o $(C_FLAGS)

obj/dev/console.o:
	$(CC) src/dev/console.c -o obj/dev/console.o $(C_FLAGS)

obj/io/port.o:
	$(CC) src/io/port.c -o obj/io/port.o $(C_FLAGS)

obj/util/string.o:
	$(CC) src/util/string.c -o obj/util/string.o $(C_FLAGS)

# x86 specific objects
obj/arch/x86/cpuid.o:
	$(CC) src/arch/x86/cpuid.c -o obj/arch/x86/cpuid.o $(C_FLAGS)
	#$(ASM) src/arch/x86/cpuid.asm -o obj/arch/x86/cpuid_asm.o $(ASM_FLAGS)
	#$(CC) -c src/arch/x86/cpuid.c -o obj/arch/x86/cpuid_c.o $(C_FLAGS)
	#$(LINK) $(LINK_FLAGS) --relocatable -o obj/arch/x86/cpuid.o \
    #		obj/arch/x86/cpuid_asm.o obj/arch/x86/cpuid_c.o

obj/arch/x86/timer.o:
	$(CC) src/arch/x86/timer.c -o obj/arch/x86/timer.o $(C_FLAGS)

obj/arch/x86/msr.o:
	$(CC) src/arch/x86/msr.c -o obj/arch/x86/msr.o $(C_FLAGS)

# Assembler stuff
kernel.o:
	$(ASM) src/kernel.asm -o obj/kernel.o $(ASM_FLAGS)

multiboot.o:
	$(ASM) src/multiboot.asm -o obj/multiboot.o $(ASM_FLAGS)
