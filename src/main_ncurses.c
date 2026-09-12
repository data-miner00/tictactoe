#include <ncurses.h>
#include <stdbool.h>
#include "state.h"
#include "args.h"

enum {
    PAIR_COUNT_1 = 1,
    PAIR_COUNT_2,
    PAIR_COUNT_3,
    PAIR_COUNT_4,
    PAIR_COUNT_5,
    PAIR_COUNT_6,
    PAIR_COUNT_7,
    PAIR_COUNT_8,
    PAIR_FLAG,
    PAIR_MINE,
};

int main(int argc, char *argv[]) {
    GameState state = {
        .board = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        .player1Turn = true,
        .gameOver = 0,
        .player1Avatar = 'X',
        .player2Avatar = 'O',
        .player1Name = "Player One",
        .player2Name = "Player Two",
    };

    parseArgs(argc, argv, &state);

    initscr();            // enter curses mode, takes over the terminal
    cbreak();             // read input char-by-char, don't wait for Enter
    noecho();             // don't auto-print typed characters
    keypad(stdscr, TRUE); // let getch() return arrow keys etc. as single KEY_* constants
    curs_set(0);          // primary cursor, hide for now
    start_color();        // enable colors
    init_pair(PAIR_COUNT_1, COLOR_BLUE, COLOR_BLACK);
    init_pair(PAIR_COUNT_2, COLOR_GREEN, COLOR_BLACK);
    init_pair(PAIR_COUNT_3, COLOR_RED, COLOR_BLACK);
    init_pair(PAIR_COUNT_4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(PAIR_COUNT_5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PAIR_COUNT_6, COLOR_CYAN, COLOR_BLACK);
    init_pair(PAIR_COUNT_7, COLOR_WHITE, COLOR_BLACK);
    init_pair(PAIR_COUNT_8, COLOR_WHITE, COLOR_BLACK);
    init_pair(PAIR_FLAG, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PAIR_MINE, COLOR_RED, COLOR_BLACK);

    while (state.gameOver == 0) {
        clear();
        mvprintw(0, 0, "Welcome to Tic Tac Toe!\n");
        int ch = getch();

        switch (ch) {
        case 'q':
            state.gameOver = 1;
        }
    }

    // if below is not run, can run `reset` or `stty sane` to reset terminal
    endwin();
    return 0;
}
