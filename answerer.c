#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "aquestions.h"


char * askCategory(){
  char * category = malloc(10);
  while (1) {
    printf("Please choose from one of the following categories: Person, Place, Thing: ");
    fgets(category, 10, stdin);
    category[strlen(category) - 1] = 0;
    if (strcmp(category, "Person") == 0 || strcmp(category, "Place") == 0 || strcmp(category, "Thing") == 0)
      break;
  }
  return category;
}

char * askObject(){
  printf("Please choose an object from the category %s: ", askCategory());
  char * object = malloc(50);
  fgets(object, 50, stdin);
  object[strlen(object) - 1] = 0;
  return object;
}

void askAnswerer(){
  printf("You have chosen to be a answerer!\n\n");
  sleep(1);
  char * category = askCategory();
  char * object = askObject();
  sleep(1);
  printf("\nYou have chosen...\tCategory: %s\t\tObject: %s\n", category, object);
}
