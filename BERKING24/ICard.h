//The file was written by Haponenko Vladislav 16.11.2019
#pragma once
#include "IEntity.h"
#include <string>
#include <vector>

class ICard :public IEntity
{
public:
	//
	//The interface is corresponding for a common representation of a card for the banking system
	//
	//A card is believed to be a representation of an information in database so it doesn't have
	//difficult and unexpected methonds
	//
	ICard() {};
	virtual ~ICard() {};

	//Nested struct Transaction is corresponding for representation of templates and transactions
	struct Transaction;

	///
	///gets the card number
	///
	///@return a number of a card
	///
	std::string getNumber() const
	{
		return do_getNumber();
	}

	///
	///sets a number of a card
	///
	///@param num A new number of a card
	///
	void setNumber(std::string num)
	{
		return do_setNumber(num);
	}

	///
	///gets cvv code of a card
	///
	///@return a current cvv code of a card
	///
	unsigned int getCVV() const
	{
		return do_getCVV();
	}

	///
	///sets a new cvv code of a card
	///
	///@param num The argument is a new cvv code of a card
	///
	void setCVV(unsigned int num)
	{
		return do_setCVV(num);
	}

	///
	///gets the pin code of a card
	///
	///@return a pin code of a card
	///
	unsigned int getPIN() const
	{
		return do_getPIN();
	}

	///
	///sets the card pin code
	///
	///@param num A new pin code for a card
	///
	void setPIN(unsigned int num)
	{
		return do_setPIN(num);
	}

	///
	///gets the card name
	///
	///@return a name of a card
	///
	std::string getName() const
	{
		return do_getName();
	}

	///
	///sets the name of a card
	///
	///@param name A new name of a card
	///
	void setName(std::string name)
	{
		return do_setName(name);
	}

	///
	///gets the balance of a card 
	///
	///@return an amount of money on a card
	///
	double getBalance() const
	{
		return do_getBalance();
	}

	///
	///changes an amount of money on a card
	///
	///@param num The parameter
	///
	void setBalance(unsigned long num)
	{
		return do_setBalance(num);
	}

	///
	///gets all transactions related to this card
	///
	///@return an array of transactions
	///
	const std::vector<Transaction>& getTransactions()const
	{
		return do_getTransactions();
	}

	///
	///changes all transactions of a card
	///
	///@param tr The parameter is an array of transactions
	///
	void setTransactions(std::vector<Transaction>& tr)
	{
		return do_setTransactions(tr);
	}

	///
	///gets all templates related to this card
	///
	///@return an array of templates
	///
	const std::vector<Transaction>& getTemplates()const
	{
		return do_getTemplates();
	}

	///
	///changes all templates of a card
	///
	///@param tr The parameter is an array of templates
	///
	void setTemplates(std::vector<Transaction>& tm)
	{
		return do_setTemplates(tm);
	}

	///
	///adds a template to card
	///
	///@param tm The parameter is a new template
	///
	void addTemplate(const Transaction& tm)
	{
		return do_addTemplate(tm);
	}

	///
	///adds a transaction to card
	///
	///@param tr The parameter is a new transaction 
	///
	void addTransaction(const Transaction& tr)
	{
		return do_addTransaction(tr);
	}

	///
	///gets the date when a card stop working
	///
	///@return the date when a card stop working
	///
	std::string getDate() const
	{
		return do_getDate();
	}

	///
	///sets the date when a card stop working
	///
	///@param st The parameter is a new date when a card stop working
	///
	void setDate(std::string st)
	{
		return do_setDate(st);
	}

