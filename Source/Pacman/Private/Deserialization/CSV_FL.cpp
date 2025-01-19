// Fill out your copyright notice in the Description page of Project Settings.

#include "Deserialization/CSV_FL.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Structs/StringRowStruct.h"

TArray<FStringRowStruct> UCSV_FL::ReadCSVTo2DArray(FString FileName)
{
    TArray<FStringRowStruct> Result;
    const FString FilePath = FPaths::ProjectContentDir() + FileName;

    if (FString FileContent; FFileHelper::LoadFileToString(FileContent, *FilePath))
    {
        TArray<FString> Lines;
        FileContent.ParseIntoArrayLines(Lines);

        for (const FString& Line : Lines)
        {
            FStringRowStruct Row;
            Line.ParseIntoArray(Row.Cells, TEXT(","), true);
            Result.Add(Row);
        }
    }

    return Result;
}

bool UCSV_FL::ReadCSVToDataTable(const FString& FileName, UDataTable* DataTable)
{
    try
    {
        UDataTableFunctionLibrary::FillDataTableFromCSVString(DataTable, FileName, DataTable->RowStruct);
    }
    catch (const std::exception& e)
    {
        UE_LOG(LogTemp, Error, TEXT("Error while reading CSV in (%s) to DataTable named (%s). The error log: %hs"), *FileName, *DataTable->GetName, e.what());
        return false;
    }
    
    return true;
}


