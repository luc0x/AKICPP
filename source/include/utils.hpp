#pragma once
#define i386

#ifdef i386

typedef long* ADDRESS;

#elif defined(x64)

#else
#error You must specifie an architecture

#endif

