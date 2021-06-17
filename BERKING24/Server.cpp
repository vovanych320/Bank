//Developed by Volodymyr Sychov
#define _CRT_SECURE_NO_WARNINGS
#include "Server.h"

/* Server constructor */
Server::Server(utility::string_t url) : m_listener(url)
{
	m_listener.support(methods::GET, std::bind(&Server::handle_get, this, std::placeholders::_1));
	m_listener.support(methods::POST, std::bind(&Server::handle_post, this, std::placeholders::_1));
}




/* Get request */
void Server::handle_get(http_request message)
{
	if (message.relative_uri().path() == U("/"))
	{
		concurrency::streams::fstream::open_istream(U("../static/index.html"), std::ios::in).then([=](concurrency::streams::istream is)
			{
				message.reply(status_codes::OK, is, U("text/html")).then([](pplx::task<void> t)
					{
						try
						{
							t.get();
						}
						catch (...)
						{
							//
						}
					});
			}).then([=](pplx::task<void>t)
				{
					try
					{
						t.get();
					}
					catch (...)
					{
						message.reply(status_codes::InternalError, U("Internal eror!!!"));

					}
				});
	}
	else if (message.relative_uri().path() == U("/js/chunk-vendors.7a7af7e9.js"))
	{
		concurrency::streams::fstream::open_istream(U("../static/js/chunk-vendors.7a7af7e9.js"), std::ios::in).then([=](concurrency::streams::istream is)
			{
				message.reply(status_codes::OK, is, U("text/javascript")).then([](pplx::task<void> t)
					{
						try
						{
							t.get();
						}
						catch (...)
						{
							//
						}
					});
			}).then([=](pplx::task<void>t)
				{
					try
					{
						t.get();
					}
					catch (...)
					{
						message.reply(status_codes::InternalError, U("Internal eror!!!"));
					}
				});
	}
	else if (message.relative_uri().path() == U("/js/chunk-vendors.7a7af7e9.js.map"))
	{
		concurrency::streams::fstream::open_istream(U("../static/js/chunk-vendors.7a7af7e9.js.map"), std::ios::in).then([=](concurrency::streams::istream is)
			{
				message.reply(status_codes::OK, is, U("application/json")).then([](pplx::task<void> t)
					{
						try
						{
							t.get();
						}
						catch (...)
						{
							//
						}
					});
			}).then([=](pplx::task<void>t)
				{
					try
					{
						t.get();
					}
					catch (...)
					{
						message.reply(status_codes::InternalError, U("Internal eror!!!"));
					}
				});
	}
	else if (message.relative_uri().path() == U("/js/app.238c90c6.js"))
	{
		concurrency::streams::fstream::open_istream(U("../static/js/app.238c90c6.js"), std::ios::in).then([=](concurrency::streams::istream is)
			{
				message.reply(status_codes::OK, is, U("text/javascript")).then([](pplx::task<void> t)
					{
						try
						{
							t.get();
						}
						catch (...)
						{
							//
						}
					});
			}).then([=](pplx::task<void>t)
				{
					try
					{
						t.get();
					}
					catch (...)
					{
						message.reply(status_codes::InternalError, U("Internal eror!!!"));
					}
				});
	}
	else if (message.relative_uri().path() == U("/js/app.238c90c6.js.map"))
	{
		concurrency::streams::fstream::open_istream(U("../static/js/app.238c90c6.js.map"), std::ios::in).then([=](concurrency::streams::istream is)
			{
				message.reply(status_codes::OK, is, U("application/json")).then([](pplx::task<void> t)
					{
						try
						{
							t.get();
						}
						catch (...)
						{
							//
						}
					});
			}).then([=](pplx::task<void>t)
				{
					try
					{
						t.get();
					}
					catch (...)
					{
						message.reply(status_codes::InternalError, U("Internal eror!!!"));
					}
				});
	}
	else if (message.relative_uri().path() == U("/css/app.ddf26b14.css"))
	{
		concurrency::streams::fstream::open_istream(U("../static/css/app.ddf26b14.css"), std::ios::in).then([=](concurrency::streams::istream is)
			{
				message.reply(status_codes::OK, is, U("text/css")).then([](pplx::task<void> t)
					{
						try
						{
							t.get();
						}
						catch (...)
						{
							//
						}
					});
			}).then([=](pplx::task<void>t)
				{
					try
					{
						t.get();
					}
					catch (...)
					{
						message.reply(status_codes::InternalError, U("Internal eror!!!"));
					}
				});
	}
	else if (message.relative_uri().path() == U("/css/chunk-vendors.626a91d5.css"))
	{
		concurrency::streams::fstream::open_istream(U("../static/css/chunk-vendors.626a91d5.css"), std::ios::in).then([=](concurrency::streams::istream is)
			{
				message.reply(status_codes::OK, is, U("text/css")).then([](pplx::task<void> t)
					{
						try
						{
							t.get();
						}
						catch (...)
						{
							//
						}
					});
			}).then([=](pplx::task<void>t)
				{
					try
					{
						t.get();
					}
					catch (...)
					{
						message.reply(status_codes::InternalError, U("Internal eror!!!"));
					}
				});
	}
	else
	{
		concurrency::streams::fstream::open_istream(U("../static/index.html"), std::ios::in).then([=](concurrency::streams::istream is)
			{
				message.reply(status_codes::OK, is, U("text/html")).then([](pplx::task<void> t)
					{
						try
						{
							t.get();
						}
						catch (...)
						{
							//
						}});
			}).then([=](pplx::task<void>t)
				{
					try
					{
						t.get();
					}
					catch (...)
					{
						message.reply(status_codes::InternalError, U("Internal eror!!"));
					}
				});
	}
};


