set(CRY_SYSTEM_SOURCES
        "ApplicationHelper.cpp"
        "CompressedFile.cpp"
        "CPUDetect.cpp"
        "CryMemoryManager.cpp"
        "CryPak.cpp"
        "CrySizerImpl.cpp"
        "CrySizerStats.cpp"
        "DataProbe.cpp"
        "DebugCallStack.cpp"
        "DllMain.cpp"
        "DownloadManager.cpp"
        "FrameProfileRender.cpp"
        "FrameProfileSystem.cpp"
        "getdxver.cpp"
        "HTTPDownloader.cpp"
        "Log.cpp"
        "Mailer.cpp"
        "md5.c"
        "MTSafeAllocator.cpp"
        "RandGen.cpp"
        "RefReadStream.cpp"
        "RefReadStreamProxy.cpp"
        "RefStreamEngine.cpp"
        "ScriptBinding.cpp"
        "ScriptObjectAnimation.cpp"
        "ScriptObjectEntity.cpp"
        "ScriptObjectMovie.cpp"
        "ScriptObjectParticle.cpp"
        "ScriptObjectScript.cpp"
        "ScriptObjectSound.cpp"
        "ScriptObjectSystem.cpp"
        "ScriptSink.cpp"
        "SourceSafeHelper.cpp"
        "StdAfx.cpp"
        "StreamEngine.cpp"
        "System.cpp"
        "SystemCFG.cpp"
        "SystemInit.cpp"
        "SystemRender.cpp"
        "SystemWin32.cpp"
        "Timer.cpp"
        "XConsole.cpp"
        "XConsoleVariable.cpp"
        "XML/Expat/xmlparse.c"
        "XML/Expat/xmlrole.c"
        "XML/Expat/xmltok.c"
        "XML/xml.cpp"
        "XML/XMLDOMDocumentImpl.cpp"
        "XML/XMLDOMNodeImpl.cpp"
        "XML/XMLDOMNodeListImpl.cpp"
        "XML/_XMLDOMParserImpl.cpp"
        "ZipDirCache.cpp"
        "ZipDirCacheFactory.cpp"
        "ZipDirCacheRW.cpp"
        "ZipDirFind.cpp"
        "ZipDirFindRW.cpp"
        "ZipDirList.cpp"
        "ZipDirStructures.cpp"
        "ZipDirTree.cpp"
        "zlib/adler32.c"
        "zlib/compress.c"
        "zlib/crc32.c"
        "zlib/deflate.c"
        "zlib/gzclose.c"
        "zlib/gzlib.c"
        "zlib/gzread.c"
        "zlib/gzwrite.c"
        "zlib/infback.c"
        "zlib/inffast.c"
        "zlib/inflate.c"
        "zlib/inftrees.c"
        "zlib/trees.c"
        "zlib/uncompr.c"
        "zlib/zutil.c"
        "ApplicationHelper.h"
        "CPUDetect.h"
        "CritSection.h"
        "CryPak.h"
        "CrySizerImpl.h"
        "CrySizerStats.h"
        "CryWaterMark.h"
        "DataProbe.h"
        "DebugCallStack.h"
        "DownloadManager.h"
        "DxDiag.h"
        "FrameProfileSystem.h"
        "HTTPDownloader.h"
        "Log.h"
        "Mailer.h"
        "md5.h"
        "MTSafeAllocator.h"
        "PakVars.h"
        "RandGen.h"
        "RefReadStream.h"
        "RefReadStreamProxy.h"
        "RefStreamEngine.h"
        "resource.h"
        "ScriptObjectAnimation.h"
        "ScriptObjectEntity.h"
        "ScriptObjectMovie.h"
        "ScriptObjectParticle.h"
        "ScriptObjectScript.h"
        "ScriptObjectSound.h"
        "ScriptObjectSystem.h"
        "ScriptSink.h"
        "SourceSafeHelper.h"
        "StdAfx.h"
        "StreamEngine.h"
        "System.h"
        "SystemCFG.h"
        "Timer.h"
        "Validator.h"
        "XConsole.h"
        "XConsoleVariable.h"
        "XML/Expat/ascii.h"
        "XML/Expat/asciitab.h"
        "XML/Expat/config.h"
        "XML/Expat/expat.h"
        "XML/Expat/iasciitab.h"
        "XML/Expat/latin1tab.h"
        "XML/Expat/nametab.h"
        "XML/Expat/utf8tab.h"
        "XML/Expat/winconfig.h"
        "XML/Expat/xmlrole.h"
        "XML/Expat/xmltok.h"
        "XML/Expat/xmltok_impl.h"
        "XML/nanoxml.h"
        "XML/xml.h"
        "XML/XMLDOMDocumentImpl.h"
        "XML/XMLDOMNodeImpl.h"
        "XML/XMLDOMNodeListImpl.h"
        "XML/xml_string.h"
        "XML/_XMLDOMParserImpl.h"
        "ZipDir.h"
        "ZipDirCache.h"
        "ZipDirCacheFactory.h"
        "ZipDirCacheRW.h"
        "ZipDirFind.h"
        "ZipDirFindRW.h"
        "ZipDirList.h"
        "ZipDirStructures.h"
        "ZipDirTree.h"
        "ZipFile.h"
        "ZipFileFormat.h"
        "zlib/crc32.h"
        "zlib/deflate.h"
        "zlib/gzguts.h"
        "zlib/inffast.h"
        "zlib/inffixed.h"
        "zlib/inflate.h"
        "zlib/inftrees.h"
        "zlib/trees.h"
        "zlib/zconf.h"
        "zlib/zlib.h"
        "zlib/zutil.h"
)

if (${FAR_CRY_WINDOWS})

    set(CRY_SYSTEM_SOURCES
            ${CRY_SYSTEM_SOURCES}
            "LuaDebugger/FileTree.cpp"
            "LuaDebugger/LUADBG.cpp"
            "LuaDebugger/LuaDbgInterface.cpp"
            "LuaDebugger/AboutWnd.h"
            "LuaDebugger/FileTree.h"
            "LuaDebugger/LUADBG.h"
            "LuaDebugger/LuaDbgInterface.h"
            "LuaDebugger/_TinyBrowseFolder.h"
            "LuaDebugger/_TinyCaptionWindow.h"
            "LuaDebugger/_TinyCoolEdit.h"
            "LuaDebugger/_TinyFileEnum.h"
            "LuaDebugger/_TinyImageList.h"
            "LuaDebugger/_TinyMain.h"
            "LuaDebugger/_TinyRegistry.h"
            "LuaDebugger/_TinySplitter.h"
            "LuaDebugger/_TinyStatusBar.h"
            "LuaDebugger/_TinyTreeList.h"
            "LuaDebugger/_TinyWindow.h"
    )

endif ()

add_library(CrySystem STATIC ${CRY_SYSTEM_SOURCES})

target_include_directories(CrySystem PRIVATE ./)
target_compile_definitions(CrySystem PRIVATE CRYSYSTEM_EXPORTS GARBAGEMEMORY)

target_link_libraries(
        CrySystem
        Cry3DEngine
        CryCommon
        CryAISystem
        CryAnimation
        CryEntitySystem
        CryFont
        CryGame
        CryInput
        CryMovie
        CrySoundSystem
        CryNetwork
        CryPhysics
        CryScriptSystem
)

if (${FAR_CRY_WINDOWS})

    target_link_libraries(
            CrySystem
            wininet
            dbghelp
            version
            dxguid
            winmm
            comctl32
            XRenderD3D9
    )

endif ()

if (${FAR_CRY_APPLE})
    target_link_libraries(CrySystem XRenderNULL)
endif ()