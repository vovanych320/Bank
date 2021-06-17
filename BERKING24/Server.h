#pragma once
#include "OperationManager.h"
#include <random>
#include <ctime>

#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/filestream.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/containerstream.h"
#include "cpprest/filestream.h"
#include "cpprest/http_client.h"
#include "cpprest/producerconsumerstream.h"
#include "cpprest/rawptrstream.h"

#include "jwt-cpp/jwt.h"

//using namespace std;
using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;
using namespace concurrency;
using namespace web::http::client;



class Server
{
public:
	Server() {}
	Server(utility::string_t url);

	pplx::task<void> open() { return m_listener.open(); }
	pplx::task<void> close() { return m_listener.close(); }

private:
	void handle_get(http_request message);
	void handle_post(http_request message);

	http_listener m_listener;
};

void check_deposit_end(const std::string& email);

std::string json_in_string(const json::value& j, const string_t& key);

std::string genetare_card_number();

std::string create_end_date();

size_t deposit_days(const std::string start, const std::string end);

bool is_leap_year(int y);

size_t days_in_month(const size_t month, const  bool is_leap);

std::string generate_constant_webtoken(const std::string& email);

std::string generate_temporary_webtoken(const std::string& email);

std::string read_refresh_jwt(std::string& t);

std::string read_jwt(std::string& t);


