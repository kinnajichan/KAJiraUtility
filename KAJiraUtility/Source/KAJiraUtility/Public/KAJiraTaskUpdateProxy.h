/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "KAJiraTaskProxyBase.h"
#include "KAJiraTaskUpdateProxy.generated.h"

/**
 * 
 */
UCLASS()
class KAJIRAUTILITY_API UKAJiraTaskUpdateProxy : public UKAJiraTaskProxyBase
{
	GENERATED_BODY()
	
public:
	//課題のタイトル
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskTitle;
	//課題の担当者
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskCurrentUser;
	//課題の種類
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskType;
	//課題のステータス
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskStatus;
	//課題の説明
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskDescription;
	//課題のコメント
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		TArray<FString> TaskComments;
	//更新時に有効ではない課題の場合自動的にJiraTaskActorを削除するかどうか
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		bool bIsInvalidTaskDelete;
};
