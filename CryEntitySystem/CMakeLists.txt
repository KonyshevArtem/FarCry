add_library(CryEntitySystem STATIC
        "CryEntityDLL.cpp"
        "Entity.cpp"
        "EntityCamera.cpp"
        "EntityCreation.cpp"
        "EntityIt.cpp"
        "EntityPesistence.cpp"
        "EntityRender.cpp"
        "EntitySystem.cpp"
        "IDGenerator.cpp"
        "LipSync.cpp"
        "RandomExprLoadSink.cpp"
        "stdafx.cpp"
        "Entity.h"
        "EntityCamera.h"
        "EntityIt.h"
        "EntitySystem.h"
        "IDGenerator.h"
        "LipSync.h"
        "RandomExprLoadSink.h"
        "stdafx.h"
)

target_compile_definitions(CryEntitySystem PRIVATE _RELEASE NDEBUG WIN64 WIN32 _AMD64_ _WINDOWS _USRDLL CRYENTITYDLL_EXPORTS DONT_USE_CRY_MEMORY_MANAGER FAR_CRY_STATIC_LIBS)
target_link_libraries(CryEntitySystem CryCommon -static)