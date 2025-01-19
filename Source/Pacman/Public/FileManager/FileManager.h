// Developed By GentoriusHord

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileManager.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API UFileManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static bool DoesFileWithStringInNameExist(FString Directory, FString StringInName, FString& FilePaths);
	static bool DoFilesWithStringsInNameExist(FString Directory, TArray<FString> StringsInName, TArray<FString>& FilePaths);
};
