// CSC 134
// M5HW1 Q2 - Gold
// Jordane
// 4/1/2026

#include <iostream>
using namespace std;

int main () {
    double width, length, height;

    cout << "Hello welcome to the Hyperrectangle volume claculator." << endl;
    cout << "Please enter the width, length and height of your block. " << endl;

    cout << "Width: ";
    cin >> width; 

    cout << "Length: ";
    cin >> length;

    cout << "Height: ";
    cin >> height; 
    
       // Check if any value is less than or equal to 0
    if (width <= 0 || length <= 0 || height <= 0) {
        cout << "Invalid entry. All sides should be more than zero." << endl;
    } else {
        // Calculate volume if inputs are valid
        double volume = width * length * height;
        cout << "The volume is: " << volume << endl;
    }

return 0;
}