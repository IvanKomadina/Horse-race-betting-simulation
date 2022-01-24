#pragma once
#include <iostream>
#include <vector>
#include "odds.hpp"

class Horse
{
	int position;
public:
	Horse() { position = 0; };
	void MoveHorse(Odds& odds, int n);
	int getPosition();
	void setPosition();
};

class Race
{
	Horse h[8];
	int length;
	int finish;
public:
	Race() { length = 35; finish = 30; };
	int start(Odds& odds);
	void printTrack(int horseNum);
	void setCursorPosition(int x, int y);
};
