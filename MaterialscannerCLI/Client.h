
#pragma once
#include "UserCallBack.h";

class Client
{
public:
	std::unique_ptr<mqtt::client> client;
	int qos = 0;
	Client(
		const std::string server,
		const std::string client_id,
		const std::string topic,
		const int qos
	);

	bool switchLamp(const unsigned int lampNr);
	bool execute(const Functions func);

private:
	const std::string _server;
	const std::string _client_id;
	const std::string _topic;
	UserCallBack _cb;

	bool initAndConnect();
	bool sendMessage(const std::string msg);
	bool doScan();
};
