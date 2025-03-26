// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/Brawler.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBrawler() {}

// Begin Cross Module References
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_ABrawler();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_ABrawler_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AUnitBase();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class ABrawler
void ABrawler::StaticRegisterNativesABrawler()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABrawler);
UClass* Z_Construct_UClass_ABrawler_NoRegister()
{
	return ABrawler::StaticClass();
}
struct Z_Construct_UClass_ABrawler_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Brawler.h" },
		{ "ModuleRelativePath", "Brawler.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABrawler>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABrawler_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AUnitBase,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABrawler_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABrawler_Statics::ClassParams = {
	&ABrawler::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABrawler_Statics::Class_MetaDataParams), Z_Construct_UClass_ABrawler_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABrawler()
{
	if (!Z_Registration_Info_UClass_ABrawler.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABrawler.OuterSingleton, Z_Construct_UClass_ABrawler_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABrawler.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<ABrawler>()
{
	return ABrawler::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABrawler);
ABrawler::~ABrawler() {}
// End Class ABrawler

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Brawler_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABrawler, ABrawler::StaticClass, TEXT("ABrawler"), &Z_Registration_Info_UClass_ABrawler, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABrawler), 1220846646U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Brawler_h_1399112635(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Brawler_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Brawler_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
