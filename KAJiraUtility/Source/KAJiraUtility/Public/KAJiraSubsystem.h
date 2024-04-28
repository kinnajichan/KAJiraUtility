/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "HttpModule.h"
#include "PlatformHttp.h"
#include "Interfaces/IHttpResponse.h"
#include "KAJiraEditorSettings.h"
#include "KAJiraSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class KAJIRAUTILITY_API UKAJiraSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize()	override;

	//このプラグインのEditorPreference設定用オブジェクトを取得する
	UFUNCTION(BlueprintCallable,Category = "KAJiraSubsystem")
	UKAJiraEditorSettings* GetJiraEditorSettings();

	//Http経由でJiraに接続する際のBasic承認用のHeader文字列を取得する
	UFUNCTION(BlueprintCallable, Category = "KAJiraSubsystem")
	FString GetJiraAuthString();

	//StringからBase64へ変換する
	UFUNCTION(BlueprintPure, Category = "KAJiraSubsystem")
	FString StringToBase64(FString InString);

	//EUW_JiraTaskActorManagerを起動させる
	UFUNCTION(BlueprintCallable, Category = "KAJiraSubsystem")
		void OpenJiraManagerEUW();

private:
	//Editorでマップが開いたときのデリゲート受け取り用
	void OnMapOpened(const FString& Filename, bool bAsTemplate);

	//ViewportのRealTime設定を有効にする
	void OnEnableRealTime();

};
