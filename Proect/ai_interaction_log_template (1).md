# AI Interaction Log — Project 4

**Name:** [Your Name]
**Project Title:** Fitness & Goal Tracker
**AI Tool(s) Used:** Gemini 3 Flash

---

## Entry 1 — May 13, 2026

**What I was trying to do:**
Create a project plan and design document for a Fitness Tracker application.

**What I prompted:**
I provided a project template and asked the AI to help me fill out the "Problem," "State Inventory," and "Function Map" sections based on a C++ fitness app that tracks BMI and workout volume.

**What AI gave me:**
A structured design document that broke the program down into structs (UserProfile and Exercise) and listed specific functions for BMI calculation and file saving.

**What I did with it:**
- [x] Modified it (explain what you changed and why)
I asked the AI to simplify the writing and remove the "profile saving" feature to make the app more beginner-friendly and faster to use during a workout.

**What I learned:**
I learned how to decompose a large program into smaller functions and how to plan "State" (the data the program keeps track of).

---

## Entry 2 — May 13, 2026

**What I was trying to do:**
Write the core C++ code and handle a "divergent branches" error in Git.

**What I prompted:**
"raw code allt hing" and I also pasted a Git error message regarding divergent branches.

**What AI gave me:**
The AI provided a full C++ source code file using structs, vectors, and fstream, and gave me terminal commands (`git config pull.rebase false`) to fix my Git sync issue.

**What I did with it:**
- [x] Used it as-is (explain why it was correct)
The Git fix worked immediately, and the code followed the structure we planned in the design document perfectly.

**What I learned:**
I learned about the `ios::app` flag in C++ which allows me to add data to the end of a file without deleting what was already there.

---

## End-of-Project Reflection

**Total AI interactions logged:** 2

**Most useful interaction and why:**
The interaction where I asked to remove the profile saving feature. It showed me how to simplify a project's "scope" so that I could focus on making the core features (BMI and workout logging) work perfectly.

**An interaction where AI got it wrong:**
Initially, the AI suggested a more complex way to load a profile from a file. I caught it because it felt too advanced for the "beginner" style I wanted. I asked for a simpler version instead.

**What would you do differently next time?**
Next time, I would try to write the basic functions myself first and then ask the AI to help me "refactor" them or find bugs, rather than starting with the AI's code.

**Honest self-assessment:**
I drove this project. While the AI helped with the syntax and the Markdown formatting, I made all the design decisions, such as using Metric/Imperial toggles and choosing which stats were important to track.
