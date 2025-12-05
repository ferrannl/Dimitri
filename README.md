# Dimitri

> Project for the **Software Architecture** course – written primarily in C++.

This repository contains the code and configuration for the **Dimitri** project, created as part of a software-architecture course. The focus of the project is on clean modular design, separation of concerns and applying common architectural patterns in C++.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building the project](#building-the-project)
  - [Running](#running)
- [Development](#development)
- [Releases](#releases)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

Dimitri is a C++ project that demonstrates:

- A clear, layered software architecture.
- Encapsulation of domain logic in dedicated classes/modules.
- Separation of UI / application / domain / infrastructure concerns where possible.
- Use of modern C++ features and standard library components.

The repository is mainly meant as a learning and demonstration project for software-architecture principles rather than a polished end-user product.

---

## Features

Some typical characteristics of the project:

- **Modular design** – code is split into logical components (e.g. domain logic, helper utilities, I/O).
- **Object-oriented C++** – classes and interfaces are used to organise behaviour and state.
- **Testable structure** – core logic is designed in a way that can be tested independently from the UI or shell.
- **Cross-platform capable** – uses standard C++ so it can be built on multiple platforms if properly configured.

> Note: The exact feature set depends on the version you are using (see [Releases](#releases)).

---

## Project Structure

At the top level, the repository looks like this:

```text
.
├── Dimitri/          # Main C++ project (sources, headers, project files)
├── .github/          # GitHub configuration (e.g. pull request template)
├── .gitignore        # Git ignore rules
└── README.md         # This file
```
Inside the Dimitri/ directory you will find the actual project code and build-related files (e.g. solution / project files or source folders). The exact layout may vary between releases, but typically includes:

src/ or similar: C++ source files (.cpp)

include/ or headers embedded in src/: header files (.h/.hpp)

One or more project / solution files (e.g. for Visual Studio) or build scripts (CMake, Makefile, etc.)



---

Getting Started

Prerequisites

You will need:

A C++ compiler (e.g. GCC, Clang, or MSVC).

A build environment:

Option A – an IDE such as Visual Studio / CLion / Qt Creator, or

Option B – a command-line toolchain (e.g. cmake + make, or your own build system).



If this repository contains a solution/project file (e.g. *.sln, *.vcxproj) you can use that directly with Visual Studio.

Building the project

1. Clone the repository

git clone https://github.com/ferrannl/Dimitri.git
cd Dimitri


2. Open or configure the project

If there is a Visual Studio solution:

1. Open the .sln file located in the Dimitri/ folder.


2. Select the desired configuration (e.g. Debug or Release).


3. Build the solution.



If you prefer your own toolchain:

1. Create a new C++ project in your IDE.


2. Add the existing source (.cpp) and header (.h/.hpp) files from the Dimitri/ directory.


3. Configure include paths if needed.


4. Build the project.






Running

After a successful build, you’ll get an executable (typically called something like Dimitri or the project name chosen in your IDE).

From the command line, for example:

# from your build output directory
./Dimitri

If the project expects arguments or has a menu/GUI, follow the on-screen instructions or refer to any accompanying course documentation.


---

Development

Some general guidelines if you want to explore or extend the project:

Coding style
Stick to the existing style in the repository (naming conventions, indentation, and file organisation).

Architecture
Try to keep responsibilities clearly separated:

Domain / business logic should not depend directly on I/O or UI code.

Prefer small, focused classes and functions.


Branches
For experiments or new features, create a dedicated branch rather than committing directly to master.

Testing
If there are tests, keep them up-to-date when you modify behaviour. If there are no tests yet, consider adding some around key components.



---

Releases

You can find tagged releases under the Releases section on GitHub:

Open the repository in your browser.

Click on Releases to see packaged versions of the project (e.g. “Final Version 1”).


These releases often reflect course milestones (e.g. initial prototype, refactoring, final hand-in).


---

Contributing

This project was originally created for an educational setting. If you still want to experiment or send improvements:

1. Fork the repository.


2. Create a new branch for your change.


3. Commit and push your changes.


4. Open a pull request with a short description of what you changed and why.




---

License

No explicit license file has been added to this repository at the time of writing.
That usually means all rights are reserved by the original authors.

If you intend to use this code beyond personal or educational purposes, please contact the repository owner (@ferrannl) or add an appropriate open-source license first.
