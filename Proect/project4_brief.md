# Design Document — Project 4

**Name:** Jordane Uter
**Track:** A  
**Project Title:** Fitness & Goal Tracker  
**One-sentence pitch:** A terminal application that calculates health stats (BMI) and logs workout sessions to track total weight lifted over time.

---

## 1. The Problem

Lifters and fitness enthusiasts often have difficulty calculating their "total volume" (Total Weight Lifted) across different exercises in a single session. This program provides a quick, user-friendly way to log sets, reps, and weights while providing a health dashboard that adapts to the user's preferred unit system (Metric or Imperial).

---

## 2. State Inventory

| Data | Type | What Changes It |
|---|---|---|
| User Name | string | Initial user input |
| Body Weight | double | Initial user input |
| Height | double | Initial user input |
| Unit System | char | Selection between Metric (M) or Imperial (I) |
| Workout List | vector<Exercise> | Adding new exercises during the logging loop |
| Total Weight Lifted | double | Calculated as (Sets * Reps * Weight) |

---

## 3. Function / Component Map

| Function or Component | What It Does | Inputs | Outputs |
|---|---|---|---|
| initProfile() | Prompts user for name, height, weight, and units | none | UserProfile struct |
| displayDashboard() | Displays user info and calculated BMI status | UserProfile | none |
| calculateBMI() | Computes BMI based on Metric or Imperial formulas | UserProfile | double (BMI) |
| getExerciseInput() | Handles prompts for specific exercise data | char (units) | Exercise struct |
| displaySessionSummary()| Prints a formatted table of all session lifts | vector<Exercise>| none |
| saveSessionToHistory() | Appends the session grand total to a log file | double | none |

---

## 4. User Flow

**Main path:**

1. User runs the program and enters their personal profile data (Name, Height, Weight).
2. The program displays a "Dashboard" showing their current stats and BMI classification.
3. The user enters a loop where they input the name, sets, reps, and weight for an exercise.
4. After each exercise, the user chooses whether to add another or finish.
5. Once finished, a summary table shows each lift and a "Grand Total" for the session.
6. The session total is automatically saved to `workout_history.txt`.

**Key branches:**

- **Metric vs. Imperial:** If the user picks 'M', they enter kg/cm; if 'I', they enter lbs/in.
- **Input Loop:** If the user enters 'y', the loop restarts; if 'n', the summary prints.
- **File Persistence:** If `workout_history.txt` doesn't exist, the system creates it automatically.

---

## 5. What Could Go Wrong

| Risk | Plan |
|---|---|
| User enters text for a numeric field (Weight/Reps) | Use cin.clear() and cin.ignore() to manage the input buffer |
| Mixing cin and getline causes skipped inputs | Explicitly use cin.ignore() after numeric reads before calling getline |
| Negative numbers entered for stats | Logic check: calculate volume as 0 or ignore negative inputs |

---

## 6. What I'll Ask AI to Help With

| Task | Why AI Help Makes Sense |
|---|---|
| Formatting the Output Table | Using <iomanip> flags like setw and left is easier to iterate with AI guidance |
| BMI Formula Conversions | Ensuring the math for the Imperial constant (703.0) and Metric conversions is accurate |

---

## 7. What I'll Do Myself (No AI)

1. **The Logic Flow:** Designing the order in which functions are called in main.
2. **Data Modeling:** Deciding which variables belong in the UserProfile vs. the Exercise struct.

---

## 8. Scope Check

- Can I build the C-tier version in one focused work session? **yes**
- Does every feature in my plan connect to the core interaction? **yes**
- Have I cut anything that's "nice to have" but not essential? **yes** (I removed persistent profile loading to focus on the core workout logic).

---

## Instructor Approval

*To be filled out during Week 13 check-in:*

- [ ] Scope is appropriate
- [ ] State inventory is complete
- [ ] Function map shows clear decomposition
- [ ] Student knows what they'll ask AI for and what they'll do themselves

**Notes:**
