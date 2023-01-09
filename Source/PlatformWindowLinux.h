#pragma once

#define VK_USE_PLATFORM_XCB_KHR 1
#include <vulkan/vulkan.h>
#include <xcb/xcb.h>


class PlatformWindowLinux
{
public:
    static const char* getInstanceSurfaceExtensionName() {return "VK_KHR_xcb_surface";}

public:
    PlatformWindowLinux(VkInstance instance, uint32_t width, uint32_t height);
    ~PlatformWindowLinux();

    VkSurfaceKHR getSurface() {return mSurface;}

private:
    VkInstance          mInstance;
    xcb_connection_t*   mConnection;
    xcb_window_t        mWindow;
    VkSurfaceKHR        mSurface;
};