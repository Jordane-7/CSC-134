// CSC 134
// M5HW1 Q5 - Gold
// Jordane
// 4/1/2026

#include <iostream>
#include <iomanip> 
using namespace std;

int main(){
    void rainfallCalculator();
    void volumeCalculator();
    void romanNum();
    void geometryCalculator();
    void distanceTracker();

    int choice;

    cout << "\n================================" << endl;
    cout << "         MAIN MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Rainfall Calculator" << endl;
    cout << "2. Volume Calculator" << endl;
    cout << "3. Roman Numeral Converter" << endl;
    cout << "4. Geometry Calculator" << endl;
    cout << "5. Distance Tracker" << endl;
    cout << "6. Exit Program" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

        if (choice == 1){
            void rainfallCalculator();
        }
         if (choice == 2){
            void volumeCalculator();
        }
         if (choice == 3){
            void rainfallCalculator();
        }
         if (choice == 4){
            void romanNum();
        }
         if (choice == 5){
            void geometryCalculator();
        }
        else if (choice == 6) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Error: The valid choices are 1 through 6." << endl;

        }
    
}