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


char *category;
char *randomQuestion(){
  char *c = malloc(100);
  FILE *fp;
  if (strcmp(category, "Person") == 0){
    fp = fopen("Person.txt", "r");
  }

  if (strcmp(category, "Thing") == 0){
    fp = fopen("Thing.txt", "r");
  }

  if (strcmp(category, "Place") == 0){
    fp = fopen("Place.txt", "r");
  }
  srand(time(0));
  int randNum = (rand() % 7 + 1);
  int i;
  // printf("random number: %d\n", randNum);
  fgets(c, 100, fp);
  for (i = 0; i != randNum; i++){
    fgets(c, 100, fp);
  }
  printf("Question: %s\n", c);
  return c;
}

void setupClient(char * name) {

    int server_socket;
    char buffer[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    int i;
    int quesAsked = 0;
    char * opponent = malloc(20);
    char * readin = malloc(20);
    char * quest = malloc(100);
    category = malloc(20);

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
      printf("(%d/20) Enter a question or press Enter if you are unsure of what question to ask: ", quesAsked);
      readin = fgets(quest, sizeof(quest), stdin);
      if (strcmp(readin, "\n") == 0){
        quest = randomQuestion();
       }
      // *strchr(quest, '\n') = 0;
      i = write(server_socket, quest, 100);
      error_check(i, "client writing");
      i = read(server_socket, quest, 100);
      error_check(i, "client reading");
      printf("%s's answer: ", opponent);
      sleep(1);
      printf("%s\n\n", quest);

      quesAsked++;
    }
    close(server_socket);
}
