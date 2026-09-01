#ifndef STATE_H
#define STATE_H

#include <stdbool.h>

typedef struct {
    int board[3][3];
    bool player1Turn;
    int gameOver;
    char player1Avatar;
    char player2Avatar;
    char player1Name[255];
    char player2Name[255];
} GameState;

bool isBoardFull(const GameState *state);
int isGameOver(const GameState *state);

#endif // STATE_H
