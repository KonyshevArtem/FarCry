add_executable(FarCry
        "Main.cpp"
        "resource.h"
)

target_include_directories(FarCry PRIVATE ./ ../CryCommon)
target_compile_definitions(FarCry PRIVATE _RELEASE NDEBUG WIN64 WIN32 _AMD64_ _WINDOWS DONT_USE_CRY_MEMORY_MANAGER)
target_compile_options(FarCry PRIVATE "-fpermissive")

target_link_libraries(
        FarCry
        Cry3DEngine
        CryAISystem
        CryAnimation
        CryEntitySystem
        CryFont
        CryGame
        CryInput
        CryMovie
        CryNetwork
        CryPhysics
        CryScriptSystem
        CrySoundSystem
        CrySystem
        XRenderD3D9
        -static
)