# Protocol Zero

## Project Name
**Protocol Zero** — A Multi-Stage Terminal Escape-Room Game in C++

---

## Description
**Protocol Zero** is an interactive, text-based escape-room game implemented in C++17. The players awake trapped within a secured facility and need to explore various objects, obtain important items and solve logic-based security locks in three stages: *The Locked Server Room*, *The Cryo-Cooling Corridor*, and *The Exit Airlock* to escape.

---

## Purpose
This project was developed for the **Vibe Coding Challenge** to practice the iterative software development process using AI assistance. Instead of writing boilerplate code from scratch, the purpose was to prototype a stateful game loop, migrate architecture between programming languages, decouple game data from game engine, and debug local compiler setup in Visual Studio Code.

---

## Features
* **Multi-stage Room System:** Sequence of three rooms (*Server Room*, *Cryo-Cooling Corridor*, and *Exit Airlock*) with unique environments, clues, and security locks.
* **Inventory & Item-Based Interactions:** Players find various tools (e.g., *Brass Key* and *UV Flashlight*) that help to uncover clues and open new containers within following rooms.
* **Modular Data Structure:** Room descriptions, interactive objects, item dependencies, and puzzle answers are stored separately in `GameData.h` and `GameData.cpp` from game
* **Case-Insensitive User Input & Validation:** Automatically strips off extra spaces, normalizes user code input, and manages user menu input errors without breaking the stream of input.
* **Performance Tracker With Built-in Hint Counter:** Counts the number of attempts, total moves, and total hints requested on each run, giving an efficiency report at the time of escape.
* **Continuous Gameplay Feature (Replay):** Enables users to replay the game right away after escape or in between runs.

---

## Technologies
* **Programming Language:** C++ (C++17 standard)
* **Standard Libraries:** `<iostream>`, `<string>`, `<vector>`, `<map>`, `<algorithm>`, `<cctype>`, `<limits>`
* **Compiler & Build System:** GCC / MinGW-w64 (`g++`) via WinLibs / MSYS2
* **Development Tools:** Visual Studio Code (with Microsoft C/C++ Extension)
* **Source Code Version Control:** Git & GitHub

---

## AI Tools Used
* **Google Gemini:** Used as the main AI coding assistant for system design, code generation, language migration, modular refactoring, and compiler debugging.

---

## Installation

### Dependencies
* A compiler that supports C++17, such as **MinGW-w64 (`g++`)** on Windows, **GCC** on Linux, or **Clang** on macOS.
* **Git** (optional, to clone the repository).

### Steps
1. **Clone the repository** (or download the source files to a local directory):
   ```bash
   git clone https://github.com/Biko-alt/escape_room.git

2. **Build the application using the g++ compiler with C++17 support:
    ```bash
    $gpp = Get-ChildItem -Path "C:\msys64","C:\MinGW","C:\Program Files","C:\Users\$env:USERNAME\AppData\Local" -Filter "g++.exe" -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($gpp) {
        $env:Path = "$($gpp.DirectoryName);$env:Path"
        Write-Host "Found compiler at: $($gpp.FullName)" -ForegroundColor Green
        g++ -std=c++17 main.cpp GameData.cpp -o protocol_zero.exe
        if (Test-Path .\protocol_zero.exe) { .\protocol_zero.exe }
    } else {
        Write-Host "g++.exe was not found on your drive." -ForegroundColor Red
    }

