# basically a command runner
.PHONY: build run format format-check test

build: build/Makefile
	cmake --build build

build/Makefile:
	cmake -S . -B build

run: build
	./build/TicTacToe

test: build
	cd build && ctest --output-on-failure

format:
	find . -path ./build -prune -o \( -name '*.c' -o -name '*.h' \) -print | xargs clang-format -i

format-check:
	find . -path ./build -prune -o \( -name '*.c' -o -name '*.h' \) -print | xargs clang-format --dry-run --Werror
