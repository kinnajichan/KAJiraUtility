/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "KAJiraTaskProxyBase.h"
#include "KAJiraTaskUploadFileProxy.generated.h"

/**
 * 
 */
UCLASS()
class KAJIRAUTILITY_API UKAJiraTaskUploadFileProxy : public UKAJiraTaskProxyBase
{
	GENERATED_BODY()

public:
	//アップロードするファイルのパス
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		FString FilePath;
	
};