3. After compiling, run the generated executable from your terminal:
    ```bash
    .\protocol_zero.exe

---

## How to Play

Input the number related to an action in the menu to examine objects in the room you are in, input the security code, ask for a hint, or start the game again.

Look carefully at the clue text since some objects give inventory items needed to solve future clues.

## How AI Was Used

AI was used throughout the entire development lifecycle in an iterative Idea → Prompt → Generate → Run → Test → Debug → Improve loop:

Prototyping & Architecture Pivot: Gemini initially generated a web-based prototype in Python and Flask, which was then refactored into a standalone, zero-dependency C++17 console application.

Separation of Concerns: AI structured the C++ codebase into header (GameData.h), data (GameData.cpp), and engine (main.cpp) files so new rooms and puzzles can be added without modifying game loop logic.

Environment & Compiler Debugging: When PowerShell failed to recognize g++ (CommandNotFoundException), AI provided diagnostic scripts to locate the compiler binary, configure Windows PATH variables, and install the MinGW-w64 UCRT toolchain for VS Code.

Examples of Prompts That Influenced the Application
Initial Prototype & Stack Selection:

"Build a functional escape-room game using vibe coding with Python and Flask, separating the puzzle data from the UI."

Impact: Established the three-stage Protocol Zero narrative, item-dependency mechanics, and clean separation between room data and application logic.

Full Language & Environment Migration:

"Redo the entire vibe coding project, but instead coded in C++, along with providing everything I need to install for C++ on VS code."

Impact: Transformed the web app into a multi-file C++17 console application (GameData.h, GameData.cpp, main.cpp) using std::map and std::vector structs, alongside a step-by-step MSYS2/MinGW-w64 setup guide.

Build & Compiler Troubleshooting:

"Unable to compile and run the code" (accompanied by a PowerShell g++ CommandNotFoundException screenshot)

Impact: Led to an automated PowerShell search-and-compile script and a winget installation workflow (BrechtSanders.WinLibs.POSIX.UCRT) that resolved the missing compiler PATH issue.

Migration of Full Language & Environment:

"Rethink all of the vibe coding project, but coded in C++, and also provide everything that is needed to be able to set up C++ on VS code."

Impact: Converted the web app into a multi-file C++17 Console Application (GameData.h, GameData.cpp, main.cpp), together with an explanation on how to setup MSYS2/MinGW-w64, using std::map and std::vector structs.

Building & Compilation Issues:

"Cannot compile and run the program" 

Impact: Results in an automated PowerShell script to search and compile, and a win-get installation process (BrechtSanders.WinLibs.POSIX.UCRT).

---

## Future Improvements

In case Protocol Zero's development had proceeded further, I would add the following improvements:

1. **Live Facility Lockdown Timer & Difficulty Levels (`<chrono>`):**
   Introduce a feature to display real-time facility lockdown timer based on `std::chrono::steady_clock` along with the ability to select the game difficulty upon starting the game. The options available would be either *Standard Mode* (not timed, unlimited hints) or *Hardcore Mode* (5-minute countdown, no hints, and 3-try limit for entering the right code in the security keypad).

2. **Game Saving & Loading Feature (`<fstream>`):**
   Introduce a game saving/loading feature allowing users to persist their game progress by saving information about room id, item inventory, number of moves, and remaining time in a local `savegame.txt` file.

3. **Room Pack Configuration Files (*.json; Data-Driven Levels):**
   Separate game room and puzzle definitions from hardcoded C++ structs inside the `GameData.cpp` into the separate `.json` configuration files. This would allow to introduce and load custom escape-room scenarios and puzzles without having to recompile the `.exe`.

---

## Vibe Coding Reflection

### 1. What did AI do particularly well?
AI performed admirably with **quick prototyping, language agnostic refactoring, and modular code design**. When switching the direction of the project from a Python/Flask application to a standalone C++17 console application, Gemini transformed the state machine, inventory system, and 3 part puzzle solving mechanics into a clean 3 file C++17 solution (`GameData.h`, `GameData.cpp`, and `main.cpp`) in one go. The segregation of the puzzle data from the rest of the game engine made the codebase easy to understand and build.

### 2. What did AI do poorly?
AI had trouble with **Windows based local environment assumptions while building the development toolchain**. During the C++ development process, the first set of instructions on setting up C++ in Visual Studio Code was dependent on the multi-step installation using MSYS2 and `pacman` combined with manual changes to the `PATH` for Windows. Since VS Code cached the environment variables until a restart and the compiler binaries were not yet available, running `g++` failed to compile the program. It required additional troubleshooting efforts from AI to provide a diagnostic PowerShell script and install command for `winget` (`BrechtSanders.WinLibs.POSIX.UCRT`).

### 3. What process was followed to verify the AI-generated code?
Verification was carried out via **local compilation and playthrough testing**: 
* **Build Verification:** Compiled all .cpp files simultaneously with `g++ -std=c++17 main.cpp GameData.cpp -o protocol_zero.exe` flag set to C++17 to ensure that there were no linker issues, missing header files, or data types mismatch between all .cpp files.
* **Functional & Progression Testing:** Tested all three levels (*"Server Room,"* *"Cryo-Cooling Corridor,"* and *"Exit Airlock") to confirm that the necessary items (*"Brass Key" and "UV Flashlight") unlocked gate actions and room progression correctly.
* **Edge-Case & Input Testing:** Used invalid menu entries (like letters instead of digits) to verify that `std::cin` does not result in an endless loop and enter the solution code with additional spaces and upper-case letter for confirmation of trimming and upper case normalization work properly.

### 4. What was the evolution of the prompts? 
Initially, I was just **using broad and high-level prompts** such as simply pasting assignment requirements and minimal stack preferences ("*"Python, Flask, escape-room game")*. Of course, that resulted in a working prototype but with the architecture and setup provided by the AI itself.

### 5. What did you learn?
This project reinforced that **vibe coding shifts the developer's role from typing syntax to directing architecture, testing edge cases, and managing the local environment**. AI can generate clean data structures (`std::map`, `std::vector`, and custom `struct` models) and refactor across languages in seconds, but it cannot directly see your local machine's `PATH` configuration or verify runtime behavior on its own. Combining clear, iterative prompts with hands-on compilation and edge-case testing produces much more reliable software than relying on a single one-shot generation.

### 6. Do you trust AI to build the entire application without human supervision?
No—AI cannot be trusted to build, configure, and deploy an entire application without human supervision. Although AI provides immense speed in writing boilerplate code, module structuring, and translating the logic across different languages, it does not have the ability to sense the environment it is working in directly and cannot test its own code to spot any potential logic errors. In addition, it depends on the human to establish the scope of the project and the architectural preferences. During the course of this project, the involvement of human intervention was necessary in deciding when to change the tech stack from Python to C++, solve the problems of the local `g++` compiler and `PATH`, and ensure that the puzzle progression and input handling were properly implemented.