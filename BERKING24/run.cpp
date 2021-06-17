//#include <iostream>
//#include "ICard.h"
//#include "Card.h"
//#include "IUser.h"
//#include "User.h"
//#include "ISaveDeposit.h"
//#include "SaveDeposit.h"
//#include "IOperationManager.h"
//#include "OperationManager.h"
//#include "DefferedICard.h"
//
//DefferedICard makeCard()
//{
//	return DefferedICard("card17", 12433, 321352, "card17", "card17", {}, {});
//}
//
//int main()
//{
//	mongocxx::instance instance{}; // This should be done only once.
//	mongocxx::uri uri("mongodb://localhost:27017");
//	mongocxx::client client(uri);
//	mongocxx::database db = client["preRelease"];
//
//	//User
//	IOperationManager* op = OperationManager::getInstance(db);
//	//DefferedIUser user = op->getUser("FINALTEST");
//	//user->addCard("kek");
//	//user->setEmail("UPFATED");
//	//user->setName("UPDATED");
//	//user->setPassword("UPDATED");
//	//user->setWebToken("UPDATED");
//	//DefferedIUser u = DefferedIUser("test4", "test4", "test4", "test4");
//	//u->addCard("lol");
//	//u->addCard("kek");
//	//DefferedIUser u2=(op->getUser("test4"));
//	//std::cout << (*u2.operator->()) << std::endl;
//	//op->addUser(user);
//	/*DefferedISaveDeposit dep = op->getSaveDeposit("FINALTEST");
//	dep->setBalance(5555);
//	dep->setCard("UPDATED");
//	dep->setEndDate("UPDATED");
//	dep->setStartDate("UPDATED");*/
//	//op->addSaveDeposit(dep);
//	DefferedICard c = op->getCard("FINALTEST");
//	//op->addCard(c);
//	c->setName("UPDATED");
//	Card::Transaction tr = Card::Transaction("tr", "tr", "tr", 1000, "tr");
//	c->addTransaction(tr);
//	c->addTemplate(tr);
//	mongocxx::collection coll = db["cards"];
//
//	//Deposit
//	//ISaveDeposit* s = new SaveDeposit("deposit","deposit","deposit",1000);
//	////op->addSaveDeposit(*s);
//	//ISaveDeposit* s2 = &(op->getSaveDeposit("deposit"));
//	//std::cout << *s2 << std::endl;
//	//mongocxx::collection coll = db["deposits"];
//
//
//	//DefferedICard c = DefferedICard("cardDEF", 111111, 222222, "cardDEF", "cardDEF", {}, {});
//	//Card::Transaction tr = Card::Transaction("tr", "tr", "tr", 1000, "tr");
//	////Card::Transaction tr2 = Card::Transaction("tr2", "tr2", "tr2", 1000, "tr2");
//	////c->addTemplate(tr);
//	////c->addTransaction(tr2);
//	////op->addCard(c);
//	//DefferedICard c2 = op->getCard("cardDEF");
//	////ICard* c2 = &op->getCard("card");
//	//mongocxx::collection coll = db["cards"];
//
//	auto cursor = coll.find({});
//	for (auto&& doc : cursor) {
//		std::cout << bsoncxx::to_json(doc) << std::endl;
//	}
//	/*c2->setDate("RESETED");
//
//
//	cursor = coll.find({});
//	for (auto&& doc : cursor) {
//		std::cout << bsoncxx::to_json(doc) << std::endl;
//	}*/
//	/*DefferedICard defCard = makeCard();
//	std::cout << (*defCard.operator->()) << std::endl;*/
//
//	//Transactions
//	/*Card::Transaction tr = Card::Transaction("tr","tr","tr",1000,"tr");
//	auto array_builder = bsoncxx::builder::basic::array{};
//	array_builder.append(transactionToDocument(tr));
//	bsoncxx::builder::basic::document doc;
//	doc.append(kvp("lol", array_builder));
//	bsoncxx::document::view docView = doc.view();
//	std::vector<Card::Transaction> vec = documentToTransactions(docView["lol"].get_array());
//	std::cout << "kek" << std::endl;*/
//	system("pause");
//	return 0;
//}