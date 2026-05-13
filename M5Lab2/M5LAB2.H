#include <iostream>
#include <iomanip>
#ifndef M5LAB2_H_INCLUDED
#define M5LAB2_H_INCLUDED

using namespace std;

double length;
double width;
double area;


int main() {
    double length;
    double width;
    double area;

    cout << "Enter the rectangle's length: ";
    cin >> length;

    cout << "Enter the rectangle's width: ";
    cin >> width;

    area = length * width;

    displayReport();
    return 0;
}

#endif // M5LAB2_H_INCLUDED