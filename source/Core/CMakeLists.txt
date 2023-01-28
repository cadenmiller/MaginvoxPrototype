set(Sources "")

list(APPEND Sources "")

add_library(WA_Core INTERFACE ${Sources})
target_include_directories(WA_Core PUBLIC INTERFACE "Include")