#pragma once

#include "xcb/xcb.h"
#include <vulkan/vulkan.h>
class PlatformLinux
{

    static xcb_connection_t* mXcbConnection;
    static xcb_window_t mXcbWindow;

public:

};