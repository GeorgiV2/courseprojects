#include <iostream>
#include <vector>
#include "Pizza.cpp"

int main() {
    // Create a vector to store Pizza objects
    std::vector<Pizza> pizzas;

    // Ask the user to input the number of pizzas
    int N;
    std::cout << "Enter number of pizzas (N <= 50): ";
    std::cin >> N;

    // Ensure N does not exceed 50
    if (N > 50) N = 50;

   // Loop to get details for each pizza
        for (int i = 0; i < N; ++i) {
            int num;
            char size;
            bool topping;

            // Get the pizza number
            std::cout << "Enter pizza number: ";
            std::cin >> num;

            // Get the size of the pizza (S/M/L)
            std::cout << "Choose size (S/M/L): ";
            std::cin >> size;

            // Ask if the pizza has a topping (1 for YES / 0 for NO)
            std::cout << "Does the pizza have topping? (1 for YES / 0 for NO): ";
            std::cin >> topping;

            // Create a Pizza object with fixed price (10 BGN) and user-provided details, then add it to the vector
            Pizza pizza(num, size, topping);
            // Add the created Pizza object to the vector of pizzas
            pizzas.push_back(pizza);
        }

       
    // Calculate and display the total order amount
    double total = 0.0;
    for (const auto& pizza : pizzas) {
        pizza.printInfo(); // Display pizza details
        total += pizza.getPrice() + pizza.additionalCost();
    }

    // Calculate VAT (20%)
    double vat = total * 0.20;

    // Display the total order amount including VAT
    std::cout << "Total Order Amount (including VAT): $" << std::fixed << std::setprecision(2) << total + vat << std::endl;

    return 0;
}
