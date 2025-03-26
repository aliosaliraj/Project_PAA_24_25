// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UnitBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AUnitBase;
#ifdef PROJECT_PAA_24_25_UnitBase_generated_h
#error "UnitBase.generated.h already included, missing '#pragma once' in UnitBase.h"
#endif
#define PROJECT_PAA_24_25_UnitBase_generated_h

#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAttackTarget); \
	DECLARE_FUNCTION(execApplyDamage);


#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAUnitBase(); \
	friend struct Z_Construct_UClass_AUnitBase_Statics; \
public: \
	DECLARE_CLASS(AUnitBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Project_PAA_24_25"), NO_API) \
	DECLARE_SERIALIZER(AUnitBase)


#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AUnitBase(AUnitBase&&); \
	AUnitBase(const AUnitBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AUnitBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AUnitBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AUnitBase) \
	NO_API virtual ~AUnitBase();


#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_19_PROLOG
#define FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_22_INCLASS_NO_PURE_DECLS \
	FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECT_PAA_24_25_API UClass* StaticClass<class AUnitBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_alios_OneDrive___unige_it_Documenti_Unreal_Projects_Project_PAA_24_25_Source_Project_PAA_24_25_UnitBase_h


#define FOREACH_ENUM_EUNITTYPE(op) \
	op(EUnitType::Sniper) \
	op(EUnitType::Brawler) 

enum class EUnitType : uint8;
template<> struct TIsUEnumClass<EUnitType> { enum { Value = true }; };
template<> PROJECT_PAA_24_25_API UEnum* StaticEnum<EUnitType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
