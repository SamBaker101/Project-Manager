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

Node::~Node(){
}

  int Node::getDay(){return dueday;}
  int Node::getMonth(){return duemonth;}
  int Node::getYear(){return dueyear;}
  char *Node::getDescript(){return descript;}

  void setDay(int day){dueday = day;}
  void setMonth(int month){duemonth = month;}
  void setYear(int year){dueyear = year;}
  void setDescript(char info[TEXT_LEN]){strcpy(descript, info);}

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

    if ((dueyear < next->dueyear) ||

    ((dueyear == next->dueyear) &&
    (duemonth < next->duemonth)) ||

    ((dueyear == next->dueyear) &&
    (duemonth == next->duemonth) &&
    (dueday < next->dueday))){

    temp->setNext(getNext());
    setNext(temp);
    temp->setDay(day);
    temp->setMonth(month);
    temp->setYear(year);
    temp->setDescript(descript);  
    }

    else{
      next->addNode(day, month, year, descript);
    }

  }


  void Node::printList();

}
