// CSC 134
// M5Lab1.h
// Jordane
// 3/25/2026


#ifndef M5LAB1_UterH
#define M5LAB1_UterH

#include <iostream>
#include <string>
using namespace std;


// Function for choice 1 outcome
void do_choice_1();
void do_choice_2();
void do_choice_3();
void do_choice_4();
int subChoice1, subChoice2, subChoice3, choice;




void do_choice_1() {
    cout << "\nYou slam the accelerator!" << endl;
    cout << "1. Push engine harder\n";
    cout << "2. Stay controlled\n";
    cout << "Enter choice: ";
    cin >> subChoice1;

    if (subChoice1 == 1) {
        cout << "Engine overheats and blows! You lose.\n";
    }
    else if (subChoice1 == 2) {
        cout << "Perfect control! You pass and WIN!\n";
    }
    else {
        cout << "Invalid choice.\n";
    }
}

void do_choice_2() {
    cout << "\nYou hit the nitro boost!" << endl;
    cout << "1. Full power\n";
    cout << "2. Use small bursts\n";
    cout << "Enter choice: ";
    cin >> subChoice2;

    if (subChoice2 == 1) {
        cout << "Too much power! Engine explodes. You lose.\n";
    }
    else if (subChoice2 == 2) {
        cout << "Smooth boost! You take first place and WIN!\n";
    }
    else {
        cout << "Invalid choice.\n";
    }
}

void do_choice_3() {
    cout << "\nYou drive aggressively!" << endl;
    cout << "1. Cut opponent off\n";
    cout << "2. Wait for opening\n";
    cout << "Enter choice: ";
    cin >> subChoice3;

    if (subChoice3 == 1) {
        cout << "You misjudge and crash! You lose.\n";
    }
    else if (subChoice3 == 2) {
        cout << "Smart move! You pass at the last second and WIN!\n";
    }
    else {
        cout << "Invalid choice.\n";
    }
}

void do_choice_4() {
    cout << "\nYou decide to play it safe." << endl;
    cout << "You finish in second place. Not bad!\n";
}

#endif