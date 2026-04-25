// CSC 134
// M4HWQ3
// Jordane
// 4/20/2026

#include <iostream>
using namespace std;

int main() {
    int number;

   
    cout << "Enter a number from 1 to 12: ";
    cin >> number;

    while (number < 1 || number > 12) {
        cout << "Invalid input. Please enter a number from 1 to 12: ";
        cin >> number;
    }


    int i = 1;
    while (i <= 12) {
        cout << number << " times " << i << " is " << number * i << "." << endl;
        i++;
    }

    return 0;
}