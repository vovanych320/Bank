//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "DefferedIUser.h"

class User :public IUser
{
	///
	///For a description of methonds and the class see IUser.h
	///
public:
	//the class is believed to be dangerous to work with so it's used through DefferedIUser,
	//thus we give special rights to constructor of a DefferedIUser
	friend  DefferedIUser::DefferedIUser(std::string, std::string, std::string, std::string, const std::list<std::string>&);

	~User() {}
private:
	///
	///constructs an User object
	///it's hidden because the class is dangerous because it's a straight representation of a data in 
	///a data base and changes in a user cause changes in database
	///
	///@param wT
	///         The parameter corresponds for web token
	///
	///@param name
	///           The parameter name coresponds for the name of a user
	///
	///@param password
	///               The parameter password corresponds for the password of a user
	///
	///@param email
	///            The parameter email corresponds for the email of a user
	///
	///@param cards
	///            The parameter cards corresponds for an array of numbers of cards owned by a user
	///
	User(std::string wT, std::string name, std::string password, std::string email, const std::list<std::string>& cards = {}) :
		_webToken(wT), _name(name), _password(password), _email(email), _cards(cards)
	{

	}

	//in order to keep as few gates to the data base as we can we hide copy constructor and operator=
	User& operator=(const User&);
	User(const User&);

	//cards of a user
	std::list<std::string> _cards;

	//web token which controlls a sesion of a user on the web site
	std::string _webToken;

	//name of a user
	std::string _name;

	//password of a user
	std::string _password;

	//email of a user
	std::string _email;

	//nested class User which is corresponds for modifying an access to User
	class UserProxy;

	void do_addCard(std::string);
	bool do_hasCard(std::string);
	const std::list<std::string>& do_getCards()const;
	void do_setCards(std::list<std::string>&);
	std::string do_getWebToken() const;
	void do_setWebToken(std::string);
	std::string do_getName()const;
	void do_setName(std::string);
	std::string do_getPassword() const;
	void do_setPassword(std::string);
	std::string do_getEmail() const;
	void do_setEmail(std::string);
	std::ostream& do_print(std::ostream&) const;

};

bool operator==(const IUser&, const IUser&);
