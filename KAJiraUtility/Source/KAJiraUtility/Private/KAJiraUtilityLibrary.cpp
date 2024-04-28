/***************************************************
* Copyright 2018 - 2024 Kinnaji.All right reserved.
****************************************************/


#include "KAJiraUtilityLibrary.h"
#include "DesktopPlatformModule.h"


#define LOCTEXT_NAMESPACE "KAJiraUtilityLibrary"

bool UKAJiraUtilityLibrary::OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& DefaultFile, const FString& FileTypes, bool bIsMultiple, TArray<FString>& OutFilenames)
{

	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	const void* ParentWindowWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);

	DesktopPlatform->OpenFileDialog(
		ParentWindowWindowHandle,
		DialogTitle,
		DefaultPath,
		DefaultFile,
		FileTypes,
		bIsMultiple,
		OutFilenames
	);

	return OutFilenames.Num() > 0;
}

#undef LOCTEXT_NAMESPACE


