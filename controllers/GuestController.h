#pragma once
#include "Controller.h"

class GuestController : public Controller
{
public:
    Response handle(const Request &req) override;
};