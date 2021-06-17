//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "ICard.h"

class DefferedICard
{
	///
	///Deffers a card among many clients
	///
	///It deffers a card among different clients. It's objective is to provide all
	///clients with an actual representation of a card in a database because
	///otherwise card's fields loose their's connection to database and CardProxy
	///wont change corresponding fields in a data base, so every time someone, who
	///uses deffered card, changes it's field he is not driven out.
	///
private:
	//Struct which correcponds for card representation for deffering
	struct CardRep;
	//pointer on card representation
	CardRep* _cardRep;

	ICard& operator*()const;
public:
	///
	///constructs an DefferedCard object
	///
	///@param num The parameter num is a card number and it's should be unique
	///
	///@param cvv The parameter is a cvv code of a card
	///
	///@param pin The parameter is a pin code of a card
	///
	///@param name The parameter is a name of a card
	///
	///@param endDate The parameter is a date when a card stops working
	///
	///@param transactiom The optional argument, it's transactions made using this card
	///
	///@param templates The optional argument, it's templates lincked to this card
	///
	///@param balance The optional argument, it's an amount of money on a card
	///
	DefferedICard(std::string num, unsigned int cvv, unsigned int pin, std::string name, std::string endDate,
		std::vector<ICard::Transaction> transaction = {}, std::vector<ICard::Transaction> templates = {}, unsigned long balance = 0);

	///
	///copy constructor
	///
	DefferedICard(const DefferedICard&);

	~DefferedICard();
	DefferedICard& operator=(const DefferedICard&);


	///
	///provide access to Card's methods
	///
	ICard* operator->()const;


};
