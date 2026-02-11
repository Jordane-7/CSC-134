// CSC 134
// M3T1
// Jordane
// 2/11/2026

#include <iostream>
using namespace std;

int main (){
    // As a user, I want to measure rectangles to find out how big they are.

    // et up variables
    double length1, width1, area1;
    double length2, width2, area2;

    //Ask user for info 
    cout << "What is the first rectangle's length? ";
    cin >> length1;
    cout << "What is the width? ";
    cin >> width1;

    cout << "What is the second reactangle's length? ";
    cin >> length2;
    cout << "What is the width? ";
    cin >> width2;
    
    // Calculation
    area1 = length1 * width1;
    area2 = length2 * width2;
    
    // Print answer
    cout << "Rectabgle #1: " << length1 << " by " << width1 << " is area: " << area1 << endl;
    cout << "Rectabgle #2: " << length2 << " by " << width2 << " is area: " << area2 << endl;

    // Which one is larger?
    if (area1 > area2) {
        cout << "The first rectangle is bigger. " << endl;
    }
    if (area2 > area1) {
        cout << "The second rectangle is bigger. " << endl;
    }
    if (area1 == area2) {
        cout << "The are the same size. " << endl;
    }

 return 0;
}