#pragma once

#include <vulkan/vulkan.h>
#include "vk_mem_alloc.h"

class RenderDevice;
class Buffer;
class Image;

class Buffer 
{

public: 
    Buffer(VmaAllocator allocator, VkDeviceSize size, VkBufferUsageFlags usage, uint32_t graphicsQueueFamilyIndex, VmaMemoryUsage memoryUsage, VkMemoryPropertyFlags requiredFlags);
    ~Buffer();

    VkBuffer getBuffer() {return mBuffer;}

private:
    VmaAllocator    mAllocator;
    VkBuffer        mBuffer;
    VmaAllocation   mAllocation;

};

class BufferView
{

public:
    BufferView(VkDevice device, VkBuffer buffer, VkFormat format, VkDeviceSize offset, VkDeviceSize range);
    ~BufferView();

    VkBufferView getBufferView() {return mBufferView;}

private:
    VkDevice mDevice;
    VkBufferView mBufferView;
};

class Image
{
public:
    Image(VmaAllocator allocator, uint32_t graphicsQueueIndex, VkImageType imageType, VkFormat format, VkExtent3D extent, uint32_t mipLevels, VkImageTiling tiling, VkImageUsageFlags usage, VmaMemoryUsage memoryUsage, VkMemoryPropertyFlags requiredFlags);
    ~Image();

public:
    VkImage getImage() {return mImage;}

private:
    VmaAllocator  mAllocator;
    VkImage       mImage;
    VmaAllocation mAllocation;

};

class ImageView
{
    
public:
    ImageView(VkDevice device, VkImage image, VkImageViewType viewType, VkExtent3D extent, VkFormat format, VkComponentMapping components, VkImageSubresourceRange subresourceRange);
    ~ImageView();

    VkImageView getImageView() {return mImageView;}

private:
    VkDevice mDevice;
    VkImageView mImageView;

};

class RenderDevice 
{

public:
    RenderDevice(uint32_t physicalDeviceIndex = 0);
    ~RenderDevice();

    VkInstance       getInstance() {return mInstance;}
    uint32_t         getPhysicalDeviceIndex() {return mPhysicalDeviceIndex;}
    VkPhysicalDevice getPhysicalDevice() {return mPhysicalDevice;}
    VkDevice         getDevice() {return mDevice;}
    uint32_t         getGraphicsQueueIndex() {return mGraphicsQueueIndex;}
    uint32_t         getPresentQueueIndex() {return mPresentQueueIndex;}
    bool             isGraphicsAndPresentQueueIndexSame() {return mGraphicsQueueIndex == mPresentQueueIndex;}
    VkQueue          getGraphicsQueue() {return mGraphicsQueue;}
    VkQueue          getPresentQueue() {return mPresentQueue;}

    Buffer*          createBuffer(VkDeviceSize size, VkBufferUsageFlagBits usage, VmaMemoryUsage memoryUsage);
    BufferView*      createBufferView(VkBuffer buffer, VkFormat format, VkDeviceSize offset, VkDeviceSize range);
    Image*           createImage(VkImageType imageType, VkFormat format, VkExtent3D extent, uint32_t mipLevels, VkImageTiling tiling, VkImageUsageFlags usage, VmaMemoryUsage memoryUsage, VkMemoryPropertyFlags requiredFlags);
    ImageView*       createImageView(VkImage image, VkImageViewType viewType, VkExtent3D extent, VkFormat format, VkComponentMapping components, VkImageSubresourceRange subresourceRange);

private:
    VkInstance               mInstance;
#ifndef NDEBUG
    VkDebugUtilsMessengerEXT mDebugMessenger;
#endif
    uint32_t                 mPhysicalDeviceIndex;
    VkPhysicalDevice         mPhysicalDevice;
    uint32_t                 mGraphicsQueueIndex, mPresentQueueIndex; 
    VkDevice                 mDevice;
    VkQueue                  mGraphicsQueue, mPresentQueue;
    VkRenderPass             mRenderPass;
    VmaAllocator             mAllocator;
    
};