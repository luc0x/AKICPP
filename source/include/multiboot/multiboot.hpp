#include <debug.hpp>

#define ALIGN 8
#define MAGIC 0x36d76289


namespace Multiboot
{
    typedef unsigned long* u32_ptr;
    typedef unsigned long u32;
    typedef unsigned short u16;
    typedef unsigned char u8;

    enum class TagsType
    {
        END = 0,
        CMDLINE = 1,
        BOOT_LOADER_NAME = 2,
        MODULE = 3,
        BASIC_MEMINFO = 4,
        BOOTDEV = 5,
        MMAP = 6,
        VBE = 7,
        FRAMEBUFFER = 8,
        ELF_SECTIONS = 9,
        APM = 10,
        EFI32 = 11,
        EFI64 = 12,
        SMBIOS = 13,
        ACPI_OLD = 14,
        ACPI_NEW = 15,
        NETWORK = 16,
        EFI_MMAP = 17,
        EFI_BS = 18,
        EFI32_IH = 19,
        EFI64_IH = 20,
        LOAD_BASE_ADDR = 21,
    }; 

    class BootInfo
    {
        public:
            BootInfo();
            BootInfo(u32_ptr address);
            ~BootInfo();

            bool load_at(u32_ptr address);
            bool is_tag(u32 tag);
            
        private: 
            u32 total_size;
            u32 reserved; 
            u32_ptr buffer;
            u32_ptr tags[21];
            bool asigned = false;
    };
};
