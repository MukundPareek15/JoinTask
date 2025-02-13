// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MinesButton/Public/WindowHUD.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWindowHUD() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	MINESBUTTON_API UClass* Z_Construct_UClass_AWindowHUD();
	MINESBUTTON_API UClass* Z_Construct_UClass_AWindowHUD_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MinesButton();
// End Cross Module References
	void AWindowHUD::StaticRegisterNativesAWindowHUD()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWindowHUD);
	UClass* Z_Construct_UClass_AWindowHUD_NoRegister()
	{
		return AWindowHUD::StaticClass();
	}
	struct Z_Construct_UClass_AWindowHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWindowHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_MinesButton,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWindowHUD_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWindowHUD_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A custom HUD class that integrates a Slate-based chat window into the game viewport.\n */" },
#endif
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "WindowHUD.h" },
		{ "ModuleRelativePath", "Public/WindowHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A custom HUD class that integrates a Slate-based chat window into the game viewport." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWindowHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWindowHUD>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWindowHUD_Statics::ClassParams = {
		&AWindowHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWindowHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_AWindowHUD_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AWindowHUD()
	{
		if (!Z_Registration_Info_UClass_AWindowHUD.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWindowHUD.OuterSingleton, Z_Construct_UClass_AWindowHUD_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWindowHUD.OuterSingleton;
	}
	template<> MINESBUTTON_API UClass* StaticClass<AWindowHUD>()
	{
		return AWindowHUD::StaticClass();
	}
	AWindowHUD::AWindowHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWindowHUD);
	AWindowHUD::~AWindowHUD() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_WindowHUD_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_WindowHUD_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWindowHUD, AWindowHUD::StaticClass, TEXT("AWindowHUD"), &Z_Registration_Info_UClass_AWindowHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWindowHUD), 4074827190U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_WindowHUD_h_2171359390(TEXT("/Script/MinesButton"),
		Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_WindowHUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Games_JoinTask_Plugins_MinesButton_Source_MinesButton_Public_WindowHUD_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
