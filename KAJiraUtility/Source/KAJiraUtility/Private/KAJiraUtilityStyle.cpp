/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#include "KAJiraUtilityStyle.h"
#include "KAJiraUtility.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FKAJiraUtilityStyle::StyleInstance = nullptr;

void FKAJiraUtilityStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FKAJiraUtilityStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FKAJiraUtilityStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("KAJiraUtilityStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FKAJiraUtilityStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("KAJiraUtilityStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("KAJiraUtility")->GetBaseDir() / TEXT("Resources"));
	Style->Set("KAJiraUtility.PluginAction", new IMAGE_BRUSH_SVG(TEXT("plugin_button_icon"), Icon20x20));
	return Style;
}

void FKAJiraUtilityStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FKAJiraUtilityStyle::Get()
{
	return *StyleInstance;
}
