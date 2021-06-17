//The file was written by Haponenko Vladislav 16.11.2019
#include "OperationManager.h"

OperationManager* OperationManager::_op = 0;

void OperationManager::do_addUser(const DefferedIUser& u)
{

	//constructing document representation of the User
	bsoncxx::builder::basic::document doc;
	doc.append(kvp("name", u->getName()));
	doc.append(kvp("password", u->getPassword()));
	doc.append(kvp("email", u->getEmail()));
	doc.append(kvp("webtoken", u->getWebToken()));

	//Adding cards
	std::list<std::string>cards = u->getCards();
	std::list<std::string>::iterator i;
	auto array_builder = bsoncxx::builder::basic::array{};
	for (i = cards.begin(); i != cards.end(); ++i)
	{
		array_builder.bsoncxx::builder::basic::sub_array::append(*i);
	}
	doc.append(bsoncxx::builder::basic::kvp("cards", array_builder));

	//Adding the user
	mongocxx::collection coll = _db["users"];
	coll.insert_one(doc.view());
	return;
}

DefferedIUser OperationManager::do_getUser(std::string email)const
{
	if (OperationManager::getInstance()->userExist(email))
	{
		//retriving User from bd
		mongocxx::collection coll = _db["users"];
		auto cursor = coll.find(make_document(bsoncxx::builder::basic::kvp("email", email)));
		bsoncxx::document::view userView;
		for (auto&& doc : cursor)
		{
			userView = doc;
		}
		//creating user
		bsoncxx::v_noabi::types::b_array cards = userView["cards"].get_array();
		bsoncxx::array::view arrayView = bsoncxx::array::view(cards);
		bsoncxx::array::view::iterator i;
		std::list<std::string> list = {};
		for (i = arrayView.begin(); i != arrayView.end(); ++i)
		{
			list.insert(list.begin(), 1, (*i).get_utf8().value.to_string());
		}
		DefferedIUser u = DefferedIUser(userView["webtoken"].get_utf8().value.to_string(),
			userView["name"].get_utf8().value.to_string(),
			userView["password"].get_utf8().value.to_string(),
			userView["email"].get_utf8().value.to_string(),
			list);


		return u;
	}
	else {
		return DefferedIUser("dummy", "dummy", "dummy", "dummy");
	}
}



DefferedISaveDeposit OperationManager::do_getSaveDeposit(std::string num)const
{
	if (OperationManager::getInstance()->depositExist(num))
	{
		//retriving User from bd
		mongocxx::collection coll = _db["deposits"];
		auto cursor = coll.find(make_document(kvp("card_number", num)));
		bsoncxx::document::view depositView;
		for (auto&& doc : cursor)
		{
			depositView = doc;
		}
		//creating user
		DefferedISaveDeposit dp = DefferedISaveDeposit(depositView["card_number"].get_utf8().value.to_string(),
			depositView["start_date"].get_utf8().value.to_string(),
			depositView["end_date"].get_utf8().value.to_string(),
			stol(depositView["balance"].get_utf8().value.to_string()));


		return dp;
	}
	else {
		return DefferedISaveDeposit("dummy", "dummy", "dummy", 0);
	}
}



std::vector<DefferedIUser> OperationManager::do_getAllUsers()const
{
	//retriving all users from data base
	mongocxx::collection coll = _db["users"];
	auto cursor = coll.find({});

	//inserting instances of a User into a vector
	std::vector<DefferedIUser>* u = new std::vector<DefferedIUser>();
	for (auto&& doc : cursor) {
		auto ellement = doc["email"];
		u->insert(u->begin(), 1, OperationManager::getInstance()->getUser(ellement.get_utf8().value.to_string()));
	}
	return std::vector<DefferedIUser>(*u);
}

bool OperationManager::do_userExist(std::string email) const
{
	//retriving users
	mongocxx::collection coll = _db["users"];

	//find a user with a given email
	auto cursor = coll.find(make_document(kvp("email", email)));

	//checking whether the array of users with a given email have size bigger than 0
	return std::distance(cursor.begin(), cursor.end()) != 0;
}

