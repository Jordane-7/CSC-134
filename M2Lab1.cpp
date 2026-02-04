/* 
CSC 134
M2Lab1 - The Crate Pogram
Jordane
1/28/2026

Find volume of crate
Find cost, customer_price, and profit
Print everything out
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables
    // Constant variables
    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;



    // Create Variables
    double length, width, height, volume; // all in feet
    // Money variables
    double cost, customer_price, profit; // all in dollars



    // Get Input
    cout << "Whelcome to the Crate Cost Calculator!" << endl;
    cout << "Enter the crate dimenions" << endl;
    cout << "Crate Length? ";
    cin >> length;
    cout << "Crate Width? ";
    cin >> width;
    cout << "Crate Height? ";
    cin >> height;

    // Calculations
    volume = length * width * height;
    // Cost and customer price
    cost = volume * COST_PER_CUBIC_FOOT;
    customer_price = volume * CHARGE_PER_CUBIC_FOOT;
    profit = customer_price - cost; 

    // Output
    cout << setprecision(2) << fixed << "\n";
    cout << "==== CRATE INFO ====" << endl;
    cout << "Volume is " << volume << " cubic feet." << endl;
    cout << "Wholesale price is $" << cost << endl;
    cout << "Customer price is $" << customer_price << endl;
    cout << "The total profit is $" << profit << endl;



    return 0;
}