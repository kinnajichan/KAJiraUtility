/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/


#include "KAJiraTaskActor.h"

void AKAJiraTaskActor::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	const FName Name = PropertyChangedEvent.Property ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	if (Name == TEXT("TaskID"))
	{
		UpdateJiraTask();
	}
	else
	{
		UpdateText();
	}

}

void AKAJiraTaskActor::InitText(const FString& InTaskTitle, const FString& InTaskDescription, const FString& InTaskCurrentUser, const FString& InTaskType, const FString& InTaskStatus, const TArray<FString>& InTaskComments)
{
	TaskTitle = InTaskTitle;
	TaskDescription = InTaskDescription;
	TaskCurrentUser = InTaskCurrentUser;
	TaskType = InTaskType;
	TaskStatus = InTaskStatus;
	TaskComments = InTaskComments;
	UpdateText();
}
