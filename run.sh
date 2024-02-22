#!/bin/bash

exe_cpp=~/opt/cross/bin/i686-elf-g++
run_time=$(date +%Y-%m-%d)
dir_obj=./builds/ObjectFiles

# TODO: Linking
$exe_cpp -T $dir_obj/linker.ld -o ./builds/bin/"$run_time".bin -ffreestanding -O2 -nostdlib $dir_obj/boot.o $dir_obj/kernel.o 


if grub2-file --is-x86-multiboot2 ./builds/bin/"$run_time".bin; then
  echo "[Console] Multiboot Confirmed"
else
  echo "[Error] This isn't a multiboot binary"
  exit 1
fi

cp ./builds/bin/"$run_time".bin ./builds/iso/boot/
mv ./builds/iso/boot/"$run_time".bin ./builds/iso/boot/kernel

grub2-mkrescue -o ./builds/AKICPP.iso ./builds/iso

qemu-system-i386 -cdrom ./builds/AKICPP.iso

