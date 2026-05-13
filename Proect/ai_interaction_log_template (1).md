# AI Interaction Log — Project 4

**Name:** [Your Name]
**Project Title:** Fitness & Goal Tracker
**AI Tool(s) Used:** Gemini 3 Flash

---

## Entry 1 — May 10, 2026 (Morning)

**What I was trying to do:**
Brainstorming the core idea for Project 4 and choosing a track.

**What I prompted:**
"I need an idea for a C++ project that uses file I/O and structs. I want it to be related to fitness."

**What AI gave me:**
Suggested a "Fitness & Goal Tracker" that calculates BMI and logs workout volume to a file.

**What I did with it:**
- [x] Used the explanation but wrote my own code
I liked the idea and decided to pursue Track A (C++ Program) because it fits my current course work best.

**What I learned:**
I learned that "meaningful state" in a program means tracking data that changes based on user input.

---

## Entry 2 — May 10, 2026 (Afternoon)

**What I was trying to do:**
Defining the data structures (structs) for the user and the exercises.

**What I prompted:**
"How should I organize my data for a fitness app? I need to track the user's name/height/weight and their specific lifts."

**What AI gave me:**
Suggested two structs: `UserProfile` for the person and `Exercise` for the individual movements.

**What I did with it:**
- [x] Used it as-is (explain why it was correct)
The structs were clean and used the correct data types (`string`, `double`, `int`), making the rest of the program easier to write.

**What I learned:**
I learned that structs are like custom data types that let me keep related information together.

---

## Entry 3 — May 11, 2026 (Morning)

**What I was trying to do:**
Creating the mathematical formulas for BMI in both Metric and Imperial.

**What I prompted:**
"What is the C++ formula for BMI? I need to support both kg/cm and lbs/inches."

**What AI gave me:**
Provided the standard metric formula and the imperial version which requires multiplying by a constant of 703.

**What I did with it:**
- [x] Used it as-is (explain why it was correct)
The formulas were mathematically accurate and included the `703.0` constant needed for US units.

**What I learned:**
I learned that you have to use `703.0` (double) instead of `703` (int) in C++ to keep the decimals accurate.

---

## Entry 4 — May 11, 2026 (Evening)

**What I was trying to do:**
Building the main menu and the loop that lets users add multiple exercises.

**What I prompted:**
"How do I make a loop that keeps asking 'Add another exercise?' until the user says no?"

**What AI gave me:**
A `do-while` loop structure using a `char choice` variable.

**What I did with it:**
- [x] Modified it (explain what you changed and why)
I added `cin.ignore()` after the `cin >> choice` because the program was skipping the next `getline()` call due to the leftover newline character in the buffer.

**What I learned:**
I learned about the "input buffer" and why `cin.ignore()` is necessary when mixing `cin` and `getline`.

---

## Entry 5 — May 12, 2026 (Morning)

**What I was trying to do:**
Saving the session totals to a permanent text file.

**What I prompted:**
"How do I save a double variable to a text file without deleting the old data in the file?"

**What AI gave me:**
Showed me how to use `ofstream` with the `ios::app` (append) flag.

**What I did with it:**
- [x] Used it as-is (explain why it was correct)
Append mode was exactly what I needed to create a historical log of workouts.

**What I learned:**
I learned that `ios::app` stands for "append" and it moves the "write pointer" to the very end of the file.

---

## Entry 6 — May 12, 2026 (Afternoon)

**What I was trying to do:**
Solving a Git error while pushing my design document.

**What I prompted:**
"I got an error saying 'divergent branches' when I tried to git pull. How do I fix this?"

**What AI gave me:**
Explained that my local and online versions were out of sync and told me to use `git config pull.rebase false`.

**What I did with it:**
- [x] Used it as-is (explain why it was correct)
Running the command allowed me to merge my work and finally push my files to GitHub.

**What I learned:**
I learned that divergent branches happen if I edit the README on GitHub.com and then try to push from my computer.

---

## Entry 7 — May 13, 2026 (Morning)

**What I was trying to do:**
Refining the code structure to be more organized.

**What I prompted:**
"Make this code more beginner-like. Remove the complex parts."

**What AI gave me:**
A version that used simpler variables and avoided advanced C++ shortcuts.

**What I did with it:**
- [x] Rejected it (explain what was wrong)
I realized that using `structs` and `vectors` (the original way) actually made my code cleaner and was easier to explain in my design doc.

**What I learned:**
I learned that organized code (like using structs) is often easier to manage than "simple" flat variables.

---

## Entry 8 — May 13, 2026 (Afternoon)

**What I was trying to do:**
Finalizing the Design Document and AI Log for submission.

**What I prompted:**
"Create 8 entries dating from May 10 to today in the raw markdown format."

**What AI gave me:**
A complete history of our interactions formatted as a Markdown file ready for GitHub.

**What I did with it:**
- [x] Used it as-is (explain why it was correct)
It accurately reflects the high-intensity work I did over the last few days to finish the project.

**What I learned:**
I learned how to document the "process" of coding, not just the final result.

---

## End-of-Project Reflection

**Total AI interactions logged:** 8

**Most useful interaction and why:**
Entry 5 was the most useful. Learning `ios::app` was the key to making this a "B Tier" project by adding file persistence.

**An interaction where AI got it wrong:**
In Entry 7, I asked for "beginner" code, but the AI removed too much structure. I caught it by realizing my original struct-based logic was actually more readable.

**What would you do differently next time?**
I would start my design document even earlier to avoid the last-minute rush in the final week.

**Honest self-assessment:**
I drove this project. I chose the fitness theme, decided to include both Metric and Imperial units, and fixed the input buffer bugs myself.
