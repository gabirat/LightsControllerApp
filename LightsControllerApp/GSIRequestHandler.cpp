#include "GSIRequestHandler.h"

GSIRequestHandler::GSIRequestHandler(GameHandler* gh) : game_handler(gh) {
}

void GSIRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& req, Poco::Net::HTTPServerResponse& resp) {
    Poco::JSON::Parser parser;
    auto result = parser.parse(req.stream());
    auto obj = result.extract<Poco::JSON::Object::Ptr>();
    game_handler->update_data(obj);
    resp.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
}