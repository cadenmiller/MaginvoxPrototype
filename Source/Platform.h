#pragma once

#ifdef _WIN32
    #define MAGINVOX_PLATFORM_WINDOWS
    using Platform = PlatformWindows;
#elif __linux__
    #define MAGINVOX_PLATFORM_LINUX
#elif __APPLE__
    #define MAGINVOX_PLATFORM_MACOS
    using Platform = PlatformMacOS;
#endif
