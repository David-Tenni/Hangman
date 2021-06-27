// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FWrongRightCount 
{
	int32 Rights = 0;
	int32 Wrongs = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void InitGame();
	void EndGame();
	void RestartGame();

	bool Validate(FString Guess);
	bool IsIsogram(FString PlayerGuess) const;
	TArray<FString> GetValidWords(TArray<FString>) const;
	FWrongRightCount GetRightLetters(const FString& Guess) const;
	// Your declarations go below!
	private:
		FString TheWord;
		INT32 Lives;
		bool GameOver;
		INT32 NumberOfLetters;
		TArray<FString> Isograms;
};
