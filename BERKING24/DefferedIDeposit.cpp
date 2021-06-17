//The file was written by Haponenko Vladislav 16.11.2019
#include "DefferedIDeposit.h"
#include "SaveDeposit.h"

//deposit representation which envolves number of clients who uses a deffered deposit and an actual deposit
struct DefferedISaveDeposit::DepositRep
{
	ISaveDeposit* _deposit;
	size_t _members;
	DepositRep(ISaveDeposit* s) :
		_deposit(s), _members(1)
	{
	}
};


DefferedISaveDeposit::DefferedISaveDeposit(std::string cN, std::string sD, std::string eD, unsigned long sum) :
	_depositRep(new DepositRep(new SaveDeposit(cN, sD, eD, sum)))
{

}

DefferedISaveDeposit::DefferedISaveDeposit(const DefferedISaveDeposit& d) :_depositRep(d._depositRep)
{
	++_depositRep->_members;
}

DefferedISaveDeposit::~DefferedISaveDeposit()
{
	if (--_depositRep->_members == 0)
	{
		delete _depositRep->_deposit;
	}
}

DefferedISaveDeposit& DefferedISaveDeposit::operator=(const DefferedISaveDeposit& d)
{
	if (this->_depositRep == d._depositRep)
	{
		return *this;
	}
	if (--_depositRep->_members == 0)
	{
		delete _depositRep;
	}
	_depositRep = d._depositRep;
	++_depositRep->_members;
	return *this;
}

ISaveDeposit* DefferedISaveDeposit::operator->() const
{
	return _depositRep->_deposit;
}
