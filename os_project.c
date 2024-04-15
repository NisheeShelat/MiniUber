#include<stdio.h>
#include<stdlib.h>

struct node
{
    char *data;
    struct node*next;
};



struct node *start = NULL;
void insert_at_begin();

void traverse();
void delete_from_begin();
void delete_from_end();
int count = 0;

int main () {
  int i;

  for (;;) {
    printf("1. Insert a file.\n");
    printf("2. Delete a file.\n");

    printf("3. Traverse linked list.\n");
    printf("4. Delete an element from beginning.\n");
    printf("5. Delete an element from end.\n");
    printf("6. Exit\n");

    scanf("%d", &i);

    if (i == 1)
        {
      printf("Enter value of element\n");
      scanf("%s", &data);
      insert_at_begin(data);
    }



    else if(i==2)
    {

    }

    else if (i == 3)
      traverse();
    else if (i == 4)
      delete_from_begin();
    else if (i == 5)
      delete_from_end();
    else if (i == 6)
      break;
    else
      printf("Please enter valid input.\n");
  }

  return 0;
}

void insert_at_begin() {
   char name[20];
  struct node *t;
  printf("Enter the file name\n");
  scanf("%s", &name);


  t = (struct node*)malloc(sizeof(struct node));
  t->data = name;
  count++;

  if (start == NULL) {
    start = t;
    start->next = NULL;
    return;
  }

  t->next = start;
  start = t;
}



void traverse() {
  struct node *t;

  t = start;

  if (t == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  printf("There are %d elements in linked list.\n", count);

  while (t->next != NULL) {
    printf("%d\n", t->data);
    t = t->next;
  }
  printf("%d\n", t->data); // Print last node
}

void delete_from_begin() {
  struct node *t;
  int n;

  if (start == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  n = start->data;
  t = start->next;
  free(start);
  start = t;
  count--;

  printf("%d deleted from the beginning successfully.\n", n);
}

void delete_from_end() {
  struct node *t, *u;
  int n;

  if (start == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  count--;

  if (start->next == NULL) {
    n = start->data;
    free(start);
    start = NULL;
    printf("%d deleted from end successfully.\n", n);
    return;
  }

  t = start;

  while (t->next != NULL) {
    u = t;
    t = t->next;
  }

  n = t->data;
  u->next = NULL;
  free(t);

  printf("%d deleted from end successfully.\n", n);
}
