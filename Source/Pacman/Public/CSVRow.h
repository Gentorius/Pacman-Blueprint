#pragma once 

#include "CoreMinimal.h"
#include "CSVRow.generated.h"

USTRUCT(BlueprintType)
struct PACMAN_API FCSVRow
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "CSV")
	TArray<FString> Cells;
};

