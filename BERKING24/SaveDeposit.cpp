//The file was written by Haponenko Vladislav 16.11.2019
#include "SaveDeposit.h"
#include "SaveDepositProxy.h"


unsigned long SaveDeposit::do_getBalance() const
{
	return _sum;
}

void SaveDeposit::do_setBalance(unsigned long sum)
{

	SaveDepositProxy c = SaveDepositProxy(*this);
	c.do_setBalance(sum);
	_sum = sum;
}

std::ostream& SaveDeposit::do_print(std::ostream& os) const
{
	os << "Card Number :" << this->do_getCardNum() << '\n'
		<< "Start Date :" << this->do_getStartDate() << '\n'
		<< "End Date :" << this->do_getEndDate();
	return os;
}

void SaveDeposit::do_setCard(std::string card)
{

	SaveDepositProxy c = SaveDepositProxy(*this);
	c.do_setCard(card);
	_cardNum = card;
}

std::string SaveDeposit::do_getCardNum() const
{
	return _cardNum;
}

std::string SaveDeposit::do_getStartDate() const
{
	return _startDate;
}

void SaveDeposit::do_setStartDate(std::string sd)
{

	SaveDepositProxy c = SaveDepositProxy(*this);
	c.do_setStartDate(sd);
	_startDate = sd;
}

std::string SaveDeposit::do_getEndDate() const
{
	return _endDate;
}

void SaveDeposit::do_setEndDate(std::string date)
{

	SaveDepositProxy c = SaveDepositProxy(*this);
	c.do_setEndDate(date);
	_endDate = date;
}


bool operator==(const ISaveDeposit& deposit1, const ISaveDeposit& deposit2)
{
	return (deposit1.getCardNum() == deposit2.getCardNum() &&
		deposit1.getEndDate() == deposit2.getEndDate() &&
		deposit1.getStartDate() == deposit2.getStartDate() &&
		deposit1.getBalance() == deposit2.getBalance());
}
