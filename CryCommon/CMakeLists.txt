add_library(CryCommon STATIC ISystem.cpp Cry_Camera.cpp)

target_include_directories(CryCommon PUBLIC ./)
target_compile_definitions(CryCommon PRIVATE WIN32 NDEBUG _WINDOWS _USRDLL CRY3DENGINE_EXPORTS WIN64 _AMD64_ DONT_USE_CRY_MEMORY_MANAGER FAR_CRY_STATIC_LIBS)
target_compile_options(CryCommon PUBLIC "-fpermissive")
