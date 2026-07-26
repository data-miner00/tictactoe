#include <stdio.h>
#include <shaun.h>
#include <stdbool.h>
#include <string.h>


int readInt();
int isGameOver(int board[3][3]);

int main(int argc, char *argv[]) {
    char player1Name[255] = "Player One";
    char player2Name[255] = "Player Two";
    // --player1 and --player2 are optional
    if (argc > 1) {
        if (strcmp(argv[1], "--player1") == 0) {
            strcpy(player1Name, argv[2]);
        } else if (strcmp(argv[1], "--player2") == 0) {
            strcpy(player2Name, argv[2]);
        }
    }
    if (argc > 3) {
        if (strcmp(argv[4], "--player1") == 0) {
            strcpy(player1Name, argv[5]);
        } else if (strcmp(argv[4], "--player2") == 0) {
            strcpy(player2Name, argv[5]);
        }
    }

    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    bool player1Turn = true;
    int gameOver = 0;
    char player1Avatar = 'X';
    char player2Avatar = 'O';

    printf("Welcome to Tic Tac Toe!\n");

    while (gameOver == 0) {
        printf("%s's turn (Player %d)\n", player1Turn ? player1Name : player2Name, player1Turn ? 1 : 2);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char displayChar;
                if (board[i][j] == 0) {
                    displayChar = '.';
                } else {
                    displayChar = board[i][j];
                }

                printf("%c ", displayChar);
            }
            printf("\n");
        }

        printf("Enter your move (1-9): ");
        int ch = readInt();

        char playerAvatar = player1Turn ? player1Avatar : player2Avatar;

        if (ch == 1) {
            int selected = board[0][0];
            if (selected != 0)
                goto invalid;
            board[0][0] = playerAvatar;
        } else if (ch == 2) {
            int selected = board[0][1];
            if (selected != 0)
                goto invalid;
            board[0][1] = playerAvatar;
        } else if (ch == 3) {
            int selected = board[0][2];
            if (selected != 0)
                goto invalid;
            board[0][2] = playerAvatar;
        } else if (ch == 4) {
            int selected = board[1][0];
            if (selected != 0)
                goto invalid;
            board[1][0] = playerAvatar;
        } else if (ch == 5) {
            int selected = board[1][1];
            if (selected != 0)
                goto invalid;
            board[1][1] = playerAvatar;
        } else if (ch == 6) {
            int selected = board[1][2];
            if (selected != 0)
                goto invalid;
            board[1][2] = playerAvatar;
        } else if (ch == 7) {
            int selected = board[2][0];
            if (selected != 0)
                goto invalid;
            board[2][0] = playerAvatar;
        } else if (ch == 8) {
            int selected = board[2][1];
            if (selected != 0)
                goto invalid;
            board[2][1] = playerAvatar;
        } else if (ch == 9) {
            int selected = board[2][2];
            if (selected != 0)
                goto invalid;
            board[2][2] = playerAvatar;
        } else {
        invalid:
            printf("Invalid move!\n");
            continue;
        }

        // while ((ch = getchar()) != '\n' && ch != EOF); // Clears the buffer line

        gameOver = isGameOver(board);

        player1Turn = !player1Turn;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char displayChar;
            if (board[i][j] == 0) {
                displayChar = '.';
            } else {
                displayChar = board[i][j];
            }

            printf("%c ", displayChar);
        }
        printf("\n");
    }

    if (gameOver == 3) {
        printf("It's a tie!\n");
    } else {
        printf("%s wins!\n", gameOver == 'X' ? player1Name : player2Name);
    }

    return 0;
}

bool isBoardFull(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int isGameOver(int board[3][3]) {
    if (isBoardFull(board)) {
        return 3;
    }

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

int readInt() {
    int num = 0;
    int ch = getchar();

    // 1. Skip non-digit characters (spaces, newlines, tabs)
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }

    // 2. Process all consecutive digit characters
    while (ch >= '0' && ch <= '9') {
        // Multiply current total by 10 and add the new digit
        num = num * 10 + (ch - '0');
        ch = getchar();
    }

    return num;
}
