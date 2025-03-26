// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Project_PAA_24_25/CellActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCellActor() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_ACellActor();
PROJECT_PAA_24_25_API UClass* Z_Construct_UClass_ACellActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_Project_PAA_24_25();
// End Cross Module References

// Begin Class ACellActor Function HighlightCell
struct Z_Construct_UFunction_ACellActor_HighlightCell_Statics
{
	struct CellActor_eventHighlightCell_Parms
	{
		bool bHighlight;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CellActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bHighlight_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHighlight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ACellActor_HighlightCell_Statics::NewProp_bHighlight_SetBit(void* Obj)
{
	((CellActor_eventHighlightCell_Parms*)Obj)->bHighlight = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACellActor_HighlightCell_Statics::NewProp_bHighlight = { "bHighlight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CellActor_eventHighlightCell_Parms), &Z_Construct_UFunction_ACellActor_HighlightCell_Statics::NewProp_bHighlight_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACellActor_HighlightCell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACellActor_HighlightCell_Statics::NewProp_bHighlight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACellActor_HighlightCell_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACellActor_HighlightCell_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACellActor, nullptr, "HighlightCell", nullptr, nullptr, Z_Construct_UFunction_ACellActor_HighlightCell_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACellActor_HighlightCell_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACellActor_HighlightCell_Statics::CellActor_eventHighlightCell_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACellActor_HighlightCell_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACellActor_HighlightCell_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACellActor_HighlightCell_Statics::CellActor_eventHighlightCell_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACellActor_HighlightCell()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACellActor_HighlightCell_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACellActor::execHighlightCell)
{
	P_GET_UBOOL(Z_Param_bHighlight);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HighlightCell(Z_Param_bHighlight);
	P_NATIVE_END;
}
// End Class ACellActor Function HighlightCell

// Begin Class ACellActor Function SetCellColor
struct Z_Construct_UFunction_ACellActor_SetCellColor_Statics
{
	struct CellActor_eventSetCellColor_Parms
	{
		FColor NewColor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CellActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACellActor_SetCellColor_Statics::NewProp_NewColor = { "NewColor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CellActor_eventSetCellColor_Parms, NewColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACellActor_SetCellColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACellActor_SetCellColor_Statics::NewProp_NewColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACellActor_SetCellColor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACellActor_SetCellColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACellActor, nullptr, "SetCellColor", nullptr, nullptr, Z_Construct_UFunction_ACellActor_SetCellColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACellActor_SetCellColor_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACellActor_SetCellColor_Statics::CellActor_eventSetCellColor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACellActor_SetCellColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACellActor_SetCellColor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACellActor_SetCellColor_Statics::CellActor_eventSetCellColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACellActor_SetCellColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACellActor_SetCellColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACellActor::execSetCellColor)
{
	P_GET_STRUCT(FColor,Z_Param_NewColor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCellColor(Z_Param_NewColor);
	P_NATIVE_END;
}
// End Class ACellActor Function SetCellColor

// Begin Class ACellActor
void ACellActor::StaticRegisterNativesACellActor()
{
	UClass* Class = ACellActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HighlightCell", &ACellActor::execHighlightCell },
		{ "SetCellColor", &ACellActor::execSetCellColor },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACellActor);
UClass* Z_Construct_UClass_ACellActor_NoRegister()
{
	return ACellActor::StaticClass();
}
struct Z_Construct_UClass_ACellActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CellActor.h" },
		{ "ModuleRelativePath", "CellActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellMesh_MetaData[] = {
		{ "Category", "CellActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CellActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CellMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACellActor_HighlightCell, "HighlightCell" }, // 2924886537
		{ &Z_Construct_UFunction_ACellActor_SetCellColor, "SetCellColor" }, // 2994691330
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACellActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACellActor_Statics::NewProp_CellMesh = { "CellMesh", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACellActor, CellMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellMesh_MetaData), NewProp_CellMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACellActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACellActor_Statics::NewProp_CellMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACellActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACellActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Project_PAA_24_25,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACellActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACellActor_Statics::ClassParams = {
	&ACellActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACellActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACellActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACellActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ACellActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACellActor()
{
	if (!Z_Registration_Info_UClass_ACellActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACellActor.OuterSingleton, Z_Construct_UClass_ACellActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACellActor.OuterSingleton;
}
template<> PROJECT_PAA_24_25_API UClass* StaticClass<ACellActor>()
{
	return ACellActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACellActor);
ACellActor::~ACellActor() {}
// End Class ACellActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACellActor, ACellActor::StaticClass, TEXT("ACellActor"), &Z_Registration_Info_UClass_ACellActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACellActor), 1648140202U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_347060205(TEXT("/Script/Project_PAA_24_25"),
	Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
