#include "GSIRequestHandler.h"

GSIRequestHandler::GSIRequestHandler(GameHandler* gh) : game_handler(gh) {
}

void GSIRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& req, Poco::Net::HTTPServerResponse& resp) {
    if (game_handler->get_gsi_path() != req.getURI()) return;
    Poco::JSON::Parser parser;
    auto result = parser.parse(req.stream());
    game_handler->update_data(result.extract<Poco::JSON::Object::Ptr>());
    resp.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
    resp.send();
}