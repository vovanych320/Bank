//The file was written by Haponenko Vladislav 16.11.2019
#include "CardProxy.h"
#include "OperationManager.h"

void Card::CardProxy::do_setDate(std::string s)
{

	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(
				kvp("$set", make_document(kvp("date_end", s)))));
		}
		else
		{
			std::cout << "You are using an old object" << std::endl;
		}
	}


}


void Card::CardProxy::do_setNumber(std::string num)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("number_card", num)))));
		}
		else
		{
			std::cout << "You are using an old object" << std::endl;
		}
	}
}


void Card::CardProxy::do_setCVV(unsigned int num)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("cvv", std::to_string(num))))));
		}
		else
		{
			std::cout << "You are using an old object" << std::endl;
		}
	}
}



void Card::CardProxy::do_setPIN(unsigned int num)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("pin", std::to_string(num))))));
		}
		else
		{
			std::cout << "You are using an old object" << std::endl;
		}
	}
}



void Card::CardProxy::do_setName(std::string name)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("name", name)))));
		}
		else
		{
			std::cout << "You are using an old object" << std::endl;
		}
	}
}



void Card::CardProxy::do_setBalance(unsigned long money)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("card_balance", std::to_string(money))))));
		}
		else
		{
			std::cout << "You are using an old object" << std::endl;
		}
	}
}




void Card::CardProxy::do_setTransactions(std::vector<Transaction>& tr)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			auto array_builder = bsoncxx::builder::basic::array{};
			std::vector<Transaction>::iterator i;
			for (i = tr.begin(); i != tr.end(); ++i)
			{
				array_builder.append(transactionToDocument(*i));
			}
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("transactions", array_builder)))));
		}
		else
		{
			std::cout << "You are using an old object" << std::endl;
		}
	}
}


void Card::CardProxy::do_setTemplates(std::vector<Transaction>& tm)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			auto array_builder = bsoncxx::builder::basic::array{};
			std::vector<Transaction>::iterator i;
			for (i = tm.begin(); i != tm.end(); ++i)
			{
				array_builder.append(transactionToDocument(*i));
			}

			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("templates", array_builder)))));
		}
		else
		{
#if DEBUG
			std::cout << "You are using an old object" << std::endl;
#endif
		}
	}
}

void Card::CardProxy::do_addTemplate(const Transaction& tr)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			auto array_builder = bsoncxx::builder::basic::array{};
			std::vector<Transaction>::iterator i;
			std::vector<Transaction> ar = _card.do_getTemplates();
			for (i = ar.begin(); i != ar.end(); ++i)
			{
				array_builder.append(transactionToDocument(*i));
			}
			array_builder.append(transactionToDocument(tr));
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("templates", array_builder)))));

		}
		else
		{
#if DEBUG
			std::cout << "You are using an old object" << std::endl;
#endif
		}
	}
}

void Card::CardProxy::do_addTransaction(const Transaction& tr)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			auto array_builder = bsoncxx::builder::basic::array{};
			std::vector<Transaction>::iterator i;
			std::vector<Transaction> ar = _card.do_getTransactions();
			for (i = ar.begin(); i != ar.end(); ++i)
			{

				array_builder.append(transactionToDocument(*i));
			}
			array_builder.append(transactionToDocument(tr));
			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("transactions", array_builder)))));
		}
		else
		{
#if DEBUG
			std::cout << "You are using an old object" << std::endl;
#endif
		}
	}
}



void Card::CardProxy::do_deleteTemplate(const Card::Transaction& temp)
{
	//getting instance of a data base
	IOperationManager* op = OperationManager::getInstance();

	//checking whether a card with this number exists in a data base
	if (op->cardExist(_card.getNumber()))
	{
		DefferedICard c = op->getCard(_card.getNumber());
		//checking whether a card in a data base and this instance of a Card class are the same
		if (*c.operator->() == _card)
		{
			//setting
			auto array_builder = bsoncxx::builder::basic::array{};
			std::vector<Transaction>::iterator i;
			std::vector<Transaction> ar = _card.do_getTransactions();
			for (i = ar.begin(); i != ar.end(); ++i)
			{
				if (!(*i == temp))
				{
					array_builder.append(transactionToDocument(*i));
				}

			}

			mongocxx::collection coll = op->getDB()["cards"];
			coll.update_one(make_document(kvp("number_card", _card.getNumber())), make_document(kvp("$set",
				make_document(kvp("transactions", array_builder)))));
		}
		else
		{
#if DEBUG
			std::cout << "You are using an old object" << std::endl;
#endif
		}
	}

}
