#include <stdio.h>
#include "include/shaun.h"
#include <stdbool.h>
#include <string.h>
#include "include/peripheral.h"
#include "include/state.h"

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

    // --player1 and --player2 are optional
    if (argc > 1) {
        if (strcmp(argv[1], "--player1") == 0) {
            strcpy(state.player1Name, argv[2]);
        } else if (strcmp(argv[1], "--player2") == 0) {
            strcpy(state.player2Name, argv[2]);
        }
    }
    if (argc > 3) {
        if (strcmp(argv[4], "--player1") == 0) {
            strcpy(state.player1Name, argv[5]);
        } else if (strcmp(argv[4], "--player2") == 0) {
            strcpy(state.player2Name, argv[5]);
        }
    }

    printf("Welcome to Tic Tac Toe!\n");

    while (state.gameOver == 0) {
        printf("%s's turn (Player %d)\n", state.player1Turn ? state.player1Name : state.player2Name,
               state.player1Turn ? 1 : 2);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char displayChar;
                if (state.board[i][j] == 0) {
                    displayChar = '.';
                } else {
                    displayChar = state.board[i][j];
                }

                printf("%c ", displayChar);
            }
            printf("\n");
        }

        printf("Enter your move (1-9): ");
        int ch = readInt();

        char playerAvatar = state.player1Turn ? state.player1Avatar : state.player2Avatar;

        if (ch == 1) {
            int selected = state.board[0][0];
            if (selected != 0)
                goto invalid;
            state.board[0][0] = playerAvatar;
        } else if (ch == 2) {
            int selected = state.board[0][1];
            if (selected != 0)
                goto invalid;
            state.board[0][1] = playerAvatar;
        } else if (ch == 3) {
            int selected = state.board[0][2];
            if (selected != 0)
                goto invalid;
            state.board[0][2] = playerAvatar;
        } else if (ch == 4) {
            int selected = state.board[1][0];
            if (selected != 0)
                goto invalid;
            state.board[1][0] = playerAvatar;
        } else if (ch == 5) {
            int selected = state.board[1][1];
            if (selected != 0)
                goto invalid;
            state.board[1][1] = playerAvatar;
        } else if (ch == 6) {
            int selected = state.board[1][2];
            if (selected != 0)
                goto invalid;
            state.board[1][2] = playerAvatar;
        } else if (ch == 7) {
            int selected = state.board[2][0];
            if (selected != 0)
                goto invalid;
            state.board[2][0] = playerAvatar;
        } else if (ch == 8) {
            int selected = state.board[2][1];
            if (selected != 0)
                goto invalid;
            state.board[2][1] = playerAvatar;
        } else if (ch == 9) {
            int selected = state.board[2][2];
            if (selected != 0)
                goto invalid;
            state.board[2][2] = playerAvatar;
        } else {
        invalid:
            printf("Invalid move!\n");
            continue;
        }

        // while ((ch = getchar()) != '\n' && ch != EOF); // Clears the buffer line

        state.gameOver = isGameOver(&state);

        state.player1Turn = !state.player1Turn;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char displayChar;
            if (state.board[i][j] == 0) {
                displayChar = '.';
            } else {
                displayChar = state.board[i][j];
            }

            printf("%c ", displayChar);
        }
        printf("\n");
    }

    if (state.gameOver == 3) {
        printf("It's a tie!\n");
    } else {
        printf("%s wins!\n", state.gameOver == 'X' ? state.player1Name : state.player2Name);
    }

    return 0;
}
