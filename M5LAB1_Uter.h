// CSC 134
// M5Lab1.h
// Jordane
// 3/25/2026


#ifndef M5LAB1_Uter.H
#define M5LAB1_Uter.H

#include <iostream>
#include <string>
using namespace std;


// Function for choice 1 outcome
void do_choice_1() {
    cout << "\nYou slam the accelerator to the floor!" << endl;
    cout << "The engine roars as your car surges forward." << endl;
    cout << "You blast past your rival and cross the finish line in FIRST place!\n" << endl;
}

// Function for choice 2 outcome
void do_choice_2() {
    cout << "\nYou hit a massive shot of nitro!" << endl;
    cout << "The car launches forward at insane speed..." << endl;
    cout << "Suddenly, the engine overheats and explodes!" << endl;
    cout << "Smoke pours out as you roll to a stop. You're out of the race!\n" << endl;
}

// Function for choice 3 outcome
void do_choice_3() {
    cout << "\nYou floor it aggressively, trying to catch up!" << endl;
    cout << "Your tires lose traction on the track!" << endl;
    cout << "The car spins out of control and crashes into the wall!" << endl;
    cout << "Race over. You lose.\n" << endl;
}

// Function for choice 4 outcome (currently not used in main)
void do_choice_4() {
    cout << "\nYou realize you have no chance of winning." << endl;
    cout << "You ease off the gas and slow down." << endl;
    cout << "You finish the race safely, but in second place.\n" << endl;
}

#endif