// CSC 134
// M1T1 (Module 1, Tutorial 1)
// Hello, world!

// magic words
#include <iostream>
using namespace std;

int main() {
    cout << "Hello CSC 134!" << endl; // E N D L
    cout << "How's it going?" << endl; 
    cout << endl; // another new line

    string name; // new box to hold name
    cout << "Whats's your name? ";
    cin >> name; // read in their answer
    
    cout << "Well hi, " << name << "!" << endl;
    


    return 0; // no errors
}