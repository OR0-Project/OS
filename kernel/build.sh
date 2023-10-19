#/bin/bash
echo Compiling...
mkdir -p {obj,obj/util,obj/io,build,cdrom/sys}
nasm -f elf64 src/multiboot.asm -o obj/multiboot.o
nasm -f elf64 src/kernel.asm -o obj/kernel.o
gcc -fno-pie -m64 -c src/io/console.c -o obj/io/console.o -ffreestanding -nostdlib
gcc -fno-pie -m64 -c src/util/string.c -o obj/util/string.o -ffreestanding -nostdlib
gcc -fno-pie -m64 -c src/main.c -o obj/main.o -ffreestanding -nostdlib
ld -n -o build/kernel obj/multiboot.o obj/kernel.o obj/util/string.o obj/io/console.o obj/main.o -T src/kernel.ld

echo Press enter to build ISO image.
read x
echo Preparing ISO image...
cp build/kernel cdrom/sys/kernel_ia64.bin
grub-mkrescue -o build/os.iso cdrom
