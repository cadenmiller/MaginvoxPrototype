#include <stdexcept>

#include "RenderDevice.h"


Buffer::Buffer(VmaAllocator allocator, VkDeviceSize size, VkBufferUsageFlags usage, uint32_t graphicsQueueFamilyIndex, VmaMemoryUsage memoryUsage, VkMemoryPropertyFlags requiredFlags)
    : mAllocator(allocator)
{

    VkBufferCreateInfo bufferCreateInfo = {0};
    bufferCreateInfo.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferCreateInfo.pNext                 = nullptr;
    bufferCreateInfo.flags                 = 0;
    bufferCreateInfo.size                  = size;
    bufferCreateInfo.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    bufferCreateInfo.queueFamilyIndexCount = 1;
    bufferCreateInfo.pQueueFamilyIndices   = &graphicsQueueFamilyIndex;

    VmaAllocationCreateInfo allocationCreateInfo = {0};
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
        throw std::runtime_error("Could not create a VMA Buffer, probably ran out of graphics memory.");
    }
}

Buffer::~Buffer()
{
    vmaDestroyBuffer(mAllocator, mBuffer, mAllocation);
}