/* Post request */
void Server::handle_post(http_request message)
{
	srand(time(0));
	IOperationManager* op = OperationManager::getInstance();

	ucout << message.to_string() << std::endl << std::endl;


	auto path = message.absolute_uri().path();
	json::value global_val = message.extract_json().get();

	
	/* User email */
	string_t KEY_EMAIL(U("email"));
	std::string EMAIL;

	/* Json WebToken */
	std::string JWT;
	std::string USER_WT;

	/* Json Webtoken validation from the client */
	string_t KEY_JWT(U("webtoken"));
	if (global_val.has_field(U("webtoken")))
	{
		EMAIL = json_in_string(global_val, KEY_EMAIL);

		JWT = json_in_string(global_val, KEY_JWT);
		USER_WT = op->getUser(EMAIL)->getWebToken();
	}


	/* ENDPOINTS */
	if (global_val.has_field(U("webtoken")) && JWT == read_jwt(USER_WT))
	{
		/* Make template */
		if (path == U("/api/make_template"))
		{
			//Key
			//sender_card receiver_card sum description

			json::value json_value = global_val;

			string_t key_sender_number(U("sender_card"));
			string_t key_receiver_number(U("receiver_card"));
			string_t key_description(U("description"));
			string_t key_sum(U("sum"));

			std::string sender_card_number = json_in_string(json_value, key_sender_number);
			std::string receiver_card_number = json_in_string(json_value, key_receiver_number);
			std::string description = json_in_string(json_value, key_description);
			std::string trans_sum = json_in_string(json_value, key_sum);
			unsigned long s = std::stol(trans_sum);

			DefferedICard sender_card = op->getCard(sender_card_number);
			DefferedICard receiver_card = op->getCard(receiver_card_number);


			if (op->cardExist(receiver_card_number))
			{
				DefferedICard sender_card = op->getCard(sender_card_number);
				DefferedICard receiver_card = op->getCard(receiver_card_number);


				std::string date("TEMPLATE");

				//Creating transactions
				ICard::Transaction temp(date, sender_card_number, receiver_card_number, s, description);
				sender_card->addTemplate(temp);

				//Json reply
				json::value reply = json::value();
				reply[U("status")] = json::value(U("success"));
				reply[U("details")] = json::value(U("Template succsesfully created"));
				message.reply(status_codes::OK, reply);
			}
			else
			{
				//Json reply
				json::value reply = json::value();
				reply[U("status")] = json::value(U("failure"));
				reply[U("details")] = json::value(U("No receiver card"));
				message.reply(status_codes::OK, reply);
			}
		}
		/* Make deposit */
		else if (path == U("/api/make_deposit"))
		{
			//Key
			//card_num exp_date sum
			json::value json_value = global_val;

			//ñonverting
			string_t key_card_num(U("card_num"));
			string_t key_exp_date(U("end_date"));
			string_t key_sum(U("init_sum"));

			std::string card_num = json_in_string(json_value, key_card_num);
			std::string expiration_date = json_in_string(json_value, key_exp_date);
			std::string dep_sum = json_in_string(json_value, key_sum);
			unsigned long deposit_sum = std::stol(dep_sum);

			//Start date
			std::time_t now = std::time(NULL);
			std::tm* ptm = std::localtime(&now);
			char buffer[32];
			// Format: 15.06.2019
			std::strftime(buffer, 32, "%d.%m.%Y", ptm);
			std::string start_date(buffer);


			DefferedICard card_with_deposit = op->getCard(card_num);
			if (!op->depositExist(card_num))
			{
				if (card_with_deposit->getBalance() >= deposit_sum)
				{
					double card_balance = card_with_deposit->getBalance();
					card_with_deposit->setBalance(card_balance - deposit_sum);

					DefferedISaveDeposit dep = DefferedISaveDeposit(card_num, start_date, expiration_date, deposit_sum);

					std::cout << dep->getCardNum() << std::endl;
					std::cout << dep->getBalance() << std::endl;

					op->addSaveDeposit(dep);

					//Json reply
					json::value reply = json::value();
					reply[U("status")] = json::value(U("success"));
					reply[U("details")] = json::value(U("Deposit succsesfully created"));
					message.reply(status_codes::OK, reply);
				}
				else
				{
					//Json reply
					json::value reply = json::value();
					reply[U("status")] = json::value(U("failure"));
					reply[U("details")] = json::value(U("Not enought money"));
					message.reply(status_codes::OK, reply);
				}
			}
			else
			{
				//Json reply
				json::value reply = json::value();
				reply[U("status")] = json::value(U("failure"));
				reply[U("details")] = json::value(U("Such deposit already exists"));
				message.reply(status_codes::OK, reply);
			}
		}
		/* Make transaction */
		else if (path == U("/api/make_transaction"))
		{
			//Key
			//sender_card receiver_card sum description

			json::value json_value = global_val;

			//ñonverting
			string_t key_sender_number(U("sender_card"));
			string_t key_receiver_number(U("receiver_card"));
			string_t key_description(U("description"));
			string_t key_sum(U("sum"));

			std::string sender_card_number = json_in_string(json_value, key_sender_number);
			std::string receiver_card_number = json_in_string(json_value, key_receiver_number);
			std::string description = json_in_string(json_value, key_description);
			std::string trans_sum = json_in_string(json_value, key_sum);
			unsigned long s = std::stol(trans_sum);

			DefferedICard sender_card = op->getCard(sender_card_number);
			DefferedICard receiver_card = op->getCard(receiver_card_number);


			if (op->cardExist(receiver_card_number) && sender_card->getBalance() >= s)
			{
				DefferedICard sender_card = op->getCard(sender_card_number);
				DefferedICard receiver_card = op->getCard(receiver_card_number);
				unsigned long current_sender_card_balance = sender_card->getBalance();
				unsigned long current_receiver_card_card_balance = receiver_card->getBalance();

				sender_card->setBalance(current_sender_card_balance - s);
				receiver_card->setBalance(current_receiver_card_card_balance + s);


				std::time_t now = std::time(NULL);
				std::tm* ptm = std::localtime(&now);
				char buffer[32];
				// Format: Mo, 15.06.2009 20:20:00
				std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
				std::string date(buffer);

				//Creating transactions
				ICard::Transaction tr_action(date, sender_card_number, receiver_card_number, s, description);
				sender_card->addTransaction(tr_action);
				receiver_card->addTransaction(tr_action);

				//Json reply
				json::value reply = json::value();
				reply[U("status")] = json::value(U("success"));
				reply[U("details")] = json::value(U("Transaction succsesfull"));
				message.reply(status_codes::OK, reply);
			}
			else
			{
				if (!op->cardExist(receiver_card_number)) {
					//Json reply
					json::value reply = json::value();
					reply[U("status")] = json::value(U("failure"));
					reply[U("details")] = json::value(U("Receiver card does not exist"));
					message.reply(status_codes::OK, reply);
				}
				else {
					json::value reply = json::value();
					reply[U("status")] = json::value(U("failure"));
					reply[U("details")] = json::value(U("Not enough money on the sending card"));
					message.reply(status_codes::OK, reply);
				}
			}
		}
		/* Create card */
		else if (path == U("/api/create_card"))
		{
			//Keys
			//card_name email

			json::value json_value = global_val;

			string_t key_name(U("card_name"));
			string_t key_email(U("email"));


			std::string card_name = json_in_string(json_value, key_name);
			std::string email = json_in_string(json_value, key_email);

			//Personal Identification Number
			unsigned int pin = rand() % 8998 + 1001;
			//CVV code
			unsigned int cvv = rand() % 898 + 101;
			//Random end date
			std::string endDate = create_end_date();
			//Random card number 
			std::string card_number = genetare_card_number();
			std::vector<DefferedICard> check_card = op->getAllUsersCards(email);

			for (size_t i = 0; i < check_card.size(); i++)//Card number is unique and can't repeat
			{
				if (check_card[i]->getNumber() == card_number)
				{
					card_number = genetare_card_number();
					break;
				}
			}


			//Creating and adding card
			DefferedICard card = DefferedICard(card_number, cvv, pin, card_name, endDate);
			DefferedIUser u = op->getUser(email);
			u->addCard(card_number);
			op->addCard(card);

			//Json card info
			json::value card_info = json::value();
			card_info[U("card_name")] = json::value(utility::conversions::to_string_t(card_name));
			card_info[U("card_number")] = json::value(utility::conversions::to_string_t(card_number));
			card_info[U("card_expiration")] = json::value(utility::conversions::to_string_t(card->getDate()));
			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("successs"));
			reply[U("details")] = json::value(U("Successfully created card"));
			reply[U("data")] = json::value(card_info);

			message.reply(status_codes::OK, reply);
		}
		/* Get all user deposits */
		else if (path == U("/api/user_deposits"))
		{
			//Key
			//email
			json::value json_value = global_val;

			//ñonverting
			string_t key_email(U("email"));

			std::string user_email = json_in_string(json_value, key_email);

			std::vector<DefferedICard> user_cards = op->getAllUsersCards(user_email);
			std::string card_num;

			for (size_t i = 0; i < user_cards.size(); i++)
			{
				if (op->depositExist(user_cards[i]->getNumber()))
					card_num = user_cards[i]->getNumber();
			}

			if (op->depositExist(card_num))
			{
				DefferedISaveDeposit dep = op->getSaveDeposit(card_num);

				json::value preview = json::value();
				preview[U("card_num")] = json::value(conversions::to_string_t(card_num));
				preview[U("start_date")] = json::value(conversions::to_string_t(dep->getStartDate()));
				preview[U("end_date")] = json::value(conversions::to_string_t(dep->getEndDate()));
				preview[U("init_sum")] = json::value(conversions::to_string_t(std::to_string(dep->getBalance())));


				//Json reply
				json::value reply = json::value();
				reply[U("status")] = json::value(U("success"));
				reply[U("details")] = json::value(U("Deposit is good"));
				reply[U("data")] = json::value(preview);
				message.reply(status_codes::OK, reply);
			}
			else
			{
				//Json reply
				json::value reply = json::value();
				reply[U("status")] = json::value(U("failed"));
				reply[U("details")] = json::value(U("Deposit does not exist"));
				reply[U("data")] = json::value(conversions::to_string_t(U("null")));
				message.reply(status_codes::OK, reply);
			}
		}
		/* Get all user cards */
		else if (path == U("/api/user_cards"))
		{
			//email
			json::value json_value = global_val;

			//ñonverting
			string_t email(U("email"));
			std::string user_email = json_in_string(json_value, email);

			//std::vector<DefferedICard> user_cards = getUserCards(user_email);
			std::vector<DefferedICard> user_cards = op->getAllUsersCards(user_email);

			//Card json
			json::value json_card = json::value();
			json::value json_card_arr = json::value();
			for (size_t i = 0; i < user_cards.size(); i++)
			{
				json_card[U("card_expiration")] = json::value(utility::conversions::to_string_t(user_cards[i]->getDate()));
				json_card[U("card_name")] = json::value(utility::conversions::to_string_t(user_cards[i]->getName()));
				json_card[U("card_number")] = json::value(utility::conversions::to_string_t(user_cards[i]->getNumber()));
				std::string sum = std::to_string(user_cards[i]->getBalance());
				json_card[U("card_balance")] = json::value(utility::conversions::to_string_t(sum));

				string_t st_i = utility::conversions::to_string_t(std::to_string(i));
				json_card_arr[st_i] = json::value(json_card);
			}

			json::value reply = json::value();

			if (json_card_arr.is_null())
			{
				//Json reply
				reply[U("status")] = json::value(U("success"));
				reply[U("details")] = json::value(U("All cards"));
				reply[U("data")] = json::value(U("null"));
			}
			else
			{
				//Json reply
				reply[U("status")] = json::value(U("success"));
				reply[U("details")] = json::value(U("All cards"));
				reply[U("data")] = json::value(json_card_arr);
			}

			message.reply(status_codes::OK, reply);
		}
		/* Get all user transactioms */
		else if (path == U("/api/user_transactions"))
		{
			//Key
			//email

			json::value json_value = global_val;

			//ñonverting
			string_t user_email(U("email"));

			std::string email = json_in_string(json_value, user_email);

			std::vector<DefferedICard> user_cards = op->getAllUsersCards(email);

			//Transaction json
			json::value json_trans = json::value();
			json::value json_trans_only_card = json::value();
			json::value json_all_user_transes = json::value();

			for (size_t i = 0; i < user_cards.size(); ++i)
			{
				std::vector<ICard::Transaction> trans_vect = user_cards[i]->getTransactions();
				for (size_t j = 0; j < trans_vect.size(); ++j)
				{
					json_trans[U("date")] = json::value(utility::conversions::to_string_t(trans_vect[j].getDate()));
					json_trans[U("description")] = json::value(utility::conversions::to_string_t(trans_vect[j].getDescription()));
					json_trans[U("receiver_card")] = json::value(utility::conversions::to_string_t(trans_vect[j].getrecieverCardNum()));
					json_trans[U("sender_card")] = json::value(utility::conversions::to_string_t(trans_vect[j].getSenderCardNum()));
					std::string sum = std::to_string(trans_vect[j].getSum());
					json_trans[U("sum")] = json::value(utility::conversions::to_string_t(sum));

					string_t st_j = utility::conversions::to_string_t(std::to_string(j));
					json_trans_only_card[st_j] = json::value(json_trans);

					json_trans.erase(U("date"));
					json_trans.erase(U("description"));
					json_trans.erase(U("receiver_card"));
					json_trans.erase(U("sender_card"));
					json_trans.erase(U("sum"));
				}
				string_t st_i = utility::conversions::to_string_t(std::to_string(i));
				json_all_user_transes[st_i] = json::value(json_trans_only_card);
			}

			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("success"));
			reply[U("details")] = json::value(U("All transactions"));
			reply[U("data")] = json::value(json_all_user_transes);

			message.reply(status_codes::OK, reply);
		}
		/* Get all user templates */
		else if (path == U("/api/user_templates"))
		{
			//Key
			//user_email

			json::value json_value = global_val;

			//ñonverting
			string_t user_email(U("email"));

			std::string email = json_in_string(json_value, user_email);

			std::vector<DefferedICard> user_cards = op->getAllUsersCards(email);

			//Transaction json
			json::value json_temps = json::value();
			json::value json_temps_only_card = json::value();
			json::value json_all_user_temps = json::value();
			for (size_t i = 0; i < user_cards.size(); ++i)
			{
				std::vector<ICard::Transaction> temp_vect = user_cards[i]->getTemplates();
				if (temp_vect.size() == 0)
				{
					json_temps_only_card[U("0")] = json::value();
				}
				else
				{
					for (size_t j = 0; j < temp_vect.size(); ++j)
					{
						json_temps[U("description")] = json::value(utility::conversions::to_string_t(temp_vect[j].getDescription()));
						json_temps[U("receiver_card")] = json::value(utility::conversions::to_string_t(temp_vect[j].getrecieverCardNum()));
						json_temps[U("sender_card")] = json::value(utility::conversions::to_string_t(temp_vect[j].getSenderCardNum()));
						std::string sum = std::to_string(temp_vect[j].getSum());
						json_temps[U("sum")] = json::value(utility::conversions::to_string_t(sum));

						string_t st_j = utility::conversions::to_string_t(std::to_string(j));
						json_temps_only_card[st_j] = json::value(json_temps);

						json_temps.erase(U("description"));
						json_temps.erase(U("receiver_card"));
						json_temps.erase(U("sender_card"));
						json_temps.erase(U("sum"));
					}
				}
				string_t st_i = utility::conversions::to_string_t(std::to_string(i));
				json_all_user_temps[st_i] = json::value(json_temps_only_card);
			}

			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("success"));
			reply[U("details")] = json::value(U("All transactions"));
			reply[U("data")] = json::value(json_all_user_temps);
			message.reply(status_codes::OK, reply);
		}
		
	}
	/* User authorization */
	else if (path == U("/api/authorize"))
	{
		//Keys
		//email password
		json::value json_value = global_val;

		//ñonverting
		string_t key_email(U("email"));
		string_t key_password(U("password"));

		std::string user_email = json_in_string(json_value, key_email);
		std::string user_pass = json_in_string(json_value, key_password);


		//Validation: if user exists
		if (op->userExist(user_email))
		{
			DefferedIUser user = op->getUser(user_email);
			if (user->getPassword() == user_pass)
			{
				std::string const_webtoken = generate_constant_webtoken(user_email);
				std::string temp_webtoken = generate_temporary_webtoken(user_email);

				std::string all_webtoken = const_webtoken + ":" + temp_webtoken;

				op->getUser(user_email)->setWebToken(all_webtoken);

				/* If deposit ended */
				check_deposit_end(user_email);

				//Json reply
				json::value reply = json::value();
				reply[U("status")] = json::value(U("success"));
				reply[U("details")] = json::value(U("User successfully authorized"));
				reply[U("refresh_webtoken")] = json::value(conversions::to_string_t(const_webtoken));
				reply[U("webtoken")] = json::value(conversions::to_string_t(temp_webtoken));
				message.reply(status_codes::OK, reply);

			}
			else
			{
				//Json reply
				json::value reply = json::value();
				reply[U("status")] = json::value(U("failure"));
				reply[U("details")] = json::value(U("Incorrect login or password"));
				message.reply(status_codes::OK, reply);
			}
		}
		else
		{
			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("failure"));
			reply[U("details")] = json::value(U("Incorrect login or password"));
			message.reply(status_codes::OK, reply);
		}
	}
	/* User registration */
	else if (path == U("/api/register"))
	{
		//Keys
		//user_name user_email user_password

		json::value json_value = global_val;

		//ñonverting
		string_t key_name(U("user_name"));
		string_t key_mail(U("user_email"));
		string_t key_password(U("user_password"));

		std::string user_name = json_in_string(json_value, key_name);
		std::string user_email = json_in_string(json_value, key_mail);
		std::string user_pass = json_in_string(json_value, key_password);

		if (!op->userExist(user_email))
		{

			std::string const_webtoken = generate_constant_webtoken(user_email);
			std::string temp_webtoken = generate_temporary_webtoken(user_email);

			std::string all_webtoken = const_webtoken + ":" + temp_webtoken;

			DefferedIUser user = DefferedIUser(all_webtoken, user_name, user_pass, user_email);
			op->addUser(user);

			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("success"));
			reply[U("details")] = json::value(U("Successfully registrated user"));
			reply[U("refresh_webtoken")] = json::value(conversions::to_string_t(const_webtoken));
			reply[U("webtoken")] = json::value(conversions::to_string_t(temp_webtoken));
			message.reply(status_codes::OK, reply);
		}
		else
		{
			json::value reply = json::value();
			reply[U("status")] = json::value(U("Failure"));
			reply[U("details")] = json::value(U("User already exists"));
			message.reply(status_codes::OK, reply);
		}
	}
	/* Forget password? */
	else if (path == U("/api/recover_password"))
	{
		//Key
		//email old_ password new_password
		json::value json_value = global_val;

		//ñonverting
		string_t email(U("email"));
		string_t o_pass(U("password"));
		string_t n_pass(U("new_password"));

		std::string user_email = json_in_string(json_value, email);
		std::string old_user_pass = json_in_string(json_value, o_pass);
		std::string new_user_pass = json_in_string(json_value, n_pass);

		DefferedIUser user = op->getUser(user_email);
		if (user->getPassword() != new_user_pass && user->getPassword() == old_user_pass)
		{
			user->setPassword(new_user_pass);

			json::value reply = json::value();
			reply[U("status")] = json::value(U("success"));
			reply[U("details")] = json::value(U("Password succsesfully chanded"));

			message.reply(status_codes::OK, reply);
		}
		else
		{
			json::value reply = json::value();
			reply[U("status")] = json::value(U("Failure"));
			reply[U("details")] = json::value(U("Same passwords"));
			message.reply(status_codes::OK, reply);
		}
	}
	/* Replenish user cards */
	else if (path == U("/api/terminal"))
	{
		//Key
		//receiver_card sum description

		json::value json_value = global_val;

		//ñonverting
		string_t key_receiver_number(U("receiver_card"));
		string_t key_description(U("description"));
		string_t key_sum(U("sum"));

		std::string receiver_card_number = json_in_string(json_value, key_receiver_number);
		std::string description = json_in_string(json_value, key_description);
		std::string trans_sum = json_in_string(json_value, key_sum);
		unsigned long s = std::stol(trans_sum);

		DefferedICard receiver_card = op->getCard(receiver_card_number);

		if (op->cardExist(receiver_card_number))
		{
			DefferedICard receiver_card = op->getCard(receiver_card_number);
			unsigned long current_receiver_card_card_balance = receiver_card->getBalance();

			receiver_card->setBalance(current_receiver_card_card_balance + s);

			std::time_t now = std::time(NULL);
			std::tm* ptm = std::localtime(&now);
			char buffer[32];
			// Format: Mo, 15.06.2009 20:20:00
			std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
			std::string date(buffer);

			std::string sender("Berking TERMINAL");
			//Creating transactions
			ICard::Transaction tr_action(date, sender, receiver_card_number, s, description);
			receiver_card->addTransaction(tr_action);

			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("success"));
			reply[U("details")] = json::value(U("Card successfully replenished"));
			message.reply(status_codes::OK, reply);
		}
		else
		{
			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("failure"));
			reply[U("details")] = json::value(U("No receiver card"));
			message.reply(status_codes::OK, reply);
		}
	}
	/* Get information about deposit before create it */
	else if (path == U("/api/preview_before_deposit"))
	{
		//Key
		//exp_date sum
		json::value json_value = global_val;

		//ñonverting
		string_t key_exp_date(U("exp_date"));
		string_t key_sum(U("sum"));

		//Start date
		std::time_t now = std::time(NULL);
		std::tm* ptm = std::localtime(&now);
		char buffer[32];
		// Format: 15.06.2019
		std::strftime(buffer, 32, "%d.%m.%Y", ptm);

		std::string start_date(buffer);
		std::string expiration_date = json_in_string(json_value, key_exp_date);
		std::string dep_sum = json_in_string(json_value, key_sum);
		unsigned long deposit_sum = std::stol(dep_sum);

		size_t d_d = deposit_days(start_date, expiration_date);
		DepositFunctor f = DepositFunctor(d_d, d_d);
		unsigned long end_deposit_sum = f(deposit_sum);

		json::value preview = json::value();
		preview[U("start_date")] = json::value(utility::conversions::to_string_t(start_date));
		preview[U("expiration_data")] = json::value(utility::conversions::to_string_t(expiration_date));
		preview[U("end_sum")] = json::value(utility::conversions::to_string_t(std::to_string(end_deposit_sum)));

		//Json reply
		json::value reply = json::value();
		reply[U("status")] = json::value(U("Success"));
		reply[U("details")] = json::value(U("Preview before creating deposit"));
		reply[U("data")] = json::value(preview);

		message.reply(status_codes::OK, reply);
	}
	/* Refreshes "old" webtoken */
	else if (path == U("/api/refresh_token"))
	{
		//Key
		//webtoken refresh_token
		json::value json_value = global_val;

		string_t key_jwt(U("webtoken"));
		string_t key_ref_jwt(U("refresh_token"));

		// Json values 
		std::string email = EMAIL;
		std::string wt = json_in_string(json_value, key_jwt);
		std::string ref_wt = json_in_string(json_value, key_ref_jwt);

		// Value from DB
		std::string user_jwt = op->getUser(email)->getWebToken();

		/* JWT validation: if jwt from client equals jwt from DB  */
		if (wt == read_refresh_jwt(user_jwt))
		{
			wt = generate_temporary_webtoken(email);
			user_jwt = read_refresh_jwt(user_jwt) + ":" + wt;

			op->getUser(email)->setWebToken(user_jwt);

			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("success"));
			reply[U("details")] = json::value(U("Successfully refreshed webtoken"));
			reply[U("refresh_token")] = json::value(conversions::to_string_t(read_refresh_jwt(user_jwt)));
			reply[U("webtoken")] = json::value(conversions::to_string_t(wt));

			message.reply(status_codes::OK, reply);
		}
		else
		{
			//Json reply
			json::value reply = json::value();
			reply[U("status")] = json::value(U("failure"));
			reply[U("details")] = json::value(U("Refresh jwt not equal"));
			message.reply(status_codes::OK, reply);
		}
	}
}


