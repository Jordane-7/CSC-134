// CSC 134
// M4HWQ2
// Jordane
// 4/20/2026

#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int i = 1;

    while (i <= 12) {
        cout << number << " times " << i << " is " << number * i << "." << endl;
        i++;
    }

    return 0;
}