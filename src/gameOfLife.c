#include "../include/gameOfLife.h"
#include "../include/board.h"
int main() {

  while(1) {
    clrscr();

    printBoardCurrentState();

    setBoardNextState();

    usleep(sleepingTime);
  }

  return 0;
}


void clrscr() {
  system("clear");
}
