#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "headers.h"

char question[100];

void askQuestioner(){
  printf("You have chosen to be a questioner! \n");
  printf("Please wait until the answerer has chosen their object.\n");
  int status;
  getQuestion();

}

void getQuestion(){
  // int i;
  // for (i = 0, i<20, i++){
  //   printf("Ask a question! ");
  //   fgets(question, 100, stdin);
  //   printf("Question " %d + " /20\n");
  //   // code to send question to answerer
  // }
}

//more functions to be added
