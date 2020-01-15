#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

void welcomeScreen();
char * getName();
char * playerSelection(char * name);
void endScreen();

char * askCategory();
char * askObject(char * category);
void askAnswerer();
void setupServer();

void askQuestioner();
void getQuestion();
void setupClient(int argc, char ** argv);

#ifndef NETWORKING_H
#define NETWORKING_H

#define BUFFER_SIZE 256
#define PORT "12012"
#define TEST_IP "127.0.0.1"

void error_check(int i, char *s);
int server_setup();
int server_connect(int sd);
int client_setup(char * server);

#endif
