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
	TheWord = TheWord.ToLower();
	NumberOfLetters = TheWord.Len();
	Lives = 3;
	GameOver = false;

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
	}
	else
	{
		PrintLine(TEXT("Guess Again!"));
		--Lives;

		PrintLine(FString::Printf(TEXT("%i Lives left!"), Lives));
	}
}
	
	
	

bool UBullCowCartridge::Validate(FString Guess)
{
	if (Guess.Len() == NumberOfLetters && Guess == TheWord)
	{
		return true;
	}
	return false;
	
}
void UBullCowCartridge::EndGame()
{
	ClearScreen();
	PrintLine(FString::Printf(TEXT("The Word was %s"), *TheWord));
	PrintLine(TEXT("\nYou lose type yes to play again"));

	GameOver = true;
}

