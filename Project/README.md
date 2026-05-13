# Fitness & Goal Tracker (Project 4)

## Project Overview
This application is a dedicated C++ terminal tool designed for student athletes and fitness enthusiasts. It streamlines the process of calculating body metrics and tracking strength progress. The program calculates a user's Body Mass Index (BMI) across multiple unit systems and records workout "volume load" (Total Weight Lifted) to a persistent local database.

**Track:** A — C++ Program  
**Course:** CSC 134 — AI-Assisted Development  

---

## Core Features
*   **Dynamic Dashboard:** Displays a formatted header with user statistics and health classifications immediately upon startup.
*   **Dual-Unit Support:** Supports both **Metric** (kg/cm) and **Imperial** (lbs/in) systems with specialized BMI constants for each.
*   **Session Logger:** An interactive loop that captures exercise names, sets, reps, and weights.
*   **Persistence (File I/O):** Automatically appends the session grand total to `workout_history.txt`, allowing for long-term progress tracking.
*   **Data Integrity:** Implements input buffer management (`cin.ignore`) to ensure smooth transitions between numeric and text-based inputs.

---

## Technologies & Concepts Used
*   **Structs:** Grouped related data for `UserProfile` and `Exercise` objects.
*   **Vectors:** Managed a dynamic list of workouts performed in a single session.
*   **Stream Formatting (`<iomanip>`):** Used `setw` and `left` to create professional, readable tables in the terminal.
*   **File Handling (`<fstream>`):** Utilized `ios::app` to ensure history is saved and not overwritten.

---

## File Structure
*   `src/Fitness_Tracker.cpp` — Main source code.
*   `design_doc.md` — The structural plan created in Week 13.
*   `ai_log.md` — Documentation of the AI collaboration and debugging process.
*   `workout_history.txt` — The generated log file for workout totals.

---

## How to Compile and Run
To build and run this project locally, use a standard C++ compiler:

1. **Compile:**
   ```bash
   g++ -o Fitness_Tracker src/Fitness_Tracker.cpp