	///
	///delets a tamlate from a card
	///
	///@param t The parameter is corresponding for the template to delete
	///
	void deleteTemplate(const ICard::Transaction& t)
	{
		return do_deleteTemplate(t);
	}


private:
	//private methonds for implementing
	virtual void do_deleteTemplate(const ICard::Transaction&) = 0;
	virtual void do_setDate(std::string) = 0;
	virtual std::string do_getDate()const = 0;
	virtual void do_setNumber(std::string) = 0;
	virtual std::string do_getNumber()const = 0;
	virtual unsigned int do_getCVV()const = 0;
	virtual void do_setCVV(unsigned int) = 0;
	virtual unsigned int do_getPIN() const = 0;
	virtual void  do_setPIN(unsigned int) = 0;
	virtual std::string do_getName()const = 0;
	virtual void do_setName(std::string) = 0;
	virtual unsigned long do_getBalance() const = 0;
	virtual void do_setBalance(unsigned long) = 0;
	virtual const std::vector<Transaction>& do_getTransactions()const = 0;
	virtual void do_setTransactions(std::vector<Transaction>&) = 0;
	virtual const std::vector<Transaction>& do_getTemplates()const = 0;
	virtual void do_setTemplates(std::vector<Transaction>&) = 0;
	virtual void do_addTemplate(const Transaction&) = 0;
	virtual void do_addTransaction(const Transaction&) = 0;



};

struct ICard::Transaction
{
	//
	//ICard::Transaction is just a representation of an information from data base
	//with trivial behavior
	//
private:
	//date the transaction was made
	std::string _date;

	//card number of a the one who sent money
	std::string _senderCardNum;

	// card number of a one who recieved money
	std::string _recieverCardNum;
	//an amount of money were sent
	unsigned long _sum;

	//a description of a transaction
	std::string _description;
public:
	///
	///Constructs an object of a card
	///
	///@param date The parameter is corresponding for the date a trasaction was made
	///            
	//@param scn The parameter is corresponding for the number of a card of a sender
	///
	///@param rcn The parameter is corresponding for the number of a card of a reciever
	///
	///@param sum The parameter is corresponding for the amount of money were sent
	///
	///@param desc The parameter is corresponding for a description of a transaction
	///
	Transaction(std::string date, std::string scn, std::string rcn, unsigned long sum, std::string desc) :
		_date(date), _senderCardNum(scn), _recieverCardNum(rcn), _sum(sum), _description(desc)
	{

	}
	~Transaction() {}

	///
	///gets the date of a date a transactrion was made
	///
	///@return the date a transaction was made
	///
	std::string getDate() const
	{
		return _date;
	}

	///
	///sets a date a transactrion was made
	///
	///@param d The parameter is a new date of a transaction was made
	///
	void setDate(std::string d)
	{
		_date = d;
	}

	///
	///gets a card number of a sender
	///
	///@return a card number of a sender
	///
	std::string getSenderCardNum() const
	{
		return _senderCardNum;
	}

	///
	///sets a date a transactrion was made
	///
	///@param scn The parameter is a new card number of a sender
	///
	void setSenderCardNum(std::string scn)
	{
		_senderCardNum = scn;
	}

	///
	///gets a card number of a reciever
	///
	///@return a card number of a reciever
	///
	std::string getrecieverCardNum() const
	{
		return _recieverCardNum;
	}

	///
	///sets a reciever card number 
	///
	///@param rcn The parameter is a card number of a reciever of a transaction
	///
	void setrecieverCardNum(std::string rcn)
	{
		_recieverCardNum = rcn;
	}

	///
	///gets a description of a transaction
	///
	///@return a description of a transaction
	///
	std::string getDescription() const
	{
		return _description;
	}

	///
	///sets a description of a transaction
	///
	///@param descr The parameter is a new description of a transaction
	///
	void setDescription(std::string descr)
	{
		_description = descr;
	}

	///
	///gets an amount of money was sent when the transaction was made
	///
	///@return an amount of money were sent when the transaction was made
	///
	unsigned long getSum() const
	{
		return _sum;
	}

	///
	///sets an amount of money were sent
	///
	///@param sum The parameter is a new amount of money were sent
	///
	void setSum(unsigned long sum)
	{
		_sum = sum;
	}



};

