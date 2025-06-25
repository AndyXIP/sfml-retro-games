# Pong

Classic 2-player Pong game built in C++ using the SFML library.

## Description

This Pong game features:

- Two paddles controlled by players.
- A bouncing ball with basic physics.
- Score tracking (optional to implement).
- Simple and responsive controls.

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

- Player 1: W (up), S (down)
- Player 2: Up arrow (up), Down arrow (down)

## Cleaning Up

To remove the compiled executable:

```sh
make clean
```