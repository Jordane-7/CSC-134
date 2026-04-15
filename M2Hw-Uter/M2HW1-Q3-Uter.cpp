// CSC 134
// M2HW1 - Gold
// Jordane
// 2/14/2026

#include <iostream>
using namespace std;

int main (){

    //INPUTS
    double NumPizza, SlicePizza, TotalVisitors, SliceLeft;
    cout << "How many pizzas are there? ";
    cin >> NumPizza;
    cout << "How many slices are in each pizza? ";
    cin >> SlicePizza;
    cout << "How many visitors are there? ";
    cin >> TotalVisitors;
   
    //CALCULATIONS
    SliceLeft = (NumPizza * SlicePizza) - (TotalVisitors * 3);   


    //OUTPUT
    cout << "\nThere are " << SliceLeft << " slices of pizza left over." << endl;
    return 0;
}