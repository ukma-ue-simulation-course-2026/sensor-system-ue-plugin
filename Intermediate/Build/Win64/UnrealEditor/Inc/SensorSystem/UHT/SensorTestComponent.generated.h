// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SensorTestComponent.h"

#ifdef SENSORSYSTEM_SensorTestComponent_generated_h
#error "SensorTestComponent.generated.h already included, missing '#pragma once' in SensorTestComponent.h"
#endif
#define SENSORSYSTEM_SensorTestComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ASensorTestComponent *****************************************************
#define FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSensorPing);


struct Z_Construct_UClass_ASensorTestComponent_Statics;
SENSORSYSTEM_API UClass* Z_Construct_UClass_ASensorTestComponent_NoRegister();

#define FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASensorTestComponent(); \
	friend struct ::Z_Construct_UClass_ASensorTestComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SENSORSYSTEM_API UClass* ::Z_Construct_UClass_ASensorTestComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(ASensorTestComponent, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SensorSystem"), Z_Construct_UClass_ASensorTestComponent_NoRegister) \
	DECLARE_SERIALIZER(ASensorTestComponent)


#define FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ASensorTestComponent(ASensorTestComponent&&) = delete; \
	ASensorTestComponent(const ASensorTestComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASensorTestComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASensorTestComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASensorTestComponent) \
	NO_API virtual ~ASensorTestComponent();


#define FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h_9_PROLOG
#define FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h_12_INCLASS_NO_PURE_DECLS \
	FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ASensorTestComponent;

// ********** End Class ASensorTestComponent *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
