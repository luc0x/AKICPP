type=$1
debug="debug"

if [ "$type" == "$debug" ]; then
    qemu-system-i386 -s -S -cdrom ./../builds/AKICPP.iso
else
    qemu-system-i386 -cdrom ./../builds/AKICPP.iso
fi