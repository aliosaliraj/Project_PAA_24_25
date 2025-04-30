// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/TurnBasedGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTurnBasedGameMode() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_ATurnBasedGameMode();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_ATurnBasedGameMode_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AUnitBase_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_UTurnIndicatorWidget_NoRegister();
PROJECT_PAA_24_25_API UEnum* Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode();
PROJECT_PAA_24_25_API UEnum* Z_Construct_UEnum_Project_PAA_24_25_ETurnState();
PROJECT_PAA_24_25_API UScriptStruct* Z_Construct_UScriptStruct_FPathNode();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Enum ETurnState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ETurnState;
static UEnum* ETurnState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ETurnState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ETurnState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Project_PAA_24_25_ETurnState, (UObject*)Z_Construct_UPackage__Script_Project_PAA_24_25(), TEXT("ETurnState"));
	}
	return Z_Registration_Info_UEnum_ETurnState.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UEnum* StaticEnum<ETurnState>()
{
	return ETurnState_StaticEnum();
}
struct Z_Construct_UEnum_Project_PAA_24_25_ETurnState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EnemyPlacement.Name", "ETurnState::EnemyPlacement" },
		{ "EnemyTurn.Name", "ETurnState::EnemyTurn" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
		{ "None.Name", "ETurnState::None" },
		{ "PlayerPlacement.Name", "ETurnState::PlayerPlacement" },
		{ "PlayerTurn.Name", "ETurnState::PlayerTurn" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ETurnState::None", (int64)ETurnState::None },
		{ "ETurnState::PlayerPlacement", (int64)ETurnState::PlayerPlacement },
		{ "ETurnState::EnemyPlacement", (int64)ETurnState::EnemyPlacement },
		{ "ETurnState::PlayerTurn", (int64)ETurnState::PlayerTurn },
		{ "ETurnState::EnemyTurn", (int64)ETurnState::EnemyTurn },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Project_PAA_24_25_ETurnState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
	nullptr,
	"ETurnState",
	"ETurnState",
	Z_Construct_UEnum_Project_PAA_24_25_ETurnState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Project_PAA_24_25_ETurnState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Project_PAA_24_25_ETurnState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Project_PAA_24_25_ETurnState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Project_PAA_24_25_ETurnState()
{
	if (!Z_Registration_Info_UEnum_ETurnState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ETurnState.InnerSingleton, Z_Construct_UEnum_Project_PAA_24_25_ETurnState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ETurnState.InnerSingleton;
}
// End Enum ETurnState

// Begin Enum EAIBehaviorMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAIBehaviorMode;
static UEnum* EAIBehaviorMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAIBehaviorMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAIBehaviorMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode, (UObject*)Z_Construct_UPackage__Script_Project_PAA_24_25(), TEXT("EAIBehaviorMode"));
	}
	return Z_Registration_Info_UEnum_EAIBehaviorMode.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UEnum* StaticEnum<EAIBehaviorMode>()
{
	return EAIBehaviorMode_StaticEnum();
}
struct Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
		{ "RandomLogic.Comment", "// Mode A*\n" },
		{ "RandomLogic.DisplayName", "Random Logic" },
		{ "RandomLogic.Name", "EAIBehaviorMode::RandomLogic" },
		{ "RandomLogic.ToolTip", "Mode A*" },
		{ "StrategicLogic.DisplayName", "Strategic Logic" },
		{ "StrategicLogic.Name", "EAIBehaviorMode::StrategicLogic" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAIBehaviorMode::StrategicLogic", (int64)EAIBehaviorMode::StrategicLogic },
		{ "EAIBehaviorMode::RandomLogic", (int64)EAIBehaviorMode::RandomLogic },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
	nullptr,
	"EAIBehaviorMode",
	"EAIBehaviorMode",
	Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode()
{
	if (!Z_Registration_Info_UEnum_EAIBehaviorMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAIBehaviorMode.InnerSingleton, Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAIBehaviorMode.InnerSingleton;
}
// End Enum EAIBehaviorMode

// Begin ScriptStruct FPathNode
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PathNode;
class UScriptStruct* FPathNode::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PathNode.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PathNode.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPathNode, (UObject*)Z_Construct_UPackage__Script_Project_PAA_24_25(), TEXT("PathNode"));
	}
	return Z_Registration_Info_UScriptStruct_PathNode.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UScriptStruct* StaticStruct<FPathNode>()
{
	return FPathNode::StaticStruct();
}
struct Z_Construct_UScriptStruct_FPathNode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPathNode>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPathNode_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
	nullptr,
	&NewStructOps,
	"PathNode",
	nullptr,
	0,
	sizeof(FPathNode),
	alignof(FPathNode),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPathNode_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPathNode_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPathNode()
{
	if (!Z_Registration_Info_UScriptStruct_PathNode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PathNode.InnerSingleton, Z_Construct_UScriptStruct_FPathNode_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_PathNode.InnerSingleton;
}
// End ScriptStruct FPathNode

// Begin Class ATurnBasedGameMode Function CalculateValidMovementLocations
struct Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics
{
	struct TurnBasedGameMode_eventCalculateValidMovementLocations_Parms
	{
		AUnitBase* Unit;
		TArray<FVector> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Unit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::NewProp_Unit = { "Unit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventCalculateValidMovementLocations_Parms, Unit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventCalculateValidMovementLocations_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::NewProp_Unit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "CalculateValidMovementLocations", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::TurnBasedGameMode_eventCalculateValidMovementLocations_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::TurnBasedGameMode_eventCalculateValidMovementLocations_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execCalculateValidMovementLocations)
{
	P_GET_OBJECT(AUnitBase,Z_Param_Unit);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FVector>*)Z_Param__Result=P_THIS->CalculateValidMovementLocations(Z_Param_Unit);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function CalculateValidMovementLocations

// Begin Class ATurnBasedGameMode Function CanAttackPlayerUnit
struct Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics
{
	struct TurnBasedGameMode_eventCanAttackPlayerUnit_Parms
	{
		AUnitBase* EnemyUnit;
		AUnitBase* PlayerUnit;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyUnit;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerUnit;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::NewProp_EnemyUnit = { "EnemyUnit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventCanAttackPlayerUnit_Parms, EnemyUnit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::NewProp_PlayerUnit = { "PlayerUnit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventCanAttackPlayerUnit_Parms, PlayerUnit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((TurnBasedGameMode_eventCanAttackPlayerUnit_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TurnBasedGameMode_eventCanAttackPlayerUnit_Parms), &Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::NewProp_EnemyUnit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::NewProp_PlayerUnit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "CanAttackPlayerUnit", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::TurnBasedGameMode_eventCanAttackPlayerUnit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::TurnBasedGameMode_eventCanAttackPlayerUnit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execCanAttackPlayerUnit)
{
	P_GET_OBJECT(AUnitBase,Z_Param_EnemyUnit);
	P_GET_OBJECT(AUnitBase,Z_Param_PlayerUnit);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanAttackPlayerUnit(Z_Param_EnemyUnit,Z_Param_PlayerUnit);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function CanAttackPlayerUnit

// Begin Class ATurnBasedGameMode Function CheckEndGameCondition
struct Z_Construct_UFunction_ATurnBasedGameMode_CheckEndGameCondition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_CheckEndGameCondition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "CheckEndGameCondition", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_CheckEndGameCondition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_CheckEndGameCondition_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_CheckEndGameCondition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_CheckEndGameCondition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execCheckEndGameCondition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CheckEndGameCondition();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function CheckEndGameCondition

// Begin Class ATurnBasedGameMode Function CoinFlip
struct Z_Construct_UFunction_ATurnBasedGameMode_CoinFlip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_CoinFlip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "CoinFlip", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_CoinFlip_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_CoinFlip_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_CoinFlip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_CoinFlip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execCoinFlip)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CoinFlip();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function CoinFlip

// Begin Class ATurnBasedGameMode Function ConvertPositionToNotation
struct Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics
{
	struct TurnBasedGameMode_eventConvertPositionToNotation_Parms
	{
		FVector Position;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventConvertPositionToNotation_Parms, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventConvertPositionToNotation_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "ConvertPositionToNotation", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::TurnBasedGameMode_eventConvertPositionToNotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::TurnBasedGameMode_eventConvertPositionToNotation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execConvertPositionToNotation)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->ConvertPositionToNotation(Z_Param_Out_Position);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function ConvertPositionToNotation

// Begin Class ATurnBasedGameMode Function EndGame
struct Z_Construct_UFunction_ATurnBasedGameMode_EndGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_EndGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "EndGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_EndGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_EndGame_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_EndGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_EndGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execEndGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndGame();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function EndGame

// Begin Class ATurnBasedGameMode Function EndTurn
struct Z_Construct_UFunction_ATurnBasedGameMode_EndTurn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_EndTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "EndTurn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_EndTurn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_EndTurn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_EndTurn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_EndTurn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execEndTurn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndTurn();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function EndTurn

// Begin Class ATurnBasedGameMode Function ExecuteEnemyAction
struct Z_Construct_UFunction_ATurnBasedGameMode_ExecuteEnemyAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_ExecuteEnemyAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "ExecuteEnemyAction", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_ExecuteEnemyAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_ExecuteEnemyAction_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_ExecuteEnemyAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_ExecuteEnemyAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execExecuteEnemyAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecuteEnemyAction();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function ExecuteEnemyAction

// Begin Class ATurnBasedGameMode Function ExecuteRandomEnemyAction
struct Z_Construct_UFunction_ATurnBasedGameMode_ExecuteRandomEnemyAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_ExecuteRandomEnemyAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "ExecuteRandomEnemyAction", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_ExecuteRandomEnemyAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_ExecuteRandomEnemyAction_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_ExecuteRandomEnemyAction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_ExecuteRandomEnemyAction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execExecuteRandomEnemyAction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExecuteRandomEnemyAction();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function ExecuteRandomEnemyAction

// Begin Class ATurnBasedGameMode Function FindClosestPlayerUnit
struct Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics
{
	struct TurnBasedGameMode_eventFindClosestPlayerUnit_Parms
	{
		AUnitBase* EnemyUnit;
		AUnitBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyUnit;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::NewProp_EnemyUnit = { "EnemyUnit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventFindClosestPlayerUnit_Parms, EnemyUnit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventFindClosestPlayerUnit_Parms, ReturnValue), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::NewProp_EnemyUnit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "FindClosestPlayerUnit", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::TurnBasedGameMode_eventFindClosestPlayerUnit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::TurnBasedGameMode_eventFindClosestPlayerUnit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execFindClosestPlayerUnit)
{
	P_GET_OBJECT(AUnitBase,Z_Param_EnemyUnit);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AUnitBase**)Z_Param__Result=P_THIS->FindClosestPlayerUnit(Z_Param_EnemyUnit);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function FindClosestPlayerUnit

// Begin Class ATurnBasedGameMode Function HandlePlayerUnitPlacement
struct Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics
{
	struct TurnBasedGameMode_eventHandlePlayerUnitPlacement_Parms
	{
		FVector ChosenLocation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChosenLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::NewProp_ChosenLocation = { "ChosenLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventHandlePlayerUnitPlacement_Parms, ChosenLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::NewProp_ChosenLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "HandlePlayerUnitPlacement", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::TurnBasedGameMode_eventHandlePlayerUnitPlacement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::TurnBasedGameMode_eventHandlePlayerUnitPlacement_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execHandlePlayerUnitPlacement)
{
	P_GET_STRUCT(FVector,Z_Param_ChosenLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePlayerUnitPlacement(Z_Param_ChosenLocation);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function HandlePlayerUnitPlacement

// Begin Class ATurnBasedGameMode Function LogAttack
struct Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics
{
	struct TurnBasedGameMode_eventLogAttack_Parms
	{
		FString PlayerID;
		FString UnitType;
		FString TargetCell;
		int32 Damage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerID_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetCell_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UnitType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetCell;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::NewProp_PlayerID = { "PlayerID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventLogAttack_Parms, PlayerID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerID_MetaData), NewProp_PlayerID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::NewProp_UnitType = { "UnitType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventLogAttack_Parms, UnitType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitType_MetaData), NewProp_UnitType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::NewProp_TargetCell = { "TargetCell", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventLogAttack_Parms, TargetCell), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetCell_MetaData), NewProp_TargetCell_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventLogAttack_Parms, Damage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::NewProp_PlayerID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::NewProp_UnitType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::NewProp_TargetCell,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::NewProp_Damage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "LogAttack", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::TurnBasedGameMode_eventLogAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::TurnBasedGameMode_eventLogAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_LogAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_LogAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execLogAttack)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PlayerID);
	P_GET_PROPERTY(FStrProperty,Z_Param_UnitType);
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetCell);
	P_GET_PROPERTY(FIntProperty,Z_Param_Damage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LogAttack(Z_Param_PlayerID,Z_Param_UnitType,Z_Param_TargetCell,Z_Param_Damage);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function LogAttack

// Begin Class ATurnBasedGameMode Function LogMove
struct Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics
{
	struct TurnBasedGameMode_eventLogMove_Parms
	{
		FString PlayerID;
		FString UnitType;
		FString OriginCell;
		FString DestinationCell;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerID_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OriginCell_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationCell_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UnitType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OriginCell;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DestinationCell;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::NewProp_PlayerID = { "PlayerID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventLogMove_Parms, PlayerID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerID_MetaData), NewProp_PlayerID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::NewProp_UnitType = { "UnitType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventLogMove_Parms, UnitType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitType_MetaData), NewProp_UnitType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::NewProp_OriginCell = { "OriginCell", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventLogMove_Parms, OriginCell), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OriginCell_MetaData), NewProp_OriginCell_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::NewProp_DestinationCell = { "DestinationCell", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventLogMove_Parms, DestinationCell), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationCell_MetaData), NewProp_DestinationCell_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::NewProp_PlayerID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::NewProp_UnitType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::NewProp_OriginCell,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::NewProp_DestinationCell,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "LogMove", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::TurnBasedGameMode_eventLogMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::TurnBasedGameMode_eventLogMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_LogMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_LogMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execLogMove)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PlayerID);
	P_GET_PROPERTY(FStrProperty,Z_Param_UnitType);
	P_GET_PROPERTY(FStrProperty,Z_Param_OriginCell);
	P_GET_PROPERTY(FStrProperty,Z_Param_DestinationCell);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LogMove(Z_Param_PlayerID,Z_Param_UnitType,Z_Param_OriginCell,Z_Param_DestinationCell);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function LogMove

// Begin Class ATurnBasedGameMode Function MoveStepByStep
struct Z_Construct_UFunction_ATurnBasedGameMode_MoveStepByStep_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_MoveStepByStep_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "MoveStepByStep", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_MoveStepByStep_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_MoveStepByStep_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_MoveStepByStep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_MoveStepByStep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execMoveStepByStep)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MoveStepByStep();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function MoveStepByStep

// Begin Class ATurnBasedGameMode Function PositionUnitsAlternately
struct Z_Construct_UFunction_ATurnBasedGameMode_PositionUnitsAlternately_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_PositionUnitsAlternately_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "PositionUnitsAlternately", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_PositionUnitsAlternately_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_PositionUnitsAlternately_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_PositionUnitsAlternately()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_PositionUnitsAlternately_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execPositionUnitsAlternately)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PositionUnitsAlternately();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function PositionUnitsAlternately

// Begin Class ATurnBasedGameMode Function SelectPrePositionedUnit
struct Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics
{
	struct TurnBasedGameMode_eventSelectPrePositionedUnit_Parms
	{
		AUnitBase* SelectedUnit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedUnit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::NewProp_SelectedUnit = { "SelectedUnit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventSelectPrePositionedUnit_Parms, SelectedUnit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::NewProp_SelectedUnit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "SelectPrePositionedUnit", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::TurnBasedGameMode_eventSelectPrePositionedUnit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::TurnBasedGameMode_eventSelectPrePositionedUnit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execSelectPrePositionedUnit)
{
	P_GET_OBJECT(AUnitBase,Z_Param_SelectedUnit);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SelectPrePositionedUnit(Z_Param_SelectedUnit);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function SelectPrePositionedUnit

// Begin Class ATurnBasedGameMode Function SetAIBehaviorMode
struct Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics
{
	struct TurnBasedGameMode_eventSetAIBehaviorMode_Parms
	{
		EAIBehaviorMode NewMode;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::NewProp_NewMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::NewProp_NewMode = { "NewMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventSetAIBehaviorMode_Parms, NewMode), Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode, METADATA_PARAMS(0, nullptr) }; // 189611490
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::NewProp_NewMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::NewProp_NewMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "SetAIBehaviorMode", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::TurnBasedGameMode_eventSetAIBehaviorMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::TurnBasedGameMode_eventSetAIBehaviorMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execSetAIBehaviorMode)
{
	P_GET_ENUM(EAIBehaviorMode,Z_Param_NewMode);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAIBehaviorMode(EAIBehaviorMode(Z_Param_NewMode));
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function SetAIBehaviorMode

// Begin Class ATurnBasedGameMode Function SetObstaclePositions
struct Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics
{
	struct TurnBasedGameMode_eventSetObstaclePositions_Parms
	{
		TArray<FVector> Positions;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Positions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Positions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Positions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::NewProp_Positions_Inner = { "Positions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::NewProp_Positions = { "Positions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventSetObstaclePositions_Parms, Positions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Positions_MetaData), NewProp_Positions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::NewProp_Positions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::NewProp_Positions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "SetObstaclePositions", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::TurnBasedGameMode_eventSetObstaclePositions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::TurnBasedGameMode_eventSetObstaclePositions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execSetObstaclePositions)
{
	P_GET_TARRAY_REF(FVector,Z_Param_Out_Positions);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetObstaclePositions(Z_Param_Out_Positions);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function SetObstaclePositions

// Begin Class ATurnBasedGameMode Function SpawnUnits
struct Z_Construct_UFunction_ATurnBasedGameMode_SpawnUnits_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_SpawnUnits_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "SpawnUnits", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_SpawnUnits_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_SpawnUnits_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_SpawnUnits()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_SpawnUnits_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execSpawnUnits)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnUnits();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function SpawnUnits

// Begin Class ATurnBasedGameMode Function StartEnemyTurn
struct Z_Construct_UFunction_ATurnBasedGameMode_StartEnemyTurn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_StartEnemyTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "StartEnemyTurn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_StartEnemyTurn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_StartEnemyTurn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_StartEnemyTurn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_StartEnemyTurn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execStartEnemyTurn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartEnemyTurn();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function StartEnemyTurn

// Begin Class ATurnBasedGameMode Function StartGame
struct Z_Construct_UFunction_ATurnBasedGameMode_StartGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_StartGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "StartGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_StartGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_StartGame_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_StartGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_StartGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execStartGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartGame();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function StartGame

// Begin Class ATurnBasedGameMode Function StartPlayerTurn
struct Z_Construct_UFunction_ATurnBasedGameMode_StartPlayerTurn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_StartPlayerTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "StartPlayerTurn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_StartPlayerTurn_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_StartPlayerTurn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_StartPlayerTurn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_StartPlayerTurn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execStartPlayerTurn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartPlayerTurn();
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function StartPlayerTurn

// Begin Class ATurnBasedGameMode
void ATurnBasedGameMode::StaticRegisterNativesATurnBasedGameMode()
{
	UClass* Class = ATurnBasedGameMode::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CalculateValidMovementLocations", &ATurnBasedGameMode::execCalculateValidMovementLocations },
		{ "CanAttackPlayerUnit", &ATurnBasedGameMode::execCanAttackPlayerUnit },
		{ "CheckEndGameCondition", &ATurnBasedGameMode::execCheckEndGameCondition },
		{ "CoinFlip", &ATurnBasedGameMode::execCoinFlip },
		{ "ConvertPositionToNotation", &ATurnBasedGameMode::execConvertPositionToNotation },
		{ "EndGame", &ATurnBasedGameMode::execEndGame },
		{ "EndTurn", &ATurnBasedGameMode::execEndTurn },
		{ "ExecuteEnemyAction", &ATurnBasedGameMode::execExecuteEnemyAction },
		{ "ExecuteRandomEnemyAction", &ATurnBasedGameMode::execExecuteRandomEnemyAction },
		{ "FindClosestPlayerUnit", &ATurnBasedGameMode::execFindClosestPlayerUnit },
		{ "HandlePlayerUnitPlacement", &ATurnBasedGameMode::execHandlePlayerUnitPlacement },
		{ "LogAttack", &ATurnBasedGameMode::execLogAttack },
		{ "LogMove", &ATurnBasedGameMode::execLogMove },
		{ "MoveStepByStep", &ATurnBasedGameMode::execMoveStepByStep },
		{ "PositionUnitsAlternately", &ATurnBasedGameMode::execPositionUnitsAlternately },
		{ "SelectPrePositionedUnit", &ATurnBasedGameMode::execSelectPrePositionedUnit },
		{ "SetAIBehaviorMode", &ATurnBasedGameMode::execSetAIBehaviorMode },
		{ "SetObstaclePositions", &ATurnBasedGameMode::execSetObstaclePositions },
		{ "SpawnUnits", &ATurnBasedGameMode::execSpawnUnits },
		{ "StartEnemyTurn", &ATurnBasedGameMode::execStartEnemyTurn },
		{ "StartGame", &ATurnBasedGameMode::execStartGame },
		{ "StartPlayerTurn", &ATurnBasedGameMode::execStartPlayerTurn },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATurnBasedGameMode);
UClass* Z_Construct_UClass_ATurnBasedGameMode_NoRegister()
{
	return ATurnBasedGameMode::StaticClass();
}
struct Z_Construct_UClass_ATurnBasedGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TurnBasedGameMode.h" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTurn_MetaData[] = {
		{ "Category", "TurnBasedGameMode" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAIBehaviorMode_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSize_MetaData[] = {
		{ "Category", "Grid" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// AI behavior mode\n" },
#endif
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AI behavior mode" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerSniperClass_MetaData[] = {
		{ "Category", "Units" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerBrawlerClass_MetaData[] = {
		{ "Category", "Units" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemySniperClass_MetaData[] = {
		{ "Category", "Units" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyBrawlerClass_MetaData[] = {
		{ "Category", "Units" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerUnits_MetaData[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyUnits_MetaData[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EliminatedPlayerUnits_MetaData[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EliminatedEnemyUnits_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// to keep track of eliminated player units\n" },
#endif
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "to keep track of eliminated player units" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurnIndicatorWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// to keep track of eliminated enemy units\n" },
#endif
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "to keep track of eliminated enemy units" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurnIndicatorWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedPlayerUnit_MetaData[] = {
		{ "Category", "Player Unit Placement" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentTurn_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentTurn;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentAIBehaviorMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentAIBehaviorMode;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSize;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerSniperClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerBrawlerClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EnemySniperClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EnemyBrawlerClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerUnits_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PlayerUnits;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemyUnits_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_EnemyUnits;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EliminatedPlayerUnits_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_EliminatedPlayerUnits;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EliminatedEnemyUnits_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_EliminatedEnemyUnits;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TurnIndicatorWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnIndicatorWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedPlayerUnit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATurnBasedGameMode_CalculateValidMovementLocations, "CalculateValidMovementLocations" }, // 588916723
		{ &Z_Construct_UFunction_ATurnBasedGameMode_CanAttackPlayerUnit, "CanAttackPlayerUnit" }, // 1035134896
		{ &Z_Construct_UFunction_ATurnBasedGameMode_CheckEndGameCondition, "CheckEndGameCondition" }, // 3857987166
		{ &Z_Construct_UFunction_ATurnBasedGameMode_CoinFlip, "CoinFlip" }, // 3686464708
		{ &Z_Construct_UFunction_ATurnBasedGameMode_ConvertPositionToNotation, "ConvertPositionToNotation" }, // 1379674188
		{ &Z_Construct_UFunction_ATurnBasedGameMode_EndGame, "EndGame" }, // 865146540
		{ &Z_Construct_UFunction_ATurnBasedGameMode_EndTurn, "EndTurn" }, // 4151594387
		{ &Z_Construct_UFunction_ATurnBasedGameMode_ExecuteEnemyAction, "ExecuteEnemyAction" }, // 2488843766
		{ &Z_Construct_UFunction_ATurnBasedGameMode_ExecuteRandomEnemyAction, "ExecuteRandomEnemyAction" }, // 2754246242
		{ &Z_Construct_UFunction_ATurnBasedGameMode_FindClosestPlayerUnit, "FindClosestPlayerUnit" }, // 3691222005
		{ &Z_Construct_UFunction_ATurnBasedGameMode_HandlePlayerUnitPlacement, "HandlePlayerUnitPlacement" }, // 153629505
		{ &Z_Construct_UFunction_ATurnBasedGameMode_LogAttack, "LogAttack" }, // 1699916775
		{ &Z_Construct_UFunction_ATurnBasedGameMode_LogMove, "LogMove" }, // 1483935191
		{ &Z_Construct_UFunction_ATurnBasedGameMode_MoveStepByStep, "MoveStepByStep" }, // 278156156
		{ &Z_Construct_UFunction_ATurnBasedGameMode_PositionUnitsAlternately, "PositionUnitsAlternately" }, // 3695659152
		{ &Z_Construct_UFunction_ATurnBasedGameMode_SelectPrePositionedUnit, "SelectPrePositionedUnit" }, // 3335018416
		{ &Z_Construct_UFunction_ATurnBasedGameMode_SetAIBehaviorMode, "SetAIBehaviorMode" }, // 2884022098
		{ &Z_Construct_UFunction_ATurnBasedGameMode_SetObstaclePositions, "SetObstaclePositions" }, // 542367847
		{ &Z_Construct_UFunction_ATurnBasedGameMode_SpawnUnits, "SpawnUnits" }, // 2564327620
		{ &Z_Construct_UFunction_ATurnBasedGameMode_StartEnemyTurn, "StartEnemyTurn" }, // 2306448951
		{ &Z_Construct_UFunction_ATurnBasedGameMode_StartGame, "StartGame" }, // 547176523
		{ &Z_Construct_UFunction_ATurnBasedGameMode_StartPlayerTurn, "StartPlayerTurn" }, // 1024927920
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATurnBasedGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentTurn_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentTurn = { "CurrentTurn", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, CurrentTurn), Z_Construct_UEnum_Project_PAA_24_25_ETurnState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTurn_MetaData), NewProp_CurrentTurn_MetaData) }; // 471892724
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentAIBehaviorMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentAIBehaviorMode = { "CurrentAIBehaviorMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, CurrentAIBehaviorMode), Z_Construct_UEnum_Project_PAA_24_25_EAIBehaviorMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAIBehaviorMode_MetaData), NewProp_CurrentAIBehaviorMode_MetaData) }; // 189611490
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, GridSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSize_MetaData), NewProp_GridSize_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerSniperClass = { "PlayerSniperClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, PlayerSniperClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerSniperClass_MetaData), NewProp_PlayerSniperClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerBrawlerClass = { "PlayerBrawlerClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, PlayerBrawlerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerBrawlerClass_MetaData), NewProp_PlayerBrawlerClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemySniperClass = { "EnemySniperClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, EnemySniperClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemySniperClass_MetaData), NewProp_EnemySniperClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemyBrawlerClass = { "EnemyBrawlerClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, EnemyBrawlerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyBrawlerClass_MetaData), NewProp_EnemyBrawlerClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerUnits_Inner = { "PlayerUnits", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerUnits = { "PlayerUnits", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, PlayerUnits), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerUnits_MetaData), NewProp_PlayerUnits_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemyUnits_Inner = { "EnemyUnits", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemyUnits = { "EnemyUnits", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, EnemyUnits), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyUnits_MetaData), NewProp_EnemyUnits_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EliminatedPlayerUnits_Inner = { "EliminatedPlayerUnits", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EliminatedPlayerUnits = { "EliminatedPlayerUnits", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, EliminatedPlayerUnits), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EliminatedPlayerUnits_MetaData), NewProp_EliminatedPlayerUnits_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EliminatedEnemyUnits_Inner = { "EliminatedEnemyUnits", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EliminatedEnemyUnits = { "EliminatedEnemyUnits", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, EliminatedEnemyUnits), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EliminatedEnemyUnits_MetaData), NewProp_EliminatedEnemyUnits_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_TurnIndicatorWidgetClass = { "TurnIndicatorWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, TurnIndicatorWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UTurnIndicatorWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurnIndicatorWidgetClass_MetaData), NewProp_TurnIndicatorWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_TurnIndicatorWidget = { "TurnIndicatorWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, TurnIndicatorWidget), Z_Construct_UClass_UTurnIndicatorWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurnIndicatorWidget_MetaData), NewProp_TurnIndicatorWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_SelectedPlayerUnit = { "SelectedPlayerUnit", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, SelectedPlayerUnit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedPlayerUnit_MetaData), NewProp_SelectedPlayerUnit_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATurnBasedGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentTurn_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentTurn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentAIBehaviorMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentAIBehaviorMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_GridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerSniperClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerBrawlerClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemySniperClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemyBrawlerClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerUnits_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerUnits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemyUnits_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemyUnits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EliminatedPlayerUnits_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EliminatedPlayerUnits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EliminatedEnemyUnits_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EliminatedEnemyUnits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_TurnIndicatorWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_TurnIndicatorWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_SelectedPlayerUnit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATurnBasedGameMode_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATurnBasedGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATurnBasedGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATurnBasedGameMode_Statics::ClassParams = {
	&ATurnBasedGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ATurnBasedGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ATurnBasedGameMode_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATurnBasedGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ATurnBasedGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATurnBasedGameMode()
{
	if (!Z_Registration_Info_UClass_ATurnBasedGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATurnBasedGameMode.OuterSingleton, Z_Construct_UClass_ATurnBasedGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATurnBasedGameMode.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<ATurnBasedGameMode>()
{
	return ATurnBasedGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATurnBasedGameMode);
ATurnBasedGameMode::~ATurnBasedGameMode() {}
// End Class ATurnBasedGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ETurnState_StaticEnum, TEXT("ETurnState"), &Z_Registration_Info_UEnum_ETurnState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 471892724U) },
		{ EAIBehaviorMode_StaticEnum, TEXT("EAIBehaviorMode"), &Z_Registration_Info_UEnum_EAIBehaviorMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 189611490U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPathNode::StaticStruct, Z_Construct_UScriptStruct_FPathNode_Statics::NewStructOps, TEXT("PathNode"), &Z_Registration_Info_UScriptStruct_PathNode, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPathNode), 4088780920U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATurnBasedGameMode, ATurnBasedGameMode::StaticClass, TEXT("ATurnBasedGameMode"), &Z_Registration_Info_UClass_ATurnBasedGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATurnBasedGameMode), 1659742505U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_1698145576(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
