#ifndef USER_H
#define USER_H

#include <string>

struct User {
    std::string login;
    std::string role;

    User(const std::string& l, const std::string& r) : login(l), role(r) {}
};

#endif 
