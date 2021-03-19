// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

#include <string>

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	
	InitGame();

}

void UBullCowCartridge::InitGame()
{
	
	TheWord = TEXT("Saturn");
	TheWord.ToLower();
	Lives = 3;
	GameOver = false;
	NumberOfLetters = 6;

	PrintLine(TEXT("Hang Man: The Beginning!"));
	PrintLine(FString::Printf(TEXT("Please enter your %i letter guess"), NumberOfLetters)); //change the number to be randomly generated

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();
	
	FString PlayerGuess = Input;
	PrintLine(PlayerGuess);
	if (GameOver == true && PlayerGuess.ToLower() == "yes")
	{
		ClearScreen();
		InitGame();
	} else
	{
		if (Lives == 0)
		{
			PrintLine(TEXT("You lose type yes to play again"));
			GameOver = true;
		}
		else
		{
			if (PlayerGuess == TheWord && Validate(PlayerGuess))
			{
				PrintLine(TEXT("You Win!"));
			}
			else
			{
				PrintLine(TEXT("Guess Again!"));
				Lives--;

				PrintLine(FString::Printf(TEXT("%i Lives left!"), Lives));
			}
		}
	}
	
	
}
bool UBullCowCartridge::Validate(FString Guess)
{
	if (Guess.Len() == NumberOfLetters)
	{
		return true;
	}
	return false;
	
}