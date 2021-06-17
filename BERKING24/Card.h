//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "DefferedICard.h"
#include <string>





class Card :public ICard
{
	///
	///For a description of methonds and the class see ICard.h
	///
public:
	//the class is believed to be dangerous to work with so it's used through DefferedICard,
	//thus we give special rights to constructor of a DefferedICard
	friend  DefferedICard::DefferedICard(std::string, unsigned int, unsigned int, std::string, std::string,
		std::vector<Transaction>, std::vector<Transaction>, unsigned long);

	~Card() {}


private:
	///
	///constructs an Card object
	///it's hidden because the class is dangerous because it's a straight representation of a data in
	///a data base and changes in a card cause changes in database
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
	Card(std::string num, unsigned int cvv, unsigned int pin, std::string name, std::string endDate,
		std::vector<Transaction> transaction, std::vector<Transaction> templates, unsigned long balance = 0) :
		_number(num), _cvv(cvv), _pin(pin), _name(name), _endDate(endDate), _balance(balance),
		_transactions(transaction), _templates(templates)
	{

	}

	//it's not a plainest object, so we close operator= and copy constructor in order to improve speed of response
	Card& operator=(const Card&);
	Card(const Card&);

	//number of a card
	std::string _number;

	//cvv code of a card
	unsigned int _cvv;

	//pin code of a card
	unsigned int _pin;

	//name of a card
	std::string _name;

	//tha date when a card stops working
	std::string _endDate;

	//an amount of money on a card
	unsigned long _balance;

	//transaction of a card
	std::vector<Transaction> _transactions;

	//templates of a card
	std::vector<Transaction> _templates;

	//nested class CardProxy which is corresponds for modifying an access to Card
	class CardProxy;


	void do_setNumber(std::string);

	std::string do_getNumber() const;

	unsigned int do_getCVV()const;

	void do_setCVV(unsigned int);

	unsigned int do_getPIN() const;

	void  do_setPIN(unsigned int);

	std::string do_getName()const;

	void do_setName(std::string);

	unsigned long do_getBalance() const;

	void do_setBalance(unsigned long);


	const std::vector<Transaction>& do_getTransactions()const;


	void do_setTransactions(std::vector<Transaction>&);


	const std::vector<Transaction>& do_getTemplates()const;


	void do_setTemplates(std::vector<Transaction>&);


	void do_addTemplate(const Transaction&);


	void do_addTransaction(const Transaction&);


	void do_setDate(std::string);

	std::string do_getDate()const;

	std::ostream& do_print(std::ostream&)const;

	void do_deleteTemplate(const Card::Transaction&);

};

std::ostream& operator<<(std::ostream& os, const ICard::Transaction&);

bool operator==(const ICard::Transaction&, const ICard::Transaction&);

bool operator==(const ICard&, const ICard&);
