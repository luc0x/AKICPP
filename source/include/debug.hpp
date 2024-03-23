#pragma once

#ifdef DEBUG
#define BREAK(label) asm volatile (label":");
#else
#define BREAK(label)

#endif