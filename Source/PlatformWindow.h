#pragma once

#include "Platform.h"

#if defined(MAGINVOX_PLATFORM_LINUX)
    #include "PlatformWindowLinux.h"
    using PlatformWindow = PlatformWindowLinux;
#endif