add_executable(FarCry
        "Main.cpp"
        "resource.h"
)

target_compile_definitions(FarCry PRIVATE _RELEASE NDEBUG WIN64 WIN32 _AMD64_ _WINDOWS DONT_USE_CRY_MEMORY_MANAGER FAR_CRY_STATIC_LIBS)

target_link_libraries(
        FarCry
        CryCommon
        CryGame
        CryScriptSystem
        CrySystem
        XRenderD3D9
        -static
)