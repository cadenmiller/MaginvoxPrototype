cmake_minimum_required(VERSION 3.12)
project(Prototype)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Compile commands for clangd
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES 
      ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

add_subdirectory(Source)