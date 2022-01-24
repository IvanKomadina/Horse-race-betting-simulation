#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "race.hpp"
#include "odds.hpp"
using namespace std;

//Move horse position depending on it's odds.
//Generate random number, if it's greater than odds on horse, move horse position for random number between 1 and 4.
//If it's smaller, move horse position for random number between 1 and 3.
void Horse::MoveHorse(Odds& odds, int i)
{
	int n = odds.getOdds(i);
	int randNum = (rand() % 10) + 1;
	if (randNum > n)
	{
		position += (rand() % 4 + 1);
	}
	else
	{
		position += (rand() % 3 + 1);
	}
}

//Get horse position in race.
int Horse::getPosition()
{
	return position;
}

//Set horse position to 0.
void Horse::setPosition()
{
	position = 0;
}

//Print track and all horses on their current positions.
//If horse position is equal to specific location on track, print horse on that location.
void Race::printTrack(int horseNum)
{
	for (int i = 0; i < length; i++)
	{
		int location = h[horseNum].getPosition();
		if (i == location)
		{
			cout << horseNum + 1;
		}
		else if (i == finish)
		{
			cout << '|';
		}
		else
		{
			cout << '.';
		}
	}
	cout << endl;
}

//Start race.
//While one of the horses dont reach end, print track for every loop.
//Return winner horse.
int Race::start(Odds& odds)
{
	bool keepRunning = true;
	int winner;
	
	for (int i = 0; i < 8; i++)
	{
		printTrack(i);
	}
	while (keepRunning)
	{
		Sleep(1000);
		setCursorPosition(0, 0);
		for (int j = 0; j < 8; j++)
		{
			h[j].MoveHorse(odds, j);
			printTrack(j);
			if (h[j].getPosition() > finish)
			{
				keepRunning = false;
				winner = j + 1;
				for (int k = j + 1; k < 8; k++)
				{
					printTrack(k);
				}
				for (int n = 0; n < 8; n++)
				{
					h[n].setPosition();
				}
				Sleep(2000);
				system("cls");
				cout << "Horse number " << winner << " won the race!" << endl;
				break;
			}
		}
	}
	return winner;
}

//Updating race in console output.
void Race::setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}