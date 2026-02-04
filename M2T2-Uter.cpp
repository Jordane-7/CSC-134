// CSC 134
// M1T2 - Recipt Calculator
// Jordane
// 1/26/2026

#include <iostream>
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

    //Get user input
    cout << "Welcome to the CSC 134 Grill." << endl;
    cout << "Today's special is the " << meal_name << " for $" << meal_price << "." << endl;
    cout << endl;
    cout << "How many meals would you like to order? ";
    cin >> num_meals;
    cout << endl;

    // Calculate totals
    sub_total = meal_price * num_meals;

  
    // Display receipt
    cout << "YOUR ORDER" << endl << "-------------------------" << endl;
    cout << "Subtotal: \t\t$" << sub_total << endl;

    return 0;





}