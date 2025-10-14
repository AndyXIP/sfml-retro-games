# Snake

Classic Snake game built in C++ using the SFML library.

## Description

This Snake game features:

- Snake movement with WASD or arrow keys
- Food spawning and consumption
- Snake growth mechanics
- Self-collision and wall collision detection
- Score tracking
- Game over and restart functionality
- Smooth grid-based movement

## Controls

- **Movement**: WASD keys or Arrow keys
- **Restart**: R key (when game over)
- **Exit**: ESC key

## Dependencies

- SFML library (https://www.sfml-dev.org/)

On macOS, install SFML via Homebrew:

```sh
brew install sfml
```

## Building

Use the provided `Makefile` to build the project.

```sh
make
```

This will compile the source code and create the executable in the `bin/` directory.

## Running

Run the game executable:

```sh
./bin/main
```

## Controls

- Player 1: Arrow buttons to change snake direction.

## Cleaning Up

To remove the compiled executable:

```sh
make clean
```