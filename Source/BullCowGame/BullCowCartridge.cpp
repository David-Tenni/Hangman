// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	PrintLine("Hang Man: The Beginning!");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

}