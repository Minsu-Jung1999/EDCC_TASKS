#pragma once

class BankAccount
{
private:
	std::string owner;
	double balance;
	double money;
public:
	BankAccount(std::string owner, double balance);

	void deposit(double money);

	bool withdraw(double money);

	std::string getOwner();

	double getBalance();
};