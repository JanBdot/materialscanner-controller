#pragma once
#include <iostream>
#include <memory>
#include "mqtt/client.h"

enum class Functions { TURN_ALL_ON, TURN_ALL_OFF, SCAN };

//responses
const std::string ERROR = "error";
const std::string DONE = "done";

//messages
const std::string ALL_ON = "all_on";
const std::string ALL_OFF = "all_off";
const std::string SCAN = "scan";
const std::string NEXT = "next";

class UserCallBack : public virtual mqtt::callback
{
public:
	void connection_lost(const std::string& cause) override;
	void delivery_complete(mqtt::delivery_token_ptr tok) override;
};