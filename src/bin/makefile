CXX = ~/opt/cross/bin/i686-elf-g++
LD_FLAGS = -ffreestanding -O2 -nostdlib -g

OUT = ./out/

CRTI_OBJ = $(OUT)crti.o
CRTBEGIN_OBJ := $(shell $(CXX) $(LD_FLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ := $(shell $(CXX) $(LD_FLAGS) -print-file-name=crtend.o)
CRTN_OBJ = $(OUT)crtn.o

OBJS = $(OUT)boot.o $(OUT)kernel.o $(OUT)multiboot.o

kernel.bin : linker.ld ./out/boot.o ./out/kernel.o ./out/multiboot.o
	$(CXX) -T linker.ld -o kernel.bin $(LD_FLAGS) $(CRTI_OBJ) $(CRTBEGIN_OBJ) $(OBJS) $(CRTEND_OBJ) $(CRTN_OBJ)  
