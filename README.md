# Battleship Simulator

A terminal-based Battleship engine implemented in **C++ (C++17)** with **SFML Audio** integration and ASCII-rendered console animations.

This project implements a complete turn-based Battleship system supporting both Player vs Player (PvP) and Player vs Computer (PvC) modes. It focuses on deterministic game state management, ship collision validation, attack resolution logic, animated console transitions, and event-driven sound feedback.

---

## Tech Stack

- C++17  
- SFML (Audio module)  
- ANSI terminal rendering  
- macOS (primary development environment)  

---

## Core Capabilities

- Turn-based PvP and PvC gameplay  
- Manual and randomized ship placement  
- Ship boundary and overlap validation  
- Hit/miss detection with scoring system  
- Win-condition evaluation  
- ASCII-rendered UI with ANSI color formatting  
- Timed console animations for gameplay events  
- Integrated sound effects using SFML  

---

## Build Instructions (macOS)

Install SFML using Homebrew:

```bash
brew install sfml
```

### Recommended Compilation Command

From the project root:

```bash
g++ src/main.cpp -std=c++17 $(pkg-config --cflags --libs sfml-all) -o battleship
```

### Alternative Manual Compilation (Local Library Setup)

If using a local SFML library directory:

```bash
g++ -std=c++17 src/main.cpp \
-I /usr/local/opt/sfml/include \
-L ../lib \
-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio \
-Wl,-rpath,@executable_path/../lib \
-o battleship
```

Run the program:

```bash
./battleship
```

---

## Cross-Platform Notes

- The core gameplay logic is platform-independent.  
- SFML supports macOS, Linux, and Windows.  
- ANSI color rendering may require modern terminal support on Windows (e.g., Windows Terminal). Minor adjustments to color handling may be necessary depending on the environment.

---

## Project Structure

```
hoyle-battleship-simulator/
/src/
     main.cpp
/assets/
      *.wav
/README.md
```

---

## Architecture Overview

The game follows a procedural architecture centered around deterministic state transitions.

- Boards are implemented as fixed 10×10 2D arrays.  
- Ship coordinates are tracked using indexed position arrays.  
- Global state variables manage turn flow, scoring, and progression.  
- The primary gameplay loop enforces rule validation, collision checks, and win-condition detection.  
- UI rendering and animated console transitions are integrated directly into the gameplay flow.

---

## Design Considerations

- The implementation uses a single-file procedural design with tightly integrated rendering and gameplay logic.  
- Ship tracking is handled through indexed coordinate arrays rather than structured abstractions.  
- AI attack logic is randomized and does not implement strategic targeting behavior.  
- The build process currently relies on manual compilation rather than automated tooling.  
- Certain control-flow constructs (e.g., `goto` for retry logic) and large procedural functions were intentionally retained to preserve linear gameplay flow within the single-file architecture.

---

## Potential Enhancements

- Refactor large procedural sections into modular components  
- Introduce structured ship abstractions using `struct` or class-based design  
- Implement a more strategic AI targeting algorithm  
- Integrate CMake for cross-platform build automation  
- Decouple rendering logic from core game state management  

---

## Author

Muhammad Zain ul Abidin  
GitHub: https://github.com/zainullabidin
