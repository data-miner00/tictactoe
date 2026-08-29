# basically a command runner
.PHONY: build run format

build: build/Makefile
	cmake --build build

build/Makefile:
	cmake -S . -B build

run: build
	./build/TicTacToe

format:
	find . -path ./build -prune -o \( -name '*.c' -o -name '*.h' \) -print | xargs clang-format -i
