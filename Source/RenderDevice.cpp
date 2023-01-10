#include <vector>
#include <vulkan/vulkan_core.h>

#define VMA_IMPLEMENTATION
#include "vk_mem_alloc.h"

#include "Version.h"
#include "PlatformWindow.h"
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
        throw std::runtime_error("Could not create a vulkan memory allocator buffer, might've ran out of graphics memory.");
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
        throw std::runtime_error("Could not create a vulkan buffer view!");
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
        throw std::runtime_error("Could not create a vulkan memory allocator image!");
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
        throw std::runtime_error("Could not create a vulkan image view!");
    }
}

RenderDevice::RenderDevice(uint32_t physicalDeviceIndex)
{

    /* Application data for the VkInstance. */
    VkApplicationInfo applicationInfo = {};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pNext = nullptr;
    applicationInfo.pApplicationName = "Maginvox";
    applicationInfo.applicationVersion = VK_MAKE_API_VERSION(MAGINVOX_VERSION_VARIANT, MAGINVOX_VERSION_MAJOR, MAGINVOX_VERSION_MINOR, MAGINVOX_VERSION_PATCH);
    applicationInfo.pEngineName = "Maginvox";
    applicationInfo.engineVersion = VK_MAKE_API_VERSION(MAGINVOX_VERSION_VARIANT, MAGINVOX_VERSION_MAJOR, MAGINVOX_VERSION_MINOR, MAGINVOX_VERSION_PATCH);
    applicationInfo.apiVersion = VK_VERSION_1_2;

    std::vector<const char*> instanceLayers{};
    std::vector<const char*> instanceExtensions{};


/* Add validation layers if we are on debug mode. */
#ifdef MAGINVOX_DEBUG

    uint32_t layerCount = 0;
    std::vector<VkLayerProperties> layerProperties = {};
    std::vector<const char*> requiredLayers = {"VK_LAYER_KHRONOS_validation"};

    if (vkEnumerateInstanceLayerProperties(&layerCount, nullptr) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not get the vulkan instance layers count!");
    }

    layerProperties.resize(layerCount);

    if (vkEnumerateInstanceLayerProperties(&layerCount, layerProperties.data()) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not get the vulkan instance layers!");
    }

    for (uint32_t i = 0; i < requiredLayers.size(); i++)
    {
        bool foundLayer = false;
        for (uint32_t j = 0; j < layerProperties.size(); j++)
        {
            if (strcmp(requiredLayers[i], layerProperties[j].layerName) == 0)
            {
                foundLayer = true;
                break;
            }
        }

        if (!foundLayer)
        {
            throw std::runtime_error("Could not find a required vulkan instance layer!");
        }

        instanceLayers.push_back(requiredLayers[i]);
    }

#endif

/* Add the instance extensions required for the VkInstance. */
    uint32_t instanceExtensionCount = 0;
    std::vector<VkExtensionProperties> instanceExtensionProperties{};
    std::vector<const char*> requiredInstanceExtensions = {
        "VK_KHR_surface",
        Platform::getSurfaceExtensionName(),
    };

#ifdef MAGINVOX_DEBUG
    requiredInstanceExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif

    if (vkEnumerateInstanceExtensionProperties(nullptr, &instanceExtensionCount, nullptr) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not get the vulkan instance extension property count!");
    }

    instanceExtensionProperties.resize(instanceExtensionCount);

    if (vkEnumerateInstanceExtensionProperties(nullptr, &instanceExtensionCount, instanceExtensionProperties.data()) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not get the vulkan instance extension properties!");
    }

    for (uint32_t i = 0; i < requiredInstanceExtensions.size(); i++)
    {
        bool foundExtension = false;
        for (uint32_t j = 0; j < instanceExtensionProperties.size(); j++)
        {
            if (strcmp(requiredInstanceExtensions[i], instanceExtensionProperties[j].extensionName) == 0)
            {
                foundExtension = true;
                break;
            }
        }

        if (!foundExtension)
        {
            throw std::runtime_error("Could not find a required vulkan instance extension!");
        }

        instanceExtensions.push_back(requiredInstanceExtensions[i]);
    }

/* Create the VkInstance. */
    VkInstanceCreateInfo instanceCreateInfo = {};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pNext = nullptr;
    instanceCreateInfo.flags = 0;
    instanceCreateInfo.pApplicationInfo = &applicationInfo;
    instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(instanceLayers.size());
    instanceCreateInfo.ppEnabledLayerNames = instanceLayers.data();
    instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtensions.size());
    instanceCreateInfo.ppEnabledExtensionNames = instanceExtensions.data();

    if (vkCreateInstance(&instanceCreateInfo, nullptr, &mInstance) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not create the instance!");
    }

/* Create the VkSurface from the window. */
    Platform::createVulkanSurface(mInstance);

/* Get the physical device we are going to use. */
    uint32_t physicalDeviceCount = 0;
    std::vector<VkPhysicalDevice> physicalDevices{};
    
    if (vkEnumeratePhysicalDevices(mInstance, &physicalDeviceCount, nullptr) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not get the vulkan physical device count!");
    }

    physicalDevices.resize(physicalDeviceCount);

    if (vkEnumeratePhysicalDevices(mInstance, &physicalDeviceCount, physicalDevices.data()) != VK_SUCCESS)
    {
        throw std::runtime_error("Could not get the vulkan physical devices!");
    }

/* TODO: We are currently just using the first physical device, change this to use the best physical device. */
    mPhysicalDevice = physicalDevices.front();

/* Find the queue families we are going to use for the VkDevice. */
    uint32_t queueFamilyPropertiesCount = 0;
    std::vector<VkQueueFamilyProperties> queueFamilyProperties = {};

    vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyPropertiesCount, nullptr);

    queueFamilyProperties.resize(queueFamilyPropertiesCount);

    vkGetPhysicalDeviceQueueFamilyProperties(mPhysicalDevice, &queueFamilyPropertiesCount, queueFamilyProperties.data());

    for (uint32_t i = 0; i < queueFamilyPropertiesCount; i++)
    {
        VkQueueFamilyProperties* pProperties = &queueFamilyProperties[i];
    
        if (pProperties->queueFlags & VK_QUEUE_GRAPHICS_BIT)
            mGraphicsQueueIndex = i;

        bool surfaceSupported = false;
        if (vkGetPhysicalDeviceSurfaceSupportKHR(mPhysicalDevice, i, Platform::getWindow()->getSurface(), &surfaceSupported) )
        {

        }
    }


}
