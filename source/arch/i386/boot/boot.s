# This uses standard multiboot two
.include "boot/header.s"


.section .multiboot

header_start:
.align  ALIGN
.long   HEADER_MAGIC
.long   MULTIBOOT_ARCHITECTURE
.long   HEADER_LENGTH
.long   CHECKSUM

// Frame Buffer
FB_start:
.align  ALIGN
.short  5
.short  TAG_FLAG_ONE
.long   (FB_end - FB_start)
.long   FB_WIDTH
.long   FB_HEIGHT
.long   FB_DEPTH
FB_end:

// EFI Service
EFI_Boot_Service_start:
.align  ALIGN
.short  7
.short  TAG_FLAG_ONE
.long   8
EFI_Boot_Service_end:

EFI_I386_start:
.align  ALIGN
.short  8
.short  TAG_FLAG_ONE
.long   (EFI_I386_end - EFI_I386_start)
.long   _start
EFI_I386_end:

.align  ALIGN
.short  0
.short  0
.long   8
header_end:

# Stack
.section .bss

.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start

.type _start, @function

_start:
    mov $stack_top, %esp

    pushl $0
    popf
 
    pushl %ebx # Bootloader INFO 
    pushl %eax # Bootloader MAGIC

    call kernel_main

    cli
loop: 
    hlt
    jmp loop

.size _start, . - _start
