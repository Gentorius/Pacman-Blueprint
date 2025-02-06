// Fill out your copyright notice in the Description page of Project Settings.

#include "Deserialization/CSV_FL.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Structs/StringRowStruct.h"

TArray<FStringRowStruct> UCSV_FL::ReadCSVTo2DArray(const FString FilePath)
{
    TArray<FStringRowStruct> Result;

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
        const FString DataTableName = DataTable->GetName();
        const FString ErrorLog = e.what();
        UE_LOG(LogTemp, Error, TEXT("Error while reading CSV in (%s) to DataTable named (%s). The error log: %ls"), *FileName, *DataTableName, *ErrorLog);
        return false;
    }
    
    return true;
}


