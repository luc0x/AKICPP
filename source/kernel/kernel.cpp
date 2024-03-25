#include <kernel/kernel.hpp>

extern "C" void kernel_main(
    unsigned long magic /* The magic 0x2BADB002*/,
    ADDRESS multiboot_addr /*Multiboot information structure*/)
{
    if(magic != MAGIC)
        return;
    
    
    if (BootInfo::load(multiboot_addr))
    {
        // Kernel Panic
    }
    
    if (BootInfo::exist<Multiboot::EFI32Table>())
    {
        auto fb = BootInfo::get<Multiboot::EFI32Table>();
    }
    

    return;
}   

