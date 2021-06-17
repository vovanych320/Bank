//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "Card.h"


class Card::CardProxy
{
	///
	///CardProxy modifies access to Card
	///
	///The class is called every time an instance of a Card class want to write down new value of a field
	///instead an old one. It checks whether the instance is a current representation of an information
	///about  a card in an actual data base and if it is CardProxy also changes corresponding values in data base
	///
	friend class Card;
private:
	Card& _card;

	CardProxy(Card& c) :_card(c)
	{

	}

	///
	///changes the date of the end of card's existance in a data base
	///
	///@param date The parameter is corresponds for a new date of the end of card's existance in a data base
	///
	void do_setDate(std::string date);

	///
	///changes the card number of a card in a data base
	///
	///@param num The parameter is a new number of a card
	///
	void do_setNumber(std::string num);

	///
	///changes the cvv code of a card in a data base
	///
	///@param cvv The parameter is a new cvv of a card
	///
	void do_setCVV(unsigned int cvv);

	///
	///changes the pin code of a card in a data base
	///
	///@param pin The parameter is a new pin of a card
	///
	void  do_setPIN(unsigned int pin);

	///
	///changes the name of a card in a data base
	///
	///@param name The parameter is a new name of a card
	///
	void do_setName(std::string name);

	///
	///changes the balance of a card in a data base
	///
	///@param bal The parameter is a new amount of money on a card
	///
	void do_setBalance(unsigned long bal);

	///
	///changes all transactions of a card in a data base
	///
	///@param tr The parameter is a new transactions of a card
	///
	void do_setTransactions(std::vector<Transaction>& tr);

	///
	///changes all templates of a card in a data base
	///
	///@param tm The parameter is a new templates of a card
	///
	void do_setTemplates(std::vector<Transaction>& tm);

	///
	///adds a template into data base
	///
	///@param tm The parameter is a new template of a card
	///
	void do_addTemplate(const Transaction& tm);

	///
	///adds a transaction into data base
	///
	///@param tr The parameter is a new transaction of a card
	///
	void do_addTransaction(const Transaction& tr);

	///
	///deletes a template from a data base
	///
	///@param tm The parameter is a template for deleting
	///
	void do_deleteTemplate(const Card::Transaction& tm);


public:


};
