/*
-----Multiboot2 header-----

Properties:
    - Must be 64-bits aligned (8 bytes)
    - Must be contained completely within the first 32768 bytes of the OS image

Layout:
    --------------------------------------------
    |Offset	Type	    Field Name	   Note    |    
    |0	    u32 	    magic	       required|
    |4	    u32 	    architecture   required|
    |8	    u32 	    header_lengte  required|
    |12	    u32 	    checksum	   required|
    |16-XX		        tags	       required|
    --------------------------------------------

Tag Layout:
            +-------------------+
    u16     | type              |
    u16     | flags             |
    u32     | size              |
            +-------------------+

Tag Properties:
    - Each tag starts at 8-bytes aligned address
    - Tags are terminated by a tag of type ‘0’ and size ‘8’
    - ‘type’ is divided into 2 parts. Lower contains an identifier of contents of the rest of the tag.
    - If bit ‘0’ of ‘flags’ (also known as ‘optional’) is set, the bootloader may ignore this tag if it lacks relevant support.
*/

.set ALIGN,             8                                    # Bytes header alignment

# Magic Field
.set HEADER_MAGIC,             0xE85250D6                           # Magic Number
.set MULTIBOOT_ARCHITECTURE,   0                                    # 32-bits protected mode
.set HEADER_LENGTH,            (header_end - header_start)          # Header Length
.set CHECKSUM,                 -(HEADER_MAGIC + MULTIBOOT_ARCHITECTURE + HEADER_LENGTH)    # Checksum

# Optional
.set TAG_FLAG_ZERO, 0
.set TAG_FLAG_ONE, 1

# Framebuffer
.set FB_WIDTH,                 640
.set FB_HEIGHT,                480
.set FB_DEPTH,                 32
