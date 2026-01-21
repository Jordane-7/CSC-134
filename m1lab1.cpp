// CSC 134
// M1LAB1 - selling items
// Jordane
// 1/21/2025

#include <iostream>
#include <iomanip> // for decimal places
using namespace std;

int main() {
    // declare vairables
    string item_name = "Burger";
    int item_count = 100;           // how many we have
    double item_cost = 2.53;        // price per item
    double total_cost;

    // Set to 2 decimal places - requires <iomanip>
    cout << setprecision(2) << fixed;

    // Do the work
    cout << "Welcome to the " << item_name << " store." << endl;
    cout << "We have " << item_count << " " << item_name << "s" << endl;
    cout << "They cost $" << item_cost << " each" << endl;

    // Total price
    total_cost = item_count * item_cost;

    cout << "To buy all of them it will cost $" << total_cost << endl;

    


    return 0;
}
