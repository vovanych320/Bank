//The file was written by Haponenko Vladislav 16.11.2019
#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H
#include "IOperationManager.h"


using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::sub_document;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;

class OperationManager :public IOperationManager
{
	///
	///The calss is designed to be a connector between data base and a client
	///
	///MongoDB's connection should be made only once and in order to use the same instance 
	///of a chosen data base throught all program we use singleton design pattern. The class
	///is composed of methods which retrieve all delete data from data base.
	///
public:
	//to see description of methonds see IOperationManager.h 
	~OperationManager()
	{
	}
	///constructing an instance of OperationManager class by giving data base
	static  IOperationManager* init(mongocxx::database& db)
	{
		if (!_op)
		{
			_op = new OperationManager(db);
		}
		return _op;
	}

	//getting OperationManager instance
	static  IOperationManager* getInstance()
	{
		if (!_op)
		{
			return NULL;
		}
		return _op;
	}



private:

	//data base
	mongocxx::database& _db;

	//the pointer on OperationManager instance
	static OperationManager* _op;

	//in order tosingleton design pattern the next methonds are hidden
	OperationManager(mongocxx::database& db) :_db(db) {}
	OperationManager(const OperationManager&);
	OperationManager& operator=(const OperationManager&);

	//all of these are described if IOperationManager.h
	std::vector<DefferedICard> do_getAllUsersCards(std::string);
	void do_deleteDeposit(std::string, const DepositFunctor&);
	void do_addSaveDeposit(const DefferedISaveDeposit&);
	void do_addCard(const DefferedICard&);
	void do_addUser(const DefferedIUser&);
	DefferedIUser do_getUser(std::string)const;
	DefferedISaveDeposit do_getSaveDeposit(std::string)const;
	DefferedICard do_getCard(std::string)const;
	std::vector<DefferedIUser> do_getAllUsers()const;
	bool do_userExist(std::string email)const;
	bool do_cardExist(std::string num)const;
	bool do_depositExist(std::string num)const;
	std::vector<DefferedISaveDeposit> do_getAllDeposits()const;
	std::vector<DefferedICard> do_getAllCards()const;
	void do_deleteCard(std::string);

	const mongocxx::database& do_getDB() const
	{
		return _db;
	}


};
bsoncxx::document::value  transactionToDocument(const ICard::Transaction& tr);
std::vector<ICard::Transaction>& documentToTransactions(const bsoncxx::v_noabi::types::b_array& ar);
#endif