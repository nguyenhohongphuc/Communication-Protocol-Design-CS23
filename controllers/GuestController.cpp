#include "GuestController.h"

Response GuestController::handle(const Request &req)
{
    return {200, "Welcome, guest VOTIEN!"};
}