/* Utilities */

/***  
*
*Check if deposit end date equals or bigger than today 
*
***/
void check_deposit_end(const std::string& email)
{
	IOperationManager* op = OperationManager::getInstance();

	//End date
	std::time_t now = std::time(NULL);
	std::tm* ptm = std::localtime(&now);
	char buffer[32];
	// Format: 15.06.2019
	std::strftime(buffer, 32, "%d.%m.%Y", ptm);


	std::string card_num = "null";

	std::vector<DefferedICard> user_cards = op->getAllUsersCards(email);
	for (size_t i = 0; i < user_cards.size(); i++)
	{
		std::string num = user_cards[i]->getNumber();
		if (op->depositExist(num))
		{
			card_num = num;
		}
	}

	std::string end_date(buffer);
	if (op->depositExist(card_num))
	{
		DefferedICard dep_card = op->getCard(card_num);
		DefferedISaveDeposit deposit = op->getSaveDeposit(card_num);

		std::string END_DATE(buffer);

		if (deposit_days(deposit->getEndDate(), END_DATE) >= 0)
		{

			std::string start_date = deposit->getStartDate();
			std::string end_date = deposit->getEndDate();

			size_t d_d = deposit_days(start_date, end_date);
			DepositFunctor goog_functor = DepositFunctor(d_d, d_d);
			unsigned long end_deposit_sum = goog_functor(deposit->getBalance());

			double card_balance = dep_card->getBalance();
			unsigned long new_card_balance = card_balance + end_deposit_sum;

			dep_card->setBalance(new_card_balance);
			op->deleteDeposit(card_num, goog_functor);
		}
	}
	else
	{
		return;
	}

}


