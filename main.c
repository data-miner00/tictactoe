#include <stdio.h>
#include <shaun.h>
#include <stdbool.h>

int readInt();

int main(void)
{
  int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  bool player1Turn = true;
  bool gameOver = false;
  char player1Name[10] = "Shaun";
  char player2Name[10] = "Shaun";
  char player1Avatar = 'X';
  char player2Avatar = 'O';

  printf("Welcome to Tic Tac Toe!\n");

  while (!gameOver) {
    printf("Player 1 turn: %s\n", player1Turn ? "Yes" : "No");


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
      board[0][0] = playerAvatar;
    } else if (ch == 2) {
      board[0][1] = playerAvatar;
    } else if (ch == 3) {
      board[0][2] = playerAvatar;
    } else if (ch == 4) {
      board[1][0] = playerAvatar;
    } else if (ch == 5) {
      board[1][1] = playerAvatar;
    } else if (ch == 6) {
      board[1][2] = playerAvatar;
    } else if (ch == 7) {
      board[2][0] = playerAvatar;
    } else if (ch == 8) {
      board[2][1] = playerAvatar;
    } else if (ch == 9) {
      board[2][2] = playerAvatar;
    } else {
      printf("Invalid move!\n");
      continue;
    }

    // while ((ch = getchar()) != '\n' && ch != EOF); // Clears the buffer line

    player1Turn = !player1Turn;
  }
    printf("Hello World! Shaun age: %d\n", age);
    return 0;
}

bool isBoardFull(int** board)
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}

bool isGameOver(int** board)
{
  if (isBoardFull(board)) {
    return true;
  }
  // TODO: Check for winner
  return false;
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
