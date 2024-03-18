#include <multiboot/multiboot.hpp>

Multiboot::BootInfo::BootInfo() 
{
    
}

Multiboot::BootInfo::BootInfo(u32_ptr address)
{
    if(load_at(address) != true)
    {
        // Kernel Panic!!!
        BREAK("KernelPanic")
    }
}

bool Multiboot::BootInfo::load_at(u32_ptr address)
{   
    total_size = address[0];
    reserved = address[1];
    buffer = &(address[2]);
    address += 2;

    while(is_tag(address[0]))
    {
        if(TagsType(address[0]) == TagsType::END)
            return true; 

        tags[address[0]] = address;
        address += (address[1] / 4) + 1; 
        BREAK("Tags_end")
    }
    return false;
}

bool Multiboot::BootInfo::is_tag(u32 tag)
{
    return (0 <= tag && tag < 22);
}

Multiboot::BootInfo::~BootInfo()
{

}

/*
int Multiboot::load_boot_information(u32* address)
{   
    boot_info.total_size = address[0];
    boot_info.reserved = address[1];
    boot_info.buffer = &(address[2]);    
    address += 3;
    
    /*
    TagsType type = TagsType(address[0]); 

    while(address[0] != 0)
    {
        BREAK("tags_loop")
        type = TagsType(address[0]); 

        switch (type)
        {
            case TagsType::END:
                break;

            case TagsType::MMAP:
                mem_map.type = type;
                mem_map.size = address[1];
                
                break;
            default: // This Thing should skip unknown tags type 
                address += (address[1] / 4); 
                break;
        }
        ++address;
    }
    return 0;
     
}
*/ 
