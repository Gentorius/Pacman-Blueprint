// Fill out your copyright notice in the Description page of Project Settings.


#include "CSV_FL.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

TArray<FCSVRow> UCSV_FL::ReadCSVTo2DArray(FString FileName)
{
    TArray<FCSVRow> Result;
    FString FilePath = FPaths::ProjectContentDir() + FileName;
    FString FileContent;

    if (FFileHelper::LoadFileToString(FileContent, *FilePath))
    {
        TArray<FString> Lines;
        FileContent.ParseIntoArrayLines(Lines);

        for (const FString& Line : Lines)
        {
            FCSVRow Row;
            Line.ParseIntoArray(Row.Cells, TEXT(","), true);
            Result.Add(Row);
        }
    }

    return Result;
}
