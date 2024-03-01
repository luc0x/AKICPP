#include "multiboot.hpp"


#ifdef MULTIBOOT2

int Multiboot::load_boot_information(unsigned long* address)
{
    u32 total_size = address[0];
    u32 reserved = address[1];
    address += 2;
    
    TagsType type = TagsType(address[0]); 

    while(address[0] != 0)
    {
        BREAK("tags_loop")
        type = TagsType(address[0]); 
        switch (type)
        {
            case TagsType::END:
                break;

            case TagsType::BASIC_MEMINFO:
                mem_basic.type = TagsType(address[0]);
                mem_basic.size = address[1];
                mem_basic.mem_lower = address[2];
                mem_basic.mem_upper = address[3];
                address += 3;
                break;

            case TagsType::BOOTDEV:
                boot_dev.type = TagsType(address[0]);
                boot_dev.size = address[1];
                boot_dev.biosdev = address[2];
                boot_dev.partition = address[3];
                boot_dev.sub_partition = address[4];
                address += 4;
                break;
            
            case TagsType::CMDLINE:
                cmd_line.type = TagsType(address[0]);
                cmd_line.size = address[1];
                
                for (int i = 2; i < cmd_line.size / 4; ++i)
                {
                    // TODO!
                }
                break; 

            default:
                address += (address[1] / 4) - 2; // Skip This Tag
                break;

            ++address;
        }

    }
    return 0; 
}

#endif