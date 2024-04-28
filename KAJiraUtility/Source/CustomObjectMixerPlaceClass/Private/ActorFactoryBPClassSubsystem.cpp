/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/


#include "ActorFactoryBPClassSubsystem.h"
#include "ActorFactoryBPClass.h"

void UActorFactoryBPClassSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FCoreDelegates::OnPostEngineInit.AddUObject(this, &UActorFactoryBPClassSubsystem::OnPostEngineInit);

}

void UActorFactoryBPClassSubsystem::OnPostEngineInit()
{
	UActorFactoryBPClassDataList* BPClassDataList = LoadObject<UActorFactoryBPClassDataList>(this, *FString("/KAJiraUtility/ObjectMixer/DA/DA_ActorClassList.DA_ActorClassList"), nullptr, LOAD_None, nullptr);
	if (!BPClassDataList)
	{
		return;
	}
	for (UBlueprint* BPActorFactory : BPClassDataList->BPActorFactories)
	{
		if (!BPActorFactory)
		{
			continue;
		}
		if (UActorFactoryBPClass* DefaultObject = BPActorFactory->GeneratedClass->GetDefaultObject<UActorFactoryBPClass>())
		{
			UActorFactoryBPClass* NewFactory = NewObject<UActorFactoryBPClass>(GetTransientPackage(), BPActorFactory->GeneratedClass);
			check(NewFactory);
			NewFactory->NewActorClassName = NewFactory->ActorClass->GetPathName();
			NewFactory->NewActorClass = NewFactory->ActorClass;
			GEditor->ActorFactories.Add(NewFactory);
		}
	}
}
