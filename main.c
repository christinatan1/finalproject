#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include "headers.h"

int main(int argc, char * argv[]){

  welcomeScreen();
  char * name = getName();
  char * player = playerSelection(name);

  if (strcmp(player, "A") == 0){
    askAnswerer();
    setupServer(name);
  }
  else if (strcmp(player, "Q") == 0) {
    askQuestioner();
    setupClient(name);
  }

  // winner = getWinner();
  // endScreen();
  //printScoreboard();
}

void welcomeScreen(){
  printf("\n\n\n\n");
  printf("----------------------------------\n\n\n");
  printf("WELCOME TO 20 QUESTIONS!\n\n");
  printf("By Christina Tan and Stephanie Liu\n\n\n");
  printf("----------------------------------\n\n\n");
  sleep(1);
}

char * getName() {
  char * name = malloc(20);
  printf("Enter your name: ");
  fgets(name, 20, stdin);
  name[strlen(name) - 1] = 0;
  return name;
}

char * playerSelection(char * name){
  char * player = malloc(10);
  printf("\nWelcome %s!\n\n", name);
  sleep(1);
  while (! (strcmp(player, "A") == 0 || strcmp(player, "Q") == 0)) {
    printf("Would you like to be an answerer or questioner? (A / Q): ");
    fgets(player, 10, stdin);
    player[strlen(player)-1] = 0;
    printf("\n");
  }
  printf("\n----------------------------------\n\n\n");
  return player;
}

// char * getWinner(){
//   //networking
// }
//
// void endScreen(){
//   printf("----------------------------------\n\n\n");
//   printf("THANKS FOR PLAYING!\n\n");
//   printf("Winner: %s", winner);
//   printf("\n\n Play Again? (y/n)");
//   char next[100];
//   fgets(next, 2, stdin);
//   printf("----------------------------------\n\n\n");
// }
