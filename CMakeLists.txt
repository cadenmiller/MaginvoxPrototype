cmake_minimum_required(VERSION 3.12)
project(WaePrototype)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Give clangd a little more info for NixOS from here https://discourse.nixos.org/t/get-clangd-to-find-standard-headers-in-nix-shell/11268/10 
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES 
      ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

set(WaeSources "Sources/main.c")
set(WaeLibraries "")
set(WaeIncludes "")

add_library(WaeLibrary )

find_package(XCB REQUIRED)
find_package(Vulkan REQUIRED)

list(APPEND WaeLibraries ${XCB_LIBRARIES} ${Vulkan_LIBRARY})
list(APPEND WaeIncludes ${XCB_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIR})

target_link_libraries(WaePrototype ${WaeLibraries})
target_include_directories(WaePrototype PUBLIC ${WaeIncludes})
set_target_properties(WaePrototype PROPERTIES CXX_STANDARD 11)

# Warning Turny-off
if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_options(WaePrototype PUBLIC "-Wno-nullability-completeness")
endif()