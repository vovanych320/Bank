//The file was written by Haponenko Vladislav 16.11.2019
#pragma once

class DepositFunctor
{
	///
	///Computes how much money to give at the end of a deposit
	///
	///The class is created in order to compute an amount of money to give for a deposit 
	///relatively the period of time the deposit was taken on and whether it's interrupted
	///by user him self.
	///
private:
	//number of days between creating and ending a deposit
	size_t _daysLasted;

	//number of days bank believed the deposit should last
	size_t _daysNeeded;
public:
	///
	///constructs a Functor
	///
	///@param daysLasted 
	///             The parameter corresponds for number of days between creating and ending a deposit
	///
	///@param daysNeeded
	///              The parameter corresponds for number of days bank believed the deposit should last
	///
	DepositFunctor(size_t daysLasted, size_t daysNeeded) :_daysLasted(daysLasted), _daysNeeded(daysNeeded) {}

	~DepositFunctor() {}

	///
	///computes how much money to give at the end of a deposit
	///
	///@param sum 
	///          The parameter is an amount of money on a deposit's balance
	///
	///@return 
	///       how much money to give at the end of a deposit
	unsigned long operator()(unsigned long sum) const
	{
		if (_daysLasted == _daysNeeded)
		{
			return sum + sum * _daysNeeded / 366;
		}
		else
		{
			return sum - sum * (_daysNeeded - _daysLasted) / 366;
		}
	}
};
