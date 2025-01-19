#pragma once

#include "CoreMinimal.h"


class FileVerificator
{
public:
	static bool VerifyFile(FString FilePath, FString LastElement);
};
