//Sam Baker 11/08
//Project Management/organizer

#include <iostream>
#include <string>
#include <cstring>
#include "include/Linklist.h"


using namespace std;

void handleInput(Node *, int *, int);
void takeInput(Node *, int *);
/////////////////////////////////////////////////////////////////////////

void takeInput(Node *first, int *running){
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

void handleInput(Node *first, int *running, int choice){
  int temp_value, temp_index;

  switch (choice){
    case 1:
      printf("Printing your array: \n");
      first->printList();
      break;

    case 2:
      first->getNodeInput();
      break;

    case 3:
      first->deleteNode(first, first->selectNode());
      break;

    case 4:
      first->saveList(first);
      break;

    case 5:
      first->saveList(first);
      *running = 0;
      break;

    default:
      printf("Not a valid selection\n");
      break;
    }
}

/////////////////////////////////////////////////////////////////////////

int main(){
  Node *first = (Node *)malloc(sizeof(Node)+1);
  int running = 1;

  first->setDay(0);
  first->setMonth(0);
  first->setYear(0);
  char tempString[] = "Disregard";
  first->setDescript(tempString);

  first->loadList(first);

  while(running){
    takeInput(first, &running);

  }
first->freeProjects(first);
}
