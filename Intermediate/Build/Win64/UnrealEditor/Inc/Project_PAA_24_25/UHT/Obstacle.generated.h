// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Obstacle.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT_PAA_24_25_Obstacle_generated_h
#error "Obstacle.generated.h already included, missing '#pragma once' in Obstacle.h"
#endif
#define PROJECT_PAA_24_25_Obstacle_generated_h

#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetMaterial);


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAObstacle(); \
	friend struct Z_Construct_UClass_AObstacle_Statics; \
public: \
	DECLARE_CLASS(AObstacle, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project_PAA_24_25"), NO_API) \
	DECLARE_SERIALIZER(AObstacle)


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AObstacle(AObstacle&&); \
	AObstacle(const AObstacle&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AObstacle); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AObstacle); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AObstacle) \
	NO_API virtual ~AObstacle();


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_7_PROLOG
#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_10_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_PAA_24_25_API UClass* StaticClass<class AObstacle>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
