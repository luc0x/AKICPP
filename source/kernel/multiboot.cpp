#include <multiboot/multiboot.hpp>

bool Multiboot::BootInfo::load(ADDRESS address)
{
    tota_size = address[0];
    reserved  = address[1];
    address  += 2;

    _basictag* tag = (_basictag*)address;
    while (is_tag(tag->type))
    {
        if (TagsType(tag->type) == TagsType::END)
            return 0;
        
        tags_start[tag->type] = address;

        tag = (_basictag*) ((u8*) tag + padding(tag->size));
    }

    return 1; 
}

template<typename Tag>
Tag Multiboot::BootInfo::get()
{
    Tag tag;
    *tag = tags_start[Tag::type];
    return tag;
}
/*
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
*/


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
