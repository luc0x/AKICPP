#!/bin/bash

exe_cpp=~/opt/cross/bin/i686-elf-g++
exe_asm=~/opt/cross/bin/i686-elf-as


# Boot And Kernel compilation
$exe_cpp -c ./kernel/kernel.cpp -o ./builds/ObjectFiles/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
$exe_asm ./boot/boot.s -o ./builds/ObjectFiles/boot.o


