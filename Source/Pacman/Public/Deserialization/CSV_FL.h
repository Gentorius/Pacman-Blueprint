// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Structs/StringRowStruct.h"
#include "CSV_FL.generated.h"

UCLASS()
class PACMAN_API UCSV_FL : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "CSV")
    static TArray<FStringRowStruct> ReadCSVTo2DArray(FString FilePath);
    UFUNCTION(BlueprintCallable, Category = "CSV")
    static bool ReadCSVToDataTable(const FString& FileName, UDataTable* DataTable);
};
