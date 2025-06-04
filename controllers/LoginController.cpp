#include "LoginController.h"

Response LoginController::handle(const Request &req)
{
    auto json = req.body;
    std::string username = json["username"];
    std::string password = json["password"];

    if (username == "admin" && password == "123456")
    {
        std::string token = TokenGenerator::generate();
        TokenStore::instance().store(token, Role::ADMIN);
        return {200, token};
        // TODO
    }
    else if (username == "user" && password == "123456")
    {
        std::string token = TokenGenerator::generate();
        TokenStore::instance().store(token, Role::USER);
        return {200, token};
        // TODO
    }
    else if (username == "guest" && password == "123456")
    {
        // TODO
        std::string token = TokenGenerator::generate();
        TokenStore::instance().store(token, Role::GUEST);
        return {200, token};
    }
    return {200, "Fail login!!!"};
}