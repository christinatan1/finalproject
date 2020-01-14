#include "headers.h"

int main() {

  int listen_socket, client_socket;
  int i;
  char buffer[BUFFER_SIZE];

  //set of file descriptors to read from
  fd_set read_fds;

  listen_socket = server_setup();
  client_socket = server_connect(listen_socket);

  while (1) {

    //select() modifies read_fds
    //we must reset it at each iteration
    FD_ZERO(&read_fds); //0 out fd set
    FD_SET(STDIN_FILENO, &read_fds); //add stdin to fd set
    FD_SET(listen_socket, &read_fds); //add socket to fd set

    //select will block until either fd is ready
    //select(listen_socket + 1, &read_fds, NULL, NULL, NULL);

    i = read(client_socket, buffer, sizeof(buffer));
    error_check( i, "server reading" );
    printf("\n\n[Player] asks: ");
    sleep(1);
    printf("%s\n", buffer);

    sleep(1);
    printf("Your answer: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    i = write(client_socket, buffer, sizeof(buffer));
    error_check( i, "server writing" );

    int i = strncmp("Bye", buffer, 3);
    if (i==0) break;

  }//end stdin select
  close(listen_socket);
  close(client_socket);
  return 0;
}
