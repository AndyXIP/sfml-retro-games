# SFML Retro Games Collection

![Status](https://img.shields.io/badge/Status-Complete-success)
![C++](https://img.shields.io/badge/C%2B%2B-23-00599C?logo=cplusplus&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-3.x-8CC445?logo=sfml&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-macOS%20%7C%20Linux-lightgrey)

A collection of classic arcade games reimagined in modern C++23 using the SFML graphics library. This project showcases object-oriented game design, real-time rendering, collision detection, and user input handling.

---

## Table of Contents

- [Overview](#overview)
- [Games Included](#games-included)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Installation](#installation)
- [Building and Running](#building-and-running)
- [Project Structure](#project-structure)
- [Controls](#controls)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

This repository contains three fully playable retro-style games built from scratch in C++:

- **Pong**: The classic two-player paddle game with physics-based ball movement
- **Snake**: Grid-based snake game with growth mechanics and collision detection
- **Tic Tac Toe**: Turn-based strategy game with win condition checking

Each game demonstrates core game development concepts including game loops, entity management, collision detection, and state handling—all implemented with clean, maintainable object-oriented code.

---

## Games Included

### 1. Pong
Classic arcade tennis game for two players.

**Features:**
- Two-player local gameplay
- Physics-based ball mechanics with angle-based rebounds
- Paddle collision detection
- Score tracking
- Reset functionality (R key)

**Screenshot/Demo:** *Classic paddle vs paddle action*

---

### 2. Snake
The beloved mobile classic with modern C++ implementation.

**Features:**
- Smooth grid-based movement (WASD or Arrow keys)
- Dynamic snake growth upon food consumption
- Self-collision and boundary detection
- Randomized food spawning
- Game over and instant restart (R key)
- Efficient deque-based body management

**Screenshot/Demo:** *Watch the snake grow!*

---

### 3. Tic Tac Toe
Strategic two-player board game with graphical interface.

**Features:**
- Mouse-based click controls
- Turn-based gameplay (X and O)
- Win/draw condition detection
- Visual mark rendering
- Reset functionality (R key)

**Screenshot/Demo:** *Classic X's and O's*

---

## Features

### Technical Highlights
- **Modern C++23**: Leverages latest language features and best practices
- **Object-Oriented Design**: Clean separation of concerns with dedicated classes (`Game`, `Paddle`, `Ball`, `Snake`, `Food`, `Board`)
- **SFML 3.x Integration**: Hardware-accelerated 2D graphics rendering
- **Entity Management**: Efficient handling of game objects and state
- **Collision Detection**: Precise AABB and grid-based collision algorithms
- **Input Handling**: Responsive keyboard and mouse input systems
- **Game Loop Architecture**: Fixed timestep with delta time for consistent gameplay

### User Experience
- **Instant Restart**: Press R to restart any game without relaunching
- **Smooth Graphics**: 60 FPS gameplay with anti-aliased rendering
- **Responsive Controls**: Low-latency input handling
- **Cross-Platform**: Compatible with macOS and Linux (with minor Makefile adjustments)

---

## 🛠️ Tech Stack

- **Language**: C++23
- **Graphics Library**: SFML 3.x (Simple and Fast Multimedia Library)
- **Build System**: GNU Make
- **Compiler**: Clang++ / G++ with C++23 support
- **Platform**: macOS (primary), Linux (compatible)

---

## Installation

### Prerequisites

- **C++ Compiler** with C++23 support (Clang 14+ or GCC 11+)
- **SFML 3.x** library
- **Make** build tool

### Install SFML

#### macOS (via Homebrew)
```bash
brew install sfml
```

#### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install libsfml-dev
```

#### Linux (Fedora)
```bash
sudo dnf install SFML-devel
```

### Clone the Repository

```bash
git clone https://github.com/AndyXIP/sfml-retro-games.git
cd sfml-retro-games
```

---

## Building and Running

Each game is self-contained in its own directory with a dedicated `Makefile`.

### General Build Instructions

1. **Navigate to a game directory**:
   ```bash
   cd Pong        # or Snake, or TicTacToe
   ```

2. **Build the game**:
   ```bash
   make
   ```

3. **Run the executable**:
   ```bash
   ./bin/main
   ```

4. **Clean build artifacts** (optional):
   ```bash
   make clean
   ```

### Quick Start - All Games

```bash
# Build and run Pong
cd Pong && make && ./bin/main

# Build and run Snake
cd ../Snake && make && ./bin/main

# Build and run Tic Tac Toe
cd ../TicTacToe && make && ./bin/main
```

### Makefile Customization

If SFML is installed in a non-standard location, update the `Makefile` in each game directory:

```makefile
# Example: Custom SFML paths
SFML_INCLUDE = /path/to/sfml/include
SFML_LIB = /path/to/sfml/lib
```

---

## Project Structure

```
sfml-retro-games/
│
├── Pong/
│   ├── Makefile               # Build configuration
│   ├── README.md              # Pong-specific documentation
│   ├── bin/
│   │   └── main               # Compiled executable
│   ├── include/
│   │   ├── game.h             # Game loop and state
│   │   ├── paddle.h           # Paddle entity
│   │   └── ball.h             # Ball physics
│   └── src/
│       ├── main.cpp           # Entry point
│       ├── game.cpp           # Game implementation
│       ├── paddle.cpp         # Paddle logic
│       └── ball.cpp           # Ball physics
│
├── Snake/
│   ├── Makefile
│   ├── README.md
│   ├── bin/
│   │   └── main
│   ├── include/
│   │   ├── game.h             # Game orchestration
│   │   ├── snake.h            # Snake entity with deque
│   │   ├── food.h             # Food spawning logic
│   │   └── board.h            # Grid rendering
│   └── src/
│       ├── main.cpp
│       ├── game.cpp
│       ├── snake.cpp
│       ├── food.cpp
│       └── board.cpp
│
├── TicTacToe/
│   ├── Makefile
│   ├── README.md
│   ├── bin/
│   │   └── main
│   ├── include/
│   │   ├── game.h             # Game state management
│   │   ├── board.h            # 3x3 board logic
│   │   └── mark.h             # X/O rendering
│   └── src/
│       ├── main.cpp
│       ├── game.cpp
│       ├── board.cpp
│       └── mark.cpp
│
└── README.md
```

---

## Controls

### Pong
| Action | Key |
|--------|-----|
| Player 1 Up | `W` |
| Player 1 Down | `S` |
| Player 2 Up | `↑` (Up Arrow) |
| Player 2 Down | `↓` (Down Arrow) |
| Restart Game | `R` |

### Snake
| Action | Key |
|--------|-----|
| Move Up | `W` or `↑` |
| Move Down | `S` or `↓` |
| Move Left | `A` or `←` |
| Move Right | `D` or `→` |
| Restart Game | `R` |
| Exit | `ESC` |

### Tic Tac Toe
| Action | Input |
|--------|-------|
| Place Mark | Left Click on square |
| Restart Game | `R` |

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Learning Objectives

This project demonstrates proficiency in:
- **Modern C++ Development**: Templates, smart pointers, STL containers
- **Game Architecture**: Game loops, state machines, entity-component patterns
- **Graphics Programming**: 2D rendering, sprite management, coordinate systems
- **Physics Simulation**: Collision detection, velocity/acceleration calculations
- **Software Design**: Object-oriented principles, separation of concerns, modularity

---

## Acknowledgments

- **SFML Community** for the excellent graphics library and documentation
- **Classic Arcade Games** for inspiring timeless gameplay mechanics

---

**Note**: This project prioritizes code quality and educational value. Each game is implemented with clean, readable code suitable for learning game development fundamentals.
