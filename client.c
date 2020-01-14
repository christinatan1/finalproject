#include "headers.h"

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];
  int i;


  if (argc == 2)
    server_socket = client_setup( argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  while (1) {
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

    int i = strncmp("Bye", buffer, 3);
    if (i==0) break;
  }
  close(server_socket);
}
