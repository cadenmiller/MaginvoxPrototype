#pragma once

class VulkanPlatformLinux
{
public:
    static const char* getSurfaceExtensionName() {return "VK_KHR_xcb_surface";}
    static VkSurfaceKHR createSurface(VkInstance instance);
};