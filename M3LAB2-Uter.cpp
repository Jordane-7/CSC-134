// CSC 134
// M3LAB2
// Jordane Uter
// 3/4/2026


#include <iostream>
using namespace std;

int main (){
    int grade;
    string letter;


    cout << "What was your quiz grade? " << endl;
    cin >> grade;

    if (grade > 90 || grade < 100){
    letter = "A";
    cout << "Your letter grade is: " << letter << endl;
    }
    else if (grade > 80 || grade < 89) { 
    letter = "B";
    cout << "Your letter grade is: " << letter << endl;
    }
    else if (grade > 70 || grade < 79) { 
    letter = "C";
    cout << "Your letter grade is: " << letter << endl;
    }
    else if (grade > 60 || grade < 69) { 
    letter = "D";
    cout << "Your letter grade is: " << letter << endl;
    }
    else if (grade > 0 || grade < 59) { 
    letter = "F";
    cout << "Your letter grade is: " << letter << endl;
    }



    return 0;
}