bool OperationManager::do_cardExist(std::string num) const
{
	//retriving cards
	mongocxx::collection coll = _db["cards"];

	//find a card with a given number
	auto cursor = coll.find(make_document(kvp("number_card", num)));

	//checking whether the array of cards with a given number have size bigger than 0
	return std::distance(cursor.begin(), cursor.end()) != 0;
}

bool OperationManager::do_depositExist(std::string num) const
{
	//retriving deposits
	mongocxx::collection coll = _db["deposits"]; \

		//find a deposit linked to a given card number
		auto cursor = coll.find(make_document(kvp("card_number", num)));

	//checking whether the array of deposits with linked to a given card number have size bigger than 0
	return std::distance(cursor.begin(), cursor.end()) != 0;
}

std::vector<DefferedISaveDeposit> OperationManager::do_getAllDeposits() const
{
	//retriving all deposits
	mongocxx::collection coll = _db["deposits"];

	//inserting instances of a SaveDeposit into a vector
	auto cursor = coll.find({});
	std::vector<DefferedISaveDeposit>* u = new std::vector<DefferedISaveDeposit>();
	for (auto&& doc : cursor) {
		auto ellement = doc["card_number"];
		u->insert(u->begin(), 1, OperationManager::getInstance()->getSaveDeposit(ellement.get_utf8().value.to_string()));
	}
	return std::vector<DefferedISaveDeposit>(*u);
}

std::vector<DefferedICard> OperationManager::do_getAllCards()const
{
	//retriving all cards
	mongocxx::collection coll = _db["cards"];

	// inserting instances of a Card into a vector
	auto cursor = coll.find({});
	std::vector<DefferedICard>* u = new std::vector<DefferedICard>();
	for (auto&& doc : cursor)
	{
		auto ellement = doc["number_card"];
		u->insert(u->begin(), 1, OperationManager::getInstance()->getCard(ellement.get_utf8().value.to_string()));
	}
	return std::vector<DefferedICard>(*u);
}

void OperationManager::do_deleteCard(std::string num)
{
	//retriving cards from a data base
	mongocxx::collection coll = _db["cards"];

	//checking whether a card exists
	if (cardExist(num))
	{
		//if so deleting related deposits to this card number
		deleteDeposit(num, DepositFunctor(188, 366));

		//deleting the card
		DefferedICard c = getCard(num);
		coll.delete_one(make_document(kvp("number_card", num)));

		//retriving all users from data base
		std::vector<DefferedIUser> users = getAllUsers();
		for (auto&& user : users)
		{
			//if user have deleted card
			if (user->hasCard(num))
			{
				std::list<std::string> list = user->getCards();
				if (*list.begin() != *(--list.end()))
				{
					//if the user has another card send money from delated card to another
					if (*list.begin() != num)
					{
						DefferedICard c2 = getCard(*list.begin());
						c2->setBalance(c2->getBalance() + c->getBalance());
					}
					else
					{
						DefferedICard c2 = getCard(*(--list.end()));
						c2->setBalance(c2->getBalance() + c->getBalance());
					}
				}
				//removing deleted card from User's array of a card numbers 
				list.remove(num);
				user->setCards(list);
			}
		}

	}
}




std::vector<DefferedICard> OperationManager::do_getAllUsersCards(std::string email)
{
	//checking whether a user with this email exists
	if (userExist(email))
	{
		//getting user with this email
		DefferedIUser u = getUser(email);

		//getting his numbers of cards
		std::list<std::string> list = u->getCards();

		//retriving actual Card objects vy their's numbers
		std::vector<DefferedICard>* vector = new std::vector<DefferedICard>();
		std::list<std::string>::iterator i;
		for (i = list.begin(); i != list.end(); ++i)
		{
			vector->insert(vector->begin(), 1, OperationManager::getInstance()->getCard(*i));
		}
		return *vector;
	}
	else
	{
		return std::vector<DefferedICard>();
	}
}

