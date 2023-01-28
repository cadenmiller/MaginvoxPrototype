#ifndef WA_RENDER_INTERFACE_H
#define WA_RENDER_INTERFACE_H

#include "PrimTypes.h"
#include "Result.h"

typedef struct waRenderInterface_T *waRenderInterface;
typedef struct waRenderPhysicalDevice_T *waRenderPhysicalDevice;
typedef struct waRenderDevice_T *waRenderDevice;
typedef struct waRenderImage_T *waRenderImage;
typedef struct waRenderBuffer_T *waRenderBuffer;
typedef enum waRenderAPI
{
    WA_RENDER_API_OPENGL,
} waRenderAPI;

typedef struct waRenderInterfaceCreateInfo
{
    waRenderAPI api;
    bool useValidation;
} waRenderInterfaceCreateInfo;

typedef enum waRenderFormat
{
    WA_RENDER_FORMAT_R8,
    WA_RENDER_FORMAT_R8G8,
    WA_RENDER_FORMAT_R8G8B8,
    WA_RENDER_FORMAT_R8G8B8A8,
    
} waRenderFormat;

typedef struct waRenderImageCreateInfo
{
    waRenderFormat format;
} waRenderImageCreateInfo;

typedef struct waRenderBufferCreateInfo
{
    size_t size;
    waRenderFormat format;
} waRenderBufferCreateInfo;

waResult waCreateRenderInterface(const waRenderInterfaceCreateInfo* pCreateInfo, waRenderInterface* pInterface);
void waDestroyRenderInterface(waRenderInterface interface);
waResult waEnumerateRenderPhysicalDevices(waRenderInterface interface, uint32_t* pPhysicalDevicesCount, waRenderPhysicalDevice* pPhysicalDevices);

waResult waCreateRenderDevice(waRenderInterface interface, waRenderPhysicalDevice physicalDevice, waRenderDevice* pDevice);
void waDestroyRenderDevice(waRenderDevice device);
waResult waCreateRenderImage(waRenderDevice device, const waRenderImageCreateInfo* pCreateInfo, waRenderImage* pImage);
void waDestroyRenderImage(waRenderImage image);
waResult waCreateRenderBuffer(waRenderDevice device, const waRenderBufferCreateInfo* pCreateInfo, waRenderBuffer* pBuffer);
void waDestroyRenderBuffer(waRenderBuffer buffer);

#endif /* WORLD_AFTER_RENDER_DEVICE_H */