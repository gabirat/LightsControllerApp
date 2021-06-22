#pragma once

#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "GSIRequestHandler.h"

class GSIRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {
private:
    GameHandler* game_handler;
public:
    GSIRequestHandlerFactory(GameHandler* gh);
    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest&);
};
