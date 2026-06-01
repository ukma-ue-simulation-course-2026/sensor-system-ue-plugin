// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SensorTestComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSensorTestComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
SENSORSYSTEM_API UClass* Z_Construct_UClass_ASensorTestComponent();
SENSORSYSTEM_API UClass* Z_Construct_UClass_ASensorTestComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_SensorSystem();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASensorTestComponent Function SensorPing *********************************
struct Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics
{
	struct SensorTestComponent_eventSensorPing_Parms
	{
		float InputValue;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SensorSystem|Debug" },
		{ "ModuleRelativePath", "Public/SensorTestComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SensorPing constinit property declarations ****************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InputValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SensorPing constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SensorPing Property Definitions ***************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::NewProp_InputValue = { "InputValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SensorTestComponent_eventSensorPing_Parms, InputValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SensorTestComponent_eventSensorPing_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::NewProp_InputValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::PropPointers) < 2048);
// ********** End Function SensorPing Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ASensorTestComponent, nullptr, "SensorPing", 	Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::SensorTestComponent_eventSensorPing_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::SensorTestComponent_eventSensorPing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASensorTestComponent_SensorPing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASensorTestComponent_SensorPing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASensorTestComponent::execSensorPing)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InputValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=ASensorTestComponent::SensorPing(Z_Param_InputValue);
	P_NATIVE_END;
}
// ********** End Class ASensorTestComponent Function SensorPing ***********************************

// ********** Begin Class ASensorTestComponent *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASensorTestComponent;
UClass* ASensorTestComponent::GetPrivateStaticClass()
{
	using TClass = ASensorTestComponent;
	if (!Z_Registration_Info_UClass_ASensorTestComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SensorTestComponent"),
			Z_Registration_Info_UClass_ASensorTestComponent.InnerSingleton,
			StaticRegisterNativesASensorTestComponent,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ASensorTestComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_ASensorTestComponent_NoRegister()
{
	return ASensorTestComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASensorTestComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Sensors" },
		{ "IncludePath", "SensorTestComponent.h" },
		{ "ModuleRelativePath", "Public/SensorTestComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ASensorTestComponent constinit property declarations *********************
// ********** End Class ASensorTestComponent constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("SensorPing"), .Pointer = &ASensorTestComponent::execSensorPing },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASensorTestComponent_SensorPing, "SensorPing" }, // 1681929032
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASensorTestComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASensorTestComponent_Statics
UObject* (*const Z_Construct_UClass_ASensorTestComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SensorSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASensorTestComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASensorTestComponent_Statics::ClassParams = {
	&ASensorTestComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASensorTestComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_ASensorTestComponent_Statics::Class_MetaDataParams)
};
void ASensorTestComponent::StaticRegisterNativesASensorTestComponent()
{
	UClass* Class = ASensorTestComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_ASensorTestComponent_Statics::Funcs));
}
UClass* Z_Construct_UClass_ASensorTestComponent()
{
	if (!Z_Registration_Info_UClass_ASensorTestComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASensorTestComponent.OuterSingleton, Z_Construct_UClass_ASensorTestComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASensorTestComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASensorTestComponent);
ASensorTestComponent::~ASensorTestComponent() {}
// ********** End Class ASensorTestComponent *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h__Script_SensorSystem_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASensorTestComponent, ASensorTestComponent::StaticClass, TEXT("ASensorTestComponent"), &Z_Registration_Info_UClass_ASensorTestComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASensorTestComponent), 1321146708U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h__Script_SensorSystem_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h__Script_SensorSystem_2045585182{
	TEXT("/Script/SensorSystem"),
	Z_CompiledInDeferFile_FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h__Script_SensorSystem_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Unreal_Projects_FirstPractice_Plugins_SensorSystem_Source_SensorSystem_Public_SensorTestComponent_h__Script_SensorSystem_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
