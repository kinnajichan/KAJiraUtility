/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "KAJiraTaskProxyBase.h"
#include "KAJiraTaskChangeStatusProxy.generated.h"

/**
 * 
 */
UCLASS()
class KAJIRAUTILITY_API UKAJiraTaskChangeStatusProxy : public UKAJiraTaskProxyBase
{
	GENERATED_BODY()

public:
	//課題のステータス
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask", meta = (GetOptions = "GetNameOptions"))
		FString TaskStatus;
	//変更可能なステータスの一覧
	UPROPERTY(BlueprintReadWrite, Category = "KAJiraTask")
		TMap<FString,int32> StatusList;
	//TaskStatusのPulldown用関数
	UFUNCTION(CallInEditor, BlueprintImplementableEvent)
		TArray<FString> GetNameOptions() const;
};
