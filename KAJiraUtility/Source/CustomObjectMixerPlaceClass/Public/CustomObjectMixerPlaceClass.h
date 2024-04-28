/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FCustomObjectMixerPlaceClassModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
