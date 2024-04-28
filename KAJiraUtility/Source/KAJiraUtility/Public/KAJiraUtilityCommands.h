/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "KAJiraUtilityStyle.h"

class FKAJiraUtilityCommands : public TCommands<FKAJiraUtilityCommands>
{
public:

	FKAJiraUtilityCommands()
		: TCommands<FKAJiraUtilityCommands>(TEXT("KAJiraUtility"), NSLOCTEXT("Contexts", "KAJiraUtility", "KAJiraUtility Plugin"), NAME_None, FKAJiraUtilityStyle::GetStyleSetName())
	{
	}

	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
