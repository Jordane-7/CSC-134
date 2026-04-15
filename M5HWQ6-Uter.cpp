// CSC 134
// M5HW1 Q5 - Gold
// Jordane
// 4/1/2026


#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

// --- Function Prototypes ---
void rainfallCalculator();
void volumeCalculator();
void romanNum();
void geometryCalculator();
void distanceTracker();

int main() {
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

        if (choice == 1) {
            rainfallCalculator();
        }
        else if (choice == 2) {
            volumeCalculator();
        }
        else if (choice == 3) {
            romanNum();
        }
        else if (choice == 4) {
            geometryCalculator();
        }
        else if (choice == 5) {
            distanceTracker();
        }
        else if (choice == 6) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Error: The valid choices are 1 through 6." << endl;
        }

    return 0;
}

// --- Function Definitions ---

void rainfallCalculator() {
    string month_1, month_2, month_3;
    double rain_1, rain_2, rain_3, average;

    cout << "\nWelcome to the Rainfall Average Calculator!" << endl;
    cout << "Month 1: "; cin >> month_1; 
    cout << "Rainfall 1: "; cin >> rain_1;
    cout << "Month 2: "; cin >> month_2; 
    cout << "Rainfall 2: "; cin >> rain_2;
    cout << "Month 3: "; cin >> month_3; 
    cout << "Rainfall 3: "; cin >> rain_3;

    average = (rain_1 + rain_2 + rain_3) / 3.0;
    cout << fixed << setprecision(2);
    cout << "Average rainfall for " << month_1 << ", " << month_2 << " and " << month_3 << " is " << average << " inches" << endl;
}

void volumeCalculator() {
    double width, length, height;
    cout << "\nHyperrectangle Volume Calculator" << endl;
    cout << "Width: "; cin >> width; 
    cout << "Length: "; cin >> length;
    cout << "Height: "; cin >> height; 
    
    if (width <= 0 || length <= 0 || height <= 0) {
        cout << "Invalid entry. All sides should be more than zero." << endl;
    } else {
        cout << "The volume is: " << (width * length * height) << endl;
    }
}

void romanNum() {
    int num; // Changed to int for better comparison
    cout << "\nEnter a number (1-10): ";
    cin >> num;

    if (num == 1) cout << "I" << endl;
    else if (num == 2) cout << "II" << endl;
    else if (num == 3) cout << "III" << endl;
    else if (num == 4) cout << "IV" << endl;
    else if (num == 5) cout << "V" << endl;
    else if (num == 6) cout << "VI" << endl;
    else if (num == 7) cout << "VII" << endl;
    else if (num == 8) cout << "VIII" << endl;
    else if (num == 9) cout << "IX" << endl;
    else if (num == 10) cout << "X" << endl;
    else cout << "Invalid choice, not in range." << endl;
}

void geometryCalculator() {
    int geoChoice;
    const double PI = 3.14159;
    cout << "\n1. Circle\n2. Rectangle\n3. Triangle\nEnter: ";
    cin >> geoChoice;

    if (geoChoice == 1) {
        double r; cout << "Radius: "; cin >> r;
        if (r < 0) cout << "Cannot be negative." << endl;
        else cout << "Area: " << (PI * r * r) << endl;
    } 
    else if (geoChoice == 2) {
        double l, w; cout << "L & W: "; cin >> l >> w;
        if (l < 0 || w < 0) cout << "No negatives." << endl;
        else cout << "Area: " << (l * w) << endl;
    }
    else if (geoChoice == 3) {
        double b, h; cout << "B & H: "; cin >> b >> h;
        if (b < 0 || h < 0) cout << "No negatives." << endl;
        else cout << "Area: " << (b * h * 0.5) << endl;
    }
}

void distanceTracker() {
    double speed;
    int hours;
    cout << "\nSpeed (mph): "; cin >> speed;
    if (speed < 0) { cout << "No negatives." << endl; return; }

    cout << "Hours: "; cin >> hours;
    if (hours < 1) { cout << "Must be >= 1." << endl; return; }

    cout << "\nHour   Distance" << endl;
    cout << "---------------" << endl;
    for (int i = 1; i <= hours; i++) {
        cout << left << setw(7) << i << (speed * i) << endl;
    }
}