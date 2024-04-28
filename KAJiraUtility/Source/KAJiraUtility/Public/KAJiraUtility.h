/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FKAJiraUtilityModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	void PluginButtonClicked();

private:
	void RegisterMenus();

	TSharedPtr<class FUICommandList> PluginCommands;

};
