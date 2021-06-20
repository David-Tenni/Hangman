// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

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

	// Your declarations go below!
	private:
		FString TheWord;
		INT32 Lives;
		bool GameOver;
		INT32 NumberOfLetters;
		TArray<FString> Isograms;
};
