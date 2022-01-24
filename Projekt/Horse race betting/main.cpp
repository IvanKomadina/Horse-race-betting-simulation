#include <iostream>
#include <windows.h>
#include "race.hpp"
#include "odds.hpp"
#include "bet.hpp"
using namespace std;

int main()
{
	int cash;
	cout << "WELCOME TO HORSE RACES!" << endl;
	Sleep(2000);
	cout << "Please enter the amount of cash you'd like to deposit: ";
	cin >> cash;

	Bet bet;
	bet.updateBalance(cash);
	Odds odds;
	Race race;

	//Betting on races going on while balance is greater than 0 or till player exits.
	while (bet.getBalance() > 0)
	{
		cout << "Your balance: " << bet.getBalance() << endl;
		odds.generateOdds();
		odds.displayOdds();

		cout << endl;

		int horse;
		int money;
		horse = bet.chooseHorse();
		money = bet.enterMoney();
		
		cout << endl;

		cout << "Get ready, race is about to start!" << endl;
		Sleep(2000);
		system("cls");
		
		bet.results(race, odds, horse, money);

		if (bet.getBalance() <= 0)
		{
			cout << "No money left, thank you for betting." << endl;
			break;
		}
			
		int cont;
		cout << "If you want to continue with betting enter 1 and if you don't want enter 2: "; 
		cin >> cont;
		if (cont == 2)
		{
			cout << "Thank you for betting." << endl;
			break;
		}
		else
		{
			Sleep(2000);
			system("cls");
			continue;
		}
	}
}
