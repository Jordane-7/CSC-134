# Testing Log — Project 4

**Project Title:** Fitness & Goal Tracker  
**Name:** [Your Name]  
**Date:** May 13, 2026

---

## 1. Test Cases

| Test Case | Input Values | Expected Result | Actual Result | Status |
|---|---|---|---|---|
| **Metric BMI** | Weight: 100kg, Height: 200cm | BMI: 25.0 (Healthy) | BMI: 25.0 (Healthy) | **Pass** |
| **Imperial BMI** | Weight: 250lb, Height: 73in | BMI: 33.0 (Obese) | BMI: 33.0 (Obese) | **Pass** |
| **Lift Calculation** | 3 Sets, 10 Reps, 100lbs | Total: 3000.0 lbs | Total: 3000.0 lbs | **Pass** |
| **Multi-Entry** | 2 different exercises | Grand Total = Sum of both | Grand Total calculated | **Pass** |
| **Empty File** | First time running | Create new .txt file | `workout_history.txt` created | **Pass** |

---

## 2. Bug Log

### Bug 1: The "Menu Skip" Glitch
*   **Description:** After entering the weight for the first exercise, the program would skip the name prompt for the second exercise and crash.
*   **Cause:** The `cin >> weight` command left a "newline" character in the input buffer.
*   **Fix:** Added `cin.ignore()` immediately after the `cin` calls in the `getExerciseInput` function.

### Bug 2: BMI Precision Mess
*   **Description:** The BMI was showing 6 decimal places (e.g., 25.123456), which looked unprofessional in the dashboard.
*   **Cause:** Default `cout` behavior for doubles.
*   **Fix:** Used `#include <iomanip>` and applied `fixed << setprecision(1)` to the BMI output.

### Bug 3: Integer Division Error
*   **Description:** During Imperial testing, the BMI was coming out as 0 or wildly incorrect numbers.
*   **Cause:** I was using `703` (integer) instead of `703.0` (double) in the formula, causing the math to truncate.
*   **Fix:** Updated the constant to `703.0` to force double-precision math.

---

## 3. Final Verification
*   [x] **File Persistence:** Verified that `workout_history.txt` updates correctly after multiple runs.
*   [x] **User Experience:** Verified that the "Obese/Healthy/Underweight" tags change correctly based on BMI.
*   [x] **Edge Cases:** Tested with 0 weight and 0 reps; the program handles these without crashing.

---
**Final Status:** All core features are functional and bug-free.
