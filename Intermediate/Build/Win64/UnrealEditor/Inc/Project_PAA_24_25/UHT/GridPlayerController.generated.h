// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GridPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ACellActor;
class AUnitBase;
#ifdef PROJECT_PAA_24_25_GridPlayerController_generated_h
#error "GridPlayerController.generated.h already included, missing '#pragma once' in GridPlayerController.h"
#endif
#define PROJECT_PAA_24_25_GridPlayerController_generated_h

#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDisablePlayerInput); \
	DECLARE_FUNCTION(execStoreAttack); \
	DECLARE_FUNCTION(execStoreMove); \
	DECLARE_FUNCTION(execHandleEndTurn); \
	DECLARE_FUNCTION(execHandleNextUnit); \
	DECLARE_FUNCTION(execHandleAttackUnit); \
	DECLARE_FUNCTION(execClearMovementRange); \
	DECLARE_FUNCTION(execShowMovementRange); \
	DECLARE_FUNCTION(execMovePlayerStepByStep); \
	DECLARE_FUNCTION(execHandleMoveUnit); \
	DECLARE_FUNCTION(execFindCellUnderUnit); \
	DECLARE_FUNCTION(execHandleSelectUnit); \
	DECLARE_FUNCTION(execHandlePlaceUnit); \
	DECLARE_FUNCTION(execUpdateAllUnitWidgets); \
	DECLARE_FUNCTION(execInitializeGridCells);


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGridPlayerController(); \
	friend struct Z_Construct_UClass_AGridPlayerController_Statics; \
public: \
	DECLARE_CLASS(AGridPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project_PAA_24_25"), NO_API) \
	DECLARE_SERIALIZER(AGridPlayerController)


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGridPlayerController(AGridPlayerController&&); \
	AGridPlayerController(const AGridPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGridPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGridPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGridPlayerController) \
	NO_API virtual ~AGridPlayerController();


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_13_PROLOG
#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_16_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_PAA_24_25_API UClass* StaticClass<class AGridPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
