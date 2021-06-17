//The file was written by Haponenko Vladislav 16.11.2019
#include "User.h"

//user representation which envolves number of clients who uses a deffered user and an actual users
struct DefferedIUser::UserRep
{
	IUser* _user;
	size_t _members;
	UserRep(IUser* u) :
		_user(u), _members(1)
	{
	}
};


DefferedIUser::DefferedIUser(std::string wT, std::string name, std::string password,
	std::string email, const std::list<std::string>& cards) :_userRep(new UserRep(new User(wT, name, password, email, cards)))
{
}

DefferedIUser::DefferedIUser(const DefferedIUser& u) : _userRep(u._userRep)
{
	++_userRep->_members;
}

DefferedIUser::~DefferedIUser()
{
	if (--_userRep->_members == 0)
	{
		delete _userRep->_user;
	}
}

DefferedIUser& DefferedIUser::operator=(const DefferedIUser& d)
{
	if (this->_userRep == d._userRep)
	{
		return *this;
	}
	if (--_userRep->_members == 0)
	{
		delete _userRep;
	}
	_userRep = d._userRep;
	++_userRep->_members;
	return *this;
}

IUser* DefferedIUser::operator->() const
{
	return _userRep->_user;
}
