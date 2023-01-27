#ifndef WORLD_AFTER_GFX_DEVICE_H
#define WORLD_AFTER_GFX_DEVICE_H

enum class waGfxRenderAPI
{
    eVulkan = 0,
    eOpenGL = 1
};

enum class waGfxShaderLanguage
{
    eGLSL,
    eSPIRV,
};

struct waGfxDeviceCreateInfo 
{
    waRenderAPI api;
    bool useValidation;
};

class waGraphicsInstance
{

public:
    waGrahpicsInstance(waGraphicsRenderAPI api);
    ~waGraphicsInstance();

};

class waGfxDevice
{

public:
    waGfxDevice();

};

waResult waGfxCreateInstance(const waInstanceCreateInfo* pInstanceCreateInfo, waeInstance* pInstance);
void waeDestroyInstance(waeInstance instance);



#endif /* WORLD_AFTER_GFX_DEVICE_H */