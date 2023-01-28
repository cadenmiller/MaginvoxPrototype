set(Sources "")

list(APPEND Sources
    "Source/RenderInterface.c")

add_library(WorldAfterGraphics STATIC ${Sources})
target_link_libraries(WorldAfterGraphics WorldAfterCore cglm)
target_include_directories(WorldAfterGraphics PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include/>
    $<INSTALL_INTERFACE:include/Graphics>)  # <prefix>/include/mylib)