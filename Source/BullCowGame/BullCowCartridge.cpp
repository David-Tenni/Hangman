// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
#include <string>

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	Isograms = GetValidWords(Words);
	InitGame();
	FWrongRightCount Count;
}

void UBullCowCartridge::InitGame()
{
	
	TheWord = Isograms[FMath::RandRange(0, Isograms.Num() -1)];
	TheWord = TheWord.ToLower();
	NumberOfLetters = TheWord.Len();
	Lives = 3;
	GameOver = false;

	PrintLine(TEXT("Hang Man: The Beginning!"));
	//PrintLine(TEXT("number of possible words, %i"), Words.Num());
	PrintLine(FString::Printf(TEXT("Please enter your %i letter guess"), NumberOfLetters)); //change the number to be randomly generated

	//for (int i = 0; i < 5; i++)
	//{
	//	PrintLine(TEXT("Word %i, is: %s"), i, *Words[i]);
	//}
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();
	
	FString PlayerGuess = Input;
	PrintLine(PlayerGuess);
	if (GameOver == true && PlayerGuess.ToLower() == "yes")
	{
		RestartGame();
		return;
	}

	if (Lives == 0)
	{
		EndGame();
		return;
	}
	

	if (Validate(PlayerGuess))
	{
		PrintLine(TEXT("You Win!"));
		PrintLine(TEXT("Type Yes to play again"));
		GameOver = true;
	}

}
	
void UBullCowCartridge::RestartGame() 
{
	ClearScreen();
	InitGame();
}
	

bool UBullCowCartridge::Validate(FString Guess)
{
	if (Guess.Len() == NumberOfLetters && Guess == TheWord)
	{
		return true;
	}
	if (!IsIsogram(Guess))
	{
		PrintLine(TEXT("Not an Isogram Guess Again!"));
		--Lives;

		PrintLine(FString::Printf(TEXT("%i Lives left!"), Lives));
		return false;
	}

	PrintLine(TEXT("Guess Again!"));
	--Lives;
	FWrongRightCount Score = GetRightLetters(Guess);
	PrintLine(TEXT("You have %i right letters and %i wrong letters"), Score.Rights, Score.Wrongs);

	PrintLine(FString::Printf(TEXT("%i Lives left!"), Lives));
	return false;
	
}
void UBullCowCartridge::EndGame()
{
	ClearScreen();
	PrintLine(FString::Printf(TEXT("The Word was %s"), *TheWord));
	PrintLine(TEXT("\nYou lose type yes to play again"));

	GameOver = true;
}


bool UBullCowCartridge::IsIsogram( FString PlayerGuess) const
{
	for (int32 Index = 0; Index < PlayerGuess.Len(); Index++)
	{
		for (int32 Comparison = Index + 1; Comparison < PlayerGuess.Len(); Comparison++) 
		{
			if (PlayerGuess[Index] == PlayerGuess[Comparison]) 
			{
				return false;
			}
		}
	}
	return true;


}

TArray<FString> UBullCowCartridge::GetValidWords(TArray<FString>Words) const
{
	TArray<FString>ValidWords;
		for (int32 Index = 0; Index <5; Index++)
		{
			if (Words[Index].Len() >= 4)
			{
				ValidWords.Emplace(Words[Index]);
			}
		}
		return ValidWords;
}

FWrongRightCount UBullCowCartridge::GetRightLetters(const FString& Guess) const
{
	FWrongRightCount Count;
	for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
	{
		if (Guess[GuessIndex] == TheWord[GuessIndex])
		{
			Count.Rights++;
			continue;
		}
		for (int32 HiddenIndex = 0; HiddenIndex < Guess.Len(); HiddenIndex++)
		{
			if (Guess[GuessIndex] == TheWord[HiddenIndex])
			{
				Count.Wrongs++;
				break;
			}
		}
	}
	return Count;
	
}