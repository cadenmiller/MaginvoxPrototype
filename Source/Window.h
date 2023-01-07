#pragma once

#include "Platform.h"

#ifdef MAGINVOX_PLATFORM_WINDOWS
    using Window = WindowWindows;
#elif MAGINVOX_PLATFORM_LINUX
    using Window = WindowX11;
#elif MAGINVOX_PLATFORM_MACOS
    using Window = WindowMacOS;
#endif