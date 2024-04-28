/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EditorUtilityBlueprint.h"
#include "ActorFactoryBPClassDataList.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CUSTOMOBJECTMIXERPLACECLASS_API UActorFactoryBPClassDataList : public UDataAsset
{
	GENERATED_BODY()

public:

	//ActorFactoryのBP
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "CustomObjectMixer")
	TArray<TObjectPtr<UEditorUtilityBlueprint>> BPActorFactories;
	
};
