# 64-bit planning
## Memory Map
| Start Address      | End Address        | Size    | Description                                                        |
|--------------------|--------------------|---------|--------------------------------------------------------------------|
| 0x0000000000000000 | 0x0000000000000FFF | 4   KiB | IDT -        256 descriptors (each descriptor is 16 bytes)         |
| 0x0000000000001000 | 0x0000000000001FFF | 4   KiB | GDT -        256 descriptors (each descriptor is 16 bytes)         |
| 0x0000000000002000 | 0x0000000000002FFF | 4   KiB | PT4 -        512 entries     (first entry points to PDP at 0x3000) |
| 0x0000000000003000 | 0x0000000000003FFF | 4   KiB | PT3 -        512 entries                                           |
| 0x0000000000004000 | 0x0000000000004FFF | 4   KiB | PT2 -        512 entries                                           |
| 0x0000000000005000 | 0x000000000000AFFF | 20  KiB | info                                                               |
| 0x000000000000B000 | 0x000000000000FFFF | 16  KiB | stack                                                              |