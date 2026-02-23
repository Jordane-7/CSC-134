// CSC 134
// M3lab1 - Option game
// Jordane
// 2/23/2026

#include <iostream>
using namespace std;

void do_choice_1 ();
void do_choice_2 ();
void do_choice_3 ();
void do_choice_4 ();


int main() {
    int choice;

    cout << "You're currenlty second place in a drag race" << endl;
    cout << "Please choose an option (1, 2, or 3): ";
    cin >> choice;

    if (choice == 1) {
        do_choice_1();
    } else if (choice == 2) {
        do_choice_2();
    } else if (choice == 3) {
        do_choice_3();
    } else {
        cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
    }

    return 0;
}