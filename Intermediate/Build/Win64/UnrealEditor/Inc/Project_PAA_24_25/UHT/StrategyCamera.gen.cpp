// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/StrategyCamera.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStrategyCamera() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACameraActor();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AStrategyCamera();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AStrategyCamera_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class AStrategyCamera
void AStrategyCamera::StaticRegisterNativesAStrategyCamera()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AStrategyCamera);
UClass* Z_Construct_UClass_AStrategyCamera_NoRegister()
{
	return AStrategyCamera::StaticClass();
}
struct Z_Construct_UClass_AStrategyCamera_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Input Rendering" },
		{ "IncludePath", "StrategyCamera.h" },
		{ "ModuleRelativePath", "StrategyCamera.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CustomCameraComponent_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "StrategyCamera.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CustomCameraComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStrategyCamera>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStrategyCamera_Statics::NewProp_CustomCameraComponent = { "CustomCameraComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStrategyCamera, CustomCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CustomCameraComponent_MetaData), NewProp_CustomCameraComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStrategyCamera_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStrategyCamera_Statics::NewProp_CustomCameraComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyCamera_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AStrategyCamera_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACameraActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyCamera_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStrategyCamera_Statics::ClassParams = {
	&AStrategyCamera::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AStrategyCamera_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyCamera_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStrategyCamera_Statics::Class_MetaDataParams), Z_Construct_UClass_AStrategyCamera_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AStrategyCamera()
{
	if (!Z_Registration_Info_UClass_AStrategyCamera.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStrategyCamera.OuterSingleton, Z_Construct_UClass_AStrategyCamera_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStrategyCamera.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<AStrategyCamera>()
{
	return AStrategyCamera::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AStrategyCamera);
AStrategyCamera::~AStrategyCamera() {}
// End Class AStrategyCamera

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_StrategyCamera_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStrategyCamera, AStrategyCamera::StaticClass, TEXT("AStrategyCamera"), &Z_Registration_Info_UClass_AStrategyCamera, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStrategyCamera), 446065931U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_StrategyCamera_h_693638219(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_StrategyCamera_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_StrategyCamera_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
