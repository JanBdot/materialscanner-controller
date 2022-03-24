#include "Client.h"

Client::Client(
	const std::string server,
	const std::string client_id,
	const std::string topic,
	const int qos
) : _server(server), _client_id(client_id), _topic(topic), qos(qos)
{
	if (!initAndConnect())
	{
		std::cout << "Couldn't connect to MQTT!" << std::endl;
	}
}

bool Client::initAndConnect()
{
	//client = std::make_unique<mqtt::client>(_server, _client_id);
	try
	{
		std::cout << "Connection to MQTT server..." << std::endl;
		mqtt::connect_response rsp = client->connect();
		std::cout << "Connected" << std::endl;
		client->set_callback(_cb);
	}
	catch (const mqtt::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool Client::sendMessage(const std::string msg)
{
	auto pubmsg = mqtt::make_message(_topic, msg);
	pubmsg->set_qos(0);
	try
	{
		client->publish(pubmsg);
		std::cout << "Message sent!" << std::endl;
	}
	catch (const mqtt::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool Client::execute(const Functions func)
{
	switch (func)
	{
	case Functions::TURN_ALL_ON:
		return sendMessage(ALL_ON);
		break;
	default:
		return false;
	}
}