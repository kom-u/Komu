#pragma once

#ifdef KM_PLATFORM_WINDOWS
#ifdef KM_BUILD_DLL
#define KOMU_API __declspec(dllexport)
#else
#define KOMU_API __declspec(dllimport)
#endif
#else
#error Komu only supports Windows!
#endif