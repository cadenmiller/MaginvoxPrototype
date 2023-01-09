#include <stdexcept>

#include "PlatformWindowLinux.h"

PlatformWindowLinux::PlatformWindowLinux(VkInstance instance, uint32_t width, uint32_t height)
    : mInstance(instance)
{

    /* Connect to the X server */
    mConnection = xcb_connect(nullptr, nullptr);

    /* Get the first screen we find */
    const xcb_setup_t* pSetup = xcb_get_setup(mConnection);
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(pSetup);
    xcb_screen_t* pScreen = iter.data;

    /* Create a new window */
    mWindow = xcb_generate_id(mConnection);
    xcb_create_window(
        mConnection, 
        XCB_COPY_FROM_PARENT, 
        mWindow,
        pScreen->root, 
        0, 0,
        static_cast<uint16_t>(width), static_cast<uint16_t>(height), 
        10, 
        XCB_WINDOW_CLASS_INPUT_OUTPUT, 
        pScreen->root_visual, 
        0, nullptr);

    /* Map the window to the screen */
    xcb_map_window(mConnection, mWindow);
    xcb_flush(mConnection);

    VkXcbSurfaceCreateInfoKHR surfaceCreateInfo = {};
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR;
    surfaceCreateInfo.pNext = nullptr;
    surfaceCreateInfo.flags = 0;
    surfaceCreateInfo.connection = mConnection;
    surfaceCreateInfo.window = mWindow;

    if (vkCreateXcbSurfaceKHR(mInstance, &surfaceCreateInfo, nullptr, &mSurface) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not create a vulkan xcb surface!");
    }
}

PlatformWindowLinux::~PlatformWindowLinux()
{
    vkDestroySurfaceKHR(mInstance, mSurface, nullptr);
    xcb_destroy_window(mConnection, mWindow);
    xcb_disconnect(mConnection);
}