#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include "headers.h"

void askQuestioner(){
  printf("You have chosen to be a questioner!\n\n");
  sleep(1);
  printf("Please wait until the answerer has chosen their object.\n");
  // code to wait for the answerer - networking
  int i;
  for (i = 0; i < 20; i++){
    printf("Please ask a question! %d / 20  ", i);
    int t;
    char *question = malloc(50);
    // for (t = 0; t <= 20; t++){ // time
    //   fgets(question, 10, stdin);
    //   wait(1);
    //   if (question[0] != NULL){
    //     break;
    //   }
    // }
    if (question[0] == NULL){
      askRandomQuestion();
    }
  }

void askRandomQuestion(){
  char *x = getCategory();
  if (strcmp(category, "Person") == 0){
    // open person.txt files of the questions
    // read a question from a line
    
  }

  if (strcmp(category, "Place") == 0){

  }

  if (strcmp(category, "Place") == 0){

  }
}

char *getCategory(){
  //networking stuff

}

void setupClient(int argc, char ** argv) {

    int server_socket;
    char buffer[BUFFER_SIZE];
    int i, quesAsked;


    if (argc == 2)
      server_socket = client_setup( argv[1]);
    else
      server_socket = client_setup( TEST_IP );

    while (quesAsked < 20) {
      sleep(1);
      printf("Please enter a question: ");
      fgets(buffer, sizeof(buffer), stdin);
      *strchr(buffer, '\n') = 0;
      i = write(server_socket, buffer, sizeof(buffer));
      error_check(i, "client writing");

      i = read(server_socket, buffer, sizeof(buffer));
      error_check(i, "client reading");
      printf("Answer: ");
      sleep(1);
      printf("%s\n\n", buffer);

      quesAsked++;
    }
    close(server_socket);
}

//more functions to be added
