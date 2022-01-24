#include <iostream>
#include <ctime>
#include <iomanip>
#include "odds.hpp"
using namespace std;

//Generate odds between 2 and 10.
void Odds::generateOdds()
{
	int max = 10;
	int min = 2;
	srand(unsigned(time(NULL)));
	for (int i = 0; i < 8; i++)
	{
		odds[i] = ((rand() % 9) + 2);
	}
}

//Display all odds.
void Odds::displayOdds()
{
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "The odds on Horse " << i + 1 << " are: 1 in " << odds[i] << endl;
	}
}

//Get odds for given horse.
int Odds::getOdds(int n)
{
	return odds[n];
}