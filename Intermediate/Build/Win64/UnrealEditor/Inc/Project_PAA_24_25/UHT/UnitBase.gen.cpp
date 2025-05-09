// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/UnitBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnitBase() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AUnitBase();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AUnitBase_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_UUnitInfoWidget_NoRegister();
PROJECT_PAA_24_25_API UEnum* Z_Construct_UEnum_Project_PAA_24_25_EUnitType();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Enum EUnitType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EUnitType;
static UEnum* EUnitType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EUnitType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EUnitType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Project_PAA_24_25_EUnitType, (UObject*)Z_Construct_UPackage__Script_Project_PAA_24_25(), TEXT("EUnitType"));
	}
	return Z_Registration_Info_UEnum_EUnitType.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UEnum* StaticEnum<EUnitType>()
{
	return EUnitType_StaticEnum();
}
struct Z_Construct_UEnum_Project_PAA_24_25_EUnitType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Brawler.DisplayName", "BRAWLER" },
		{ "Brawler.Name", "EUnitType::Brawler" },
		{ "ModuleRelativePath", "UnitBase.h" },
		{ "Sniper.DisplayName", "SNIPER" },
		{ "Sniper.Name", "EUnitType::Sniper" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EUnitType::Sniper", (int64)EUnitType::Sniper },
		{ "EUnitType::Brawler", (int64)EUnitType::Brawler },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Project_PAA_24_25_EUnitType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
	nullptr,
	"EUnitType",
	"EUnitType",
	Z_Construct_UEnum_Project_PAA_24_25_EUnitType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Project_PAA_24_25_EUnitType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Project_PAA_24_25_EUnitType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Project_PAA_24_25_EUnitType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Project_PAA_24_25_EUnitType()
{
	if (!Z_Registration_Info_UEnum_EUnitType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EUnitType.InnerSingleton, Z_Construct_UEnum_Project_PAA_24_25_EUnitType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EUnitType.InnerSingleton;
}
// End Enum EUnitType

// Begin Class AUnitBase Function ApplyDamage
struct Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics
{
	struct UnitBase_eventApplyDamage_Parms
	{
		int32 DamageAmount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// unit is placed on the grid\n" },
#endif
		{ "ModuleRelativePath", "UnitBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "unit is placed on the grid" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_DamageAmount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::NewProp_DamageAmount = { "DamageAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UnitBase_eventApplyDamage_Parms, DamageAmount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::NewProp_DamageAmount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUnitBase, nullptr, "ApplyDamage", nullptr, nullptr, Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::PropPointers), sizeof(Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::UnitBase_eventApplyDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::UnitBase_eventApplyDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AUnitBase_ApplyDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUnitBase_ApplyDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AUnitBase::execApplyDamage)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_DamageAmount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyDamage(Z_Param_DamageAmount);
	P_NATIVE_END;
}
// End Class AUnitBase Function ApplyDamage

// Begin Class AUnitBase Function CounterAttack
struct Z_Construct_UFunction_AUnitBase_CounterAttack_Statics
{
	struct UnitBase_eventCounterAttack_Parms
	{
		AUnitBase* Attacker;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UnitBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Attacker;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::NewProp_Attacker = { "Attacker", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UnitBase_eventCounterAttack_Parms, Attacker), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::NewProp_Attacker,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUnitBase, nullptr, "CounterAttack", nullptr, nullptr, Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::UnitBase_eventCounterAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::UnitBase_eventCounterAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AUnitBase_CounterAttack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUnitBase_CounterAttack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AUnitBase::execCounterAttack)
{
	P_GET_OBJECT(AUnitBase,Z_Param_Attacker);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CounterAttack(Z_Param_Attacker);
	P_NATIVE_END;
}
// End Class AUnitBase Function CounterAttack

// Begin Class AUnitBase Function UpdateMaterial
struct Z_Construct_UFunction_AUnitBase_UpdateMaterial_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UnitBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUnitBase_UpdateMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUnitBase, nullptr, "UpdateMaterial", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_UpdateMaterial_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUnitBase_UpdateMaterial_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AUnitBase_UpdateMaterial()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUnitBase_UpdateMaterial_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AUnitBase::execUpdateMaterial)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateMaterial();
	P_NATIVE_END;
}
// End Class AUnitBase Function UpdateMaterial

// Begin Class AUnitBase
void AUnitBase::StaticRegisterNativesAUnitBase()
{
	UClass* Class = AUnitBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplyDamage", &AUnitBase::execApplyDamage },
		{ "CounterAttack", &AUnitBase::execCounterAttack },
		{ "UpdateMaterial", &AUnitBase::execUpdateMaterial },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUnitBase);
UClass* Z_Construct_UClass_AUnitBase_NoRegister()
{
	return AUnitBase::StaticClass();
}
struct Z_Construct_UClass_AUnitBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "UnitBase.h" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitType_MetaData[] = {
		{ "Category", "Unit" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitRole_MetaData[] = {
		{ "Category", "Unit" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPlayerControlled_MetaData[] = {
		{ "Category", "Control" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasCompletedAction_MetaData[] = {
		{ "Category", "Turn" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanMove_MetaData[] = {
		{ "Category", "Turn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// unit has completed its action for the turn\n" },
#endif
		{ "ModuleRelativePath", "UnitBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "unit has completed its action for the turn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanAttack_MetaData[] = {
		{ "Category", "Turn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// unit can move\n" },
#endif
		{ "ModuleRelativePath", "UnitBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "unit can move" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanAttackAfterMove_MetaData[] = {
		{ "Category", "Turn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// unit can attack\n" },
#endif
		{ "ModuleRelativePath", "UnitBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "unit can attack" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPlaced_MetaData[] = {
		{ "Category", "Placement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// unit can attack only after has moved\n" },
#endif
		{ "ModuleRelativePath", "UnitBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "unit can attack only after has moved" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitMesh_MetaData[] = {
		{ "Category", "UnitBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMovement_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageMin_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamageMax_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentDamage_MetaData[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SniperPlayerMat_MetaData[] = {
		{ "Category", "Material" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SniperEnemyMat_MetaData[] = {
		{ "Category", "Material" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrawlerPlayerMat_MetaData[] = {
		{ "Category", "Material" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrawlerEnemyMat_MetaData[] = {
		{ "Category", "Material" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitInfoWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitInfoWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_UnitType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UnitType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UnitRole;
	static void NewProp_bIsPlayerControlled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPlayerControlled;
	static void NewProp_bHasCompletedAction_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasCompletedAction;
	static void NewProp_bCanMove_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanMove;
	static void NewProp_bCanAttack_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanAttack;
	static void NewProp_bCanAttackAfterMove_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanAttackAfterMove;
	static void NewProp_bIsPlaced_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPlaced;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnitMesh;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Health;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxMovement;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackRange;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DamageMin;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DamageMax;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentDamage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SniperPlayerMat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SniperEnemyMat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BrawlerPlayerMat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BrawlerEnemyMat;
	static const UECodeGen_Private::FClassPropertyParams NewProp_UnitInfoWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnitInfoWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AUnitBase_ApplyDamage, "ApplyDamage" }, // 3612769686
		{ &Z_Construct_UFunction_AUnitBase_CounterAttack, "CounterAttack" }, // 473856446
		{ &Z_Construct_UFunction_AUnitBase_UpdateMaterial, "UpdateMaterial" }, // 1363636272
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnitBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitType = { "UnitType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitType), Z_Construct_UEnum_Project_PAA_24_25_EUnitType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitType_MetaData), NewProp_UnitType_MetaData) }; // 2876934478
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitRole = { "UnitRole", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitRole_MetaData), NewProp_UnitRole_MetaData) };
void Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlayerControlled_SetBit(void* Obj)
{
	((AUnitBase*)Obj)->bIsPlayerControlled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlayerControlled = { "bIsPlayerControlled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AUnitBase), &Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlayerControlled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPlayerControlled_MetaData), NewProp_bIsPlayerControlled_MetaData) };
void Z_Construct_UClass_AUnitBase_Statics::NewProp_bHasCompletedAction_SetBit(void* Obj)
{
	((AUnitBase*)Obj)->bHasCompletedAction = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_bHasCompletedAction = { "bHasCompletedAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AUnitBase), &Z_Construct_UClass_AUnitBase_Statics::NewProp_bHasCompletedAction_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasCompletedAction_MetaData), NewProp_bHasCompletedAction_MetaData) };
void Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanMove_SetBit(void* Obj)
{
	((AUnitBase*)Obj)->bCanMove = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanMove = { "bCanMove", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AUnitBase), &Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanMove_MetaData), NewProp_bCanMove_MetaData) };
void Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanAttack_SetBit(void* Obj)
{
	((AUnitBase*)Obj)->bCanAttack = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanAttack = { "bCanAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AUnitBase), &Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanAttack_MetaData), NewProp_bCanAttack_MetaData) };
void Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanAttackAfterMove_SetBit(void* Obj)
{
	((AUnitBase*)Obj)->bCanAttackAfterMove = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanAttackAfterMove = { "bCanAttackAfterMove", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AUnitBase), &Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanAttackAfterMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanAttackAfterMove_MetaData), NewProp_bCanAttackAfterMove_MetaData) };
void Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlaced_SetBit(void* Obj)
{
	((AUnitBase*)Obj)->bIsPlaced = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlaced = { "bIsPlaced", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AUnitBase), &Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlaced_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPlaced_MetaData), NewProp_bIsPlaced_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitMesh = { "UnitMesh", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitMesh_MetaData), NewProp_UnitMesh_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_MaxMovement = { "MaxMovement", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, MaxMovement), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMovement_MetaData), NewProp_MaxMovement_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRange_MetaData), NewProp_AttackRange_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_DamageMin = { "DamageMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, DamageMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageMin_MetaData), NewProp_DamageMin_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_DamageMax = { "DamageMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, DamageMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageMax_MetaData), NewProp_DamageMax_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_CurrentDamage = { "CurrentDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, CurrentDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentDamage_MetaData), NewProp_CurrentDamage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_SniperPlayerMat = { "SniperPlayerMat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, SniperPlayerMat), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SniperPlayerMat_MetaData), NewProp_SniperPlayerMat_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_SniperEnemyMat = { "SniperEnemyMat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, SniperEnemyMat), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SniperEnemyMat_MetaData), NewProp_SniperEnemyMat_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_BrawlerPlayerMat = { "BrawlerPlayerMat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, BrawlerPlayerMat), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrawlerPlayerMat_MetaData), NewProp_BrawlerPlayerMat_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_BrawlerEnemyMat = { "BrawlerEnemyMat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, BrawlerEnemyMat), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrawlerEnemyMat_MetaData), NewProp_BrawlerEnemyMat_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitInfoWidgetClass = { "UnitInfoWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitInfoWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUnitInfoWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInfoWidgetClass_MetaData), NewProp_UnitInfoWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitInfoWidget = { "UnitInfoWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitInfoWidget), Z_Construct_UClass_UUnitInfoWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInfoWidget_MetaData), NewProp_UnitInfoWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AUnitBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitRole,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlayerControlled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_bHasCompletedAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_bCanAttackAfterMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlaced,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_MaxMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_AttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_DamageMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_DamageMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_CurrentDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_SniperPlayerMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_SniperEnemyMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_BrawlerPlayerMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_BrawlerEnemyMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitInfoWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitInfoWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUnitBase_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AUnitBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUnitBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AUnitBase_Statics::ClassParams = {
	&AUnitBase::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AUnitBase_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AUnitBase_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUnitBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AUnitBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AUnitBase()
{
	if (!Z_Registration_Info_UClass_AUnitBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUnitBase.OuterSingleton, Z_Construct_UClass_AUnitBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AUnitBase.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<AUnitBase>()
{
	return AUnitBase::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AUnitBase);
AUnitBase::~AUnitBase() {}
// End Class AUnitBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EUnitType_StaticEnum, TEXT("EUnitType"), &Z_Registration_Info_UEnum_EUnitType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2876934478U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AUnitBase, AUnitBase::StaticClass, TEXT("AUnitBase"), &Z_Registration_Info_UClass_AUnitBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnitBase), 3580078579U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_2439688056(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
