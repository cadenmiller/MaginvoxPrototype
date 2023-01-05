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

target_link_libraries(MaginvoxPrototype ${MaginvoxLibraries})
target_include_directories(MaginvoxPrototype PUBLIC ${MaginvoxIncludes})
set_target_properties(MaginvoxPrototype PROPERTIES CXX_STANDARD 11)

# Warning Turnyoff
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_options(MaginvoxPrototype PUBLIC "-Wno-nullability-completeness")
endif()