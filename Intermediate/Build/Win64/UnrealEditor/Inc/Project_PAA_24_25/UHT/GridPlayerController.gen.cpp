// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/GridPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridPlayerController() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_ACellActor_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AGridPlayerController();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AGridPlayerController_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AStrategyCamera_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AUnitBase_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_UTurnIndicatorWidget_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_UUnitInfoWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class AGridPlayerController Function ClearMovementRange
struct Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics
{
	struct GridPlayerController_eventClearMovementRange_Parms
	{
		bool bMovementOrAttack;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bMovementOrAttack_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMovementOrAttack;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::NewProp_bMovementOrAttack_SetBit(void* Obj)
{
	((GridPlayerController_eventClearMovementRange_Parms*)Obj)->bMovementOrAttack = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::NewProp_bMovementOrAttack = { "bMovementOrAttack", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GridPlayerController_eventClearMovementRange_Parms), &Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::NewProp_bMovementOrAttack_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::NewProp_bMovementOrAttack,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "ClearMovementRange", nullptr, nullptr, Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::GridPlayerController_eventClearMovementRange_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::GridPlayerController_eventClearMovementRange_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridPlayerController_ClearMovementRange()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_ClearMovementRange_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execClearMovementRange)
{
	P_GET_UBOOL(Z_Param_bMovementOrAttack);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearMovementRange(Z_Param_bMovementOrAttack);
	P_NATIVE_END;
}
// End Class AGridPlayerController Function ClearMovementRange

// Begin Class AGridPlayerController Function DisablePlayerInput
struct Z_Construct_UFunction_AGridPlayerController_DisablePlayerInput_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_DisablePlayerInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "DisablePlayerInput", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_DisablePlayerInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_DisablePlayerInput_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_DisablePlayerInput()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_DisablePlayerInput_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execDisablePlayerInput)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DisablePlayerInput();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function DisablePlayerInput

// Begin Class AGridPlayerController Function FindCellUnderUnit
struct Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics
{
	struct GridPlayerController_eventFindCellUnderUnit_Parms
	{
		FVector UnitLocation;
		ACellActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_UnitLocation;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::NewProp_UnitLocation = { "UnitLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridPlayerController_eventFindCellUnderUnit_Parms, UnitLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridPlayerController_eventFindCellUnderUnit_Parms, ReturnValue), Z_Construct_UClass_ACellActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::NewProp_UnitLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "FindCellUnderUnit", nullptr, nullptr, Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::GridPlayerController_eventFindCellUnderUnit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::GridPlayerController_eventFindCellUnderUnit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execFindCellUnderUnit)
{
	P_GET_STRUCT(FVector,Z_Param_UnitLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ACellActor**)Z_Param__Result=P_THIS->FindCellUnderUnit(Z_Param_UnitLocation);
	P_NATIVE_END;
}
// End Class AGridPlayerController Function FindCellUnderUnit

// Begin Class AGridPlayerController Function HandleAttackUnit
struct Z_Construct_UFunction_AGridPlayerController_HandleAttackUnit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_HandleAttackUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "HandleAttackUnit", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_HandleAttackUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_HandleAttackUnit_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_HandleAttackUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_HandleAttackUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execHandleAttackUnit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleAttackUnit();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function HandleAttackUnit

// Begin Class AGridPlayerController Function HandleEndTurn
struct Z_Construct_UFunction_AGridPlayerController_HandleEndTurn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_HandleEndTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "HandleEndTurn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_HandleEndTurn_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_HandleEndTurn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_HandleEndTurn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_HandleEndTurn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execHandleEndTurn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleEndTurn();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function HandleEndTurn

// Begin Class AGridPlayerController Function HandleMoveUnit
struct Z_Construct_UFunction_AGridPlayerController_HandleMoveUnit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_HandleMoveUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "HandleMoveUnit", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_HandleMoveUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_HandleMoveUnit_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_HandleMoveUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_HandleMoveUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execHandleMoveUnit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoveUnit();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function HandleMoveUnit

// Begin Class AGridPlayerController Function HandleNextUnit
struct Z_Construct_UFunction_AGridPlayerController_HandleNextUnit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_HandleNextUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "HandleNextUnit", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_HandleNextUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_HandleNextUnit_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_HandleNextUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_HandleNextUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execHandleNextUnit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleNextUnit();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function HandleNextUnit

// Begin Class AGridPlayerController Function HandlePlaceUnit
struct Z_Construct_UFunction_AGridPlayerController_HandlePlaceUnit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_HandlePlaceUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "HandlePlaceUnit", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_HandlePlaceUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_HandlePlaceUnit_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_HandlePlaceUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_HandlePlaceUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execHandlePlaceUnit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePlaceUnit();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function HandlePlaceUnit

// Begin Class AGridPlayerController Function HandleSelectUnit
struct Z_Construct_UFunction_AGridPlayerController_HandleSelectUnit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_HandleSelectUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "HandleSelectUnit", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_HandleSelectUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_HandleSelectUnit_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_HandleSelectUnit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_HandleSelectUnit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execHandleSelectUnit)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSelectUnit();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function HandleSelectUnit

// Begin Class AGridPlayerController Function InitializeGridCells
struct Z_Construct_UFunction_AGridPlayerController_InitializeGridCells_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_InitializeGridCells_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "InitializeGridCells", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_InitializeGridCells_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_InitializeGridCells_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_InitializeGridCells()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_InitializeGridCells_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execInitializeGridCells)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeGridCells();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function InitializeGridCells

// Begin Class AGridPlayerController Function MovePlayerStepByStep
struct Z_Construct_UFunction_AGridPlayerController_MovePlayerStepByStep_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_MovePlayerStepByStep_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "MovePlayerStepByStep", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_MovePlayerStepByStep_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_MovePlayerStepByStep_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_MovePlayerStepByStep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_MovePlayerStepByStep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execMovePlayerStepByStep)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->MovePlayerStepByStep();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function MovePlayerStepByStep

// Begin Class AGridPlayerController Function ShowMovementRange
struct Z_Construct_UFunction_AGridPlayerController_ShowMovementRange_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_ShowMovementRange_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "ShowMovementRange", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_ShowMovementRange_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_ShowMovementRange_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_ShowMovementRange()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_ShowMovementRange_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execShowMovementRange)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowMovementRange();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function ShowMovementRange

