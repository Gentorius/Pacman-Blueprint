// Fill out your copyright notice in the Description page of Project Settings.


#include "CSV_FL.h"
#include "../../../../../../../../../Program Files/Epic Games/UE_5.5/Engine/Source/Runtime/Core/Public/Containers/Array.h"
#include "../../../../../../../../../Program Files/Epic Games/UE_5.5/Engine/Source/Runtime/TraceLog/standalone_prologue.h"
#include "CSVFunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"


TArray<TArray<FString>> UCSV_FL::ReadCSVTo2DArray(FString FilePath)
{
	TArray<FString> CSVLines;
	TArray<TArray<FString>> CSV2DArray;

	FString FullPath = FPaths::ProjectContentDir() + FilePath;
	FFileHelper::LoadFileToStringArray(CSVLines, *FullPath);

	for (const FString& Line : CSVLines)
	{
		TArray<FString> CSVLineArray;
		Line.ParseIntoArray(CSVLineArray, TEXT(","), true);
		CSV2DArray.Add(CSVLineArray);
	}

	return CSV2DArray;
}
