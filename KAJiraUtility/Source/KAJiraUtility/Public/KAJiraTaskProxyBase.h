/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityTask.h"
#include "KAJiraTaskActor.h"
#include "KAJiraTaskProxyBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Transient)
class KAJIRAUTILITY_API UKAJiraTaskProxyBase : public UEditorUtilityTask
{
	GENERATED_BODY()

public:
	//JiraTaskActor（GC対策でSoftObjectPtr）
	UPROPERTY(BlueprintReadOnly, Category = "KAJiraTask")
		TSoftObjectPtr<AKAJiraTaskActor> JiraTask;
	//現在このプロキシタスクが実行されているかどうか
	UPROPERTY(BlueprintReadOnly, Category = "KAJiraTask")
		bool bIsCuurentryExecutingTask;

protected:

	virtual void BeginExecution() override; 
	virtual void CancelRequested() override; 

public:
	//タスクの初期化
	UFUNCTION(BlueprintCallable, Category = "KAJiraTask")
		void InitTask(TSoftObjectPtr<AKAJiraTaskActor> InjiraTask);

private:
	void CallbackFinishTask(UEditorUtilityTask* Task);
	
};
