# Bootstrapping

The kernel is loaded as a multiboot image via Grub2.

This is done for several reasons:

 - Grub2 is a widely used bootloader and effort is better spent on things like the kernel instead of creating our very own bootloader.

 - Grub2 provides useful services post-boot that we can interact with.

## How this works

To load this OS, the kernel is specified as a `multiboot2` image that Grub can load.

This also means that the kernel is multiboot compliant. You can find the multiboot header code in `src/multiboot.asm`.

The boot entry is defined as follows:

```
menuentry "OS Developer Image (32-bit)" {
    multiboot2 /sys/kernel32.bin
    boot
}
```