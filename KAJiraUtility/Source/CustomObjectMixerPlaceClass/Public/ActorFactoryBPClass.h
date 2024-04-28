/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "ActorFactories/ActorFactoryBlueprint.h"
#include "ActorFactoryBPClass.generated.h"

/**
 * 
 */
UCLASS(config = Editor, collapsecategories, hidecategories = Object, Blueprintable, Abstract)
class CUSTOMOBJECTMIXERPLACECLASS_API UActorFactoryBPClass : public UActorFactoryBlueprint
{
	GENERATED_UCLASS_BODY()
public:

	virtual AActor* GetDefaultActor(const FAssetData& AssetData) override;
	virtual UClass* GetDefaultActorClass(const FAssetData& AssetData) override;

	//Spawnするアクタークラス
	UPROPERTY(EditAnywhere, Category = "CustomObjectMixer")
		TSubclassOf<AActor> ActorClass;
};
