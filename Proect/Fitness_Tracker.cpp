// CSC 134
// M7T1 - restaurant reviews
// Jordane
// 5/13/2025

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// --- Data Structures ---
struct UserProfile {
    string name;
    double weight;
    double height;
    char unitType; // 'M' for Metric, 'I' for Imperial
};

struct Exercise {
    string name;
    int sets;
    int reps;
    double weightUsed;
    double totalTonnage;
};

// --- Function Prototypes ---
UserProfile initProfile();
void displayDashboard(UserProfile user);
Exercise getExerciseInput(char unitType);
void displaySessionSummary(const vector<Exercise>& session);

int main() {
    UserProfile myProfile = initProfile();
    vector<Exercise> sessionWorkouts;
    char choice;

    displayDashboard(myProfile);

    // Main Workout Loop
    do {
        Exercise newEntry = getExerciseInput(myProfile.unitType);
        sessionWorkouts.push_back(newEntry);

        cout << "\nAdd another exercise? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clear the buffer for the next string input
    } while (choice == 'y' || choice == 'Y');

    // Show the results of the session
    displaySessionSummary(sessionWorkouts);

    return 0;
}

// --- Function Definitions ---

UserProfile initProfile() {
    UserProfile u;
    cout << "--- Welcome to the Fitness Tracker ---" << endl;
    cout << "Enter your name: ";
    getline(cin, u.name);

    cout << "Choose units - (M)etric or (I)mperial: ";
    cin >> u.unitType;
    u.unitType = toupper(u.unitType);

    if (u.unitType == 'M') {
        cout << "Enter body weight (kg): "; cin >> u.weight;
        cout << "Enter height (cm): "; cin >> u.height;
    } else {
        cout << "Enter body weight (lbs): "; cin >> u.weight;
        cout << "Enter height (inches): "; cin >> u.height;
    }
    cin.ignore(); 
    return u;
}

Exercise getExerciseInput(char unitType) {
    Exercise e;
    string unitLabel = (unitType == 'M') ? "kg" : "lbs";

    cout << "\n--- Log New Exercise ---" << endl;
    cout << "Exercise Name: ";
    getline(cin, e.name);
    
    cout << "Sets: "; cin >> e.sets;
    cout << "Reps: "; cin >> e.reps;
    cout << "Weight used (" << unitLabel << "): "; cin >> e.weightUsed;

    // A-Tier Logic: Calculate Tonnage
    e.totalTonnage = e.sets * e.reps * e.weightUsed;

    return e;
}

void displaySessionSummary(const vector<Exercise>& session) {
    double grandTotalTonnage = 0;

    cout << "\n===============================" << endl;
    cout << "       SESSION SUMMARY         " << endl;
    cout << "===============================" << endl;
    cout << left << setw(15) << "Exercise" << setw(10) << "Volume" << "Tonnage" << endl;
    cout << "-------------------------------" << endl;

    for (const auto& e : session) {
        cout << left << setw(15) << e.name 
             << e.sets << "x" << setw(7) << e.reps 
             << fixed << setprecision(1) << e.totalTonnage << endl;
        grandTotalTonnage += e.totalTonnage;
    }

    cout << "-------------------------------" << endl;
    cout << "Total Session Tonnage: " << grandTotalTonnage << endl;
    cout << "===============================" << endl;
}

void displayDashboard(UserProfile user) {
    string wUnit = (user.unitType == 'M') ? "kg" : "lbs";
    string hUnit = (user.unitType == 'M') ? "cm" : "in";
    cout << "\nHello, " << user.name << "! Your current stats: " 
         << user.weight << wUnit << " / " << user.height << hUnit << endl;
}