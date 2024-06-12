if (${FAR_CRY_WINDOWS})
    add_executable(FarCry "Main.cpp" "resource.h")
elseif (${FAR_CRY_APPLE})
    add_library(FarCry STATIC "Main.cpp" "resource.h")
endif ()

target_link_libraries(FarCry CryCommon CryGame CrySystem)