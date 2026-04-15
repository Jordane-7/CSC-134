// CSC 134
// M1T2 - Recipt Calculator
// Jordane
// 1/26/2026

#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    // Declare variables
    string meal_name = "Sushi Platter";
    int num_meals;
    double meal_price = 5.25;  
    double sub_total;             
    double tip_amount;
    double tax_amount;
    double total_amount;

    double tax_rate = 0.08;
    double tip_rate = 0.15;

    // Get user input
    cout << "Welcome to the CSC 134 Grill." << endl;
    cout << "Today's special is the " << meal_name << " for $" << meal_price << "." << endl;
    cout << endl;
    cout << "How many meals would you like to order? ";
    cin >> num_meals;
    cout << endl;

    // Calculate totals
    sub_total = meal_price * num_meals;
    tax_amount = sub_total * tax_rate;
    tip_amount = sub_total * tip_rate;
    total_amount = sub_total + tax_amount + tip_amount;

    // Format to 2 decimal places
    cout << fixed << setprecision(2);

    // Display receipt
    cout << "YOUR ORDER" << endl << "-------------------------" << endl;
    cout << "Subtotal:\t\t$" << sub_total << endl;
    cout << "Tax (8%):\t\t$" << tax_amount << endl;
    cout << "Tip (15%):\t\t$" << tip_amount << endl;
    cout << "Total:\t\t\t$" << total_amount << endl;

    return 0;

}