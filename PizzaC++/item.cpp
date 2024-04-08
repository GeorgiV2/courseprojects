#include <iostream>
#include <iomanip>

class Item {
private:
    int itemNumber;
    double price;

public:
    // Constructor
    Item(int num, double p) : itemNumber(num), price(p) {}

    // Destructor
    ~Item() {}

    // Access methods
    int getItemNumber() const { return itemNumber; }
    double getPrice() const { return price; }

    // Method to print item info
    virtual void printInfo() const {
        std::cout << "Pizza Number: " << itemNumber 
                  << ", Price: 10.00 BGN" 
                  << std::endl;
    }
};
