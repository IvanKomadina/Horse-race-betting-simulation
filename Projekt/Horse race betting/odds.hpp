#pragma once
#include <iostream>

class Odds
{
	int odds[8];
public:
	void generateOdds();
	void displayOdds();
	int getOdds(int n);
};