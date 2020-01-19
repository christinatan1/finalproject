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
}

// void randomQuestion(){
//   //char * category = getCategory();
//   if (strcmp(category, "Person") == 0){
//     // open person.txt files of the questions
//     // read a question from a line
//
//   }
//
//   if (strcmp(category, "Place") == 0){
//
//   }
//
//   if (strcmp(category, "Place") == 0){
//
//   }
// }

void setupClient(char * name) {

    int server_socket;
    char buffer[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    int i;
    int quesAsked = 0;
    char * opponent = malloc(20);
    char * category = malloc(20);

    char server[BUFFER_SIZE];
    printf("Enter the IP Address of your opponent: ");
    fgets(server, sizeof(server), stdin);
    *strchr(server, '\n') = 0;
    server_socket = client_setup( server );
    printf("\n----------------------------------\n\n\n");

    i = write(server_socket, name, sizeof(name));
    error_check(i, "name writing");

    i = read(server_socket, buffer, sizeof(buffer)-1);
    error_check(i, "name reading");
    strcpy(opponent, buffer);

    i = read(server_socket, buffer2, sizeof(buffer2)-1);
    error_check(i, "category reading");
    strcpy(category, buffer2);
    // printf("This is the category: %s\n", category);

    while (quesAsked < 20) {
      sleep(1);
      printf("Your question: (%d/20)", quesAsked);
      wait(1);
      fgets(buffer, sizeof(buffer), stdin);
      // if (buffer[1] == NULL){  implement wait later******
      //    buffer = randomQuestion();
      //  }
      *strchr(buffer, '\n') = 0;
      i = write(server_socket, buffer, sizeof(buffer));
      error_check(i, "client writing");

      i = read(server_socket, buffer, sizeof(buffer));
      error_check(i, "client reading");
      printf("%s's answer: ", opponent);
      sleep(1);
      printf("%s\n\n", buffer);

      quesAsked++;
    }
    close(server_socket);
}

//more functions to be added
