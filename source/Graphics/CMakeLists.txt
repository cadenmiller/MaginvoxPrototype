set(Sources "")

list(APPEND Sources
    "Source/RenderInterface.c")

add_library(WA_Graphics STATIC ${Sources})
target_link_libraries(WA_Graphics WA_Core)
target_include_directories(WA_Graphics PUBLIC "Include")