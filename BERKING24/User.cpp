//The file was written by Haponenko Vladislav 16.11.2019
#include "UserProxy.h"
#include "User.h"

void User::do_addCard(std::string tm)
{

	UserProxy uP = UserProxy(*this);
	uP.do_addCard(tm);
	_cards.insert(_cards.begin(), 1, tm);
}

bool User::do_hasCard(std::string num)
{
	std::list<std::string>::iterator i;
	for (i = _cards.begin(); i != _cards.end(); i++)
	{
		if (*i == num)
		{
			return true;
		}
	}
	return false;
}



const std::list<std::string>& User::do_getCards() const
{
	return _cards;
}

void User::do_setCards(std::list<std::string>& c)
{

	UserProxy uP = UserProxy(*this);
	uP.do_setCards(c);
	_cards = c;

}

std::string User::do_getWebToken() const
{
	return _webToken;
}

void User::do_setWebToken(std::string wT)
{

	UserProxy uP = UserProxy(*this);
	uP.do_setWebToken(wT);
	_webToken = wT;
}

std::string User::do_getName() const
{
	return _name;
}

void User::do_setName(std::string name)
{

	UserProxy uP = UserProxy(*this);
	uP.do_setName(name);
	_name = name;
}

std::string User::do_getPassword() const
{
	return _password;
}

void User::do_setPassword(std::string pass)
{

	UserProxy uP = UserProxy(*this);
	uP.do_setPassword(pass);
	_password = pass;
}

std::string User::do_getEmail() const
{
	return _email;
}

void User::do_setEmail(std::string em)
{
	UserProxy uP = UserProxy(*this);
	uP.do_setEmail(em);
	_email = em;
}



std::ostream& User::do_print(std::ostream& os) const
{
	os << "Name :" << this->do_getName() << '\n'
		<< "Email :" << this->do_getEmail() << '\n'
		<< "Password :" << this->getPassword() << '\n';
	return os;
}

bool operator==(const IUser& user1, const IUser& user2)
{
	return (user1.getEmail() == user2.getEmail() &&
		user1.getName() == user2.getName() &&
		user1.getPassword() == user2.getPassword() &&
		user1.getWebToken() == user2.getWebToken() &&
		user1.getCards() == user2.getCards());
}
