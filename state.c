#include <state.h>

bool isBoardFull(const GameState *state) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state->board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int isGameOver(const GameState *state) {
    if (isBoardFull(state)) {
        return 3;
    }

    const int(*board)[3] = state->board;

    // First row
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] != 0) {
        return board[0][0];
    }

    // Second row
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] != 0) {
        return board[1][0];
    }
    // Third row
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] != 0) {
        return board[2][0];
    }
    // First column
    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] != 0) {
        return board[0][0];
    }
    // Second column
    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] != 0) {
        return board[0][1];
    }
    // Third column
    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] != 0) {
        return board[0][2];
    }
    // First diagonal
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != 0) {
        return board[0][0];
    }
    // Second diagonal
    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != 0) {
        return board[2][0];
    }
    return 0;
}
