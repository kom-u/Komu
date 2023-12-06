#pragma once

#ifdef KM_PLATFORM_WINDOWS
#  ifdef KM_BUILD_DLL
#    define KOMU_API __declspec(dllexport)
#  else
#    define KOMU_API __declspec(dllimport)
#  endif
#else
#  error Komu only supports Windows!
#endif

#ifdef KM_ENABLE_ASSERTS
#  define KM_ASSERT(x, ...) { if(!(x)) { KM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#  define KM_CORE_ASSERT(x, ...) { if(!(x)) { KM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#  define KM_ASSERT(x, ...)
#  define KM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
/*
    this is a bitshift operator that shifts 1 by x bits
    so if x = 2, then 1 << 2 = 100
    if x = 3, then 1 << 3 = 1000

    0 << 0 << 0 << 0 << 0 << 0 << 0 << 0
    7 << 6 << 5 << 4 << 3 << 2 << 1 << 0

    so if we have a bitfield of 0001, and we want to set the 3rd bit to 1, we can do
    0001 | (1 << 3) = 1001
    and if we want to set the 2nd bit to 1, we can do
    0001 | (1 << 2) = 0101
*/