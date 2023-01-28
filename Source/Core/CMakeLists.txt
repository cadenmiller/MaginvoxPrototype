set(Sources "")

list(APPEND Sources "")

add_library(WorldAfterCore INTERFACE ${Sources})
target_include_directories(WorldAfterCore PUBLIC INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include/>
    $<INSTALL_INTERFACE:include/Core>)  # <prefix>/include/mylib)