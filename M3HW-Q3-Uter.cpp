// CSC 134
// M3HW1 - Gold
// Jordane Uter
// 3/2/2026


#include <iostream>
using namespace std;

int main () {
    int choice, choice1, choice2;

    cout << " Hello and Welcome to the Dragon Adventure! " << endl;
    cout << " While hikinh you spot a myterious looking cave. Do you: " << endl;
    cout << " 1. Enter the cave " << endl;
    cout << " 2. Walk past the cave " << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice ==1){
        cout << "\nYou bravely enter the cave..." << endl;
        cout << "Inside, you see a sleeping dragon guarding treasure." << endl;
        cout << "Do you:" << endl;
        cout << "1. Try to steal the treasure" << endl;
        cout << "2. Sneak past the dragon quietly" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice2;
        if (choice2 == 1) {
            cout << "\nThe dragon wakes up and burns you with fire!" << endl;
            cout << "Defeat! Game Over." << endl;
        } 
        else if (choice2 == 2) {
            cout << "\nYou successfully sneak past the dragon and escape with treasure!" << endl;
            cout << "Victory! You win!" << endl;
        } 
        else {
            cout << "\nInvalid choice. The dragon wakes up while you hesitate." << endl;
            cout << "Defeat! Game Over." << endl;
        }
    } 
    else if (choice1 == 2) {
        cout << "\nYou run away safely... but trip over a rock." << endl;
        cout << "Game Over. Maybe next time you'll be braver!" << endl;
    } 
    else {
        cout << "\nInvalid choice. The cave collapses while you stand there confused." << endl;
        cout << "Game Over." << endl;

    }
    return 0;
}