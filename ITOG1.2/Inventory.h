
#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <vector>
#include <string>

class Inventory {
public:
    void addProduct(int id, const std::string& name, int quantity);
    void useProduct(const std::string& name, int quantity);
    int getProductQuantity(const std::string& name) const;
    int getProductInfo1(const std::string& name) const;
    void removeProduct(const std::string& name);
    void printAllProducts() const;


    
    
private:
    std::map<std::string,   int> products;
};

#endif 