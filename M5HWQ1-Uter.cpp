// CSC 134
// M5HW1 Q1 - Gold
// Jordane
// 4/1/2026

#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    string month_1, month_2, month_3;
    double rain_1, rain_2, rain_3, average;

    // Declare variables to store month names and rainfall amounts
    string month_1, month_2, month_3;
    double rain_1, rain_2, rain_3, average;

    // Display program title and instructions
    cout << "Welcome to the Rainfall Average Calculator!" << endl;
    cout << "Please enter the first month and the amount of rainfall in inches." << endl;

    // Get input for first month and rainfall
    cout << "Month: ";
    cin >> month_1; 
    cout << "Rainfall: ";
    cin >> rain_1;

    // Get input for second month and rainfall
    cout << "Month: ";
    cin >> month_2; 
    cout << "Rainfall: ";
    cin >> rain_2;

    // Get input for third month and rainfall
    cout << "Month: ";
    cin >> month_3; 
    cout << "Rainfall: ";
    cin >> rain_3;

    // Format output to show 2 decimal places
    cout << fixed << setprecision(2);

    // Calculate the average rainfall
    average = (rain_1 + rain_2 + rain_3) / 3;

    // Display the result
    cout << "Average rainfall for " << month_1 << ", " << month_2 << " and " << month_3 << " is " << average << " inches" << endl;

    return 0;
}