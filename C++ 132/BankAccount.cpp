#include <iostream>
#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount(std::string owner, double balance) :owner(owner),balance(balance){}

void BankAccount::deposit(double money)
{
	balance += money;
}

bool BankAccount::withdraw(double money)
{
	if (balance >= money)
	{
		balance -= money;
		return true;
	}
	else
	{
		return false;
	}
}

string BankAccount::getOwner()
{
	return owner;
}

double BankAccount::getBalance()
{
	return balance;
}