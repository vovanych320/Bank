//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "User.h"

class User::UserProxy
{
	///
	///UserProxy modifies access to Card
	///
	///The class is called every time an instance of a User class want to write down new value of a field
	///instead an old one. It checks whether the instance is a current representation of an information
	///about a user in an actual data base and if it is UserProxy also changes corresponding values in data base
	///
	friend class User;
private:
	User& _user;

	UserProxy(User& c) :_user(c)
	{

	}

	///
	///adds a card to data base
	///
	///@param num The parameter corresponds for the number of a card the user created
	///
	void do_addCard(std::string num);

	///
	///replaces all user cards 
	///
	///@param cards The parameter corresponds for new numbers of a cards
	///
	void do_setCards(std::list<std::string>& cards);

	///
	///changes web token for user
	///
	///@param wT The parameter corresponds for the web token of a user
	///which defines a time for a web session of a user
	///
	void do_setWebToken(std::string wT);

	///
	///changes name of a user
	///
	///@param name The parameter is corresponds for a new name of a user
	///
	void do_setName(std::string name);

	///
	///changes password of a user
	///
	///@param pass The parameter is corresponds for a new password of a user
	///
	void do_setPassword(std::string pass);

	///
	///changes email of a user
	///
	///@param email The parameter is corresponds for a new email of a user
	///
	void do_setEmail(std::string email);
public:

};

