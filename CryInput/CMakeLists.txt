add_library(CryInput STATIC
        "CryInput.cpp"
        "Input.cpp"
        "Joystick.cpp"
        "StdAfx.cpp"
        "XActionMap.cpp"
        "XActionMapManager.cpp"
        "XKeyboard.cpp"
        "XMouse.cpp"
        "Input.h"
        "Joystick.h"
        "Keyboard.h"
        "StdAfx.h"
        "XActionMap.h"
        "XActionMapManager.h"
        "XKeyboard.h"
        "XMouse.h"
)

target_compile_definitions(CryInput PRIVATE _RELEASE NDEBUG WIN64 WIN32 _AMD64_ _WINDOWS _USRDLL CRYINPUT_EXPORTS DIRECTINPUT_VERSION=0x0800 DONT_USE_CRY_MEMORY_MANAGER FAR_CRY_STATIC_LIBS)
target_link_libraries(CryInput CryCommon -static dinput8 dxguid winmm)