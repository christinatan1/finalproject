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

char * askCategory(){
  char * category = malloc(10);
  while (! (strcmp(category, "Person") == 0 || strcmp(category, "Place") == 0 || strcmp(category, "Thing") == 0)) {
    printf("Please choose from one of the following categories:\nPerson, Place, Thing: ");
    fgets(category, 10, stdin);
    category[strlen(category) - 1] = 0;
    printf("\n");
  }
  return category;
}

char * askObject(char * category){
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

void askAnswerer(){
  sleep(1);
  printf("You have chosen to be an answerer!\n\n");
  sleep(1);
  char * category = askCategory();
  char * object = askObject(category);
  sleep(1);
  printf("You have chosen...\tCategory: %s\t\tObject: %s\n", category, object);
  printf("\n----------------------------------\n\n\n");
  sleep(1);
}

void setupServer(char * name) {
  int listen_socket, client_socket;
  int i;
  int quesAsked = 0;
  char buffer[BUFFER_SIZE];
  char * opponent = malloc(20);

  //set of file descriptors to read from
  fd_set read_fds;

  listen_socket = server_setup();
  printf("Please wait for an opponent...\n\n");

  client_socket = server_connect(listen_socket);
  printf("Opponent found!\n\n");

  printf("\n----------------------------------\n\n\n");
  printf("Please wait for a question...\n");

  i = read(client_socket, buffer, sizeof(buffer)-1);
  error_check(i, "name reading");
  strcpy(opponent, buffer);

  i = write(client_socket, name, sizeof(name));
  error_check(i, "name writing");

  // i = write(server_socket, name, sizeof(name));
  // error_check(i, "category writing");

  while (quesAsked < 3) {

    //select() modifies read_fds
    //we must reset it at each iteration
    FD_ZERO(&read_fds); //0 out fd set
    FD_SET(STDIN_FILENO, &read_fds); //add stdin to fd set
    FD_SET(listen_socket, &read_fds); //add socket to fd set

    //select will block until either fd is ready
    //select(listen_socket + 1, &read_fds, NULL, NULL, NULL);

    i = read(client_socket, buffer, sizeof(buffer));
    error_check( i, "server reading" );
    printf("\n%s asks: ", opponent);
    sleep(1);
    printf("%s\n", buffer);

    sleep(1);

    while (!(strcmp(buffer, "Y") == 0 || strcmp(buffer, "N") == 0)) {
      printf("Your answer (Y / N): ");
      fgets(buffer, sizeof(buffer), stdin);
      *strchr(buffer, '\n') = 0;
      i = write(client_socket, buffer, sizeof(buffer));
      error_check( i, "server writing" );
    }

    memset(buffer, 0, 256);
    quesAsked++;

  }//end stdin select
  close(listen_socket);
  close(client_socket);
}
