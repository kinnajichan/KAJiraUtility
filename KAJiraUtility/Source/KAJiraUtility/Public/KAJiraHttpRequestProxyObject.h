/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "HttpHeader.h"
#include "Interfaces/IHttpRequest.h"
#include "KAJiraHttpRequestProxyObject.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRequestCompletForUploadFile, FString, Response, bool, bSuccessful);
/**
 * 
 */
UCLASS()
class KAJIRAUTILITY_API UKAJiraHttpRequestProxyObject : public UObject
{
	GENERATED_BODY()

public:
	//リクエストが完了したときのコールバック
	UPROPERTY(BlueprintAssignable)
		FOnRequestCompletForUploadFile OnRequestComplete;

	//Httpリクエストにて、ファイルデータをアップロードする用の関数
	UFUNCTION(BlueprintCallable, Meta = (BlueprintInternalUseOnly), Category = "Http")
		static UKAJiraHttpRequestProxyObject* CreateHttpRequestProxyObjectForUploadFile(const FString& InUrl,const FString& InVerb,TMap<FString, FString> InHeader,FString InBody,FString FilePatn);

protected:

	void ProcessRequestForUploadFile(const FString& InUrl, const FString& InVerb, TMap<FString, FString>& InHeader, FString InBody,FString FilePatn);
	void ProcessCompleteForUploadFile(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, bool bInSuccessful);

private:

};
