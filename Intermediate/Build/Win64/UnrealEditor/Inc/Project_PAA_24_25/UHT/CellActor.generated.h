// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CellActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FColor;
#ifdef PROJECT_PAA_24_25_CellActor_generated_h
#error "CellActor.generated.h already included, missing '#pragma once' in CellActor.h"
#endif
#define PROJECT_PAA_24_25_CellActor_generated_h

#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetCellColor); \
	DECLARE_FUNCTION(execHighlightCell);


#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACellActor(); \
	friend struct Z_Construct_UClass_ACellActor_Statics; \
public: \
	DECLARE_CLASS(ACellActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project_PAA_24_25"), NO_API) \
	DECLARE_SERIALIZER(ACellActor)


#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACellActor(ACellActor&&); \
	ACellActor(const ACellActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACellActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACellActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACellActor) \
	NO_API virtual ~ACellActor();


#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_9_PROLOG
#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_12_INCLASS_NO_PURE_DECLS \
	FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_PAA_24_25_API UClass* StaticClass<class ACellActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_CellActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
