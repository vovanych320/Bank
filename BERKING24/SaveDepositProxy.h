//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "SaveDeposit.h"

class SaveDeposit::SaveDepositProxy
{
	///
	///SaveDepositProxy modifies access to Card
	///
	///The class is called every time an instance of a Deposit class want to write down new value of a field
	///instead an old one. It checks whether the instance is a current representation of an information
	///about a deposit in an actual data base and if it is SaveDepositProxy also changes corresponding values in data base
	///
	friend class SaveDeposit;
private:
	SaveDeposit& _deposit;

	SaveDepositProxy(SaveDeposit& c) :_deposit(c)
	{

	}


	///
	///changes an amount of money on a deposit
	///
	///@param bal The parameter is corresponds for a new amount of money on a deposit
	///
	void do_setBalance(unsigned long bal);

	///
	///changes number of a card to which deposit is lincked
	///
	///@param num The parameter is corresponds for a new number of a card to which deposit is lincked
	///
	void do_setCard(std::string num);

	///
	///changes the date a deposit was created
	///
	///@param date The parameter is corresponds for a new date for day of creating a deposit
	///
	void do_setStartDate(std::string date);

	///
	///changes the date a deposit will ended
	///
	///@param date The parameter is corresponds for a new date for day of ending a deposit
	///
	void do_setEndDate(std::string date);



public:

};
