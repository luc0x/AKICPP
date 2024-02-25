ISO_DIR = ./../builds/iso/


AKICPP.iso : 
	make -C boot DEBUG=${DEBUG}
	make -C kernel DEBUG=${DEBUG}
	make -C bin DEBUG=${DEBUG}

	mv ./bin/kernel.bin $(ISO_DIR)boot/kernel

	grub2-mkrescue -o ./../builds/AKICPP.iso $(ISO_DIR)