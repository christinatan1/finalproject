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

void hiQuestioner(){
  printf("You have chosen to be a questioner!\n\n");
  sleep(1);
}

char * randomQuestion(char * category){
  char * ques = malloc(256);
  FILE * fp;

  if (strcmp(category, "Person") == 0)
    fp = fopen("Person.txt", "r");

  else if (strcmp(category, "Thing") == 0)
    fp = fopen("Thing.txt", "r");

  else if (strcmp(category, "Place") == 0)
    fp = fopen("Place.txt", "r");

  int randNum = rand() % 7 + 1;
  for (int i = 0; i != randNum; i ++)
    fgets(ques, 256, fp);

  fclose(fp);
  printf("Random question: %s\n", ques);

  return ques;
}

// char * getQuestion(char * category) {
//   char * ques = malloc(100);
//   fd_set read_fds;
//   struct timeval timeout;
//
//   FD_ZERO(&read_fds); //0 out fd set
//   FD_SET(STDIN_FILENO, &read_fds); //add stdin to fd set
//     //FD_SET(server_socket, &read_fds); //add socket to fd set
//
//   timeout.tv_sec = TIMELIMIT;
//   timeout.tv_usec = 0;
//
//   int sret = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);
//
//   if (sret == 0) {
//     return randomQuestion(category);
//   }
//   else {
//     fgets(ques, sizeof(ques), stdin);
//     *strchr(ques, '\n') = 0;
//   }
//   return ques;
// }

void setupClient(char * name) {
    int server_socket;
    char buffer[BUFFER_SIZE];
    int i;
    int quesAsked = 1;
    int status = 0;
    char * opponent = malloc(20);
    char * category;

    char server[BUFFER_SIZE];
    printf("Enter the IP Address of your opponent: ");
    fgets(server, sizeof(server), stdin);
    *strchr(server, '\n') = 0;
    server_socket = client_setup( server );
    printf("\n----------------------------------\n\n\n");

    // get category
    i = read(server_socket, buffer, sizeof(buffer));
    error_check(i, "category reading");
    strncpy(category, buffer, sizeof(buffer));
    memset(buffer, 0, 256);
    printf("THE CATEGORY IS: %s\n\n", category);

    // give name
    i = write(server_socket, name, sizeof(name));
    error_check(i, "name writing");

    // get opponent's name
    i = read(server_socket, buffer, sizeof(buffer));
    error_check(i, "name reading");
    strncpy(opponent, buffer, sizeof(buffer));

    while (quesAsked <= 20 && status == 0) {
      memset(buffer, 0, 256);

      sleep(1);

      printf("\n(%d/20) Enter a question (or press Enter for a random question): ", quesAsked);

      fgets(buffer, sizeof(buffer), stdin);
      *strchr(buffer, '\n') = 0;
      //printf("strle: %lu", strlen(buffer));

      if (strlen(buffer) == 0){
        char * ques = randomQuestion(category);
        i = write(server_socket, ques, strlen(ques));
        error_check(i, "client writing");
      }

      else {
        i = write(server_socket, buffer, strlen(buffer));
        error_check(i, "client writing");
      }

      memset(buffer, 0, 256);

      i = read(server_socket, buffer, sizeof(buffer));
      error_check(i, "client reading");
      printf("%s's answer: ", opponent);
      sleep(1);
      printf("%s\n", buffer);
      if (strlen(buffer) > 1)
        status = 1;

      quesAsked++;
    }

    if (quesAsked > 20 && status == 0) {
      memset(buffer, 0, 256);
      i = read(server_socket, buffer, 100);
      error_check(i, "client writing");

      printf("\n\n\nYou did not guess and lost this round :(\n");
      sleep(1);
      printf("The answer is: %s\n\n\n", buffer);
    }
    close(server_socket);
}
