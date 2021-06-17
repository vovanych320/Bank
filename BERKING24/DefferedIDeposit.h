//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "ISaveDeposit.h"
class DefferedISaveDeposit
{
	///
	///Deffers a deposit among many clients
	///
	///It deffers a deposit among different clients. It's objective is to provide all
	///clients with an actual representation of a deposit in a database because
	///otherwise deposit's fields loose their's connection to database and SaveDepositProxy
	///wont change corresponding fields in a data base, so every time someone, who
	///uses deffered deposit, changes it's field he is not driven out.
	///
private:
	//Struct which correcponds for deposit representation for deffering
	struct DepositRep;
	//pointer on deposit representation
	DepositRep* _depositRep;

	ISaveDeposit& operator*()const;
public:
	///
	///constructs a DefferedDeposit object
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
	DefferedISaveDeposit(std::string cN, std::string sD, std::string eD, unsigned long sum);

	///
	///copy constructor
	///
	DefferedISaveDeposit(const DefferedISaveDeposit&);

	~DefferedISaveDeposit();
	DefferedISaveDeposit& operator=(const DefferedISaveDeposit&);


	///
	///provide access to Deposit's methods
	///
	ISaveDeposit* operator->()const;


};
