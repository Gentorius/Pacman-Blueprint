// Fill out your copyright notice in the Description page of Project Settings.

#include "Deserialization/CSV_FL.h"
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
            Line.ParseIntoArray(Row.Cells, TEXT(","), false);
            Result.Add(Row);
        }
    }

    return Result;
}

bool UCSV_FL::DoesFileExist(const FString& FilePath)
{
    return FPaths::FileExists(FilePath);
}


