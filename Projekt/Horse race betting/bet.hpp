#pragma once
#include <iostream>
#include "race.hpp"

class Bet
{
	int balance = 0;
public:
	void updateBalance(int cash);
	int getBalance();
	void results(Race& race, Odds& odds, int horse, int money);
	int chooseHorse();
	int enterMoney();
};