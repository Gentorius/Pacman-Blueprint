// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CSVFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API UCSVFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CSV")
	static TArray<FString> ReadCSV(FString FilePath);
};