void OperationManager::do_deleteDeposit(std::string num, const DepositFunctor& func)
{
	//checking whether the deposit related to this card exists
	if (depositExist(num))
	{
		//retriving the deposit
		DefferedISaveDeposit d = getSaveDeposit(num);

		//computing an amount of money to give a User
		unsigned long sum = func(d->getBalance());

		//deleting a deposit
		_db["deposits"].delete_one(make_document(kvp("card_number", num)));

		//if card to which the deposit was related exists we throw money from deposit back to user
		if (cardExist(num))
		{
			DefferedICard c = getCard(num);
			c->setBalance(c->getBalance() + sum);
		}
	}
}

void OperationManager::do_addSaveDeposit(const DefferedISaveDeposit& dp)
{
	//constructing document representation of the User
	bsoncxx::builder::basic::document doc;
	doc.append(kvp("card_number", dp->getCardNum()));
	doc.append(kvp("start_date", dp->getStartDate()));
	doc.append(kvp("end_date", dp->getEndDate()));
	doc.append(kvp("balance", std::to_string(dp->getBalance())));

	//Adding the deposit
	mongocxx::collection coll = _db["deposits"];
	coll.insert_one(doc.view());
	return;
}

void OperationManager::do_addCard(const DefferedICard& c)
{
	//constructing document representation of the User
	bsoncxx::builder::basic::document doc;
	doc.append(kvp("number_card", c->getNumber()));
	doc.append(kvp("cvv", std::to_string(c->getCVV())));
	doc.append(kvp("pin", std::to_string(c->getPIN())));
	doc.append(kvp("name", c->getName()));
	doc.append(kvp("date_end", c->getDate()));
	doc.append(kvp("card_balance", std::to_string(c->getBalance())));
	doc.append(kvp("transactions", bsoncxx::builder::basic::make_array()));
	doc.append(kvp("templates", bsoncxx::builder::basic::make_array()));

	//Adding the deposit
	mongocxx::collection coll = _db["cards"];
	coll.insert_one(doc.view());
	return;
}

DefferedICard OperationManager::do_getCard(std::string number)const
{
	if (OperationManager::getInstance()->cardExist(number))
	{
		//retriving Card from bd
		mongocxx::collection coll = _db["cards"];
		auto cursor = coll.find(bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("number_card", number)));
		bsoncxx::document::view cardView;
		for (auto&& doc : cursor)
		{
			cardView = doc;
		}
		//creating card
		DefferedICard c = DefferedICard(cardView["number_card"].get_utf8().value.to_string(),
			std::stoi(cardView["cvv"].get_utf8().value.to_string()),
			std::stoi(cardView["pin"].get_utf8().value.to_string()),
			cardView["name"].get_utf8().value.to_string(),
			cardView["date_end"].get_utf8().value.to_string(),
			documentToTransactions(cardView["transactions"].get_array()),
			documentToTransactions(cardView["templates"].get_array()),
			stol(cardView["card_balance"].get_utf8().value.to_string()));
		return c;
	}
	else
	{
		return DefferedICard("dummy", 111, 111, "dummy", "dummy");
	}
}
bsoncxx::document::value  transactionToDocument(const ICard::Transaction& tr)
{
	return make_document(kvp("trans_date", tr.getDate()),
		kvp("senderCN", tr.getSenderCardNum()),
		kvp("recieverCN", tr.getrecieverCardNum()),
		kvp("sum", std::to_string(tr.getSum())),
		kvp("description", tr.getDescription()));
}


std::vector<ICard::Transaction>& documentToTransactions(const bsoncxx::v_noabi::types::b_array& ar)
{
	std::vector<ICard::Transaction>* tr = new std::vector<ICard::Transaction>();
	bsoncxx::array::view arrayView = bsoncxx::array::view(ar);
	bsoncxx::array::view::iterator i;
	for (i = arrayView.begin(); i != arrayView.end(); ++i)
	{
		auto tran = (*i).get_value().get_document();
		bsoncxx::document::view trView = tran.view();
		(*tr).insert((*tr).begin(), 1, ICard::Transaction(trView["trans_date"].get_utf8().value.to_string(),
			trView["senderCN"].get_utf8().value.to_string(),
			trView["recieverCN"].get_utf8().value.to_string(),
			stol(trView["sum"].get_utf8().value.to_string()),
			trView["description"].get_utf8().value.to_string()));
	}
	return *tr;
}