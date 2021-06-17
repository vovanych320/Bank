//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "IUser.h"
class DefferedIUser
{
	///
	///Deffers a user among many clients
	///
	///It deffers a card among different clients. It's objective is to provide all
	///clients with an actual representation of a user in a database because
	///otherwise user's fields loose their's connection to database and UserProxy
	///wont change corresponding fields in a data base, so every time someone, who
	///uses deffered user, changes it's field he is not driven out.
	///
private:
	//Struct which correcponds for user representation for deffering
	struct UserRep;
	//pointer on user representation
	UserRep* _userRep;

	IUser& operator*()const;
public:
	///
	///constructs a DefferedIUser object
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
	DefferedIUser(std::string wT, std::string name, std::string password, std::string email,
		const std::list<std::string>& cards = {});

	///
	///copy constructor
	///
	DefferedIUser(const DefferedIUser&);

	~DefferedIUser();
	DefferedIUser& operator=(const DefferedIUser&);


	///
	///provide access to User's methods
	///
	IUser* operator->()const;


};