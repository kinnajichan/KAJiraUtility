/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/


#include "KAJiraTaskProxyBase.h"

void UKAJiraTaskProxyBase::BeginExecution()
{
	bIsCuurentryExecutingTask = true;
	OnFinished.AddUObject(this, &UKAJiraTaskProxyBase::CallbackFinishTask);
}

void UKAJiraTaskProxyBase::CancelRequested()
{
	bIsCuurentryExecutingTask = false;
	OnFinished.RemoveAll(this);
}

void UKAJiraTaskProxyBase::InitTask(TSoftObjectPtr<AKAJiraTaskActor> InjiraTask)
{
	JiraTask = InjiraTask;
}

void UKAJiraTaskProxyBase::CallbackFinishTask(UEditorUtilityTask* Task)
{
	bIsCuurentryExecutingTask = false;
	OnFinished.RemoveAll(this);
}
