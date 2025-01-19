#pragma once

#include "CoreMinimal.h"
#include "GoogleSheetsLoader.generated.h"

UCLASS()
class PACMAN_API UGoogleSheetsLoader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GoogleSheets")
	static void DownloadCSVGoogleSheets(FString URL);
};
	