// Begin Class AGridPlayerController Function StoreAttack
struct Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics
{
	struct GridPlayerController_eventStoreAttack_Parms
	{
		AUnitBase* AttackingUnit;
		AUnitBase* TargetUnit;
		int32 CurrentDamage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackingUnit;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetUnit;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentDamage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::NewProp_AttackingUnit = { "AttackingUnit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridPlayerController_eventStoreAttack_Parms, AttackingUnit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::NewProp_TargetUnit = { "TargetUnit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridPlayerController_eventStoreAttack_Parms, TargetUnit), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::NewProp_CurrentDamage = { "CurrentDamage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridPlayerController_eventStoreAttack_Parms, CurrentDamage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::NewProp_AttackingUnit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::NewProp_TargetUnit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::NewProp_CurrentDamage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "StoreAttack", nullptr, nullptr, Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::GridPlayerController_eventStoreAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::GridPlayerController_eventStoreAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridPlayerController_StoreAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_StoreAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execStoreAttack)
{
	P_GET_OBJECT(AUnitBase,Z_Param_AttackingUnit);
	P_GET_OBJECT(AUnitBase,Z_Param_TargetUnit);
	P_GET_PROPERTY(FIntProperty,Z_Param_CurrentDamage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StoreAttack(Z_Param_AttackingUnit,Z_Param_TargetUnit,Z_Param_CurrentDamage);
	P_NATIVE_END;
}
// End Class AGridPlayerController Function StoreAttack

// Begin Class AGridPlayerController Function StoreMove
struct Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics
{
	struct GridPlayerController_eventStoreMove_Parms
	{
		FVector TargetLocation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GridPlayerController_eventStoreMove_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::NewProp_TargetLocation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "StoreMove", nullptr, nullptr, Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::GridPlayerController_eventStoreMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::GridPlayerController_eventStoreMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGridPlayerController_StoreMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_StoreMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execStoreMove)
{
	P_GET_STRUCT(FVector,Z_Param_TargetLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StoreMove(Z_Param_TargetLocation);
	P_NATIVE_END;
}
// End Class AGridPlayerController Function StoreMove

// Begin Class AGridPlayerController Function UpdateAllUnitWidgets
struct Z_Construct_UFunction_AGridPlayerController_UpdateAllUnitWidgets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridPlayerController_UpdateAllUnitWidgets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridPlayerController, nullptr, "UpdateAllUnitWidgets", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridPlayerController_UpdateAllUnitWidgets_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridPlayerController_UpdateAllUnitWidgets_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGridPlayerController_UpdateAllUnitWidgets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridPlayerController_UpdateAllUnitWidgets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGridPlayerController::execUpdateAllUnitWidgets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateAllUnitWidgets();
	P_NATIVE_END;
}
// End Class AGridPlayerController Function UpdateAllUnitWidgets

// Begin Class AGridPlayerController
void AGridPlayerController::StaticRegisterNativesAGridPlayerController()
{
	UClass* Class = AGridPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearMovementRange", &AGridPlayerController::execClearMovementRange },
		{ "DisablePlayerInput", &AGridPlayerController::execDisablePlayerInput },
		{ "FindCellUnderUnit", &AGridPlayerController::execFindCellUnderUnit },
		{ "HandleAttackUnit", &AGridPlayerController::execHandleAttackUnit },
		{ "HandleEndTurn", &AGridPlayerController::execHandleEndTurn },
		{ "HandleMoveUnit", &AGridPlayerController::execHandleMoveUnit },
		{ "HandleNextUnit", &AGridPlayerController::execHandleNextUnit },
		{ "HandlePlaceUnit", &AGridPlayerController::execHandlePlaceUnit },
		{ "HandleSelectUnit", &AGridPlayerController::execHandleSelectUnit },
		{ "InitializeGridCells", &AGridPlayerController::execInitializeGridCells },
		{ "MovePlayerStepByStep", &AGridPlayerController::execMovePlayerStepByStep },
		{ "ShowMovementRange", &AGridPlayerController::execShowMovementRange },
		{ "StoreAttack", &AGridPlayerController::execStoreAttack },
		{ "StoreMove", &AGridPlayerController::execStoreMove },
		{ "UpdateAllUnitWidgets", &AGridPlayerController::execUpdateAllUnitWidgets },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGridPlayerController);
UClass* Z_Construct_UClass_AGridPlayerController_NoRegister()
{
	return AGridPlayerController::StaticClass();
}
struct Z_Construct_UClass_AGridPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "GridPlayerController.h" },
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StrategyCamera_MetaData[] = {
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitInfoWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitInfoWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurnIndicatorWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurnIndicatorWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GridPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StrategyCamera;
	static const UECodeGen_Private::FClassPropertyParams NewProp_UnitInfoWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnitInfoWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TurnIndicatorWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TurnIndicatorWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGridPlayerController_ClearMovementRange, "ClearMovementRange" }, // 1049601700
		{ &Z_Construct_UFunction_AGridPlayerController_DisablePlayerInput, "DisablePlayerInput" }, // 2633247372
		{ &Z_Construct_UFunction_AGridPlayerController_FindCellUnderUnit, "FindCellUnderUnit" }, // 814662622
		{ &Z_Construct_UFunction_AGridPlayerController_HandleAttackUnit, "HandleAttackUnit" }, // 4240023143
		{ &Z_Construct_UFunction_AGridPlayerController_HandleEndTurn, "HandleEndTurn" }, // 1482757832
		{ &Z_Construct_UFunction_AGridPlayerController_HandleMoveUnit, "HandleMoveUnit" }, // 1933543776
		{ &Z_Construct_UFunction_AGridPlayerController_HandleNextUnit, "HandleNextUnit" }, // 582752946
		{ &Z_Construct_UFunction_AGridPlayerController_HandlePlaceUnit, "HandlePlaceUnit" }, // 3714290024
		{ &Z_Construct_UFunction_AGridPlayerController_HandleSelectUnit, "HandleSelectUnit" }, // 1082739266
		{ &Z_Construct_UFunction_AGridPlayerController_InitializeGridCells, "InitializeGridCells" }, // 714945266
		{ &Z_Construct_UFunction_AGridPlayerController_MovePlayerStepByStep, "MovePlayerStepByStep" }, // 2541556196
		{ &Z_Construct_UFunction_AGridPlayerController_ShowMovementRange, "ShowMovementRange" }, // 4042033101
		{ &Z_Construct_UFunction_AGridPlayerController_StoreAttack, "StoreAttack" }, // 2926099931
		{ &Z_Construct_UFunction_AGridPlayerController_StoreMove, "StoreMove" }, // 2822338634
		{ &Z_Construct_UFunction_AGridPlayerController_UpdateAllUnitWidgets, "UpdateAllUnitWidgets" }, // 1325010530
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridPlayerController_Statics::NewProp_StrategyCamera = { "StrategyCamera", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridPlayerController, StrategyCamera), Z_Construct_UClass_AStrategyCamera_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StrategyCamera_MetaData), NewProp_StrategyCamera_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGridPlayerController_Statics::NewProp_UnitInfoWidgetClass = { "UnitInfoWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridPlayerController, UnitInfoWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUnitInfoWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInfoWidgetClass_MetaData), NewProp_UnitInfoWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridPlayerController_Statics::NewProp_UnitInfoWidget = { "UnitInfoWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridPlayerController, UnitInfoWidget), Z_Construct_UClass_UUnitInfoWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInfoWidget_MetaData), NewProp_UnitInfoWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGridPlayerController_Statics::NewProp_TurnIndicatorWidgetClass = { "TurnIndicatorWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridPlayerController, TurnIndicatorWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UTurnIndicatorWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurnIndicatorWidgetClass_MetaData), NewProp_TurnIndicatorWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridPlayerController_Statics::NewProp_TurnIndicatorWidget = { "TurnIndicatorWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridPlayerController, TurnIndicatorWidget), Z_Construct_UClass_UTurnIndicatorWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurnIndicatorWidget_MetaData), NewProp_TurnIndicatorWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridPlayerController_Statics::NewProp_StrategyCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridPlayerController_Statics::NewProp_UnitInfoWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridPlayerController_Statics::NewProp_UnitInfoWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridPlayerController_Statics::NewProp_TurnIndicatorWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridPlayerController_Statics::NewProp_TurnIndicatorWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGridPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGridPlayerController_Statics::ClassParams = {
	&AGridPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AGridPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AGridPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AGridPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGridPlayerController()
{
	if (!Z_Registration_Info_UClass_AGridPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGridPlayerController.OuterSingleton, Z_Construct_UClass_AGridPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGridPlayerController.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<AGridPlayerController>()
{
	return AGridPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGridPlayerController);
AGridPlayerController::~AGridPlayerController() {}
// End Class AGridPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGridPlayerController, AGridPlayerController::StaticClass, TEXT("AGridPlayerController"), &Z_Registration_Info_UClass_AGridPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridPlayerController), 1664919010U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_1319562316(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
