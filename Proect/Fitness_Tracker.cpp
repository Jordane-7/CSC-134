#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>

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
    double totalWeightLifted;
};

// --- Function Prototypes ---
UserProfile initProfile();
void saveProfile(UserProfile u);
bool loadProfile(UserProfile &u);
void displayDashboard(UserProfile user);
double calculateBMI(UserProfile user);
Exercise getExerciseInput(char unitType);
void displaySessionSummary(const vector<Exercise>& session);
void saveSessionToHistory(double total);

int main() {
    UserProfile myProfile;
    vector<Exercise> sessionWorkouts;
    char choice;

    // Phase 1: Profile Loading/Setup
    if (!loadProfile(myProfile)) {
        myProfile = initProfile();
        saveProfile(myProfile);
    }

    displayDashboard(myProfile);

    // Phase 2: Workout Logging Loop
    cout << "\n--- Start Your Workout Session ---" << endl;
    do {
        Exercise newEntry = getExerciseInput(myProfile.unitType);
        sessionWorkouts.push_back(newEntry);

        cout << "\nAdd another exercise? (y/n): ";
        cin >> choice;
        cin.ignore(); // Clean buffer for next string input
    } while (choice == 'y' || choice == 'Y');

    // Phase 3: Results and Persistence
    displaySessionSummary(sessionWorkouts);

    double sessionTotal = 0;
    for (const auto& e : sessionWorkouts) {
        sessionTotal += e.totalWeightLifted;
    }
    
    saveSessionToHistory(sessionTotal);

    cout << "\nProgram complete. Great work today!" << endl;
    return 0;
}

// --- Function Definitions ---

UserProfile initProfile() {
    UserProfile u;
    cout << "--- Fitness Tracker: First Time Setup ---" << endl;
    cout << "Enter your name: ";
    getline(cin, u.name);

    cout << "Choose units - (M)etric [kg/cm] or (I)mperial [lb/in]: ";
    cin >> u.unitType;
    u.unitType = toupper(u.unitType);

    if (u.unitType == 'M') {
        cout << "Enter weight (kg): "; cin >> u.weight;
        cout << "Enter height (cm): "; cin >> u.height;
    } else {
        cout << "Enter weight (lbs): "; cin >> u.weight;
        cout << "Enter height (inches): "; cin >> u.height;
    }
    cin.ignore(); 
    return u;
}

void saveProfile(UserProfile u) {
    ofstream outFile("profile.txt");
    if (outFile) {
        outFile << u.name << endl;
        outFile << u.unitType << endl;
        outFile << u.weight << endl;
        outFile << u.height << endl;
        outFile.close();
        cout << "[System: Profile Saved]" << endl;
    }
}

bool loadProfile(UserProfile &u) {
    ifstream inFile("profile.txt");
    if (!inFile) return false;

    getline(inFile, u.name);
    inFile >> u.unitType;
    inFile >> u.weight;
    inFile >> u.height;
    inFile.close();
    return true;
}

double calculateBMI(UserProfile user) {
    if (user.unitType == 'M') {
        double heightInMeters = user.height / 100.0;
        return user.weight / (heightInMeters * heightInMeters);
    } else {
        return (user.weight / (user.height * user.height)) * 703.0;
    }
}

void displayDashboard(UserProfile user) {
    double bmi = calculateBMI(user);
    string wUnit = (user.unitType == 'M') ? "kg" : "lbs";
    
    cout << "\n===============================" << endl;
    cout << "       USER DASHBOARD          " << endl;
    cout << "===============================" << endl;
    cout << "User:   " << user.name << endl;
    cout << "Stats:  " << user.weight << wUnit << " / BMI: " << fixed << setprecision(1) << bmi << endl;
    cout << "Status: ";
    if (bmi < 18.5) cout << "Underweight";
    else if (bmi < 25) cout << "Healthy weight";
    else if (bmi < 30) cout << "Overweight";
    else cout << "Obese";
    cout << "\n===============================" << endl;
}

Exercise getExerciseInput(char unitType) {
    Exercise e;
    string unitLabel = (unitType == 'M') ? "kg" : "lbs";

    cout << "\n--- Log Exercise ---" << endl;
    cout << "Name: "; getline(cin, e.name);
    cout << "Sets: "; cin >> e.sets;
    cout << "Reps: "; cin >> e.reps;
    cout << "Weight (" << unitLabel << "): "; cin >> e.weightUsed;

    e.totalWeightLifted = e.sets * e.reps * e.weightUsed;
    return e;
}

void displaySessionSummary(const vector<Exercise>& session) {
    double grandTotal = 0;

    cout << "\n===============================" << endl;
    cout << "       SESSION SUMMARY         " << endl;
    cout << "===============================" << endl;
    cout << left << setw(15) << "Exercise" << setw(10) << "Sets/Reps" << "Total Weight" << endl;
    cout << "-------------------------------" << endl;

    for (const auto& e : session) {
        cout << left << setw(15) << e.name 
             << e.sets << " x " << setw(6) << e.reps 
             << fixed << setprecision(1) << e.totalWeightLifted << endl;
        grandTotal += e.totalWeightLifted;
    }

    cout << "-------------------------------" << endl;
    cout << "Grand Total Weight Lifted: " << grandTotal << endl;
    cout << "===============================" << endl;
}

void saveSessionToHistory(double total) {
    ofstream outFile("workout_history.txt", ios::app); 
    if (outFile) {
        outFile << "Session Total: " << fixed << setprecision(1) << total << endl;
        outFile.close();
        cout << "[System: Workout logged to workout_history.txt]" << endl;
    }
}
