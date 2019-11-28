//Sam Baker
//Link list and node Management

#define FILE_NAME "bin/projectlist.txt"
#define TEXT_LEN 128

class Node{
  int dueday, duemonth, dueyear, index;
  char descript[TEXT_LEN];
  Node *next;

public:
  Node(int, int, int, char* , Node*);
  Node();
  ~Node();

// get //
  int getDay();
  int getMonth();
  int getYear();
  char *getDescript();
  Node *getNext();
  int getIndex();

// set//
  void setDay(int);
  void setIndex(int);
  void setMonth(int);
  void setYear(int);
  void setDescript(char *);
  void setNext(Node *);
  void setIndices();

// manipulate list //
  void getNodeInput();
  void addNode(int, int, int, char*);
  void printList();
  void printNode();
  int selectNode();
  void deleteNode(Node*, int);

// file I/O and cleanup //
  void saveList(Node*);
  void loadList(Node*);
  void freeProjects(Node *);

};
