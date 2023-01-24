#ifndef WAE_RENDERER_H
#define WAE_RENDERER_H

#include "wae-primitive.h"

typedef void* waeInstance;
typedef void* waeDevice;
typedef void* waeBuffer;
typedef void* waeShader;
typedef void* waePipeline;
typedef void* waeShaderCompiler;

typedef enum waeRenderAPI
{
    WAE_RENDER_API_VULKAN = 1,
    WAE_RENDER_API_OPENGL = 2,
} waeRenderAPI;

typedef enum waeShaderLanguange
{
    WAE_SHADER_LANGUAGE_GLSL,
    WAE_SHADER_LANGUAGE_SPIRV,
} waeShaderLanguage;

typedef enum waeInstanceCreateInfo 
{
    waeRenderAPI api;
    bool useValidation;
} waeInstanceCreateInfo;

waeResult waeCreateInstance(const waeInstanceCreateInfo* pInstanceCreateInfo, waeInstance* pInstance);
void waeDestroyInstance(waeInstance instance);



#endif /* WAE_RENDERER_H */