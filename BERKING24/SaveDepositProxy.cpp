//The file was written by Haponenko Vladislav 16.11.2019
#include "SaveDepositProxy.h"
#include "OperationManager.h"



void SaveDeposit::SaveDepositProxy::do_setBalance(unsigned long c)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a deposit with linked to this this card number exists in a data base
	if (op->depositExist(_deposit.getCardNum()));
	{
		DefferedISaveDeposit dep = op->getSaveDeposit(_deposit.getCardNum());
		//checking whether a deposit in a data base and this instance of a Deposit class are the same
		if (*dep.operator->() == _deposit)
		{
			//setting
			mongocxx::collection coll = op->getDB()["deposits"];
			coll.update_one(make_document(kvp("card_number", _deposit.getCardNum())), make_document(kvp("$set",
				make_document(kvp("balance", std::to_string(c))))));
		}
		else
		{
#if DEBUG
			std::cout << "You are using an old object" << std::endl;
#endif
		}
	}
}


void SaveDeposit::SaveDepositProxy::do_setCard(std::string num)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a deposit with linked to this this card number exists in a data base
	if (op->depositExist(_deposit.getCardNum()));
	{
		DefferedISaveDeposit dep = op->getSaveDeposit(_deposit.getCardNum());
		//checking whether a deposit in a data base and this instance of a Deposit class are the same
		if (*dep.operator->() == _deposit)
		{
			//setting
			IOperationManager* op = OperationManager::getInstance();
			mongocxx::collection coll = op->getDB()["deposits"];
			coll.update_one(make_document(kvp("card_number", _deposit.getCardNum())), make_document(kvp("$set",
				make_document(kvp("card_number", num)))));
		}
		else
		{
#if DEBUG
			std::cout << "You are using an old object" << std::endl;
#endif
		}
	}
}




void SaveDeposit::SaveDepositProxy::do_setStartDate(std::string date)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a deposit with linked to this this card number exists in a data base
	if (op->depositExist(_deposit.getCardNum()));
	{
		DefferedISaveDeposit dep = op->getSaveDeposit(_deposit.getCardNum());
		//checking whether a deposit in a data base and this instance of a Deposit class are the same
		if (*dep.operator->() == _deposit)
		{
			//setting
			IOperationManager* op = OperationManager::getInstance();
			mongocxx::collection coll = op->getDB()["deposits"];
			coll.update_one(make_document(kvp("card_number", _deposit.getCardNum())), make_document(kvp("$set",
				make_document(kvp("start_date", date)))));
		}
		else
		{
#if DEBUG
			std::cout << "You are using an old object" << std::endl;
#endif
		}
	}
}


void SaveDeposit::SaveDepositProxy::do_setEndDate(std::string date)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a deposit with linked to this this card number exists in a data base
	if (op->depositExist(_deposit.getCardNum()));
	{
		DefferedISaveDeposit dep = op->getSaveDeposit(_deposit.getCardNum());
		//checking whether a deposit in a data base and this instance of a Deposit class are the same
		if (*dep.operator->() == _deposit)
		{
			//setting
			IOperationManager* op = OperationManager::getInstance();
			mongocxx::collection coll = op->getDB()["deposits"];
			coll.update_one(make_document(kvp("card_number", _deposit.getCardNum())), make_document(kvp("$set",
				make_document(kvp("end_date", date)))));
		}
		else
		{
#if DEBUG
			std::cout << "You are using an old object" << std::endl;
#endif
		}
	}
}




