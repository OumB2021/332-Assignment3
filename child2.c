#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

// insert a new node at the beginning of the linked list
struct node *insertInLinkedList(struct node *head, int data)
{
  // create a new node
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data; // insert data into new node
  newNode->next = head; // have new node point to head
  newNode->prev = NULL; // new node prev point to null

  // make the new node to be head
  if (head != NULL)
  {
    head->prev = newNode;
  }

  return newNode; // return the new node
}

// Display linked list
void displayLinkedList(struct node *head)
{
  struct node *current = head;
  // Traverse the linked list and print the values

  printf("Reverse order: ");

  while (current->next != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("%d -> NULL\n", current->data);

  printf("Forward order: ");
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->prev;
  }
  printf("NULL\n");
}

int main(int argc, char *argv[])
{

  int ans;                          // to store the answer of the user
  FILE *file = fopen(argv[1], "r"); // open the file
  int valueRead;                    // read the value
  struct node *head = NULL;         // Create an empty doubly linked list

  // Check if file is opened
  if (file == NULL)
  {
    perror("Error opening the file");
    return 1;
  }

  while (fscanf(file, "%d", &valueRead) == 1)
    head = insertInLinkedList(head, valueRead);

  displayLinkedList(head);
  fclose(file);

  system("cls");
  displayLinkedList(head);
  return 0;
}