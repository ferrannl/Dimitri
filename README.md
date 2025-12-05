# Dimitri – Software Architecture Game Project

**Dimitri** is a 2D C++ game project built as part of a *Software Architectuur* course.  
The focus of this repository is not just on gameplay, but on **clean architecture**, **separation of concerns**, and **testable game logic**.

> Language: C++ (≈99%) + a small amount of C.  
> Structure: Multi-module game with controllers, views, physics and graphics engines. 0

---

## Overview

Dimitri is a side-scrolling platformer with:

- A home screen, help screen and credits
- A playable level with scrolling camera
- Pause, win and game-over screens
- Basic platformer mechanics like jumping and collision
- Extra polish such as FPS display and background music 1

The codebase is organised to practice **software architecture principles**:

- Clear split between **game logic**, **input**, **physics**, **graphics** and **UI screens**
- Controllers and views for different game screens (home, level, help, pause, game over, win) 2
- Use of observers/observables and other patterns to keep modules decoupled

---

## Features

### Gameplay

- 2D side-scrolling platformer
- Home screen, level, help, pause, win and game-over views
- Support for **double jump** and other player actions
- Side-scrolling camera following the player
- Collision handling between player, floor and world geometry 3

### Technical / Architecture

- **Screen navigation system** – central controller that manages which screen is active/visible at any time
- **Graphics engine** and **physics / collision engine** modules
- FPS overlay / FPS view for performance feedback
- Input handling wired through a main controller using an **observable / observer** pattern
- Doxygen-style comments across namespaces and modules
- Unit tests for critical logic (e.g. collision, FPS) 4

### Content & Polish

- Home screen with graphics and buttons
- Help screen describing controls
- Pause, win and game-over overlays
- Background and level built from tiles (Tiled-style level support) 5
- Music and sound effects (e.g. mission failed / game-over music) 6

---

## Project Structure

At the top level the repository contains:

- `Dimitri/` – main C++ game source code and project files
- `.github/` – pull request templates and GitHub configuration
- `README.md` – this file 7

Inside the `Dimitri` folder you’ll find (names may vary slightly depending on the IDE/project layout):

- Controllers (e.g. `MainController`, `HomeController`, level/scene controllers)
- Views (home, help, pause, win, game over, HUD/FPS)
- Engines (graphics engine, physics / collision engine)
- Utility code and tests
- Doxygen configuration / comments for generated documentation 8

---

## Getting Started

> **Note:** The exact build setup depends on the project files in the `Dimitri` directory  
> (e.g. CMake project, Visual Studio solution, Qt Creator/CLion project).  
> Use the project file that matches your toolchain.

### Prerequisites

- A modern C++ compiler (e.g. GCC, Clang or MSVC)
- A C++ IDE or build system that can open the project files in `Dimitri/`
- Standard C++ tooling (debugger, build system, etc.)

If the project uses an IDE solution (e.g. Visual Studio):

1. Clone the repository:
   ```bash
   git clone https://github.com/ferrannl/Dimitri.git
   cd Dimitri
