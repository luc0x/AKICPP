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
        
        tags_start[tag->type] = (ADDRESS)tag;

        tag = (_basictag*) ((u8*) tag + padding(tag->size));
    }

    return 1; 
}
