type=$1

if [ "$type" == "debug" ]; then
    qemu-system-i386 -s -S -cdrom ./disk/AKICPP.iso
else 
    qemu-system-i386 -cdrom ./disk/AKICPP.iso
fi