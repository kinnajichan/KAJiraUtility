/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#include "KAJiraUtility.h"
#include "ISettingsModule.h"
#include "KAJiraEditorSettings.h"
#include "KAJiraSubsystem.h"
#include "KAJiraUtilityCommands.h"

#define LOCTEXT_NAMESPACE "FKAJiraUtilityModule"

void FKAJiraUtilityModule::StartupModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings(
			"Editor",
			"Plugins",
			"KAJiraUtility",
			LOCTEXT("KAJiraUtilityName", "KAJiraUtility"),
			LOCTEXT("KAJiraUtilityDescription", "Settings For KAJiraUtility"),
			GetMutableDefault<UKAJiraEditorSettings>()
		);
	}
	FKAJiraUtilityStyle::Initialize();
	FKAJiraUtilityStyle::ReloadTextures();

	FKAJiraUtilityCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FKAJiraUtilityCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FKAJiraUtilityModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FKAJiraUtilityModule::RegisterMenus));
}

void FKAJiraUtilityModule::ShutdownModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings(
			"Editor",
			"Plugins",
			"KAJiraUtility"
		);
	}
	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FKAJiraUtilityStyle::Shutdown();

	FKAJiraUtilityCommands::Unregister();
}

void FKAJiraUtilityModule::PluginButtonClicked()
{
	if (!GEditor)
	{
		return;
	}
	if (auto* JiraSubsystem = GEditor->GetEditorSubsystem<UKAJiraSubsystem>())
	{
		JiraSubsystem->OpenJiraManagerEUW();
	}
}

void FKAJiraUtilityModule::RegisterMenus()
{
	FToolMenuOwnerScoped OwnerScoped(this);
	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("KAJiraUtility");
			Section.Label = LOCTEXT("KAJiraUtilitySection", "KAJiraUtility");
			Section.AddMenuEntryWithCommandList(FKAJiraUtilityCommands::Get().PluginAction, PluginCommands, LOCTEXT("KAJiraUtilityOpenEUWButton", "Jira Task Actor Manager"));
		}
	}

	UToolMenus::Get()->RefreshAllWidgets();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FKAJiraUtilityModule, KAJiraUtility)
