
#include "Inventory.h"
#include <string>
#include <iostream>


void Inventory::addProduct(int id, const std::string& name, int quantity) {
    products[name] += quantity;

}

void Inventory::useProduct(const std::string& name, int quantity) {
    if (products[name] >= quantity) {
        products[name] -= quantity;
    }
    else {
        
    }
}

int Inventory::getProductQuantity(const std::string& name) const {
    auto it = products.find(name);
    
    if (it != products.end()) {
        return it->second;
       
    } else {
        return 0;
    }
}
void Inventory::removeProduct(const std::string& name) {
    auto it = products.find(name);
    if (it != products.end()) {
        products.erase(it);
    }
    else {
        std::cerr << "Продукт не найден: " << name << std::endl;
    }
}

void Inventory::printAllProducts() const {
    
    for (const auto& product : products) {
        std::cout << "Продукт: " << product.first << ", Количество: " << product.second << std::endl;
    }
}
