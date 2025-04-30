// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TurnBasedGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AUnitBase;
enum class EAIBehaviorMode : uint8;
#ifdef PROJECT_PAA_24_25_TurnBasedGameMode_generated_h
#error "TurnBasedGameMode.generated.h already included, missing '#pragma once' in TurnBasedGameMode.h"
#endif
#define PROJECT_PAA_24_25_TurnBasedGameMode_generated_h

#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_32_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPathNode_Statics; \
	PROJECT_PAA_24_25_API static class UScriptStruct* StaticStruct();


template<> PROJECT_PAA_24_25_API UScriptStruct* StaticStruct<struct FPathNode>();

#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execStartGame); \
	DECLARE_FUNCTION(execPositionUnitsAlternately); \
	DECLARE_FUNCTION(execEndGame); \
	DECLARE_FUNCTION(execCheckEndGameCondition); \
	DECLARE_FUNCTION(execConvertPositionToNotation); \
	DECLARE_FUNCTION(execLogAttack); \
	DECLARE_FUNCTION(execLogMove); \
	DECLARE_FUNCTION(execSetObstaclePositions); \
	DECLARE_FUNCTION(execHandlePlayerUnitPlacement); \
	DECLARE_FUNCTION(execSelectPrePositionedUnit); \
	DECLARE_FUNCTION(execCoinFlip); \
	DECLARE_FUNCTION(execMoveStepByStep); \
	DECLARE_FUNCTION(execSpawnUnits); \
	DECLARE_FUNCTION(execEndTurn); \
	DECLARE_FUNCTION(execCanAttackPlayerUnit); \
	DECLARE_FUNCTION(execFindClosestPlayerUnit); \
	DECLARE_FUNCTION(execExecuteEnemyAction); \
	DECLARE_FUNCTION(execCalculateValidMovementLocations); \
	DECLARE_FUNCTION(execExecuteRandomEnemyAction); \
	DECLARE_FUNCTION(execStartEnemyTurn); \
	DECLARE_FUNCTION(execStartPlayerTurn); \
	DECLARE_FUNCTION(execSetAIBehaviorMode);


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATurnBasedGameMode(); \
	friend struct Z_Construct_UClass_ATurnBasedGameMode_Statics; \
public: \
	DECLARE_CLASS(ATurnBasedGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project_PAA_24_25"), NO_API) \
	DECLARE_SERIALIZER(ATurnBasedGameMode)


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_50_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATurnBasedGameMode(ATurnBasedGameMode&&); \
	ATurnBasedGameMode(const ATurnBasedGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATurnBasedGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATurnBasedGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATurnBasedGameMode) \
	NO_API virtual ~ATurnBasedGameMode();


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_47_PROLOG
#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_50_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_PAA_24_25_API UClass* StaticClass<class ATurnBasedGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h


#define FOREACH_ENUM_ETURNSTATE(op) \
	op(ETurnState::None) \
	op(ETurnState::PlayerPlacement) \
	op(ETurnState::EnemyPlacement) \
	op(ETurnState::PlayerTurn) \
	op(ETurnState::EnemyTurn) 

enum class ETurnState : uint8;
template<> struct TIsUEnumClass<ETurnState> { enum { Value = true }; };
template<> PROJECT_PAA_24_25_API UEnum* StaticEnum<ETurnState>();

#define FOREACH_ENUM_EAIBEHAVIORMODE(op) \
	op(EAIBehaviorMode::StrategicLogic) \
	op(EAIBehaviorMode::RandomLogic) 

enum class EAIBehaviorMode : uint8;
template<> struct TIsUEnumClass<EAIBehaviorMode> { enum { Value = true }; };
template<> PROJECT_PAA_24_25_API UEnum* StaticEnum<EAIBehaviorMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
