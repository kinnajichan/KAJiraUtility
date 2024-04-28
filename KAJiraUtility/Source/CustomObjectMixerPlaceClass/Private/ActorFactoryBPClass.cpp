/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/


#include "ActorFactoryBPClass.h"

UActorFactoryBPClass::UActorFactoryBPClass(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//ActorClass = NULL;
	//DisplayName = LOCTEXT("BlueprintDisplayName", "Blueprint");
}

AActor* UActorFactoryBPClass::GetDefaultActor(const FAssetData& AssetData)
{
	return ActorClass->GetDefaultObject<AActor>();
}

UClass* UActorFactoryBPClass::GetDefaultActorClass(const FAssetData& AssetData)
{
	return ActorClass;
}
