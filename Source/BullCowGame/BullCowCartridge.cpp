// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	PrintLine(TEXT("Hang Man: The Beginning!"));
	PrintLine(TEXT("Please enter your 6 letter guess")); //change the number to be randomly generated
	TheWord = TEXT("Saturn"); 
	TheWord.ToLower();
	Lives = INT32(3);
	GameOver = false;
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();
	
	FString PlayerGuess = Input;
	PrintLine(PlayerGuess);
	if (GameOver == true && PlayerGuess.ToLower() == "yes")
	{
		GameOver = false;
		Lives = 3;
		PrintLine(TEXT("Hang Man: The Beginning!"));
		PrintLine(TEXT("Please enter your 6 letter guess")); //change the number to be randomly generated
	} else
	{
		if (Lives == 0)
		{
			PrintLine(TEXT("You lose type yes to play again"));
			GameOver = true;
		}
		else
		{
			if (PlayerGuess == TheWord)
			{
				PrintLine(TEXT("You Win!"));
			}
			else
			{


				PrintLine(TEXT("Guess Again!"));
				Lives--;
			}
		}
	}

	

	
}