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
   