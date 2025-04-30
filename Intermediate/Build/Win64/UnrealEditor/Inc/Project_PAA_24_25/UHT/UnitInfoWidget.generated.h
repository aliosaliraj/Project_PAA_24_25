// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UnitInfoWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECT_PAA_24_25_UnitInfoWidget_generated_h
#error "UnitInfoWidget.generated.h already included, missing '#pragma once' in UnitInfoWidget.h"
#endif
#define PROJECT_PAA_24_25_UnitInfoWidget_generated_h

#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateHistory); \
	DECLARE_FUNCTION(execUpdateUnitInfo);


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUnitInfoWidget(); \
	friend struct Z_Construct_UClass_UUnitInfoWidget_Statics; \
public: \
	DECLARE_CLASS(UUnitInfoWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Project_PAA_24_25"), NO_API) \
	DECLARE_SERIALIZER(UUnitInfoWidget)


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUnitInfoWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UUnitInfoWidget(UUnitInfoWidget&&); \
	UUnitInfoWidget(const UUnitInfoWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUnitInfoWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUnitInfoWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUnitInfoWidget) \
	NO_API virtual ~UUnitInfoWidget();


#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_11_PROLOG
#define FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_14_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_PAA_24_25_API UClass* StaticClass<class UUnitInfoWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitInfoWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
