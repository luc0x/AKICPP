#pragma once

#ifndef DEBUG

#define BREAK(label) asm volatile (label":");

#endif