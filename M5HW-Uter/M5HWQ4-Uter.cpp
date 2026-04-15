// CSC 134
// M5HW1 Q4 - Gold
// Jordane
// 4/1/2026

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int choice;
    double radius, area_cir, area_rec, area_tri, length_rec, width_rec, base_tri, height_tri;
    const double PI = 3.14159;

    cout << "Geometry Calculator" << endl;
    cout << "1. Calculate the Area of a Circle" << endl;
    cout << "2. Calculate the Area of a Rectangle" << endl;
    cout << "3. Calculate the Area of a Triangle" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
    
    cin >> choice;

    if (choice == 1) {
        cout << "Please enter the radius of the circle: ";
        cin >> radius;

        if (radius < 0) {
            cout << "The radius cannot be less than zero." << endl;
        } else {
            area_cir = radius * radius * PI;
            cout << "The area of the circle is " << area_cir << endl;
        }
    }
    else if (choice == 2) {
        cout << "Please enter length of the rectangle: ";
        cin >> length_rec;
        cout << "Please enter width of the rectangle: ";
        cin >> width_rec;

        if (length_rec < 0 || width_rec < 0) {
            cout << "Only enter positive values for length and width." << endl;
        } else {
            area_rec = width_rec * length_rec;
            cout << "The area of the rectangle is " << area_rec << endl;
        }
    }
    else if (choice == 3) {
        cout << "Please enter length of the triangle's base: ";
        cin >> base_tri;
        cout << "Please enter the triangle's height: ";
        cin >> height_tri;

        if (base_tri < 0 || height_tri < 0) {
            cout << "Only enter positive values for base and height." << endl;
        } else {
            area_tri = base_tri * height_tri * 0.5;
            cout << "The area of the triangle is " << area_tri << endl;
        }
    }
    else if (choice == 4) {
        cout << "Program ending..." << endl;
    }
    else {
        cout << "The valid choices are 1 through 4. Run the program again and select one of those." << endl;
    }

    return 0;
}