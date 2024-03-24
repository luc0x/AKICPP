#pragma once

#include <utils.hpp>
#include <multiboot/multiboot.hpp>

using Multiboot::BootInfo;
using Multiboot::BootLoaderName;

extern "C" void kernel_main(
    unsigned long magic /* The magic 0x2BADB002*/,
    ADDRESS multiboot_addr /*Multiboot information structure*/
    );
