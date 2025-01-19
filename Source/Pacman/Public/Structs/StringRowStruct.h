#pragma once 

#include "CoreMinimal.h"
#include "StringRowStruct.generated.h"

USTRUCT(BlueprintType)
struct PACMAN_API FStringRowStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "CSV")
	TArray<FString> Cells;
};

