// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/Obstacle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObstacle() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AObstacle();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AObstacle_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class AObstacle
void AObstacle::StaticRegisterNativesAObstacle()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AObstacle);
UClass* Z_Construct_UClass_AObstacle_NoRegister()
{
	return AObstacle::StaticClass();
}
struct Z_Construct_UClass_AObstacle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Obstacle.h" },
		{ "ModuleRelativePath", "Obstacle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObstacleMesh_MetaData[] = {
		{ "Category", "Obstacle" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Obstacle.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObstacleMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AObstacle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AObstacle_Statics::NewProp_ObstacleMesh = { "ObstacleMesh", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AObstacle, ObstacleMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObstacleMesh_MetaData), NewProp_ObstacleMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AObstacle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AObstacle_Statics::NewProp_ObstacleMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AObstacle_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AObstacle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AObstacle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AObstacle_Statics::ClassParams = {
	&AObstacle::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AObstacle_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AObstacle_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AObstacle_Statics::Class_MetaDataParams), Z_Construct_UClass_AObstacle_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AObstacle()
{
	if (!Z_Registration_Info_UClass_AObstacle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AObstacle.OuterSingleton, Z_Construct_UClass_AObstacle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AObstacle.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<AObstacle>()
{
	return AObstacle::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AObstacle);
AObstacle::~AObstacle() {}
// End Class AObstacle

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AObstacle, AObstacle::StaticClass, TEXT("AObstacle"), &Z_Registration_Info_UClass_AObstacle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AObstacle), 4188992988U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_111034882(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
