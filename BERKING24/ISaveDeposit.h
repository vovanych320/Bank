//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "IEntity.h"
#include <string>
#include <vector>

class ISaveDeposit :public IEntity
{
public:
	///
	///The intefrace ISaveDeposit is ment to be a common representation of a deposit for the banking system
	///
	///The intefrace is believed to be just a representation of a data stored in a data base
	///thus it has a nearly trivial behavior
	///

	ISaveDeposit() {};
	virtual ~ISaveDeposit() {};

	///
	///gives the date of a creation of a deposit
	///
	///@return a date of a creation of a deposit
	///
	std::string getStartDate() const
	{
		return do_getStartDate();
	}

	///
	///sets a new value for the date of creation of a deposit
	///
	///@param date The parameter stands for the date of creation of a deposit
	///
	void setStartDate(std::string date)
	{
		return do_setStartDate(date);
	}

	///
	///gives a date of ending of a deposit contract between bank and user
	///
	///@return a date of ending of a deposit contract between bank and user
	///
	std::string getEndDate() const
	{
		return do_getEndDate();
	}

	///
	///sets a new date of ending of a deposit contract between bank and user
	///
	///@param date The parameter stands for a new date of ending of a deposit contract between bank and user
	///
	void setEndDate(std::string date)
	{
		return do_setEndDate(date);
	}

	///
	///sets a new card number to which a deposit is lincked
	///
	///@param cardNum The parameter stands for a new card number to which a deposit is lincked
	///
	void setCard(std::string cardNum)
	{
		return do_setCard(cardNum);
	}

	///
	///gives a number of a card to which a deposit is lincked
	///
	///@return a number of a card to which a deposit is lincked
	///
	std::string getCardNum()const
	{
		return do_getCardNum();
	}

	///
	///gives an amount of money on a deposit
	///
	///@return an amount of money on a deposit
	///
	unsigned long getBalance()const
	{
		return do_getBalance();
	}

	///
	///sets a new amount of money for a deposit
	///
	///@param sum The parameter sum stands for a new amount of money for a deposit
	///
	void setBalance(unsigned long sum)
	{
		return do_setBalance(sum);
	}

private:
	virtual unsigned long do_getBalance()const = 0;
	virtual void do_setBalance(unsigned long) = 0;
	virtual void do_setCard(std::string) = 0;
	virtual std::string do_getCardNum()const = 0;
	virtual std::string  do_getStartDate() const = 0;
	virtual void do_setStartDate(std::string) = 0;
	virtual std::string do_getEndDate() const = 0;
	virtual void do_setEndDate(std::string date) = 0;

};

