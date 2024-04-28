/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KAJiraUtilityLibrary.generated.h"

/**
 * 
 */
UCLASS()
class KAJIRAUTILITY_API UKAJiraUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//ファイルを選択させるダイアログを開く
	UFUNCTION(BlueprintCallable, Category = "KAJiraUtility")
		static bool OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& DefaultFile, const FString& FileTypes, bool bIsMultiple, TArray< FString >& OutFilenames);

	
};
