include make.config

boot : boot/header.s boot/boot.s boot/crti.s boot/crtn.s
	$(ASM) boot/boot.s -o $(DIR_OUT)/boot.o
	$(ASM) boot/crti.s -o $(DIR_OUT)/crti.o
	$(ASM) boot/crtn.s -o $(DIR_OUT)/crtn.o

