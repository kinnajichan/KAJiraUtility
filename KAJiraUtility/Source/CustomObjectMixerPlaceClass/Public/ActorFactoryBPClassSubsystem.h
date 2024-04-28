/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "ActorFactoryBPClassDataList.h"
#include "ActorFactoryBPClassSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CUSTOMOBJECTMIXERPLACECLASS_API UActorFactoryBPClassSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	void OnPostEngineInit();
};
