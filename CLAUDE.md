# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

Simple TicTacToe game in C. This is a learning/toy project — expect rough edges (dead code, inconsistent style, scratch experiments) left in intentionally as the author practices C.

## Build & Run

```
mkdir -p build && cd build
cmake ..
cmake --build .
./TicTacToe
```

There is no test suite, linter, or CI configured in this repo.

## Architecture

- `main.c` contains everything: game state, input handling, and win-checking logic, all in one translation unit. There is no separation into modules (board, game loop, input) yet — keep this in mind before assuming logic lives in a dedicated file.
- Board state is `int board[3][3]`, `0` meaning empty and any other value holding a player's avatar char (`'X'`/`'O'`) stored as an int.
- Moves are entered as 1-9 (not row/col) and mapped to `board[row][col]` via an explicit `if/else` ladder in `main()` rather than arithmetic (e.g. `row = (ch-1)/3`) — so adding board-related features generally means touching this ladder plus the two board-printing loops (one mid-game, one post-game) and `isGameOver`/`isBoardFull` in parallel, since none of these share code today.
- Invalid moves are handled with a `goto invalid;` jump to a label at the bottom of the input ladder, which then `continue`s the game loop.
- `readInt()` reads a move directly from stdin char-by-char (skips non-digits, then accumulates digits) rather than using `scanf`.
- `include/shaun.h` is a personal scratch header (currently just a stray `int age` global used for a debug print at game end) — not part of the game logic.
- There is currently no AI/computer player; it's local two-player hotseat only.
