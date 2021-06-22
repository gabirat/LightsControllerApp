#include "GSIRequestHandlerFactory.h"

GSIRequestHandlerFactory::GSIRequestHandlerFactory(GameHandler* gh) : game_handler(gh) {
}

Poco::Net::HTTPRequestHandler* GSIRequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest&) {
    return new GSIRequestHandler(game_handler);
}
