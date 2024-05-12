#ifndef cryphysics_h
#define cryphysics_h
#pragma once

#if !defined(_XBOX) && !defined(FAR_CRY_STATIC_LIBS)
	#ifdef PHYSICS_EXPORTS
		#define CRYPHYSICS_API __declspec(dllexport)
	#else
		#define CRYPHYSICS_API __declspec(dllimport)
		#define vector_class Vec3d
	#endif
#else
	#define CRYPHYSICS_API
#endif

#include "utils.h"
#include "primitives.h"
#include "physinterface.h"

extern "C" CRYPHYSICS_API IPhysicalWorld *CreatePhysicalWorld();

#endif