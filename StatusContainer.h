#pragma once
#include "User.h"

class StatusContainer
{
public:static User current_user;
};

User StatusContainer::current_user = User("unknown", "unknown");
