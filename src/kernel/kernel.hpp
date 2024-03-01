#pragma once

#include "multiboot/multiboot.hpp"
#include "utils.hpp"

extern "C" void kernel_main(
    unsigned long magic /* The magic 0x2BADB002*/,
    unsigned long multiboot_addr /*Multiboot information structure*/
    );
