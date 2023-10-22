# 64-bit planning
## Memory Map
| Start Address      | End Address        | Size    | Description                                                        |
|--------------------|--------------------|---------|--------------------------------------------------------------------|
| 0x0000000000000000 | 0x0000000000000FFF | 4   KiB | IDT -        256 descriptors (each descriptor is 16 bytes)         |
| 0x0000000000001000 | 0x0000000000001FFF | 4   KiB | GDT -        256 descriptors (each descriptor is 16 bytes)         |
| 0x0000000000002000 | 0x0000000000002FFF | 4   KiB | PML4 -       512 entries     (first entry points to PDP at 0x3000) |
| 0x0000000000003000 | 0x0000000000003FFF | 4   KiB | PDP low -    512 entries                                           |
| 0x0000000000004000 | 0x0000000000004FFF | 4   KiB | PDP high -   512 entries                                           |
| 0x0000000000005000 | 0x000000000000FFFF | 12  KiB | info                                                               |
| 0x0000000000010000 | 0x000000000001FFFF | 64  KiB | PD low -     entries are 8 bytes per 2MiB page                     |
| 0x0000000000020000 | 0x000000000005FFFF | 256 KiB | PD high -    entries are 8 bytes per 2MiB page                     |
| 0x0000000000060000 | 0x000000000009FFFF | 256 KiB | free                                                               |
| 0x00000000000A0000 | 0x00000000000FFFFF | 384 KiB | ROM                                                                |
| ROM + 0x0000000000 | ROM + 0x0000018000 | 128 KiB | VGA                                                                |
| ROM + 0x0000018000 | ROM + 0x0000020000 | 8   KiB | VGA color text                                                     |
| ROM + 0x0000020000 | ROM + 0x0000030000 | 64  KiB | BIOS video                                                         |
| ROM + 0x0000050000 | ROM + 0x0000060000 | 64  KiB | motherboard BIOS                                                   |
| 0x0000000000100000 | 0xFFFFFFFFFFFFFFFF | ...     | free                                                               |