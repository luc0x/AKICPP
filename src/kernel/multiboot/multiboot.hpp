#pragma once 

#include "../utils.hpp"

#define MULTIBOOT2

namespace Multiboot
{
    int load_boot_information(unsigned long* address);

    enum class TagsType;

    struct Tag;

    typedef unsigned long u32;
    typedef unsigned short u16;
    typedef unsigned char u8;


#ifdef MULTIBOOT2
    struct BasicMemInfo : Tag 
    {
        u32 mem_lower;
        u32 mem_upper;
    } mem_basic;

    struct BiosDevice : Tag
    {
        u32 biosdev;
        u32 partition;
        u32 sub_partition;
    } boot_dev;

    struct CmdLine : Tag
    {
        u8 string;
    } cmd_line;
};

#define ALIGN 8
#define MAGIC 0x36d76289


enum class Multiboot::TagsType 
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

struct Multiboot::Tag 
{
    TagsType type;
    u32 size;
};

#endif 
