#include "Server.h"

std::unique_ptr<Server> g_http;

void on_initialize(const string_t& address)
{

	uri_builder uri(address);
	uri.append_path(U("/"));

	auto addr = uri.to_uri().to_string();
	g_http = std::unique_ptr<Server>(new Server(addr));
	g_http->open().wait();

	ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

	return;
}

void on_shutdown()
{
	g_http->close().wait();
	return;
}

int wmain(int argc, wchar_t* argv[])
{
	mongocxx::instance instance{}; // This should be done only once.
	mongocxx::uri uri("mongodb://localhost:27017");
	mongocxx::client client(uri);
	mongocxx::database db = client["preRelease"];
	IOperationManager* op = OperationManager::init(db);


	utility::string_t port = U("34568");
	if (argc == 2)
	{
		port = argv[1];
	}

	utility::string_t address = U("http://localhost:");
	address.append(port);

	on_initialize(address);
	std::cout << "Press ENTER to exit." << std::endl;

	std::string line;
	std::getline(std::cin, line);

	on_shutdown();
	return 0;
}