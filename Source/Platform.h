#pragma once

#ifdef _WIN32
    #define MAGINVOX_PLATFORM_WINDOWS
#elif __linux__
    #define MAGINVOX_PLATFORM_LINUX
#elif __APPLE__
    #define MAGINVOX_PLATFORM_MACOS
#endif

