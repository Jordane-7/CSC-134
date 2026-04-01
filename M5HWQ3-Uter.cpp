// CSC 134
// M5HW1 Q3 - Gold
// Jordane
// 4/1/2026

#include <iostream>
using namespace std;

int main (){
    double choice;

    cout << "Please choose a number in the range of 1 and 10" << endl;
    cin >> choice;

    if (choice == 1){
        cout << "The Roman numeral version of " << choice << " is I" << endl;
    }
    else if (choice == 2){
        cout << "The Roman numeral version of " << choice << " is II" << endl;
    }
    else if (choice == 3){
        cout << "The Roman numeral version of " << choice << " is III" << endl;
    }
    else if (choice == 4){
        cout << "The Roman numeral version of " << choice << " is IV" << endl;
    }
    else if (choice == 5){
        cout << "The Roman numeral version of " << choice << " is V" << endl;
    }
    else if (choice == 6){
        cout << "The Roman numeral version of " << choice << " is VI" << endl;
    }
    else if (choice == 7){
        cout << "The Roman numeral version of " << choice << " is VII" << endl;
    }
    else if (choice == 8){
        cout << "The Roman numeral version of " << choice << " is VIII" << endl;
    }
    else if (choice == 9){
        cout << "The Roman numeral version of " << choice << " is IX" << endl;
    }
    else if (choice == 10){
        cout << "The Roman numeral version of " << choice << " is X" << endl;
    }
    else if (choice <= 1 || choice >= 10){
        cout << " Invlaid choice not in range";
    }
    return 0;
}