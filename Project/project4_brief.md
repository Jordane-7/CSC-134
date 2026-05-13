# Design Document — Project 4

**Name:** Jordane Uter

**Track:** A  
**Project Title:** Fitness & Goal Tracker  
**One-sentence pitch:** This program calculates a user's BMI and logs their workout to show the total weight they lifted.

---

## 1. The Problem

It is hard for people to remember exactly how much total weight they lifted during a workout. This program makes it easy to log exercises and see a "Grand Total." It also helps users track their body weight and health stats using either Metric (kg) or Imperial (lbs) units.

---

## 2. State Inventory

| Data | Type | What Changes It |
|---|---|---|
| User Name | text | User typing it in at the start |
| Body Weight | number | User typing it in at the start |
| Height | number | User typing it in at the start |
| Units (M or I) | character | User choosing Metric or Imperial |
| Exercise List | list | Adding a new exercise to the session |
| Total Lifted | number | Calculated using: sets * reps * weight |

---

## 3. Function / Component Map

| Function Name | What It Does | Inputs | Outputs |
|---|---|---|---|
| initProfile() | Asks for user name, height, and weight | none | User info |
| displayDashboard() | Shows the user's current stats and BMI | User info | text on screen |
| calculateBMI() | Does the math for the BMI score | User info | BMI number |
| getExerciseInput() | Asks for exercise name and lift numbers | unit type | Exercise info |
| displaySummary() | Prints the final table of all lifts | list of exercises| text on screen |
| saveSession() | Saves the total weight to a text file | total weight | saved file |

---

## 4. User Flow

**Main path:**

1. User starts the program and enters their name and body stats.
2. The program shows their BMI and weight status.
3. User types in an exercise name, then enters sets, reps, and weight used.
4. User chooses to either add another exercise or stop.
5. The program shows a summary table and the "Grand Total" lifted.
6. The total weight is saved into a file called `workout_history.txt`.

**Key branches:**

- **Units:** If the user picks 'M', they use kg/cm. If they pick 'I', they use lbs/in.
- **Repeat:** The user can add as many exercises as they want until they say "no."

---

## 5. What Could Go Wrong

| Risk | Plan |
|---|---|
| User types letters when a number is needed | Use code to clear the error and ask again |
| User skips the name input | Use "cin.ignore" to make sure the name is recorded correctly |
| File doesn't exist | The program will create a new file automatically |

---

## 6. What I'll Ask AI to Help With

| Task | Why AI Help Makes Sense |
|---|---|
| Making the summary table look neat | Aligning columns in a terminal can be tricky |
| BMI Math formulas | To make sure the Imperial vs Metric math is exactly right |

---

## 7. What I'll Do Myself (No AI)

1. **Program Structure:** I will decide the order of the functions, necessary calculations and simple codes I learned already.
2. **Variable Setup:** I will choose the names and types for all variables.

---

## 8. Scope Check

- Can I build the C-tier version in one focused work session? **yes**
- Does every feature in my plan connect to the core interaction? **yes**
- Have I cut anything that's "nice to have" but not essential? **yes**

---

## Instructor Approval

- [ ] Scope is appropriate
- [ ] State inventory is complete
- [ ] Function map shows clear decomposition
- [ ] Student knows what they'll ask AI for and what they'll do themselves

**Notes:**
