cmake_minimum_required(VERSION 3.12)
project(MaginvoxPrototype)

set(MaginvoxSources 
    "Source/RenderDevice.cpp"
    "Source/Main.cpp")
set(MaginvoxLibraries "")
set(MaginvoxIncludes "")

add_executable(MaginvoxPrototype ${MaginvoxSources})

find_package(Vulkan REQUIRED)

list(APPEND MaginvoxLibraries ${Vulkan_LIBRARY})
list(APPEND MaginvoxIncludes ${Vulkan_INCLUDE_DIR})