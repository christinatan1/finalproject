#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include "headers.h"

int main(int argc, char * argv[]){

  welcomeScreen();

  char player[100];
  char winner[100];
  playerSelection();

  if (!strcmp(argv[1],"a")){
    askQuestioner();
  } else if (!strcmp(argv[1],"q")){
    askAnswerer();
  } else {
    printf("Error: invalid option. Please enter A or Q.\n");
  }

  endScreen();
  //printScoreboard();
}

void welcomeScreen(){
  printf("\n\n\n\n");
  printf("----------------------------------\n\n\n");
  printf("WELCOME TO 20 QUESTIONS!\n\n");
  printf("By Christina Tan and Stephanie Liu\n\n");
  printf("----------------------------------\n\n\n");
}

void playerSelection(){
  // printf("Choose your player: \n");
  // printf(" \t answerer or questioner (a/q)");
  // fgets(player, 5, stdin);
  // player[strlen(player) - 1] = 0;
}

void endScreen(){
  // printf("----------------------------------\n\n\n");
  // printf("THANKS FOR PLAYING!\n\n");
  // printf("Winner: %s", winner);
  // printf("\n\n Play Again? (y/n)");
  // char next[100];
  // fgets(next, 2, stdin);
  // printf("----------------------------------\n\n\n");
}
