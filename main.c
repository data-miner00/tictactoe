#include <stdio.h>
#include <shaun.h>
#include <stdbool.h>

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
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }

    getchar();

    if (player1Turn) {
      player1Turn = false;
    } else {
      player1Turn = true;
    }
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
