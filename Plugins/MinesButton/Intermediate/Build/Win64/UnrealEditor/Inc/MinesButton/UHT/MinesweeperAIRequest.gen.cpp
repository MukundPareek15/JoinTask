// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinesButton/Public/MinesweeperAIRequest.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMinesweeperAIRequest() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	MINESBUTTON_API UClass* Z_Construct_UClass_UMinesweeperAIRequest();
	MINESBUTTON_API UClass* Z_Construct_UClass_UMinesweeperAIRequest_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinesButton();
// End Cross Module References
	void UMinesweeperAIRequest::StaticRegisterNativesUMinesweeperAIRequest()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMinesweeperAIRequest);
	UClass* Z_Construct_UClass_UMinesweeperAIRequest_NoRegister()
	{
		return UMinesweeperAIRequest::StaticClass();
	}
	struct Z_Construct_UClass_UMinesweeperAIRequest_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMinesweeperAIRequest_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_MinesButton,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMinesweeperAIRequest_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMinesweeperAIRequest_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MinesweeperAIRequest.h" },
		{ "ModuleRelativePath", "Public/MinesweeperAIRequest.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMinesweeperAIRequest_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMinesweeperAIRequest>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMinesweeperAIRequest_Statics::ClassParams = {
		&UMinesweeperAIRequest::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMinesweeperAIRequest_Statics::Class_MetaDataParams), Z_Construct_UClass_UMinesweeperAIRequest_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMinesweeperAIRequest()
	{
		if (!Z_Registration_Info_UClass_UMinesweeperAIRequest.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMinesweeperAIRequest.OuterSingleton, Z_Construct_UClass_UMinesweeperAIRequest_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMinesweeperAIRequest.OuterSingleton;
	}
	template<> MINESBUTTON_API UClass* StaticClass<UMinesweeperAIRequest>()
	{
		return UMinesweeperAIRequest::StaticClass();
	}
	UMinesweeperAIRequest::UMinesweeperAIRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMinesweeperAIRequest);
	UMinesweeperAIRequest::~UMinesweeperAIRequest() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_MinesweeperAIRequest_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_MinesweeperAIRequest_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMinesweeperAIRequest, UMinesweeperAIRequest::StaticClass, TEXT("UMinesweeperAIRequest"), &Z_Registration_Info_UClass_UMinesweeperAIRequest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMinesweeperAIRequest), 7837830U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_MinesweeperAIRequest_h_3405886930(TEXT("/Script/MinesButton"),
		Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_MinesweeperAIRequest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_MinesweeperAIRequest_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