/***
*
*Converts takes value with key fron json::value and convert it to std::string
*
***/
std::string json_in_string(const json::value& j, const string_t& key)
{
	string_t json_val = j.at(key).as_string();
	std::string valu = utility::conversions::to_utf8string(json_val);
	return valu;
};

/***
*
*Generates random card number. It is always starts from 5679...
*
***/
std::string genetare_card_number()
{
	srand(time(0));
	const size_t size = 17;
	char num[size] = { '5','6','7','9' };
	for (size_t i = 4; i < size - 1; i++)
	{
		char a = (rand() % 10) + 48;
		num[i] = a;
	}
	std::string res(num);
	return res;
};

/***
*
*Creates expiration date for the card
*
***/
std::string create_end_date()
{
	srand(time(0));
	const size_t size = 8;
	char date[size] = { '0',' ','/','2','0','2',' ' };
	for (size_t i = 0; i < size; i++)
	{
		if (i == 1)
		{
			char a = (rand() % 8) + 49;
			date[i] = a;
		}
		if (i == 6)
		{
			char a = (rand() % 3) + 49;
			date[i] = a;
		}
	}
	std::string res(date);
	return res;
};

/***
*
*Return the number of days between two dates
*
***/
size_t deposit_days(const std::string start, const  std::string end)
{
	//Start date
	const char* d = start.c_str();

	char day[] = { start.c_str()[0],start.c_str()[1],'\0' };	
	std::string s_day(day);
	char month[] = { start.c_str()[3] ,start.c_str()[4],'\0' };
	std::string s_mounth(month);
	char year[] = { start.c_str()[6],start.c_str()[7],start.c_str()[8] ,start.c_str()[9],'\0' };
	std::string s_year(year);

	size_t start_day = std::stol(s_day);
	size_t start_mounth = std::stol(s_mounth);
	size_t start_year = std::stol(s_year);


	//End date
	char day1[] = { end.c_str()[0],end.c_str()[1],'\0' };
	std::string e_day(day1);
	char month1[] = { end.c_str()[3],end.c_str()[4], '\0' };
	std::string e_mounth(month1);
	char year1[] = { end.c_str()[6],end.c_str()[7],end.c_str()[8],end.c_str()[9],'\0' };
	std::string e_year(year1);
	size_t end_day = std::stol(e_day);
	size_t end_mounth = std::stol(e_mounth);
	size_t end_year = std::stol(e_year);

	//All functionality
	size_t number_of_days = 0;
	if ((end_mounth - start_mounth) == 0)
	{
		number_of_days = end_day - start_day;
		std::cout << "Number of days " << number_of_days << std::endl;
		return number_of_days;
	}
	else if ((end_year - start_year) == 0)
	{
		number_of_days += (days_in_month(start_mounth, is_leap_year(start_year)) - start_day);
		number_of_days += end_day;
		for (size_t i = start_mounth + 1; i < end_mounth; i++)
		{
			number_of_days += days_in_month(i, is_leap_year(start_year));
		}
		std::cout << "Number of days " << number_of_days << std::endl;
		return number_of_days;
	}
	else if ((end_year - start_year) == 1)
	{
		number_of_days += (days_in_month(start_mounth, is_leap_year(start_year)) - start_day);
		number_of_days += end_day;
		for (size_t i = start_mounth + 1; i <= 12; i++)
		{
			number_of_days += days_in_month(i, is_leap_year(start_year));
		}
		for (size_t i = 1; i < end_mounth; i++)
		{
			number_of_days += days_in_month(i, is_leap_year(start_year));
		}
		std::cout << "Number of days " << number_of_days << std::endl;
		return number_of_days;
	}
	else if ((end_year - start_year) > 1)
	{
		number_of_days = 365;
		std::cout << "Number of days " << number_of_days << std::endl;
		return number_of_days;
	}
	else
	{
		return 0;
	}

}

