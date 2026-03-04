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

    int first_num, sec_num, answer;

    int seed = time(0);
    srand(seed);

    first_num = roll();
    answer = first_num + sec_num;
    sec_num = roll ();
    cout << "What is " << first_num << " + " << sec_num << " ?" << endl;
    cin >> answer;

    if ( answer == answer) {
        cout << "\nThat is correct!" << endl; 
    }


    return 0;

}

int roll() {
    return rand() % 30 + 1;
}