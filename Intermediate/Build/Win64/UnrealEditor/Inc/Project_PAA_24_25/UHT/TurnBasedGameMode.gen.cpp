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
		{ "EnemyTurn.Name", "ETurnState::EnemyTurn" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
		{ "PlayerTurn.Name", "ETurnState::PlayerTurn" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
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

// Begin Class ATurnBasedGameMode Function FindPath
struct Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics
{
	struct TurnBasedGameMode_eventFindPath_Parms
	{
		AUnitBase* Unit;
		FVector StartLocation;
		FVector TargetLocation;
		TArray<FVector> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Unit;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StartLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_Unit = { "Unit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventFindPath_Parms, Unit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_StartLocation = { "StartLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventFindPath_Parms, StartLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventFindPath_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TurnBasedGameMode_eventFindPath_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_Unit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_StartLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_TargetLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATurnBasedGameMode, nullptr, "FindPath", nullptr, nullptr, Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::TurnBasedGameMode_eventFindPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::TurnBasedGameMode_eventFindPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATurnBasedGameMode_FindPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATurnBasedGameMode_FindPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATurnBasedGameMode::execFindPath)
{
	P_GET_OBJECT(AUnitBase,Z_Param_Unit);
	P_GET_STRUCT(FVector,Z_Param_StartLocation);
	P_GET_STRUCT(FVector,Z_Param_TargetLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FVector>*)Z_Param__Result=P_THIS->FindPath(Z_Param_Unit,Z_Param_StartLocation,Z_Param_TargetLocation);
	P_NATIVE_END;
}
// End Class ATurnBasedGameMode Function FindPath

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
		{ "EndTurn", &ATurnBasedGameMode::execEndTurn },
		{ "FindPath", &ATurnBasedGameMode::execFindPath },
		{ "SpawnUnits", &ATurnBasedGameMode::execSpawnUnits },
		{ "StartEnemyTurn", &ATurnBasedGameMode::execStartEnemyTurn },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSize_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerUnitClass_MetaData[] = {
		{ "Category", "Units" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnemyUnitClass_MetaData[] = {
		{ "Category", "Units" },
		{ "ModuleRelativePath", "TurnBasedGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentTurn_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentTurn;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSize;
	static const UECodeGen_Private::FClassPropertyParams NewProp_PlayerUnitClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EnemyUnitClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATurnBasedGameMode_EndTurn, "EndTurn" }, // 4151594387
		{ &Z_Construct_UFunction_ATurnBasedGameMode_FindPath, "FindPath" }, // 462398572
		{ &Z_Construct_UFunction_ATurnBasedGameMode_SpawnUnits, "SpawnUnits" }, // 2564327620
		{ &Z_Construct_UFunction_ATurnBasedGameMode_StartEnemyTurn, "StartEnemyTurn" }, // 2306448951
		{ &Z_Construct_UFunction_ATurnBasedGameMode_StartPlayerTurn, "StartPlayerTurn" }, // 1024927920
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATurnBasedGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentTurn_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentTurn = { "CurrentTurn", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, CurrentTurn), Z_Construct_UEnum_Project_PAA_24_25_ETurnState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTurn_MetaData), NewProp_CurrentTurn_MetaData) }; // 3743081961
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, GridSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSize_MetaData), NewProp_GridSize_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerUnitClass = { "PlayerUnitClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, PlayerUnitClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerUnitClass_MetaData), NewProp_PlayerUnitClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemyUnitClass = { "EnemyUnitClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATurnBasedGameMode, EnemyUnitClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnemyUnitClass_MetaData), NewProp_EnemyUnitClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATurnBasedGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentTurn_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_CurrentTurn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_GridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_PlayerUnitClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATurnBasedGameMode_Statics::NewProp_EnemyUnitClass,
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
		{ ETurnState_StaticEnum, TEXT("ETurnState"), &Z_Registration_Info_UEnum_ETurnState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3743081961U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPathNode::StaticStruct, Z_Construct_UScriptStruct_FPathNode_Statics::NewStructOps, TEXT("PathNode"), &Z_Registration_Info_UScriptStruct_PathNode, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPathNode), 4088780920U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATurnBasedGameMode, ATurnBasedGameMode::StaticClass, TEXT("ATurnBasedGameMode"), &Z_Registration_Info_UClass_ATurnBasedGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATurnBasedGameMode), 75930185U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_3350492426(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_TurnBasedGameMode_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
