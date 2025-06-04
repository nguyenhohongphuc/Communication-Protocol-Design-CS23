#include "Router.h"
#include "controllers/LoginController.h"
#include "controllers/AdminController.h"
#include "controllers/UserController.h"
#include "controllers/GuestController.h"

Controller *Router::getController(const Request &req)
{

    if (req.path == "/login" && req.method == "POST")
    {
        return new LoginController();
    }
    else if (req.path == "/admin" && req.method == "GET")
    {
        if( TokenStore::instance().getRole(req.token) != Role::ADMIN)
        {
            return nullptr; 
        }

        return new AdminController();
    }
    else if (req.path == "/user" && req.method == "GET")
    {
        
        if( TokenStore::instance().getRole(req.token) == Role::USER)
        {
            return new UserController();
        }
    }
    else if (req.path == "/guest" && req.method == "GET")
    {
        if( TokenStore::instance().getRole(req.token) == Role::GUEST)
        {
            return new GuestController();
        }
    }
    // TODO
    return nullptr;
}
