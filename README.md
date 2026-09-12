# TicTacToe

Simple TicTacToe.

## Nix

A `shell.nix` is provided for a reproducible dev environment (cmake, gcc, ncurses, clang-format, gdb):

```
nix-shell
```

Then use the `make` commands below as usual inside the shell.

## Build & Run

1. Build all

```
make build
```

2. TicTacToe CLI

```
make run
```

3. TicTacToe TUI

```
make rn
```

4. Test

```
make test
```

5. Format

```
make format
```

6. Format Check

```
make check-format
```
