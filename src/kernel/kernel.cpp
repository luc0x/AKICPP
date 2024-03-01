#include "kernel.hpp"

extern "C" void kernel_main(
    unsigned long magic /* The magic 0x2BADB002*/,
    unsigned long multiboot_addr /*Multiboot information structure*/)
{
    if(magic != MAGIC)
        return;

    Multiboot::load_boot_information((unsigned long*) multiboot_addr);
    
    return;
}   
