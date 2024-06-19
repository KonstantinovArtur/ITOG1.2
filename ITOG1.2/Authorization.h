#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <string>
#include "User.h"

User* authorizeUser(const std::string& login, const std::string& password);

#endif 
