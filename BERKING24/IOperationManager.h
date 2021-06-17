//The file was written by Haponenko Vladislav 16.11.2019
#ifndef IOPERATIONMANAGER_H
#define IOPERATIONMANAGER_H
#include <string>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx\builder\stream\document.hpp>
#include <mongocxx\instance.hpp>


#include "DefferedICard.h"
#include "DefferedIDeposit.h"
#include "DefferedIUser.h"
#include "DepositFunctor.h"
class IOperationManager
{
	///
	///The intefrace IOperation manager is ment to be a representation for all classes
	/// wich objective is to be something like connector between data base and client
	///
	///It has an methods which objective is retrive al delete data from data base
	///
public:
	IOperationManager() {};
	virtual ~IOperationManager() {};

	///
	///adds a user to the data base
	///
	///@param u The parameter is corresponding for the user being inserted in db
	///
	void addUser(const DefferedIUser& u)
	{
		return do_addUser(u);
	}


	///
	///retriving a user from data base by hi's email, which is ment to be a unique
	///
	///@param email The parameter email stands for electonic address of a user
	///
	///@return a user from database
	///
	DefferedIUser getUser(std::string email)
	{
		return do_getUser(email);
	}

	///
	///retriving a save deposit from data base by number of a card which is linked to the deposit
	///
	///@param u The parameter u stands for a card number to which a deposit is lincked
	///
	///@return a save deposit from database
	///
	DefferedISaveDeposit getSaveDeposit(std::string u)
	{
		return do_getSaveDeposit(u);
	}

	///
	///retriving a card from data base by it's number which is ment to be unique
	///
	///@param num The parameter num stands for the card number
	///
	///@return a card from database
	///
	DefferedICard getCard(std::string num)
	{
		return do_getCard(num);
	}

	///
	///gives the current data base
	///
	///@return database it self
	///
	const mongocxx::database& getDB()
	{
		return do_getDB();
	}

	///
	///adding a save deposit to a data base
	///
	///@param d The parameter d stands for save deposit is wanted to be added to db
	///
	void addSaveDeposit(const DefferedISaveDeposit& d)
	{
		return do_addSaveDeposit(d);
	}

	///
	///adding a card to a data base
	///
	///@param c The parameter c is stands for a card
	///
	void addCard(const DefferedICard& c)
	{
		return do_addCard(c);
	}

	///
	///gives all users stored in a data base
	///
	///@return a vector of all users in a current data base
	///
	std::vector<DefferedIUser> getAllUsers()
	{
		return do_getAllUsers();
	}

	///
	///gives all deposits which are store in a data base
	///
	///@return a vector of all deposits stored in a current db
	///
	std::vector<DefferedISaveDeposit> getAllDeposits()
	{
		return do_getAllDeposits();
	}

	///
	///gives all cards which are stored in a data base
	///
	///@return a vector of all cards in a current data base
	///
	std::vector<DefferedICard> getAllCards()
	{
		return do_getAllCards();
	}

	///
	///says whether a user with given email exists in a current data base or not
	///
	///@param email The paramenet email stands for an email of a user
	///
	///@return a bool value which says  whether a user with given email exists in a current data base or not
	///
	bool userExist(std::string email)const
	{
		return do_userExist(email);
	}

	///
	///says whether a card with given number exists in a current data base or not
	///
	///@param num The paramenet num stands for an card number of a card
	///
	///@return a bool value which says whether a card with given number exists in a current data base or not
	///
	bool cardExist(std::string num)const
	{
		return do_cardExist(num);
	}

	///
	///says whether a deposit lincked to the given card number exists in a current data base or not
	///
	///@param num The paramenet num stands for an card number of a card to which a deposit is ment to be lincked
	///
	///@return a bool value which says whether a deposit lincked to the given 
	///card number exists in a current data base or not
	///
	bool depositExist(std::string num)const
	{
		return do_depositExist(num);
	}


	///
	///deletes a card with a given number from a database
	///
	///@param num The paraneter stands for the number of a card
	///
	void deleteCard(std::string num)
	{
		return do_deleteCard(num);
	}

	///
	///deletes a deposit which is lincked to the given card number
	///
	///@param num The paraneter stands for the number of a card to which a deposit is lincked
	///
	void deleteDeposit(std::string num, const DepositFunctor& func)
	{
		return do_deleteDeposit(num, func);
	}

	///
	///retriving all cards owned by a user with a given email
	///
	///@param email The parameter email stands for electronic address of a user
	///
	///@return a vector of a cards of a user with given email
	///
	std::vector<DefferedICard> getAllUsersCards(std::string email)
	{
		return do_getAllUsersCards(email);
	}
private:
	virtual std::vector<DefferedICard> do_getAllUsersCards(std::string) = 0;
	virtual void do_deleteDeposit(std::string, const DepositFunctor&) = 0;
	virtual void do_deleteCard(std::string) = 0;
	virtual std::vector<DefferedISaveDeposit> do_getAllDeposits()const = 0;
	virtual std::vector<DefferedICard> do_getAllCards()const = 0;
	virtual void do_addSaveDeposit(const DefferedISaveDeposit&) = 0;
	virtual void do_addCard(const DefferedICard&) = 0;
	virtual const mongocxx::database& do_getDB()const = 0;
	virtual void do_addUser(const DefferedIUser&) = 0;
	virtual DefferedIUser do_getUser(std::string)const = 0;
	virtual DefferedISaveDeposit do_getSaveDeposit(std::string)const = 0;
	virtual DefferedICard do_getCard(std::string)const = 0;
	virtual std::vector<DefferedIUser> do_getAllUsers()const = 0;
	virtual bool do_userExist(std::string email)const = 0;
	virtual bool do_cardExist(std::string num)const = 0;
	virtual bool do_depositExist(std::string num)const = 0;


};
#endif