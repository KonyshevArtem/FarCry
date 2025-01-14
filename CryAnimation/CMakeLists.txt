add_library(CryAnimation STATIC
        "AnimObject.cpp"
        "AnimObjectLoader.cpp"
        "AnimObjectManager.cpp"
        "BoneLightBindInfo.cpp"
        "BoneLightDynamicBind.cpp"
        "BSplineKnots.cpp"
        "BSplineOpen.cpp"
        "BSplineVec3dPacked.cpp"
        "CgfUtils.cpp"
        "ChunkFileReader.cpp"
        "Controller.cpp"
        "ControllerCryBone.cpp"
        "ControllerManager.cpp"
        "ControllerPackedBSpline.cpp"
        "ControllerTCB.cpp"
        "CryAnimationBase.cpp"
        "CryBone.cpp"
        "CryBoneDesc.cpp"
        "CryBoneHierarchyLoader.cpp"
        "CryBoneInfo.cpp"
        "CryCharBody.cpp"
        "CryCharDecal.cpp"
        "CryCharDecalBuilder.cpp"
        "CryCharDecalManager.cpp"
        "CryCharFxTrail.cpp"
        "CryCharInstance.cpp"
        "CryCharInstanceRenderParams.cpp"
        "CryCharManager.cpp"
        "CryCharParticleManager.cpp"
        "CryCharRenderElement.cpp"
        "CryCharReShadowManager.cpp"
        "CryCharReShadowVolume.cpp"
        "CryGeometryInfo.cpp"
        "CryGeomMorphTarget.cpp"
        "CryKeyInterpolation.cpp"
        "CryModEffAnimation.cpp"
        "CryModEffIKSolver.cpp"
        "CryModEffMorph.cpp"
        "CryModel-Data.cpp"
        "CryModel.cpp"
        "CryModelAnimationContainer.cpp"
        "CryModelArrays.cpp"
        "CryModelGeometryLoader.cpp"
        "CryModelLoader.cpp"
        "CryModelShadowVolume.cpp"
        "CryModelState.cpp"
        "CryModelStatePhys.cpp"
        "CryModelSubmesh.cpp"
        "CrySkinBase.cpp"
        "CrySkinBasisBuilder.cpp"
        "CrySkinBuilder.cpp"
        "CrySkinBuilderBase.cpp"
        "CrySkinFull.cpp"
        "CrySkinMorph.cpp"
        "CrySkinMorphBuilder.cpp"
        "CrySkinRigidBasis.cpp"
        "CryVertexBinding.cpp"
        "cvars.cpp"
        "DebugUtils.cpp"
        "drand.cpp"
        "FileMapping.cpp"
        "IncContHeap.cpp"
        "MathUtils.cpp"
        "QuaternionExponentX87.cpp"
        "RenderUtils.cpp"
        "SSEUtils.cpp"
        "stdafx.cpp"
        "VertexBufferArrayDrivers.cpp"
        "XBoxExport.cpp"
        "AnimationLayerInfo.h"
        "AnimObject.h"
        "AnimObjectLoader.h"
        "AnimObjectManager.h"
        "BoneLightBindInfo.h"
        "BoneLightDynamicBind.h"
        "BSplineKnots.h"
        "BSplineOpen.h"
        "BSplineVec3dPacked.h"
        "CgfUtils.h"
        "ChunkFileReader.h"
        "Controller.h"
        "ControllerCryBone.h"
        "ControllerManager.h"
        "ControllerPackedBSpline.h"
        "ControllerTCB.h"
        "CryAnimationBase.h"
        "CryAnimationInfo.h"
        "CryBone.h"
        "CryBoneDesc.h"
        "CryBoneHierarchyLoader.h"
        "CryBoneInfo.h"
        "CryCharBody.h"
        "CryCharDecal.h"
        "CryCharDecalBuilder.h"
        "CryCharDecalCommon.h"
        "CryCharDecalManager.h"
        "CryCharFxTrail.h"
        "CryCharInstance.h"
        "CryCharInstanceRenderParams.h"
        "CryCharManager.h"
        "CryCharParticleManager.h"
        "CryCharRenderElement.h"
        "CryCharReShadowManager.h"
        "CryCharReShadowVolume.h"
        "CryGeometryInfo.h"
        "CryGeomMorphTarget.h"
        "CryKeyInterpolation.h"
        "CryModEffAnimation.h"
        "CryModEffector.h"
        "CryModEffIKSolver.h"
        "CryModEffMorph.h"
        "CryModel.h"
        "CryModelAnimationContainer.h"
        "CryModelGeometryLoader.h"
        "CryModelLoader.h"
        "CryModelState.h"
        "CryModelSubmesh.h"
        "CrySkinBase.h"
        "CrySkinBasisBuilder.h"
        "CrySkinBuilder.h"
        "CrySkinBuilderBase.h"
        "CrySkinFull.h"
        "CrySkinMorph.h"
        "CrySkinMorphBuilder.h"
        "CrySkinRigidBasis.h"
        "CrySkinTypes.h"
        "CryVertexBinding.h"
        "cvars-list.h"
        "cvars.h"
        "DebugUtils.h"
        "drand.h"
        "FileMapping.h"
        "GeomCommon.h"
        "IncContHeap.h"
        "MathUtils.h"
        "QuaternionExponentX87.h"
        "RenderUtils.h"
        "SparseArrayDriver.h"
        "SSEUtils.h"
        "stdafx.h"
        "TCBSpline.h"
        "TFace.h"
        "Vec3a16.h"
        "VertexBufferArrayDrivers.h"
)

target_compile_definitions(CryAnimation PRIVATE COMP_VC)
target_link_libraries(CryAnimation CryCommon)