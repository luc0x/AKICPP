# This uses multiboot standard number one
/*Magic Definition*/
.set MAGIC,     0x1BADB002 # The Magic Number / Boot Signature
.set ALIGN,     0 << 0
.set MEMINFO,   0 << 1
.set VIDEO,     1 << 2
.set FLAG,      ALIGN | MEMINFO | VIDEO
.set CHECKSUM,  -(MAGIC + FLAG)

/*Graphics Fields Definition*/
.set MODE,      1 /* 0 -> Linear Graphic / 1 -> EGA-standard text mode*/
.set WIDTH,     640
.set HEIGHT,    480
.set DEPTH,     0


/*Multiboot Header*/
.section .multiboot 
.align 4

/*Magic Fields*/
.long   MAGIC
.long   FLAG
.long   CHECKSUM

/*Address Fields*/
#ifdef __ELF__
.long   0

.long   0
.long   0
.long   0
.long   0  
#endif

/*Graphic Fields*/
.long   MODE
.long   WIDTH
.long   HEIGHT
.long   DEPTH

/*BSS section*/
.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

/*Text Section*/
.section .text
.global _start

.type _start, @function

_start:
    mov $stack_top, %esp 

    pushl $0
    popf

    pushl %ebx /*Address to the multiboot information structure*/
    pushl %eax /*Magic Value*/

    call kernel_main
    
    cli
loop:
    hlt
    jmp loop

.size _start, . - _start    
/*
.align 8
FRAMEBUFFER_start:
.short  5
.short  FB_FLAGS
.long   (FRAMEBUFFER_end - FRAMEBUFFER_start)
.long   FB_WIDTH
.long   FB_HEIGHT
.long   FB_DEPTH

.align 8
FRAMEBUFFER_end:
*/