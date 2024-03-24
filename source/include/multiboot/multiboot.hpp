#include <debug.hpp>
#include <utils.hpp>


#define MAGIC 0x36d76289

namespace Multiboot
{
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

    struct _basictag
    {
        u32 type;
        u32 size;
    };

    struct BasicMemoryInfo
    {   
        static inline u32 type = 4;
        u32 size;
        u32 mem_lower;
        u32 mem_upper;
    };

    struct BootDevice 
    {
        static inline u32 type = 5;
        u32 size;
        u32 biosdev;
        u32 partition;
        u32 sub_partition;
    };

    struct CommandLine 
    {
        static inline u32 type = 1;
        u32 size;
        u8* string;
    };

    struct Modules
    {
        static inline u32 type = 3;
        u32 size;
        u32 mod_start;
        u32 mod_end;
        u8* string;
    };

    struct ELFSymbol
    {
        static inline u32 type = 9;
        u32 size;
        u16 num;
        u16 entsize;
        u16 shndx;
        u16 reserved;
        // TODO: Varies
    };

    struct MemoryEntry
    {
        u32 base_address;
        u32 length;
        u32 type;
        u32 reserved;
    };

    struct MemoryMap
    {
        static inline u32 type = 6;
        u32 size;
        u32          entry_size;
        u32          entry_version;
        MemoryEntry* entries;
    };

    struct BootLoaderName 
    {
        static inline u32 type = 2;
        u32 size;
        u8* string;
    };

    struct AMPTable 
    {
        static inline u32 type = 10;
        u32 size;
        u16 version;
        u16 cseg;
        u16 cseg_16;
        u16 dseg;
        u16 flags;
        u16 cseg_len;
        u16 cseg_16_len; 
        u16 dseg_len;     
    };

    struct VBEInfo
    {
        static inline u32 type = 7;
        u32 size;
        u16 vbe_mode;
        u16 vbe_interface_seg;
        u16 vbe_interface_off;
        u16 vbe_interface_len;
        u8  vbe_control_info[512];
        u8  vbe_mode_info[256];
    };

    struct FrameBufferInfo
    {
        static inline u32 type = 8;
        u32     size;
        ADDRESS framebuffer_addr;
        u32     framebuffer_pitch;
        u32     framebuffer_width;
        u32     framebuffer_height;
        u8      framebuffer_bpp;
        u8      framebuffer_type;
        u8      reserved;  
        // TODO: color_info    
    };

    struct EFI32Table
    {
        static inline u32 type = 11;
        u32 size;
        ADDRESS pointer;
    };

    struct EFI64Table
    {
        static inline u32 type = 12;
        u32 size;
        ADDRESS pointer;
    };

    struct SMBIOSTable
    {
        static inline u32 type = 13;
        u32 size;
        u8 major;
        u8 minor;
        u8 reserved[8];
    };

    // TODO: ACPI old
    // TODO: ACPI new
    // TODO: Network Information
    // TODO: EFI Memory Map
    
    struct EFI32ImageHandler
    {
        static inline u32 type = 19;
        u32 size;
        ADDRESS pointer;
    };

    struct EFI64ImageHandler
    {
        static inline u32 type = 20;
        u32 size;
        ADDRESS pointer;
    };

    struct ImageLoadBase
    {
        static inline u32 type = 21;
        u32 size;
        u32 load_base_address;
    };

    class BootInfo
    {
        public:
            static bool load(ADDRESS address);

            template <class Tag>
            static inline Tag* get() { return (Tag*)(++tags_start[Tag::type]); }

            
            static inline bool is_tag(u32 tag) { return tag <= 21; }
            
        private:
            static inline u32 padding(u32 size) { return (size + 7) & ~7; }
            static inline ADDRESS tags_start[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            static inline u32 tota_size = 0;
            static inline u32 reserved = 0;

    };
};
