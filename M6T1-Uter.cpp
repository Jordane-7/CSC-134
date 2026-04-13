// CSC 134
// M6T1
// Jordane
// 4/13/2026


#include <iostream>
using namespace std;

int main (){

    //set variables 
    const int SIZE = 5; // chaning this is the only way to resize array
    int cars [SIZE];
    double sum = 0;
    double average;
    
    cout << "This progrma will ask yiu to eneter a count of cars seen." << endl;

    // first loop: get data
    for (int i=0; i<SIZE; i++) {
        cout << "Day" << i+1 << ": ";
        cin >> cars[i];
    }

    // second loop: sum and average

    for (int i=0; i<SIZE; i++){
        sum += cars[i]; // add that days cars
    }
    average = sum / SIZE;
    cout << "Over " << SIZE << " days," << endl;
    cout << "Total cars: " << sum << endl;
    cout << "Average: " << average << endl;
}