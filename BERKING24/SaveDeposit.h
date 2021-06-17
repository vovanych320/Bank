//The file was written by Haponenko Vladislav 16.11.2019
#pragma once


#include <string>"
#include "DefferedIDeposit.h"


class SaveDeposit :public ISaveDeposit
{
	//
	///For a description of methonds and the class see ISaveDeposit.h
	///
public:
	//the class is believed to be dangerous to work with so it's used through DefferedISaveDeposit,
	//thus we give special rights to constructor of a DefferedISaveDeposit
	friend  DefferedISaveDeposit::DefferedISaveDeposit(std::string, std::string, std::string, unsigned long);


	~SaveDeposit() {}
private:
	///
	///constructs an SaveDeposit object
	///it's hidden because the class is dangerous because it's a straight representation of a data in
	///a data base and changes in a deposit cause changes in database
	///
	///@param cN
	///         The parameter corresponds for the number of a card to which a deposit is linked
	///
	///@param sD
	///         The parameter corresponds for a day a deposit was created
	///
	///@param eD
	///         The parameter corresponds for a day a deposit will be delated
	///
	///@param sum
	///          The parameter corresponds for an amount of money invested in a deposit
	///
	SaveDeposit(std::string cN, std::string sD, std::string eD, unsigned long sum) :
		_cardNum(cN), _startDate(sD), _endDate(eD), _sum(sum)

	{

	}

	//in order to keep as few gates to the data base as we can we hide copy constructor and operator=
	SaveDeposit& operator=(const SaveDeposit&);
	SaveDeposit(const SaveDeposit&);

	//number of card to which a deposit is lincked
	std::string _cardNum;

	//the day a deposit was created
	std::string _startDate;

	//day a deposit will be delated
	std::string _endDate;

	//an amount of money invested in a deposit
	unsigned long _sum;

	//nested class SaveDepositProxy which is corresponds for modifying an access to SaveDeposit
	class SaveDepositProxy;

	unsigned long do_getBalance()const;
	void do_setBalance(unsigned long);
	std::ostream& do_print(std::ostream& out)const;
	void do_setCard(std::string);
	std::string do_getCardNum()const;
	std::string  do_getStartDate() const;
	void do_setStartDate(std::string);
	std::string do_getEndDate() const;
	void do_setEndDate(std::string date);


};

bool operator==(const ISaveDeposit&, const ISaveDeposit&);