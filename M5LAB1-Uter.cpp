// CSC 134
// M5Lab1
// Jordane
// 3/25/2026

#include <iostream>
#include "M5LAB1_Uter.h"
using namespace std;

// Function prototypes
void do_choice_1();
void do_choice_2();
void do_choice_3();
void do_choice_4();

int main() {
    int choice;  // Variable to store the user's menu choice

    // Display introduction message
    cout << "You're currently second place in a drag race" << endl;

    // Ask the user to choose an option
    cout << "Please choose an option (1, 2, or 3): ";
    cin >> choice;  // Get user input

    // Check which option the user selected
    if (choice == 1) {
        do_choice_1();  // Call function for choice 1
    } 
    else if (choice == 2) {
        do_choice_2();  // Call function for choice 2
    } 
    else if (choice == 3) {
        do_choice_3();  // Call function for choice 3
    } 
    else if (choice == 4) {
        do_choice_4();  // Call function for choice 4
    }
    else {
        // If user enters something other than 1, 2, 3, or 4
        cout << "Invalid choice. Please choose 1, 2, 3, or 4." << endl;
    }


    return 0;  // End the program successfully
}