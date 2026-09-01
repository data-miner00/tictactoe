#include <assert.h>
#include <stdio.h>
#include "../include/state.h"

static GameState emptyState(void) {
    GameState state = {0};
    state.player1Avatar = 'X';
    state.player2Avatar = 'O';
    return state;
}

static void fillRow(GameState *state, int row, char avatar) {
    state->board[row][0] = avatar;
    state->board[row][1] = avatar;
    state->board[row][2] = avatar;
}

static void fillCol(GameState *state, int col, char avatar) {
    state->board[0][col] = avatar;
    state->board[1][col] = avatar;
    state->board[2][col] = avatar;
}

static void test_isBoardFull_empty(void) {
    GameState state = emptyState();
    assert(isBoardFull(&state) == false);
}

static void test_isBoardFull_oneEmptyCell(void) {
    GameState state = emptyState();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            state.board[i][j] = 'X';
        }
    }
    state.board[2][2] = 0;
    assert(isBoardFull(&state) == false);
}

static void test_isBoardFull_full(void) {
    GameState state = emptyState();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            state.board[i][j] = 'X';
        }
    }
    assert(isBoardFull(&state) == true);
}

static void test_isGameOver_empty(void) {
    GameState state = emptyState();
    assert(isGameOver(&state) == 0);
}

static void test_isGameOver_noWin(void) {
    GameState state = emptyState();
    state.board[0][0] = 'X';
    state.board[1][1] = 'O';
    assert(isGameOver(&state) == 0);
}

static void test_isGameOver_rowWin(void) {
    for (int row = 0; row < 3; row++) {
        GameState state = emptyState();
        fillRow(&state, row, 'X');
        assert(isGameOver(&state) == 'X');
    }
}

static void test_isGameOver_colWin(void) {
    for (int col = 0; col < 3; col++) {
        GameState state = emptyState();
        fillCol(&state, col, 'O');
        assert(isGameOver(&state) == 'O');
    }
}

static void test_isGameOver_diagWin(void) {
    GameState state1 = emptyState();
    state1.board[0][0] = 'X';
    state1.board[1][1] = 'X';
    state1.board[2][2] = 'X';
    assert(isGameOver(&state1) == 'X');

    GameState state2 = emptyState();
    state2.board[2][0] = 'O';
    state2.board[1][1] = 'O';
    state2.board[0][2] = 'O';
    assert(isGameOver(&state2) == 'O');
}

static void test_isGameOver_tie(void) {
    GameState state = emptyState();
    char vals[3][3] = {
        {'X', 'O', 'X'},
        {'X', 'O', 'O'},
        {'O', 'X', 'X'},
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            state.board[i][j] = vals[i][j];
        }
    }
    assert(isGameOver(&state) == 3);
}

// Known bug (state.c): isGameOver checks isBoardFull() before checking for a
// winning line, so a board that is full AND has a winning row/col/diagonal
// on the final move is reported as a tie (3) instead of returning the
// winner. This test encodes the *correct* behavior and is expected to fail
// until that check order is fixed.
static void test_isGameOver_winOnFullBoard_knownBug(void) {
    GameState state = emptyState();
    char vals[3][3] = {
        {'X', 'X', 'X'},
        {'O', 'O', 'X'},
        {'O', 'X', 'O'},
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            state.board[i][j] = vals[i][j];
        }
    }
    assert(isGameOver(&state) == 'X');
}

int main(void) {
    test_isBoardFull_empty();
    test_isBoardFull_oneEmptyCell();
    test_isBoardFull_full();

    test_isGameOver_empty();
    test_isGameOver_noWin();
    test_isGameOver_rowWin();
    test_isGameOver_colWin();
    test_isGameOver_diagWin();
    test_isGameOver_tie();
    test_isGameOver_winOnFullBoard_knownBug();

    printf("All state tests passed.\n");
    return 0;
}
