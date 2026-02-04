// CSC 134
// M1LAB1 - selling items
// Jordane
// 2/2/2026

#include <iostream>
#include <iomanip> // for decimal places
using namespace std;

int main() {
    // declare vairables
    string name;
    string numBurger;          // how many we have
    double pricePerBurger;        // price per item
    double total_cost;

    // Set to 2 decimal places - requires <iomanip>
    cout << setprecision(2) << fixed;

    // Do the work
    cout << "What is your name? " << endl;
    cin >> name;
    cout << "How many burgers are for sale? " << endl;
    cin >> numBurger;
    cout << "How much per burger? " << endl;
    cin >> pricePerBurger;


    cout << "Welcome to " << name << "'s " << " burger store." << endl;
    cout << "We have " << numBurger << " burgersin stock." << endl;
    cout << "Each burger costs $" << pricePerBurger << endl;

    // Total price
    total_cost = stod(numBurger) * pricePerBurger;

    cout << "To buy all of them it will cost $" << total_cost << endl;

    


    return 0;
}