// Is leap year?
bool is_leap_year(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0)))
		return true;
	else
		return false;
};
//Number of days in the month
size_t days_in_month(const size_t month, const  bool is_leap)
{
	int numberOfDays = 0;
	switch (month)
	{
	case 2: numberOfDays = 28 + is_leap;
		break;
	case 4: case 6: case 9: case 11:
		numberOfDays = 30;
		break;
	case 1: case 3: case 5:
	case 7: case 8: case 10: case 12:
		numberOfDays = 31;
		break;
	default: numberOfDays = 0;
	}

	return numberOfDays;
}


/***
*
*Json WebToken generation and read it from DB
*
***/
std::string generate_constant_webtoken(const std::string& email)
{
	std::string key_email("user_email");
	jwt::claim val_email(email);

	std::string key_status("status");
	jwt::claim val_status(std::string("user"));

	std::string key_jwt_type("jwt_type");
	jwt::claim val_jwt_type(std::string("constant"));

	auto token = jwt::create()
		.set_type("JWS")
		.set_payload_claim(key_status, val_status)
		.set_payload_claim(key_email, val_email)
		.sign(jwt::algorithm::hs256{ "key" });

	return token;
};

std::string generate_temporary_webtoken(const std::string& email)
{
	std::string key_email("email");
	jwt::claim val_email(email);

	std::string key_status("status");
	jwt::claim val_status(std::string("user"));

	std::string key_jwt_type("jwt_type");
	jwt::claim val_jwt_type(std::string("temporary"));

	auto token = jwt::create()
		.set_type("JWS")
		.set_payload_claim(key_status, val_status)
		.set_payload_claim(key_email, val_email)
		.sign(jwt::algorithm::hs256{ "key" });

	return token;
};

std::string read_refresh_jwt(std::string& t)
{
	std::string str = t;
	std::string delimiter = ":";

	std::string token = str.substr(0, str.find(delimiter));

	return token;
};

std::string read_jwt(std::string& t)
{
	std::string str = t;
	std::string delimiter = ":";

	std::string token = str.substr(str.find(delimiter) + 1, str.length() - 1);

	return token;
};
