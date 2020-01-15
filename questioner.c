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
