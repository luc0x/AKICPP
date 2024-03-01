CXX = ~/opt/cross/bin/i686-elf-g++
CXX_FLAGS = -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti 

MULTIBOOT = MULTIBOOT2

ifeq (${DEBUG}, y)
	CXX_FLAGS += -g
else
	CXX_FLAGS += -O2
endif

multiboot.o : ./multiboot/multiboot.hpp ./multiboot/multiboot.cpp utils.hpp kernel.o
	$(CXX) -c -D $(MULTIBOOT) multiboot/multiboot.cpp -o ../bin/out/multiboot.o $(CXX_FLAGS)

kernel.o : kernel.cpp kernel.hpp ./multiboot/multiboot.hpp utils.hpp
	$(CXX) -c kernel.cpp -o ../bin/out/kernel.o $(CXX_FLAGS)
	

