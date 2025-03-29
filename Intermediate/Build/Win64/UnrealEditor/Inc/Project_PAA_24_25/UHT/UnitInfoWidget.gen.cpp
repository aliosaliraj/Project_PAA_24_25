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
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class UUnitInfoWidget
void UUnitInfoWidget::StaticRegisterNativesUUnitInfoWidget()
{
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitDamageText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnitHealthText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "UnitInfoWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UnitInfoWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_UnitInfoWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnitNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnitDamageText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnitHealthText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUnitInfoWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitInfoWidgetClass = { "UnitInfoWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, UnitInfoWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUnitInfoWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitInfoWidgetClass_MetaData), NewProp_UnitInfoWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitNameText = { "UnitNameText", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, UnitNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitNameText_MetaData), NewProp_UnitNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitDamageText = { "UnitDamageText", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, UnitDamageText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitDamageText_MetaData), NewProp_UnitDamageText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitHealthText = { "UnitHealthText", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUnitInfoWidget, UnitHealthText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnitHealthText_MetaData), NewProp_UnitHealthText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUnitInfoWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitInfoWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitDamageText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUnitInfoWidget_Statics::NewProp_UnitHealthText,
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
	nullptr,
	Z_Construct_UClass_UUnitInfoWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
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
		{ Z_Construct_UClass_UUnitInfoWidget, UUnitInfoWidget::StaticClass, TEXT("UUnitInfoWidget"), &Z_Registration_Info_UClass_UUnitInfoWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUnitInfoWidget), 1236533287U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_2937839319(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
