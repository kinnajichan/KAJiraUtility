/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#include "KAJiraUtilityCommands.h"

#define LOCTEXT_NAMESPACE "FKAJiraUtilityModule"

void FKAJiraUtilityCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "Jira Task Actor Manager", "JiraTaskActorManagerを開く", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
