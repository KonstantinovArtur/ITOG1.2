#include "Authorization.h"


User* authorizeUser(const std::string& login, const std::string& password) {
    if (login == "Povar" && password == "222") {
        return new User("Povar", "Повар");
    }
    else if (login == "Admin" && password == "111") {
        return new User("Admin", "Администратор");
    }
    else if (login == "Oficiant" && password == "333") {
        return new User("Oficiant", "Официант");
    }
    else if (login == "" && password == "333") {
        return new User("Oficiant", "Официанта");
    }
    return nullptr;
}