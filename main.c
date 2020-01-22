#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

#include "headers.h"

int main(int argc, char * argv[]){

  welcomeScreen();
  char * name = getName();
  char * player = playerSelection(name);
  char ** winLose; // first is winner, second is loser

  if (strcmp(player, "A") == 0){
    hiAnswerer();
    char * category = getCategory();
    char * object = getObject(category);
    confirmSelection(category, object);
    winLose = setupServer(name, category, object);
    free(winLose);
  }
  else if (strcmp(player, "Q") == 0) {
    srand(time(NULL));
    hiQuestioner();
    setupClient(name);
  }


  // int playAgainA = endScreenA();
  // int playAgainQ = endScreenQ();
  //
  // if (playAgainA == 0){
  //   printScoreboardA(winLose);
  //   //printf("Thanks for playing! \n");
  // }
  // if (playAgainQ == 0){
  //   printScoreboardQ(winLose);
  //   //printf("Thanks for playing! \n");
  // }
  // if (playAgainA == 1){
  //   char * category = getCategory();
  //   char * object = getObject(category);
  //   confirmSelection(category, object);
  //   winLose = setupServer(name, category, object);
  // }
  // if (playAgainQ == 1){
  //   hiQuestioner();
  //   setupClient(name);
  // }

  printf("\n----------------------------------\n\n\n");
  printf("THANKS FOR PLAYING! \n");
  printf("\n\n\n----------------------------------\n\n\n");
  free(name);
  free(player);
  return 0;
}

//******************************************

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
//
// int endScreen(){
//   printf("----------------------------------\n\n\n");
//   printf("THANKS FOR PLAYING!\n\n");
//   char *next = malloc (10);
//   while (! (strcmp(next, "Y") == 0 || strcmp(next, "N") == 0)) {
//     printf("\n\n Play Again? (Y/N) ");
//     fgets(next, 2, stdin);
//   }
//   if (strcmp(next, "Y") == 0){
//     return 1;
//   } if (strcmp(next, "N") == 0){
//     return 0;
//   }
//   return -1;
// }

// void printScoreboard(char * winner, char * loser){
//   printf("----------------------------------\n\n\n");
//   printf("Scoreboard: \n");
//   printf("%-10s\t\t %-10d\n", winner, 1);
//   printf("%-10s\t\t %-10d\n\n\n", loser, 0);
//   printf("----------------------------------\n\n\n");
// }
