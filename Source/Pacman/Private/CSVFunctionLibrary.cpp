// Fill out your copyright notice in the Description page of Project Settings.


#include "CSVFunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

TArray<FString> UCSVFunctionLibrary::ReadCSV(FString FilePath)
{
	TArray<FString> FileLines;
	FString FullPath = FPaths::ProjectContentDir() + FilePath;
	FFileHelper::LoadFileToStringArray(CSVData, *FullPath);
	return CSVData;
}

