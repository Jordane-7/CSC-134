// CSC 134
// M5HW1 Q5 - Gold
// Jordane
// 4/1/2026

#include <iostream>
#include <iomanip> 
using namespace std;

int main () {

    double distance, speed, hours;

    cout << "Please enter speed you traveld in mph: ";
    cin >> speed;

    if (speed < 0) {
        cout << "Error: Speed cannot be negative." << endl;
        return 0;
    }

    cout << "Please total hours of travel: ";
    cin >> hours;

    if (hours < 1) {
        cout << "Error: Time traveled must be at least 1 hour." << endl;
        return 0; 
    }


    cout << "\nHour   Distance Traveled" << endl;
    cout << "--------------------------------" << endl;


    for (int i = 1; i <= hours; i++) {
        double distance = speed * i;
        
        cout << left << setw(10) << i << distance << endl;
    }

 

    return 0;
}