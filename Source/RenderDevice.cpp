#include "vulkan/vulkan_core.h"
#include <stdexcept>

#define VMA_IMPLEMENTATION
#include "vk_mem_alloc.h"

#include "RenderDevice.h"


Buffer::Buffer(VmaAllocator allocator, VkDeviceSize size, VkBufferUsageFlags usage, uint32_t graphicsQueueFamilyIndex, VmaMemoryUsage memoryUsage, VkMemoryPropertyFlags requiredFlags)
    : mAllocator(allocator)
{

    VkBufferCreateInfo bufferCreateInfo = {};
    bufferCreateInfo.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferCreateInfo.pNext                 = nullptr;
    bufferCreateInfo.flags                 = 0;
    bufferCreateInfo.size                  = size;
    bufferCreateInfo.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    bufferCreateInfo.queueFamilyIndexCount = 1;
    bufferCreateInfo.pQueueFamilyIndices   = &graphicsQueueFamilyIndex;

    VmaAllocationCreateInfo allocationCreateInfo = {};
    allocationCreateInfo.flags          = 0;
    allocationCreateInfo.usage          = memoryUsage;
    allocationCreateInfo.requiredFlags  = requiredFlags;
    allocationCreateInfo.preferredFlags = 0;
    allocationCreateInfo.memoryTypeBits = 0;
    allocationCreateInfo.pool           = nullptr;
    allocationCreateInfo.pUserData      = nullptr;
    allocationCreateInfo.priority       = 0.0f;

    VmaAllocationInfo allocationInfo = {0};

    if (vmaCreateBuffer(allocator, &bufferCreateInfo, &allocationCreateInfo, &mBuffer, &mAllocation, &allocationInfo) != VK_SUCCESS) 
    {
        throw std::runtime_error("Could not create a VMA Buffer, might've ran out of graphics memory.");
    }
}

Buffer::~Buffer()
{
    vmaDestroyBuffer(mAllocator, mBuffer, mAllocation);
}

BufferView::BufferView(VkDevice device, VkBuffer buffer, VkFormat format, VkDeviceSize offset, VkDeviceSize range)
    : mDevice(device)
{
    VkBufferViewCreateInfo bufferViewCreateInfo = {};
    bufferViewCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
    bufferViewCreateInfo.pNext = nullptr;
    bufferViewCreateInfo.flags = 0;
    bufferViewCreateInfo.buffer = buffer;
    bufferViewCreateInfo.format = format;
    bufferViewCreateInfo.offset = offset;
    bufferViewCreateInfo.range = range;

    if (vkCreateBufferView(mDevice, &bufferViewCreateInfo, nullptr, &mBufferView) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not create a buffer view!");
    }
}

BufferView::~BufferView()
{
    vkDestroyBufferView(mDevice, mBufferView, nullptr);
}

Image::Image(VmaAllocator allocator, uint32_t graphicsQueueIndex, VkImageType imageType, VkFormat format, VkExtent3D extent, uint32_t mipLevels, VkImageTiling tiling, VkImageUsageFlags usage, VmaMemoryUsage memoryUsage, VkMemoryPropertyFlags requiredFlags)
    : mAllocator(allocator)
{

    VkImageCreateInfo imageCreateInfo = {};
    imageCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    imageCreateInfo.pNext = nullptr;
    imageCreateInfo.flags = 0;
    imageCreateInfo.imageType = imageType;
    imageCreateInfo.format = format;
    imageCreateInfo.extent = extent;
    imageCreateInfo.mipLevels = mipLevels;
    imageCreateInfo.arrayLayers = 1;
    imageCreateInfo.samples = VK_SAMPLE_COUNT_1_BIT;
    imageCreateInfo.tiling = tiling;
    imageCreateInfo.usage = usage;
    imageCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    imageCreateInfo.queueFamilyIndexCount = 1;
    imageCreateInfo.pQueueFamilyIndices = &graphicsQueueIndex;
    imageCreateInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

    VmaAllocationCreateInfo allocationCreateInfo = {};
    allocationCreateInfo.flags = 0;
    allocationCreateInfo.usage = VMA_MEMORY_USAGE_GPU_ONLY;
    allocationCreateInfo.requiredFlags = memoryUsage;
    allocationCreateInfo.preferredFlags = 0;
    allocationCreateInfo.memoryTypeBits = 0;
    allocationCreateInfo.pool = VK_NULL_HANDLE;
    allocationCreateInfo.pUserData = nullptr;
    allocationCreateInfo.priority = 0.0f;

    VmaAllocationInfo allocationInfo = {};

    if (vmaCreateImage(allocator, &imageCreateInfo, &allocationCreateInfo, &mImage, &mAllocation, &allocationInfo) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not create a VMA Image!");
    }
}

Image::~Image()
{
    vmaDestroyImage(mAllocator, mImage, mAllocation);
}

ImageView::ImageView(VkDevice device, VkImage image, VkImageViewType viewType, VkExtent3D extent, VkFormat format, VkComponentMapping components, VkImageSubresourceRange subresourceRange)
    : mDevice(device)
{
    VkImageViewCreateInfo imageViewCreateInfo = {};
    imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    imageViewCreateInfo.pNext = nullptr;
    imageViewCreateInfo.flags = 0;
    imageViewCreateInfo.image = image;
    imageViewCreateInfo.viewType = viewType;
    imageViewCreateInfo.format = format;
    imageViewCreateInfo.components = components;
    imageViewCreateInfo.subresourceRange = subresourceRange;

    if (vkCreateImageView(mDevice, &imageViewCreateInfo, nullptr, &mImageView) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not create an image view!");
    }
}