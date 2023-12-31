#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include <string.h>
#include <memory.h>
#include <math.h>
#include <time.h>

#include <crtdbg.h>
#include <crtdefs.h>

#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>

#include <zlib.h>

#if defined(_WIN32)
#define NOGDI
#define NOUSER
#endif

#include <windows.h>

#if defined(_WIN32)
#undef near
#undef far

#define MAKEINTRESOURCE(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#else
#define MAX_PATH 260
#endif

#define sfree(x) \
    if (x)       \
        free(x);

#if defined(_DEBUG) && defined(_WIN32)

#define measure(name, x)                                                             \
    LARGE_INTEGER start, end, frequency;                                             \
    long long elapsed_time;                                                          \
    QueryPerformanceFrequency(&frequency);                                           \
    QueryPerformanceCounter(&start);                                                 \
    x;                                                                               \
    QueryPerformanceCounter(&end);                                                   \
    elapsed_time = (end.QuadPart - start.QuadPart) * 100000000 / frequency.QuadPart; \
    printf("[%s]: %lld ns\n", #name, elapsed_time);

#else
#define measure(name, x)
#endif // _DEBUG && _WIN32
