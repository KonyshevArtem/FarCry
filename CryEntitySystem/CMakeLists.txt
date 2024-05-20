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

target_link_libraries(CryEntitySystem CryCommon)