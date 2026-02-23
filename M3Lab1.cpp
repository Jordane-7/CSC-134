#include <iostream>   
using namespace std;  

// Function declarations (prototypes)
// These tell the compiler that these functions exist
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
    else {
        // If user enters something other than 1, 2, or 3
        cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
    }

    return 0;  // End the program successfully
}

// Function for choice 1 outcome
void do_choice_1() {
    cout << "You slam the accelerator to the floor!" << endl;
    cout << "The engine roars as your car surges forward." << endl;
    cout << "You blast past your rival and cross the finish line in FIRST place!" << endl;
}

// Function for choice 2 outcome
void do_choice_2() {
    cout << "You hit a massive shot of nitro!" << endl;
    cout << "The car launches forward at insane speed..." << endl;
    cout << "Suddenly, the engine overheats and explodes!" << endl;
    cout << "Smoke pours out as you roll to a stop. You're out of the race!" << endl;
}

// Function for choice 3 outcome
void do_choice_3() {
    cout << "You floor it aggressively, trying to catch up!" << endl;
    cout << "Your tires lose traction on the track!" << endl;
    cout << "The car spins out of control and crashes into the wall!" << endl;
    cout << "Race over. You lose." << endl;
}

// Function for choice 4 outcome (currently not used in main)
void do_choice_4() {
    cout << "You realize you have no chance of winning." << endl;
    cout << "You ease off the gas and slow down." << endl;
    cout << "You finish the race safely, but in second place." << endl;
}