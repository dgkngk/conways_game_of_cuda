#include "../include/board.h"
int currentBoard[MAXROWS][MAXCOLUMNS];

//device kernel function
void initializeBoard() {
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      currentBoard[i][j] = rand() & 1;
    }
  }
}

void printBoardCurrentState() {
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      if(currentBoard[i][j]) {
        printf("█");
      } else {
        printf(" ");
      }
    }

    printf("\n");
  }
}

//global kernel function
void setBoardNextState() {
  int nextBoard[MAXROWS][MAXCOLUMNS];

  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      int neighbors = 0;

      neighbors = aliveNeighbors(currentBoard, i,j);

      if ((currentBoard[i][j] && neighbors == 2) || neighbors == 3) {
        nextBoard[i][j] = 1;
      } else {
        nextBoard[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLUMNS; j++) {
      currentBoard[i][j] = nextBoard[i][j];
    }
  }
}


