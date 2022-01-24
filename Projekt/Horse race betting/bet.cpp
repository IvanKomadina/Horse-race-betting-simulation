#include <iostream>
#include <ctime>
#include "bet.hpp"
#include "race.hpp"
#include "odds.hpp"
using namespace std;

void Bet::updateBalance(int cash)
{
	balance += cash;
}

int Bet::getBalance()
{
	return balance;
}

//Get horse that won the race.
//Subtract entered money from balance.
//If player guessed winner horse, multiplicate entered money with odds on winner horse and add that to balance.
void Bet::results(Race& race, Odds& odds, int horse, int money)
{
	int winner = race.start(odds);
	int subtract = 0 - money;
	updateBalance(subtract);
	if (winner == horse)
	{
		int cash = money * odds.getOdds(horse-1);
		cout << "Congratulations, you won "<< cash << "!!!" << endl;;
		updateBalance(cash);
		cout << "Your balance: " << getBalance() << endl;
	}
	else
	{
		cout << "You lost, better luck next time." << endl;
		cout << "Your balance: " << getBalance() << endl;
	}
}

//Choosing horse to bet on by entering horse number.
int Bet::chooseHorse()
{
	int horse;
	cout << "Choose horse you would like to bet on by entering the number between 1 and 8: ";
	cin >> horse;
	if (horse > 8 || horse <= 0)
	{
		do {
			cout << "Choose number between 1 and 8: ";
			cin >> horse;
		} while (horse > 8 || horse <= 0);
	}
	return horse;
}

//Enter money for one bet (amount can't be greater than balance). 
int Bet::enterMoney()
{
	int money;
	cout << "Enter the amount of money you would like to bet: ";
	cin >> money;
	if (money > getBalance())
	{
		do {
			cout << "Not enough money, try again: ";
			cin >> money;
		} while (money > getBalance());
	}
	return money;
}