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

char * getCategory(){
  char * category = malloc(10);
  while (! (strcmp(category, "Person") == 0 || strcmp(category, "Place") == 0 || strcmp(category, "Thing") == 0)) {
    printf("Please choose from one of the following categories:\nPerson, Place, Thing: ");
    fgets(category, 10, stdin);
    category[strlen(category) - 1] = 0;
    printf("\n");
  }
  return category;
}

char * getObject(char * category){
  char * object = malloc(50);
  while (strlen(object) == 0) {
    printf("Please choose an object from the category %s: ", category);
    fgets(object, 50, stdin);
    object[strlen(object) - 1] = 0;
    printf("\n");
  }
  printf("\n");
  return object;
}

void hiAnswerer(){
  sleep(1);
  printf("You have chosen to be an answerer!\n\n");
  sleep(1);
}

void confirmSelection(char * category, char * object) {
  sleep(1);
  printf("You have chosen...\tCategory: %s\t\tObject: %s\n", category, object);
  printf("\n----------------------------------\n\n\n");
  sleep(1);
}


char ** setupServer(char * name, char * category, char * object) {
  int listen_socket, client_socket;
  int i;
  int quesAsked = 1;
  int status = 0;
  char buffer[BUFFER_SIZE];
  char buffer1[BUFFER_SIZE];
  char * opponent = malloc(20);
  fd_set read_fds;
  char ** output = malloc(20);
  int questioner = 0;
  int answerer = 0;

  listen_socket = server_setup();
  printf("Please wait for an opponent...\n\n");

  client_socket = server_connect(listen_socket);
  printf("Opponent found!\n\n");

  printf("\n----------------------------------\n\n\n");
  printf("Please wait for a question...\n\n");

  // give category
  i = write(client_socket, category, sizeof(category));
  error_check(i, "category writing");

  //get name
  i = read(client_socket, buffer, sizeof(buffer));
  error_check(i, "name reading");
  strncpy(opponent, buffer, sizeof(buffer));

  // give name
  i = write(client_socket, name, sizeof(name));
  error_check(i, "name writing");

  while (quesAsked <= 20 && status == 0) {
    memset(buffer, 0, 256);
    memset(buffer1, 0, 256);

    // FD_ZERO(&read_fds); //0 out fd set
    // FD_SET(STDIN_FILENO, &read_fds); //add stdin to fd set
    // FD_SET(listen_socket, &read_fds); //add socket to fd set
    //
    // select(listen_socket + 1, &read_fds, NULL, NULL, NULL);

    i = read(client_socket, buffer, sizeof(buffer));
    error_check( i, "server reading");
    printf("\n(%d/20) %s asks: ", quesAsked, opponent);
    sleep(1);
    printf("%s\n", buffer);

    sleep(1);

    while (!(strncmp(buffer, "Y", 1) == 0 || strncmp(buffer, "N", 1) == 0)) {
      printf("Your answer (Y / N): ");
      fgets(buffer, sizeof(buffer), stdin);
      *strchr(buffer, '\n') = 0;
      error_check( i, "server writing" );

      if (strcmp(buffer, "Y") == 0) {
        while (!(strcmp(buffer1, "Y") == 0 || strcmp(buffer1, "N") == 0)) {
          printf("Has the object been guessed? (Y / N): ");
          fgets(buffer1, sizeof(buffer1), stdin);
          *strchr(buffer1, '\n') = 0;
          if (strcmp(buffer1, "Y") == 0) {
            printf("\n\n%s has won this round!\n\n\n", opponent);
            output[0] = opponent;
            output[1] = name;
            strcat(buffer, "\n\n\nYou guessed it! You have won this round!\n\n\n");
            status = 1;
          }
        }
      }
    }
    i = write(client_socket, buffer, 100);
    error_check(i, "client writing");

    quesAsked++;

  }//end stdin select

  if (quesAsked > 20 & status == 0) {
    printf("\n\n\nYou have won this round!\n\n\n");
    output[0] = name;
    output[1] = opponent;
    memset(buffer, 0, 256);
    strcpy(buffer, object);
    i = write(client_socket, buffer, 100);
    error_check(i, "client writing");
  }

  close(listen_socket);
  close(client_socket);

  return output;

}

// char * getWinner(char * name, char * opponent){
//   if (questioner > answerer){
//     return opponent;
//   } else {
//     return name;
//   }
// }
//
// char * getLoser(char * name, char * opponent){
//   if (questioner > answerer){
//     return name;
//   } else {
//     return opponent;
//   }
// }

// char * getOpponent(){
//   char * output = malloc(20);
//   char buffer[BUFFER_SIZE];
//   int client_socket;
//   int i;
//   i = read(client_socket, buffer, sizeof(buffer));
//   error_check(i, "name reading");
//   strncpy(output, buffer, sizeof(buffer));
//   return output;
// }

int endScreenA(){
  printf("----------------------------------\n\n\n");
  printf("THANKS FOR PLAYING!\n\n");
  char *next = malloc (10);
  while (! (strcmp(next, "Y") == 0 || strcmp(next, "N") == 0)) {
    printf("\n\n Play Again? (Y/N) ");
    fgets(next, 2, stdin);
  }
  if (strcmp(next, "Y") == 0){
    return 1;
  } if (strcmp(next, "N") == 0){
    return 0;
  }
  return -1;
}

void printScoreboardA(char ** winLose){
  printf("----------------------------------\n\n\n");
  printf("Scoreboard: \n");
  printf("%-10s\t\t %-10d\n", winLose[1], 1);
  printf("%-10s\t\t %-10d\n\n\n", winLose[0], 0);
  printf("----------------------------------\n\n\n");
}
