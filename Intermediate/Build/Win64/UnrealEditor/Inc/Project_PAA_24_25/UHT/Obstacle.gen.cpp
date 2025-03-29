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
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AObstacle();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_AObstacle_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class AObstacle Function SetMaterial
struct Z_Construct_UFunction_AObstacle_SetMaterial_Statics
{
	struct Obstacle_eventSetMaterial_Parms
	{
		bool bTree;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// true = tree, false = mountain\n" },
#endif
		{ "ModuleRelativePath", "Obstacle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "true = tree, false = mountain" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bTree_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTree;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AObstacle_SetMaterial_Statics::NewProp_bTree_SetBit(void* Obj)
{
	((Obstacle_eventSetMaterial_Parms*)Obj)->bTree = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AObstacle_SetMaterial_Statics::NewProp_bTree = { "bTree", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Obstacle_eventSetMaterial_Parms), &Z_Construct_UFunction_AObstacle_SetMaterial_Statics::NewProp_bTree_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AObstacle_SetMaterial_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AObstacle_SetMaterial_Statics::NewProp_bTree,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AObstacle_SetMaterial_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AObstacle_SetMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AObstacle, nullptr, "SetMaterial", nullptr, nullptr, Z_Construct_UFunction_AObstacle_SetMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AObstacle_SetMaterial_Statics::PropPointers), sizeof(Z_Construct_UFunction_AObstacle_SetMaterial_Statics::Obstacle_eventSetMaterial_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AObstacle_SetMaterial_Statics::Function_MetaDataParams), Z_Construct_UFunction_AObstacle_SetMaterial_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AObstacle_SetMaterial_Statics::Obstacle_eventSetMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AObstacle_SetMaterial()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AObstacle_SetMaterial_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AObstacle::execSetMaterial)
{
	P_GET_UBOOL(Z_Param_bTree);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaterial(Z_Param_bTree);
	P_NATIVE_END;
}
// End Class AObstacle Function SetMaterial

// Begin Class AObstacle
void AObstacle::StaticRegisterNativesAObstacle()
{
	UClass* Class = AObstacle::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetMaterial", &AObstacle::execSetMaterial },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TreeMaterial_MetaData[] = {
		{ "Category", "Material" },
		{ "ModuleRelativePath", "Obstacle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MountainMaterial_MetaData[] = {
		{ "Category", "Material" },
		{ "ModuleRelativePath", "Obstacle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsTree_MetaData[] = {
		{ "Category", "Obstacle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Obstacle type:\n" },
#endif
		{ "ModuleRelativePath", "Obstacle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Obstacle type:" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ObstacleMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TreeMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MountainMaterial;
	static void NewProp_bIsTree_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsTree;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AObstacle_SetMaterial, "SetMaterial" }, // 1671600226
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AObstacle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AObstacle_Statics::NewProp_ObstacleMesh = { "ObstacleMesh", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AObstacle, ObstacleMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ObstacleMesh_MetaData), NewProp_ObstacleMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AObstacle_Statics::NewProp_TreeMaterial = { "TreeMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AObstacle, TreeMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TreeMaterial_MetaData), NewProp_TreeMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AObstacle_Statics::NewProp_MountainMaterial = { "MountainMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AObstacle, MountainMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MountainMaterial_MetaData), NewProp_MountainMaterial_MetaData) };
void Z_Construct_UClass_AObstacle_Statics::NewProp_bIsTree_SetBit(void* Obj)
{
	((AObstacle*)Obj)->bIsTree = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AObstacle_Statics::NewProp_bIsTree = { "bIsTree", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AObstacle), &Z_Construct_UClass_AObstacle_Statics::NewProp_bIsTree_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsTree_MetaData), NewProp_bIsTree_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AObstacle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AObstacle_Statics::NewProp_ObstacleMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AObstacle_Statics::NewProp_TreeMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AObstacle_Statics::NewProp_MountainMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AObstacle_Statics::NewProp_bIsTree,
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
	FuncInfo,
	Z_Construct_UClass_AObstacle_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
struct Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AObstacle, AObstacle::StaticClass, TEXT("AObstacle"), &Z_Registration_Info_UClass_AObstacle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AObstacle), 361977152U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_2806142259(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_Obstacle_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
