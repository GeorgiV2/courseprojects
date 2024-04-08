#include "Item.cpp"
#include <iostream>

class Pizza : public Item {
private:
    char size;        // S, M, L
    bool hasTopping;  // true (YES) / false (NO)

public:
    // Constructor
    Pizza(int num, char sz, bool topping)
        : Item(num, 10.0), size(sz), hasTopping(topping) {}

    // Method to print pizza info (overrides Item's printInfo)
    void printInfo() const override {
        Item::printInfo();  // Call base class printInfo to display item details
        std::cout << "Size: " << size
                  << ", Topping: " << (hasTopping ? "YES" : "NO")
                  << std::endl;
    }

    // Additional cost for topping
    double additionalCost() const {
        return hasTopping ? 2.50 : 0.0;
    }
};