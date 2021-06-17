//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "IEntity.h"
#include <list>
#include "ICard.h"
#include "ISaveDeposit.h"
class IUser :public IEntity
{
public:
	///
	///The intefrace corresponds for a common representation of a user of a banking system
	///
	///The interface is believed to be just an image of an information in a data base
	///thus it doesn't have complicated behavior
	///

	IUser() {};
	virtual ~IUser() {};

	///
	///adds a number of a new card created by user 
	///
	///@param cardNUM The parameter is number of a card
	///
	void addCard(std::string cardNUM)
	{
		return do_addCard(cardNUM);
	}

	///
	///gives all number of user's cards
	///
	///@return list of a string which are just card numbers
	///
	const std::list<std::string>& getCards() const
	{
		return do_getCards();
	}

	///
	///replaces all card numbers of a user
	///
	///@param cards The parameter is an array of new card numbers
	///
	void setCards(std::list<std::string>& cards)
	{
		return do_setCards(cards);
	}

	///
	///gives a current web token of a user
	///
	///@return a current web token of a user
	///
	std::string getWebToken() const
	{
		return do_getWebToken();
	}

	///
	///sets a new web token of a user
	///
	///@param token The parameter is a new web token of a user
	///
	void setWebToken(std::string token)
	{
		return do_setWebToken(token);
	}

	///
	///gives a name of a user
	///
	///@return a name of a user
	///
	std::string getName()const
	{
		return do_getName();
	}

	///
	///replaces a name of a user
	///
	///@param s The parameter is a new name of a user
	///
	void setName(std::string s)
	{
		return do_setName(s);
	}

	///
	///gives a current password of a user
	///
	///@return a current password of a user
	///
	std::string getPassword() const
	{
		return do_getPassword();
	}

	///
	///replaces a password of a user
	///
	///@param password The parameter is a new password for a user
	///
	void setPassword(std::string password)
	{
		return do_setPassword(password);
	}

	///
	///gives email of a user
	///
	///@return an email of a user
	///
	std::string getEmail() const
	{
		return do_getEmail();
	}

	///
	///replaces the email of a user
	///
	///@param em The parameter is a new email of a user
	///it's believed to be unique for a correct work with a database
	///
	void setEmail(std::string em)
	{
		return do_setEmail(em);
	}

	///
	///says whether a user has the card with a given card number or not
	///
	///@param num The parameter is a card number
	///
	///@return bool which says whether a user has the card with a given card number or not
	///
	bool hasCard(std::string num)
	{
		return do_hasCard(num);
	}



private:
	virtual void do_addCard(std::string) = 0;
	virtual bool do_hasCard(std::string) = 0;
	virtual const std::list<std::string>& do_getCards()const = 0;
	virtual void do_setCards(std::list<std::string>&) = 0;
	virtual std::string do_getWebToken() const = 0;
	virtual void do_setWebToken(std::string) = 0;
	virtual std::string do_getName()const = 0;
	virtual void do_setName(std::string) = 0;
	virtual std::string do_getPassword() const = 0;
	virtual void do_setPassword(std::string) = 0;
	virtual std::string do_getEmail() const = 0;
	virtual void do_setEmail(std::string) = 0;


};
