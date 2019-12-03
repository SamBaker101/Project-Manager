//Sam Baker 11/08
//Project Management/organizer

#include <iostream>
#include <string>
#include <cstring>
#include "include/Linklist.h"


using namespace std;

Node::Node(int day, int month, int year, char descript[TEXT_LEN], Node *ptrnext){
    dueday = day;
    duemonth = month;
    dueyear = year;
    index = 0;
    next = ptrnext;
}

Node::Node(){
  dueday = 0;
  duemonth = 0;
  dueyear = 0;
  index = 0;
  next = NULL;
}

Node::~Node(){
}

// Get Functions //
  int Node::getDay(){return dueday;}
  int Node::getMonth(){return duemonth;}
  int Node::getYear(){return dueyear;}
  char *Node::getDescript(){return descript;}
  Node* Node::getNext(){return next;}
  int Node::getIndex(){return index;}

// Set Functions //
  void Node::setDay(int day){dueday = day;}
  void Node::setMonth(int month){duemonth = month;}
  void Node::setYear(int year){dueyear = year;}
  void Node::setDescript(char *detail){strcpy(descript, detail);}
  void Node::setNext(Node *nextptr){next = nextptr;}
  void Node::setIndex(int i){index = i;}
  void Node::setIndices(){
    Node *temp = getNext();
    int i = 1;
      while (temp){
        temp->setIndex(i++);
        temp = temp->getNext();
      }
  }

// Link List Functions //
  void Node::getNodeInput(){
    int dueday, duemonth, dueyear;
    char detail[TEXT_LEN];
    cout<<"Please enter the duedate for your project (dd/mm/yyyy)\n";
    scanf("%d/%d/%d", &dueday, &duemonth, &dueyear);
    while(dueday > 31 || dueday <= 0 ||
          duemonth > 12 || duemonth <= 0){
      cout<<"Invalid date, please enter in the format dd/mm/yyyy \n";
      scanf("%d/%d/%d", &dueday, &duemonth, &dueyear);
    }

    cout<<"Please enter the details for this project:\n";
    scanf("\n%[^\n]%*c", detail);

    addNode(dueday, duemonth, dueyear, detail);

  }

  void Node::addNode(int day, int month, int year, char* descript){
    Node *temp = (Node*)malloc(sizeof(Node)+1);
    Node *temp2 = getNext();
    int ind = getIndex();

    temp->setDay(day);
    temp->setMonth(month);
    temp->setYear(year);
    temp->setDescript(descript);;

    if (getNext() == NULL){
      temp->setNext(NULL);
      setNext(temp);
    }

    else if ((year < temp2->getYear())||
      ((year == temp2->getYear()) &&
      (month < temp2->getMonth())) ||
      ((year == temp2->getYear() &&
      (month == temp2->getMonth()) &&
      (day < temp2->getDay()))))

    {
    temp->setNext(temp2);
    setNext(temp);
    }

    else{
      next->addNode(day, month, year, descript);
    }

  }

  void Node::printList(){

    setIndices();

    Node *temp = getNext();
    while (temp){
      temp->printNode();
      temp = temp->getNext();
      }
  }

  void Node::printNode(){
    int day = getDay();
    int month = getMonth();
    int year = getYear();
    char *descript = getDescript();
    int index = getIndex();

    cout<<index<<" - "<<day<<"/"<<month<<"/"<<year<<" : "<<descript<<endl;
  }

  int Node::selectNode(){
    int i;
    printList();
    cout<<"Please select a Project"<<endl;
    cin>>i;

    return i;
  }

  void Node::deleteNode(Node *n, int index){
    Node *temp, *temp2;
    int i = 1;

    while (n != NULL){

      if(i == index){
        temp = n->getNext();
        if(temp){
          temp2 = temp->getNext();
          n->setNext(temp2);
          free(temp);
          }

        }
      n = n->getNext();
      i++;
      }
  }

  void Node::saveList(Node* n){
    FILE *save_file = fopen(FILE_NAME, "w");
    int i = 0;

    if (save_file != NULL){
      n = n->getNext();
      while(n != NULL){
        fprintf(save_file, "%d/%d/%d %s \n", n->getDay(), n->getMonth(), n->getYear(), n->getDescript());
        n = n->getNext();
      }
    fclose(save_file);
    }
  }

  void Node::loadList(Node* n){
    FILE *load_file = fopen(FILE_NAME, "r");
    int dueday, duemonth, dueyear;
    char descript[TEXT_LEN];
    char buffer[TEXT_LEN];

    while(fscanf(load_file, "%d/%d/%d %[^\n]",
          &dueday, &duemonth, &dueyear, &descript) != EOF)
          {
      addNode(dueday, duemonth, dueyear, descript);
    }

    fclose(load_file);
  }

  void Node::freeProjects(Node *n){
    Node *next;

    while(n != NULL){
      next = n->next;
      free(n);
      n = next;
    }
  }
