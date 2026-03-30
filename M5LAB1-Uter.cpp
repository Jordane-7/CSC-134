// CSC 134
// M5Lab1
// Jordane
// 3/25/2026

#include <iostream>
#include "M5LAB1_Uter.H"
using namespace std;



int main() {
    int choice;
    cout << "\n--- Drag Race Menu ---\n";
    cout << "You're currently second place in a drag race!\n";
    cout << "1. Slam accelerator\n";
    cout << "2. Use nitro boost\n";
    cout << "3. Drive aggressively\n";
    cout << "4. Play it safe (Quit)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        do_choice_1();
    }
    else if (choice == 2) {
        do_choice_2();
    }
    else if (choice == 3) {
        do_choice_3();
    }
    else if (choice == 4) {
        do_choice_4();
    }
    else {
        cout << "Invalid choice. Please choose 1-4.\n";
    }

    return 0;
}