// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/UnitInfoWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnitInfoWidget() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_UUnitInfoWidget();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_UUnitInfoWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UScrollBox_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class UUnitInfoWidget Function UpdateHistory
struct Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics
{
	struct UnitInfoWidget_eventUpdateHistory_Parms
	{
		TArray<FString> History;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Updates the History\n" },
#endif
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates the History" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_History_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_History_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_History;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::NewProp_History_Inner = { "History", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::NewProp_History = { "History", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UnitInfoWidget_eventUpdateHistory_Parms, History), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_History_MetaData), NewProp_History_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::NewProp_History_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::NewProp_History,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUnitInfoWidget, nullptr, "UpdateHistory", nullptr, nullptr, Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::UnitInfoWidget_eventUpdateHistory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::UnitInfoWidget_eventUpdateHistory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUnitInfoWidget::execUpdateHistory)
{
	P_GET_TARRAY_REF(FString,Z_Param_Out_History);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateHistory(Z_Param_Out_History);
	P_NATIVE_END;
}
// End Class UUnitInfoWidget Function UpdateHistory

// Begin Class UUnitInfoWidget Function UpdateUnitInfo
struct Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics
{
	struct UnitInfoWidget_eventUpdateUnitInfo_Parms
	{
		FString UnitRole;
		int32 UnitHealth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Updates the unit Widget\n" },
#endif
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates the unit Widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitRole_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_UnitRole;
	static const UECodeGen_Private::FIntPropertyParams NewProp_UnitHealth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::NewProp_UnitRole = { "UnitRole", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UnitInfoWidget_eventUpdateUnitInfo_Parms, UnitRole), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitRole_MetaData), NewProp_UnitRole_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::NewProp_UnitHealth = { "UnitHealth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UnitInfoWidget_eventUpdateUnitInfo_Parms, UnitHealth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::NewProp_UnitRole,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::NewProp_UnitHealth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUnitInfoWidget, nullptr, "UpdateUnitInfo", nullptr, nullptr, Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::UnitInfoWidget_eventUpdateUnitInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::UnitInfoWidget_eventUpdateUnitInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UUnitInfoWidget::execUpdateUnitInfo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_UnitRole);
	P_GET_PROPERTY(FIntProperty,Z_Param_UnitHealth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateUnitInfo(Z_Param_UnitRole,Z_Param_UnitHealth);
	P_NATIVE_END;
}
// End Class UUnitInfoWidget Function UpdateUnitInfo

// Begin Class UUnitInfoWidget
void UUnitInfoWidget::StaticRegisterNativesUUnitInfoWidget()
{
	UClass* Class = UUnitInfoWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "UpdateHistory", &UUnitInfoWidget::execUpdateHistory },
		{ "UpdateUnitInfo", &UUnitInfoWidget::execUpdateUnitInfo },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUnitInfoWidget);
UClass* Z_Construct_UClass_UUnitInfoWidget_NoRegister()
{
	return UUnitInfoWidget::StaticClass();
}
struct Z_Construct_UClass_UUnitInfoWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "UnitInfoWidget.h" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitInfoWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PSniperName_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PSniperHealth_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PBrawlerName_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PBrawlerHealth_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ESniperName_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ESniperHealth_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EBrawlerName_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EBrawlerHealth_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HistoryScrollBox_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_UnitInfoWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PSniperName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PSniperHealth;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PBrawlerName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PBrawlerHealth;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ESniperName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ESniperHealth;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EBrawlerName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EBrawlerHealth;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HistoryScrollBox;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUnitInfoWidget_UpdateHistory, "UpdateHistory" }, // 242731798
		{ &Z_Construct_UFunction_UUnitInfoWidget_UpdateUnitInfo, "UpdateUnitInfo" }, // 2891676277
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUnitInfoWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitInfoWidgetClass = { "UnitInfoWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, UnitInfoWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUnitInfoWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInfoWidgetClass_MetaData), NewProp_UnitInfoWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_PSniperName = { "PSniperName", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, PSniperName), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PSniperName_MetaData), NewProp_PSniperName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_PSniperHealth = { "PSniperHealth", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, PSniperHealth), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PSniperHealth_MetaData), NewProp_PSniperHealth_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_PBrawlerName = { "PBrawlerName", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, PBrawlerName), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PBrawlerName_MetaData), NewProp_PBrawlerName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_PBrawlerHealth = { "PBrawlerHealth", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, PBrawlerHealth), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PBrawlerHealth_MetaData), NewProp_PBrawlerHealth_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_ESniperName = { "ESniperName", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, ESniperName), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ESniperName_MetaData), NewProp_ESniperName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_ESniperHealth = { "ESniperHealth", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, ESniperHealth), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ESniperHealth_MetaData), NewProp_ESniperHealth_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_EBrawlerName = { "EBrawlerName", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, EBrawlerName), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EBrawlerName_MetaData), NewProp_EBrawlerName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_EBrawlerHealth = { "EBrawlerHealth", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, EBrawlerHealth), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EBrawlerHealth_MetaData), NewProp_EBrawlerHealth_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_HistoryScrollBox = { "HistoryScrollBox", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, HistoryScrollBox), Z_Construct_UClass_UScrollBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HistoryScrollBox_MetaData), NewProp_HistoryScrollBox_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUnitInfoWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitInfoWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_PSniperName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_PSniperHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_PBrawlerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_PBrawlerHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_ESniperName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_ESniperHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_EBrawlerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_EBrawlerHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_HistoryScrollBox,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUnitInfoWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UUnitInfoWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUnitInfoWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUnitInfoWidget_Statics::ClassParams = {
	&UUnitInfoWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UUnitInfoWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UUnitInfoWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUnitInfoWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UUnitInfoWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUnitInfoWidget()
{
	if (!Z_Registration_Info_UClass_UUnitInfoWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUnitInfoWidget.OuterSingleton, Z_Construct_UClass_UUnitInfoWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUnitInfoWidget.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<UUnitInfoWidget>()
{
	return UUnitInfoWidget::StaticClass();
}
UUnitInfoWidget::UUnitInfoWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUnitInfoWidget);
UUnitInfoWidget::~UUnitInfoWidget() {}
// End Class UUnitInfoWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUnitInfoWidget, UUnitInfoWidget::StaticClass, TEXT("UUnitInfoWidget"), &Z_Registration_Info_UClass_UUnitInfoWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUnitInfoWidget), 3026906260U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_1522330426(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
