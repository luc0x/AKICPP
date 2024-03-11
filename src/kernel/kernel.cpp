#include "kernel.hpp"

extern "C" void kernel_main(
    unsigned long magic /* The magic 0x2BADB002*/,
    unsigned long* multiboot_addr /*Multiboot information structure*/)
{
    
    if(magic != MAGIC)
        return;
        
    
    BREAK("bf_tags")
    Multiboot::BootInfo boot_information = Multiboot::BootInfo(multiboot_addr);
    
    return;
}   
