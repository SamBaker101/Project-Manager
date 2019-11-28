//Sam Baker 11/08
//Project Management/organizer

#include <iostream>
#include <string.h>
#include "include/Linklist.h"

using namespace std;

Node::Node(int day, int month, int year, char descript[TEXT_LEN], Node *ptrnext){
    dueday = day;
    duemonth = month;
    dueyear = year;
    next = ptrnext;
}

Node::Node(){
  dueday = 0;
  duemonth = 0;
  dueyear = 0;
  next = NULL;
}

Node::~Node(){
}

  int Node::getDay(){return dueday;}
  int Node::getMonth(){return duemonth;}
  int Node::getYear(){return dueyear;}
  char *Node::getDescript(){return descript;}
  Node* Node::getNext(){return next;}

  void Node::setDay(int day){dueday = day;}
  void Node::setMonth(int month){duemonth = month;}
  void Node::setYear(int year){dueyear = year;}
  void Node::setDescript(char *info){strcpy(descript, info);}
  void Node::setNext(Node *nextptr){next = nextptr;}

  void Node::getNodeInput(){
    int dueday, duemonth, dueyear;
    char detail[TEXT_LEN];
    printf("Please enter the duedate for your project (dd/mm/yyyy)\n");
    scanf("%d/%d/%d", &dueday, &duemonth, &dueyear);
    while(dueday > 31 || dueday <= 0 ||
          duemonth > 12 || duemonth <= 0){
      printf("Invalid date, please enter in the format dd/mm/yyyy \n");
      scanf("%d/%d/%d", &dueday, &duemonth, &dueyear);
    }

    printf("Please enter the details for this project:\n");
    scanf("\n%[^\n]%*c", detail);

    addNode(dueday, duemonth, dueyear, descript);

  }

  void Node::addNode(int day, int month, int year, char* descript){
    Node *temp = (Node*)malloc(sizeof(Node)+1);
    Node *temp2 = getNext();

    if (getNext() == NULL){
      temp->setDay(day);
      temp->setMonth(month);
      temp->setYear(year);
      temp->setDescript(descript);
      temp->setNext(NULL);

      setNext(temp);
    }

    else if ((dueyear < next->dueyear) ||

    ((dueyear == next->dueyear) &&
    (duemonth < next->duemonth)) ||

    ((dueyear == next->dueyear) &&
    (duemonth == next->duemonth) &&
    (dueday < next->dueday))){


    temp->setDay(day);
    temp->setMonth(month);
    temp->setYear(year);
    temp->setDescript(descript);

    temp->setNext(temp2);
    setNext(temp);
    }

    else{
      next->addNode(day, month, year, descript);
    }

  }


  void Node::printList(){
    Node *temp = getNext();
    if (temp){
      temp->printNode();
      temp->printList();
      }
  }

  void Node::printNode(){
    int day = getDay();
    int month = getMonth();
    int year = getYear();
    char *descript = getDescript();

    cout<<day<<"/"<<month<<"/"<<year<<" : "<<descript<<endl;
  }
