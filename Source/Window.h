#pragma once

#include "Platform.h"

#ifdef MAGINVOX_PLATFORM_WINDOWS
    using VulkanWindow = VulkanWindows;
#elif MAGINVOX_PLATFORM_LINUX
    using VulkanWindow = VulkanX11;
#elif MAGINVOX_PLATFORM_MACOS
    using VulkanWindow = VulkanMacos;
#endif