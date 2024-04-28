/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityActor.h"
#include "KAJiraTaskActor.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, hidecategories = (Actor, Input, Collision, Rendering, Replication, Partition, HLOD, Cooking, Physics,Networking,LevelInstance))
class KAJIRAUTILITY_API AKAJiraTaskActor : public AEditorUtilityActor
{
	GENERATED_BODY()

public:

	//課題のID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		int32 TaskID;
	//課題のタイトルをWidgetComponentで表示するかどうか
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		bool bIsVisibleTaskTitle = true;
	//課題のタイトル
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskTitle;
	//課題の担当者をWidgetComponentで表示するかどうか
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		bool bIsVisibleTaskCurrentUser = true;
	//課題の担当者
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskCurrentUser;
	//課題の種類をWidgetComponentで表示するかどうか
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		bool bIsVisibleTaskType = true;
	//課題の種類
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskType;
	//課題のステータスをWidgetComponentで表示するかどうか
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		bool bIsVisibleTaskStatus = true;
	//課題のステータス
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		FString TaskStatus;
	//課題の説明をWidgetComponentで表示するかどうか
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		bool bIsVisibleTaskDescription = false;
	//課題の説明
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "KAJiraTask", meta = (MultiLine = "true"))
		FString TaskDescription;
	//課題のコメントをWidgetComponentで表示するかどうか
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KAJiraTask")
		bool bIsVisibleTaskComments = false;
	//課題のコメント
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "KAJiraTask", meta = (MultiLine = "true"))
		TArray<FString> TaskComments;

public:
	//表示テキストのプロパティを設定する
	UFUNCTION(BlueprintCallable,  Category = "KAJiraTask")
		void InitText(const FString& InTaskTitle,const  FString& InTaskDescription, const FString& InTaskCurrentUser, const FString& InTaskType, const FString& InTaskStatus, const TArray<FString>& InTaskComments);
	//課題を更新（同期）する
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, CallInEditor, Category = "KAJiraTask", meta = (DisplayPriority = 1))
		void UpdateJiraTask();
	//WidgetComponentの表示を更新する
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, CallInEditor, Category = "KAJiraTask", meta = (DisplayPriority = 2))
		void UpdateText();
	//WebBrowser上で課題を表示する
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, CallInEditor, Category = "KAJiraTask", meta = (DisplayPriority = 3))
		void OpenWebBrowser();
	//コメントを追加する
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, CallInEditor, Category = "KAJiraTask", meta = (DisplayPriority = 4))
		void AddComment();
	//ステータスを変更する
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, CallInEditor, Category = "KAJiraTask", meta = (DisplayPriority = 5))
		void ChangeStatus();
	//任意のファイルをアップロードする
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, CallInEditor, Category = "KAJiraTask", meta = (DisplayPriority = 6))
		void UploadFile();
	//現在のビューポートをキャプチャーし、その画像データをアップロードする
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, CallInEditor, Category = "KAJiraTask", meta = (DisplayPriority = 7))
		void UploadCurrentViewportCapture();

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

};
