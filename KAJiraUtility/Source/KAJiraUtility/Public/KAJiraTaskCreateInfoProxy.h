/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "KAJiraTaskProxyBase.h"
#include "KAJiraTaskCreateInfoProxy.generated.h"

/**
 * 
 */
UCLASS()
class KAJIRAUTILITY_API UKAJiraTaskCreateInfoProxy : public UKAJiraTaskProxyBase
{
	GENERATED_BODY()

public:
	//課題のタイトル
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskTitle;
	//課題の担当者
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask", meta = (GetOptions = "GetUserNameOptions"))
		FString TaskTargetUser;
	//課題の種類
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask", meta = (GetOptions = "GetTaskTypeNameOptions"))
		FString TaskType;
	//課題の説明
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask", meta = (MultiLine = "true"))
		FString TaskDescription;
	//初期化が完了したかどうか
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		bool bIsInitialized;
	//Jira上のユーザー一覧
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		TMap<FString, FString> JiraUserList;
	//課題の種類一覧
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		TArray<FString> TaskTypeList;
	//TaskTargetUserのPulldown用関数
	UFUNCTION(CallInEditor, BlueprintImplementableEvent)
		TArray<FString> GetUserNameOptions() const;
	//TaskTypeのPulldown用関数
	UFUNCTION(CallInEditor, BlueprintImplementableEvent)
		TArray<FString> GetTaskTypeNameOptions() const;
	
};
