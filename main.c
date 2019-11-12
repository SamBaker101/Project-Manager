//Sam Baker 11/08
//Project Management/organizer

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "include/Linklist.h"

void handleInput(struct Project *, int *, int);
void takeInput(struct Project *, int *);
/////////////////////////////////////////////////////////////////////////

void takeInput(struct Project *first, int *running){
  int choice;

  printf("\nPlease make a selection: \n");
  printf("1 - Show Project List \n");
  printf("2 - Add a Project \n");
  printf("3 - Delete a Project \n");
  printf("4 - Save Project List \n");
  printf("5 - Quit\n");

  scanf("%d", &choice);
  printf("\n");

  handleInput(first, running, choice);
}

/////////////////////////////////////////////////////////////////////////

void handleInput(struct Project *first, int *running, int choice){
  int temp_value, temp_index;

  switch (choice){
    case 1:
      printf("Printing your array: \n");
      printList(first);
      break;

    case 2:
      getProject(first);
      break;

    case 3:
      completeProject(first);
      break;

    case 4:
      saveList(first);
      break;

    case 5:
      saveList(first);
      *running = 0;
      break;

    default:
      printf("Not a valid selection\n");
      break;
    }
}

/////////////////////////////////////////////////////////////////////////

void main(){
  struct Project *first = (struct Project*)malloc(sizeof(struct Project)+1);
  int running = 1;

  first->dueday = 0;
  first->duemonth = 0;
  first->dueyear = 0;
  strcpy(first->descript, "Disregard");
  first->next = NULL;

  loadList(first);

  while(running){
    takeInput(first, &running);

  }
freeProjects(first);
}
