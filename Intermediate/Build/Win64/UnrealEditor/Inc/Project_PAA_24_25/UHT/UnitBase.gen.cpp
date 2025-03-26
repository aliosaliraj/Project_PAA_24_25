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
		{ "Brawler.DisplayName", "Brawler" },
		{ "Brawler.Name", "EUnitType::Brawler" },
		{ "ModuleRelativePath", "UnitBase.h" },
		{ "Sniper.DisplayName", "Sniper" },
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
		{ "ModuleRelativePath", "UnitBase.h" },
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

// Begin Class AUnitBase Function AttackTarget
struct Z_Construct_UFunction_AUnitBase_AttackTarget_Statics
{
	struct UnitBase_eventAttackTarget_Parms
	{
		AUnitBase* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UnitBase.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UnitBase_eventAttackTarget_Parms, Target), Z_Construct_UClass_AUnitBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AUnitBase, nullptr, "AttackTarget", nullptr, nullptr, Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::UnitBase_eventAttackTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::UnitBase_eventAttackTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AUnitBase_AttackTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AUnitBase_AttackTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AUnitBase::execAttackTarget)
{
	P_GET_OBJECT(AUnitBase,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttackTarget(Z_Param_Target);
	P_NATIVE_END;
}
// End Class AUnitBase Function AttackTarget

// Begin Class AUnitBase
void AUnitBase::StaticRegisterNativesAUnitBase()
{
	UClass* Class = AUnitBase::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplyDamage", &AUnitBase::execApplyDamage },
		{ "AttackTarget", &AUnitBase::execAttackTarget },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SniperMat_MetaData[] = {
		{ "Category", "Material" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BrawlerMat_MetaData[] = {
		{ "Category", "Material" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitType_MetaData[] = {
		{ "Category", "Unit" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitMesh_MetaData[] = {
		{ "Category", "UnitBase" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitBase.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Stats Base\n" },
#endif
		{ "ModuleRelativePath", "UnitBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stats Base" },
#endif
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPlayerControlled_MetaData[] = {
		{ "Category", "Control" },
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SniperMat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BrawlerMat;
	static const UECodeGen_Private::FBytePropertyParams NewProp_UnitType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_UnitType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnitMesh;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Health;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxMovement;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AttackRange;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DamageMin;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DamageMax;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentDamage;
	static void NewProp_bIsPlayerControlled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPlayerControlled;
	static const UECodeGen_Private::FClassPropertyParams NewProp_UnitInfoWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnitInfoWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AUnitBase_ApplyDamage, "ApplyDamage" }, // 628239800
		{ &Z_Construct_UFunction_AUnitBase_AttackTarget, "AttackTarget" }, // 463811163
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnitBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_SniperMat = { "SniperMat", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, SniperMat), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SniperMat_MetaData), NewProp_SniperMat_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_BrawlerMat = { "BrawlerMat", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, BrawlerMat), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BrawlerMat_MetaData), NewProp_BrawlerMat_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitType = { "UnitType", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitType), Z_Construct_UEnum_Project_PAA_24_25_EUnitType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitType_MetaData), NewProp_UnitType_MetaData) }; // 404567969
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitMesh = { "UnitMesh", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitMesh_MetaData), NewProp_UnitMesh_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_MaxMovement = { "MaxMovement", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, MaxMovement), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMovement_MetaData), NewProp_MaxMovement_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, AttackRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackRange_MetaData), NewProp_AttackRange_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_DamageMin = { "DamageMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, DamageMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageMin_MetaData), NewProp_DamageMin_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_DamageMax = { "DamageMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, DamageMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamageMax_MetaData), NewProp_DamageMax_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_CurrentDamage = { "CurrentDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, CurrentDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentDamage_MetaData), NewProp_CurrentDamage_MetaData) };
void Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlayerControlled_SetBit(void* Obj)
{
	((AUnitBase*)Obj)->bIsPlayerControlled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlayerControlled = { "bIsPlayerControlled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AUnitBase), &Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlayerControlled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPlayerControlled_MetaData), NewProp_bIsPlayerControlled_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitInfoWidgetClass = { "UnitInfoWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitInfoWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUnitInfoWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInfoWidgetClass_MetaData), NewProp_UnitInfoWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitInfoWidget = { "UnitInfoWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AUnitBase, UnitInfoWidget), Z_Construct_UClass_UUnitInfoWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInfoWidget_MetaData), NewProp_UnitInfoWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AUnitBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_SniperMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_BrawlerMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_UnitMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_MaxMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_AttackRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_DamageMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_DamageMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_CurrentDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AUnitBase_Statics::NewProp_bIsPlayerControlled,
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
struct Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EUnitType_StaticEnum, TEXT("EUnitType"), &Z_Registration_Info_UEnum_EUnitType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 404567969U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AUnitBase, AUnitBase::StaticClass, TEXT("AUnitBase"), &Z_Registration_Info_UClass_AUnitBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnitBase), 2062180638U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_865942049(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
