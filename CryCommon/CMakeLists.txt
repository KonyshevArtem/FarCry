add_library(CryCommon STATIC ISystem.cpp Cry_Camera.cpp splitpath.cpp makepath.cpp  AppleSpecific.cpp cwalk/cwalk.c)

target_include_directories(CryCommon PUBLIC ./)
target_compile_definitions(CryCommon PUBLIC ${FAR_CRY_PLATFORM_DEFINES} _RELEASE NDEBUG _AMD64_ DONT_USE_CRY_MEMORY_MANAGER FAR_CRY_STATIC_LIBS)

if (${FAR_CRY_WINDOWS})

    target_compile_options(CryCommon PUBLIC "-fpermissive")
    target_link_libraries(CryCommon PUBLIC -static)

endif ()