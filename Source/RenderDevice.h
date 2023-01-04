#pragma once

#include <vulkan/vulkan.h>
#include "vk_mem_alloc.h"

class RenderDevice;
class Buffer;

class Buffer 
{
public: 
    Buffer(VmaAllocator allocator, VkDeviceSize size, VkBufferUsageFlags usage, uint32_t graphicsQueueFamilyIndex, VmaMemoryUsage memoryUsage, VkMemoryPropertyFlags requiredFlags);
    ~Buffer();

private:
    VmaAllocator    mAllocator;
    VkBuffer        mBuffer;
    VmaAllocation   mAllocation;
};

class RenderDevice 
{

public:
    RenderDevice();
    ~RenderDevice();


    Buffer* CreateBuffer(VkDeviceSize size, VkBufferUsageFlagBits usage, VmaMemoryUsage memoryUsage);


private:
    VkInstance mInstance;
#ifndef NDEBUG
    VkDebugUtilsMessengerEXT mDebugMessenger;
#endif
    VkPhysicalDevice mPhysicalDevice;
    VkDevice mDevice;
    VmaAllocator mAllocator;
    
};