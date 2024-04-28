/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/


#include "KAJiraSubsystem.h"
#include "EditorUtilitySubsystem.h"
#include "EditorUtilityWidgetBlueprint.h"
#include "Editor.h"
#include "LevelEditorViewport.h"
#include "Kismet/GameplayStatics.h"
#include "KAJiraTaskActor.h"
#include "Misc/FileHelper.h"

void UKAJiraSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FEditorDelegates::OnMapOpened.AddUObject(this, &UKAJiraSubsystem::OnMapOpened);
	if (GEditor)
	{
		GEditor->OnLevelViewportClientListChanged().AddUObject(this, &UKAJiraSubsystem::OnEnableRealTime);
	}
	OnEnableRealTime();
}

void UKAJiraSubsystem::Deinitialize()
{
	Super::Deinitialize();
	FEditorDelegates::OnMapOpened.RemoveAll(this);
	if (GEditor)
	{
		GEditor->OnLevelViewportClientListChanged().RemoveAll(this);
	}
}

UKAJiraEditorSettings* UKAJiraSubsystem::GetJiraEditorSettings()
{
	return GetMutableDefault<UKAJiraEditorSettings>();
}

FString UKAJiraSubsystem::GetJiraAuthString()
{
	FString OutString;
	FString AuthString;
	UKAJiraEditorSettings* Settings = GetJiraEditorSettings();

	OutString.Append(TEXT("Basic "));
	AuthString.Append(Settings->JiraUserID);
	AuthString.Append(TEXT(":"));
	AuthString.Append(Settings->JiraAPIToken);
	AuthString = StringToBase64(AuthString);
	OutString.Append(AuthString);
	return OutString;
}

FString UKAJiraSubsystem::StringToBase64(FString InString)
{
	return FBase64::Encode(InString);
}

void UKAJiraSubsystem::OpenJiraManagerEUW()
{
	if (auto* EUW = LoadObject<UEditorUtilityWidgetBlueprint>(this, *FString("/KAJiraUtility/KAJiraUtility/EUW/EUW_JiraTaskActorManager"), nullptr, LOAD_None, nullptr))
	{
		if (auto* EUS = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>())
		{
			EUS->SpawnAndRegisterTab(EUW);
		}
	}
}

void UKAJiraSubsystem::OnMapOpened(const FString& Filename, bool bAsTemplate)
{
	if (!GetJiraEditorSettings()->bAutoUpdateJiraTaskWhenOnMapOpened)
	{
		return;
	}

	UKAJiraEditorSettings* Settings = GetJiraEditorSettings();
	if (Settings->JiraContextURL.IsEmpty()
		|| Settings->JiraProjectKey.IsEmpty()
		|| Settings->JiraUserID.IsEmpty()
		|| Settings->JiraAPIToken.IsEmpty())
	{
		return;
	}

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GEditor->GetEditorWorldContext().World(), AKAJiraTaskActor::StaticClass(), OutActors);
	for (auto OutActor : OutActors)
	{
		if (auto JiraTask = Cast<AKAJiraTaskActor>(OutActor))
		{
			JiraTask->UpdateJiraTask();
		}
	}
}

void UKAJiraSubsystem::OnEnableRealTime()
{
	if (auto* Settings = GetJiraEditorSettings())
	{
		if (Settings->bAutoEnableRealTime)
		{
			for (auto* VC : GEditor->GetLevelViewportClients())
			{
				if (VC->IsRealtimeOverrideSet())
				{
					VC->PopRealtimeOverride();
				}
				if (!VC->IsRealtime())
				{
					VC->SetRealtime(true);
				}
			}
		}
	}
}
