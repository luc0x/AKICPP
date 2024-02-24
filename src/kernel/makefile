CXX = ~/opt/cross/bin/i686-elf-g++
CXX_FLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti


kernel.o : kernel.cpp kernel.hpp multiboot.hpp
	$(CXX) -c kernel.cpp -o ../bin/out/kernel.o $(CXX_FLAGS)