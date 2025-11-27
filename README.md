# Tik-Tak-Toe

Ultra‑simple Tic‑Tac‑Toe game.

## Description
A minimal Tic‑Tac‑Toe (noughts and crosses) implementation. Intended as a small demo or learning project.

## Requirements
- C++ compiler (g++, clang) or Python 3 — depending on the implementation file in the repository.
- (Optional) CMake if a CMakeLists.txt is provided.

## Build & Run

If the project is a single C++ source file (e.g. `main.cpp`):
- Build:
  g++ -std=c++17 main.cpp -o tik_tak_toe
- Run:
  ./tik_tak_toe

If the project uses CMake:
- Configure & build:
  mkdir -p build
  cd build
  cmake ..
  cmake --build .
- Run the produced executable from the build directory.

If the project is a Python script (e.g. `main.py`):
- Run:
  python3 main.py

(Adjust filenames to match the repository contents.)