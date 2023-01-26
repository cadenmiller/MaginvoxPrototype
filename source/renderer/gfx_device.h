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

class waGfxInstance
{

public:
    waGfxInstance();

};

class waGfxDevice
{

public:
    waGfxDevice();

};

waResult waGfxCreateInstance(const waInstanceCreateInfo* pInstanceCreateInfo, waeInstance* pInstance);
void waeDestroyInstance(waeInstance instance);



#endif /* WAE_RENDERER_H */