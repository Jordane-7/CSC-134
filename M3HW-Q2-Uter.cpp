// CSC 134
// M3HW1 - Gold
// Jordane Uter
// 3/2/2026


#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int main() {
    // Declare variables
    string meal_name = "Sushi Platter";
    int num_meals;
    double meal_price = 5.25;
    double sub_total;
    double tip_amount = 0;
    double tax_amount;
    double total_amount;

    // Get user input
    cout << "Welcome to the CSC 134 Grill." << endl;
    cout << "Today's special is the " << meal_name << " for $" << meal_price << "." << endl << endl;

    cout << "How many meals would you like to order? ";
    cin >> num_meals;
    cout << endl;

    cout << "Will you be dining in or taking out? (Enter 'dine' or 'takeout'): ";
    string dining_option;
    cin >> dining_option;
    cout << endl;

    // Calculate subtotal first
    sub_total = meal_price * num_meals;

    // Determine tip
    if (dining_option == "dine") {
        tip_amount = sub_total * 0.15;  // 15% tip for dine-in
    }
    else if (dining_option == "takeout") {
        cout << "How much would you like to tip? $";
        cin >> tip_amount;
    }
    else {
        cout << "Invalid option, assuming dining in." << endl;
        tip_amount = sub_total * 0.15;
    }

    // Calculate tax and total
    tax_amount = sub_total * 0.07; // assuming 7% sales tax
    total_amount = sub_total + tip_amount + tax_amount;

    // Display receipt
    cout << "\nYOUR ORDER" << endl;
    cout << "-------------------------" << endl;
    cout << "Subtotal: \t$" << sub_total << endl;
    cout << "Tip: \t\t$" << tip_amount << endl;
    cout << "Tax: \t\t$" << tax_amount << endl;
    cout << "Total: \t\t$" << total_amount << endl;

    return 0;
}

   
    

