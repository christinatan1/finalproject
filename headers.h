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
// char * getWinner(char * name, char * opponent);
// char * getLoser(char * name, char * opponent);
int endScreenA();
int endScreenQ();
void printScoreboardA(char ** winLose);
void printScoreboardQ(char ** winLose);

char * getCategory();
char * getObject(char * category);
void hiAnswerer();
char * getOpponent();
void confirmSelection(char * category, char * object);
char ** setupServer(char * name, char * category, char * object);

void hiQuestioner();
char * randomQuestion(char * category);
char * getQuestion(char * category);
void setupClient(char * name);

#ifndef NETWORKING_H
#define NETWORKING_H

#define BUFFER_SIZE 256
#define PORT "27213"

void error_check(int i, char *s);
int server_setup();
int server_connect(int sd);
int client_setup(char * server);

#endif
