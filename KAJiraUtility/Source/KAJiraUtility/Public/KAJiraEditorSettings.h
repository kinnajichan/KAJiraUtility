/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "KAJiraEditorSettings.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, config = Editor)
class KAJIRAUTILITY_API UKAJiraEditorSettings : public UObject
{
	GENERATED_BODY()

public:
	//JiraのベースとなるURL
	UPROPERTY(BlueprintReadWrite, EditAnywhere, config, Category = KAJiraSettings)
		FString JiraContextURL;

	//Jiraのプロジェクトキー（プロジェクトの詳細で確認可能）
	UPROPERTY(BlueprintReadWrite, EditAnywhere, config, Category = KAJiraSettings)
		FString JiraProjectKey;

	//JiraのユーザーID（メールアドレス）
	UPROPERTY(EditAnywhere, config, Category = KAJiraSettings)
		FString JiraUserID;

	//JiraのAPIトークン
	//https://id.atlassian.com/manage-profile/security/api-tokensにて発行する必要がある
	UPROPERTY(EditAnywhere, config, Category = KAJiraSettings, meta = (PasswordField = true))
		FString JiraAPIToken;

	//エディタでMapを開いた際に自動的にすべてのタスクを同期するかどうか
	UPROPERTY(BlueprintReadWrite, EditAnywhere, config, Category = KAJiraSettings)
		bool bAutoUpdateJiraTaskWhenOnMapOpened = true;

	//JiraTaskActorの各種ボタンを使う際にEditorUtilityTaskにて動作中かどうかのPopupを出すかどうか
	UPROPERTY(BlueprintReadWrite, EditAnywhere, config, Category = KAJiraSettings)
		bool bUseEditorUtilityTaskForUtilityButton = false;

	//ViewportのRealTime設定がRemoteDesktop等では無効になっているので有効にする。
	//RealTimeが有効でないとWidgetComponentが正常に描画されない
	UPROPERTY(BlueprintReadWrite, EditAnywhere, config, Category = KAJiraSettings)
		bool bAutoEnableRealTime = true;


};