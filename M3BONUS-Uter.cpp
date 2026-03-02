// CSC 134
// M3 Bonus - AI-Assisted Game Development Explorer
// Jordane
// 3/2/2026

#include <iostream>
using namespace std;

int monster_health;  // Global variable to track monster's health
int player_health = 100;   // Global variable to track player's health
int player_attack = 20;   // Global variable for player's attack strength

void battle ();
void run_away ();


int choice;  // Variable to store the user's menu choice

    // Display introduction message
    cout << "You've stumble uppon two monsters!" << endl;

    // Ask the user to choose an option
    cout << "The first is a and has a health bar of 100 and the second is a and has health level of 60.\nWhich one do you want to fight? (1 or 2): ";
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


    return 0;  
}