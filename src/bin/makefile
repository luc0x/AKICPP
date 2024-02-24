CXX = ~/opt/cross/bin/i686-elf-g++
LD_FLAGS = -ffreestanding -O2 -nostdlib

kernel.bin : linker.ld ./out/boot.o ./out/kernel.o
	$(CXX) -T linker.ld -o kernel.bin $(LD_FLAGS) ./out/boot.o ./out/kernel.o 
