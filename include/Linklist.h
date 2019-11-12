//Sam Baker
//Link list and node Management

#define FILE_NAME "bin/projectlist.txt"
#define TEXT_LEN 128

struct Project{
  int dueday, duemonth, dueyear;
  char descript[TEXT_LEN];
  struct Project *next;
};

void printList(struct Project*);
void addProject(struct Project*, int, int, int, char*);
void getProject(struct Project*);
void completeProject(struct Project*);
void freeProjects(struct Project*);
void saveList(struct Project*);

/////////////////////////////////////////////////////////////////////////

void printList(struct Project *n){
  int i = 1;
  n = n->next;
  while(n){
    printf("%d: %d/%d/%d: %s \n",i, n->dueday, n->duemonth, n->dueyear, n->descript);
    n = n->next;
    i++;
  }
}

/////////////////////////////////////////////////////////////////////////

void getProject(struct Project *n){
  int dueday, duemonth, dueyear;
  char detail[255];
  printf("Please enter the duedate for your project (dd/mm/yyyy)\n");
  scanf("%d/%d/%d", &dueday, &duemonth, &dueyear);
  while(dueday > 31 || dueday <= 0 ||
        duemonth > 12 || duemonth <= 0){
    printf("Invalid date, please enter in the format dd/mm/yyyy \n");
    scanf("%d/%d/%d", &dueday, &duemonth, &dueyear);
  }

  printf("Please enter the details for this project:\n");
  scanf("\n%[^\n]%*c", detail);

  addProject(n, dueday, duemonth, dueyear, detail);
}

/////////////////////////////////////////////////////////////////////////

void addProject(struct Project *n, int dueday, int duemonth, int dueyear, char *detail){
  struct Project *temp = (struct Project*)malloc(sizeof(struct Project)+1);

  temp->dueday = dueday;
  temp->duemonth = duemonth;
  temp->dueyear = dueyear;
  strcpy(temp->descript, detail);

  while(n->next != NULL){
    if ((dueyear < n->next->dueyear) ||

    ((dueyear == n->next->dueyear) &&
    (duemonth < n->next->duemonth)) ||

    ((dueyear == n->next->dueyear) &&
    (duemonth == n->next->duemonth) &&
    (dueday < n->next->dueday))){
      break;
    }
    n = n->next;
  }

  if (n->next != NULL){
    temp->next = n->next;
    n->next = temp;
  }
  else{
    n->next = temp;
    temp->next = NULL;
  }
}

/////////////////////////////////////////////////////////////////////////

void completeProject(struct Project* n){
  struct Project *temp;
  int index, i = 0;

  printList(n);
  printf("\n Please select the item you would like to delete\n");
  scanf("%d", &index);

  while (n != NULL){

    if(i == index - 1){
      temp = n->next;
      if(temp){
        n->next = n->next->next;
        free(temp);
        }

      }
    n = n->next;
    i++;
    }
}

/////////////////////////////////////////////////////////////////////////

void saveList(struct Project* n){
  FILE *save_file = fopen(FILE_NAME, "w");
  int i = 0;

  if (save_file != NULL){
    n = n->next;
    while(n != NULL){
      fprintf(save_file, "%d/%d/%d %s \n", n->dueday, n->duemonth, n->dueyear, n->descript);
      n = n->next;
    }
  fclose(save_file);
  }
}

/////////////////////////////////////////////////////////////////////////

void loadList(struct Project* n){
  FILE *load_file = fopen(FILE_NAME, "r");
  int dueday, duemonth, dueyear;
  char descript[TEXT_LEN];
  char buffer[2*TEXT_LEN];

  while(fscanf(load_file, "%d/%d/%d %[^\n]",
        &dueday, &duemonth, &dueyear, &descript) != EOF)
        {
    addProject(n, dueday, duemonth, dueyear, descript);
  }

  fclose(load_file);
}

/////////////////////////////////////////////////////////////////////////

void freeProjects(struct Project *n){
  struct Project *next;

  while(n != NULL){
    next = n->next;
    free(n);
    n = next;
  }

}
