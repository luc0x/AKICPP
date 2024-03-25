#include <kernel/kernel.hpp>

extern "C" void kernel_main(
    unsigned long magic /* The magic 0x2BADB002*/,
    ADDRESS multiboot_addr /*Multiboot information structure*/)
{
    if(magic != MAGIC)
        return;
    
    if (BootInfo::load(multiboot_addr))
    {
        // An Error Happened -> Kernel Panic
    }
    if (BootInfo::exist<Multiboot::FrameBufferInfo>())
    {
        auto fb = BootInfo::get<Multiboot::FrameBufferInfo>();
        
        auto a  = fb->size;
    }
    return;
}   

