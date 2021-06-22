#pragma once

#include <iostream>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
class GameHandler;
#include "GameHandler.h"

class GSIRequestHandler : public Poco::Net::HTTPRequestHandler {
private:
    GameHandler* game_handler;
public:
    GSIRequestHandler(GameHandler* gh);
    virtual void handleRequest(Poco::Net::HTTPServerRequest& req, Poco::Net::HTTPServerResponse& resp);

};

