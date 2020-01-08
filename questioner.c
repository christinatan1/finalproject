#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

void askQuestioner(){
  printf("You have chosen to be a questioner! \n");
  printf("Please wait until the answerer has chosen their object.\n");
  getQuestion();
  
}

//more functions to be added
