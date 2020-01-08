#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <question.h>
#include <answer.h>

int main(int argc, char * argv[]){

  welcomeScreen();

  char player[100];
  playerSelection();

  if (!strcmp(argv[1],"a")){
    askObject(); // ask for object/person
  } else if (!strcmp(argv[1],"q")){
    // functions for answerers
  } else {
    printf("Error: invalid option.\n");
  }

  endScreen();
  printScoreboard();
}

void welcomeScreen(){
  printf("----------- WELCOME TO 20 QUESTIONS -----------\n");
  // will make this better later
}

void playerSelection(){
  printf("Choose your player : \n");
  printf(" \t answerer or questioner (a | w)");
  fgets(player, 5, stdin);
  player[strlen(player) - 1] = 0;
}
