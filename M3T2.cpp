// CSC 134
// M3T2
// Jordane
// 2/18/2026


#include <iostream>
#include <cstdlib> // for random
#include <ctime>    // for time
using namespace std;

// Function declarations
// (Tell the program what functions will be!)
int roll();

// main() goes here
int main() {
    // Seed the random number generator
    int seed = time(0);
    srand(seed);

    // Roll two dice and show the results
    int first, second, total;
    first = roll();
    second = roll();
    total = first + second;
    cout << "You rolled 🎲 " << first << " + " << second << " = " << total << endl;
    
    return 0;
}

// Function definitions
// (Actually write the ENTIRE function!)
int roll() {
    // rand() gives a large random number
    // % 6 divides by six, and keeps the remainder
    // finally, add 1 so it's 1 to 6, not zero to five
    int my_roll = (rand() % 6) + 1;
    return my_roll; 
}