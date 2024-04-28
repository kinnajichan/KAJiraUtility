/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/


#include "KAJiraHttpRequestProxyObject.h"
#include "HttpModule.h"
#include "HttpHeader.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Serialization/BufferArchive.h"
#include "Misc/FileHelper.h"

UKAJiraHttpRequestProxyObject* UKAJiraHttpRequestProxyObject::CreateHttpRequestProxyObjectForUploadFile(const FString& InUrl, const FString& InVerb, TMap<FString,FString> InHeader, FString InBody, FString FilePatn)
{
	UKAJiraHttpRequestProxyObject* const Proxy = NewObject<UKAJiraHttpRequestProxyObject>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->ProcessRequestForUploadFile(InUrl, InVerb, InHeader,InBody, FilePatn);
	return Proxy;
}

void UKAJiraHttpRequestProxyObject::ProcessRequestForUploadFile(const FString& InUrl, const FString& InVerb, TMap<FString, FString>& InHeader, FString InBody, FString FilePatn)
{
	FHttpModule& HttpModule = FHttpModule::Get();
	const TSharedRef<IHttpRequest> Request = HttpModule.CreateRequest();
	Request->SetURL(InUrl);
	Request->SetVerb(InVerb);
	
	//boundaryは暫定で固定
	FString Boundary = TEXT("----WebKitFormBoundary7MA4YWxkTrZu0gW");
	
	FString ContentType = FString::Printf(TEXT("multipart/form-data; boundary=%s"), *Boundary);
	Request->SetHeader(TEXT("Content-Type"), ContentType);

	for (auto& HeaderKeyVal : InHeader)
	{
		Request->SetHeader(HeaderKeyVal.Key, HeaderKeyVal.Value);
	}
	// リクエストボディの構築
	FString BeginBoundary = FString::Printf(TEXT("--%s\r\n"), *Boundary);
	FString EndBoundary = FString::Printf(TEXT("\r\n--%s--\r\n"), *Boundary);

	FString FileHeader = FString::Printf(TEXT("Content-Disposition: form-data; name=\"file\"; filename=\"%s\"\r\nContent-Type: application/octet-stream\r\n\r\n"), *FilePatn);

	TArray<uint8> FileData;
	FFileHelper::LoadFileToArray(FileData, *FilePatn);

	FBufferArchive Payload;
	Payload.Append((uint8*)TCHAR_TO_ANSI(*BeginBoundary), BeginBoundary.Len());
	Payload.Append((uint8*)TCHAR_TO_ANSI(*InBody), InBody.Len());
	Payload.Append((uint8*)TCHAR_TO_ANSI(*FileHeader), FileHeader.Len());
	Payload.Append(FileData);
	Payload.Append((uint8*)TCHAR_TO_ANSI(*EndBoundary), EndBoundary.Len());
	
	Request->SetContent(Payload);

	Request->ProcessRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &UKAJiraHttpRequestProxyObject::ProcessCompleteForUploadFile);
}

void UKAJiraHttpRequestProxyObject::ProcessCompleteForUploadFile(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, bool bInSuccessful)
{
	OnRequestComplete.Broadcast(InResponse->GetContentAsString(), bInSuccessful);
}

