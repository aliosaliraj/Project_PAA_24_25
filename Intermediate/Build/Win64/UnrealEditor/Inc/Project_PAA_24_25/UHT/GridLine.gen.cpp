// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/GridLine.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridLine() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AGridLine();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AGridLine_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AObstacle_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class AGridLine
void AGridLine::StaticRegisterNativesAGridLine()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGridLine);
UClass* Z_Construct_UClass_AGridLine_NoRegister()
{
	return AGridLine::StaticClass();
}
struct Z_Construct_UClass_AGridLine_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GridLine.h" },
		{ "ModuleRelativePath", "GridLine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSize_MetaData[] = {
		{ "Category", "Gridline" },
		{ "ModuleRelativePath", "GridLine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellSize_MetaData[] = {
		{ "Category", "Gridline" },
		{ "ModuleRelativePath", "GridLine.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ObstacleClass_MetaData[] = {
		{ "Category", "GridLine" },
		{ "ModuleRelativePath", "GridLine.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_GridSize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CellSize;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ObstacleClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridLine>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AGridLine_Statics::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridLine, GridSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSize_MetaData), NewProp_GridSize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridLine_Statics::NewProp_CellSize = { "CellSize", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridLine, CellSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellSize_MetaData), NewProp_CellSize_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGridLine_Statics::NewProp_ObstacleClass = { "ObstacleClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridLine, ObstacleClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AObstacle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObstacleClass_MetaData), NewProp_ObstacleClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridLine_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridLine_Statics::NewProp_GridSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridLine_Statics::NewProp_CellSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridLine_Statics::NewProp_ObstacleClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridLine_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGridLine_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridLine_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGridLine_Statics::ClassParams = {
	&AGridLine::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AGridLine_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AGridLine_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridLine_Statics::Class_MetaDataParams), Z_Construct_UClass_AGridLine_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGridLine()
{
	if (!Z_Registration_Info_UClass_AGridLine.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGridLine.OuterSingleton, Z_Construct_UClass_AGridLine_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGridLine.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<AGridLine>()
{
	return AGridLine::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGridLine);
AGridLine::~AGridLine() {}
// End Class AGridLine

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridLine_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGridLine, AGridLine::StaticClass, TEXT("AGridLine"), &Z_Registration_Info_UClass_AGridLine, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridLine), 1997166282U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridLine_h_1832739829(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridLine_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_GridLine_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
