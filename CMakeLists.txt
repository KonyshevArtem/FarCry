cmake_minimum_required(VERSION 3.19)
project(FarCry VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/x64/Build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")


if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")

    set(FAR_CRY_WINDOWS 1)
    set(FAR_CRY_APPLE 0)

    set(FAR_CRY_PLATFORM_DEFINES WIN32 WIN64 _WINDOWS)
    # Destination path is the default path for Ubisoft Connect and Far Cry 1 installation
    set(FAR_CRY_INSTALL_DESTINATION "C:/Program Files (x86)/Ubisoft/Ubisoft Game Launcher/games/FAR CRY 1/CustomBuild_GCC")

elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

    set(FAR_CRY_WINDOWS 0)
    set(FAR_CRY_APPLE 1)

    set(FAR_CRY_PLATFORM_DEFINES APPLE DARWIN_NO_CARBON)
    set(FAR_CRY_INSTALL_DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/x64/Output")

endif ()

add_subdirectory(Cry3DEngine)
add_subdirectory(CryAISystem)
add_subdirectory(CryAnimation)
add_subdirectory(CryCommon)
add_subdirectory(CryEntitySystem)
add_subdirectory(CryFont)
add_subdirectory(CryGame)
add_subdirectory(CryInput)
add_subdirectory(CryMovie)
add_subdirectory(CryNetwork)
add_subdirectory(CryPhysics)
add_subdirectory(CryScriptSystem)
add_subdirectory(CrySoundSystem)
add_subdirectory(CrySystem)
add_subdirectory(ResourceCompiler)
add_subdirectory(RenderDll/XRenderD3D9)
add_subdirectory(FARCRY)

install(TARGETS FarCry DESTINATION ${FAR_CRY_INSTALL_DESTINATION})