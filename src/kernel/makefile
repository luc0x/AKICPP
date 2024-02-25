CXX = ~/opt/cross/bin/i686-elf-g++
CXX_FLAGS = -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti 

ifeq (${DEBUG}, y)
	CXX_FLAGS += -g
else
	CXX_FLAGS += -O2
endif

kernel.o : kernel.cpp kernel.hpp multiboot.hpp
	$(CXX) -c kernel.cpp -o ../bin/out/kernel.o $(CXX_FLAGS)