ISO_DIR = ./../builds/iso/

AKICPP.iso : 
	make -C boot
	make -C kernel
	make -C bin

	mv ./bin/kernel.bin $(ISO_DIR)boot/kernel

	grub2-mkrescue -o ./../builds/AKICPP.iso $(ISO_DIR)