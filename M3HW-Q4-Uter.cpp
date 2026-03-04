// CSC 134
// M3HW1 - Gold
// Jordane Uter
// 3/2/2026


#include <iostream>
using namespace std;
#include <cstdlib> 
#include <ctime>

int roll();

int main (){

    int first_num, sec_num, answer, userans;

    int seed = time(0);
    srand(seed);

    first_num = roll();
    sec_num = roll ();
    answer = first_num + sec_num;
    
    cout << "What is " << first_num << " + " << sec_num << " ?" << endl;
    cin >> userans;

    if (userans == answer) {
        cout << "\nThat is correct!" << endl; 
    }
    else if (userans != answer) {
     cout << "\nThat is incorrect!" << endl; 
    }

    return 0;

}

int roll() {
    return rand() % 6 + 1;
}