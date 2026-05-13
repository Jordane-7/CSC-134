// CSC 134
// M5Lab2 -
// Jordane
// 5/4/2025

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double length;    
    double width;     
    double area;   

    cout << "Enter the rectangle's length: ";
    cin >> length;

    cout << "Enter the rectangle's width: ";    
    cin >> width;

    area = length * width;
    cout << fixed << setprecision(2);

   cout << "\n-----------------------------" << endl;
    cout << "Rectangle Data Report" << endl;
    cout << "-----------------------------" << endl;
    
    // Kept your specific setw formatting
    cout << left << setw(15) << "Length:" << length << endl;
    cout << left << setw(15) << "Width:" << width << endl;
    cout << left << setw(15) << "Total Area:" << area << endl;
    cout << "-----------------------------" << endl;

    return 0;
}

    