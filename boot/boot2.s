# This uses standard multiboot two
.include "./boot/header.s"

.align 8
.section .multiboot
header_start:

.long   HEADER_MAGIC
.long   MULTIBOOT_ARCHITECTURE
.long   HEADER_LENGTH
.long   CHECKSUM

.short  0
.short  0
.long   8
header_end:

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
