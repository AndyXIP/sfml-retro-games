# Pong

Classic 2-player TicTacToe game built in C++ using the SFML library.

## Description

This TicTacToe game features:

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

- Player 1/2: Mouse left click on square you want your tic/tac.

## Cleaning Up

To remove the compiled executable:

```sh
make clean
```