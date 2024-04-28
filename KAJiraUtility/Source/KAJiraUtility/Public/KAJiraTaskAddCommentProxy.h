/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "KAJiraTaskProxyBase.h"
#include "KAJiraTaskAddCommentProxy.generated.h"

/**
 * 
 */
UCLASS()
class KAJIRAUTILITY_API UKAJiraTaskAddCommentProxy : public UKAJiraTaskProxyBase
{
	GENERATED_BODY()

public:
	//課題のコメント
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask", meta = (MultiLine = true))
		FString TaskComment;
	
};
