ASM = ~/opt/cross/bin/i686-elf-as

boot.o : boot2.s header.s
	$(ASM) boot2.s -o ../bin/out/boot.o
	$(ASM) crti.s -o ../bin/out/crti.o
	$(ASM) crtn.s -o ../bin/out/crtn.o