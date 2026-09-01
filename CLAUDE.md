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

Or via the Makefile command runner: `make build`, `make run`, `make test`, `make format` (clang-format over all `.c`/`.h` files, formatted in place per `.clang-format`), `make format-check` (same, but `--dry-run --Werror` — fails instead of rewriting).

There is a small ctest-based test suite under `tests/` (`test_state.c`, `test_peripheral.c`), wired into the root `CMakeLists.txt` via `enable_testing()`/`add_subdirectory(tests)`. Run it with `make test` or `cd build && ctest --output-on-failure`.

CI (`.github/workflows/ci.yml`) runs on every push and pull request: `make format-check`, then configure/build/`ctest` on `ubuntu-latest`. There is no linter beyond clang-format.

## Architecture

- All source lives flat under `src/` (no separate `include/` dir): `main.c`, `state.c`/`state.h`, `peripheral.c`/`peripheral.h`. Headers are included with quoted relative paths (e.g. `"state.h"` from `src/`, `"../src/state.h"` from `tests/`), not `<angle brackets>` — there's no `target_include_directories` search path set up for project headers.
- `main.c` handles game state setup, the input/game loop, and board printing; `state.c` holds `isBoardFull`/`isGameOver` (win/tie detection); `peripheral.c` holds `readInt`. These are separate translation units — assume logic lives in the module matching its concern, not all in `main.c`.
- Board state is `int board[3][3]`, `0` meaning empty and any other value holding a player's avatar char (`'X'`/`'O'`) stored as an int.
- Moves are entered as 1-9 (not row/col) and mapped to `board[row][col]` via an explicit `if/else` ladder in `main()` rather than arithmetic (e.g. `row = (ch-1)/3`) — so adding board-related features generally means touching this ladder plus the two board-printing loops (one mid-game, one post-game) in `main.c`, since none of these share code today.
- Invalid moves are handled with a `goto invalid;` jump to a label at the bottom of the input ladder, which then `continue`s the game loop.
- `readInt()` reads a move directly from stdin char-by-char (skips non-digits, then accumulates digits) rather than using `scanf`.
- There is currently no AI/computer player; it's local two-player hotseat only.
