set(Sources "")

list(APPEND Sources
    "Main.c")

add_executable(Application ${Sources})
target_link_libraries(Application WorldAfterCore WorldAfterGraphics)