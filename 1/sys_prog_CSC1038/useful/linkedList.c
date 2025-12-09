#include <stdio.h>
#include <stdlib.h>

// struct definition of a Node
typedef struct Node {
  int Value;         // the value stored in the node
  struct Node *Prev; // a pointer to the previous node in the linked list
  struct Node *Next; // a pointer to the next node in the linked list
} Node;

// struct definition of a Linked List
typedef struct {
  Node *Head; // pointer to the head node
  Node *Tail; // pointer to the tail node
} LinkedList;

// function header for converting array of string numbers to nodes
// returns the head of the linked list
Node *getLinkedList(char *argv[]);
// function header for printing the values of all nodes in a linked list
void displayLinkedList(Node *head);
// function header for inserting a new node with value m after the existing node
// with value n in a linked list
void llInsert(LinkedList *linkedList, int n, int m);

// function for converting array of string numbers to nodes
// returns the head of the linked list
Node *getLinkedList(char *argv[]) {
  // get the total number of nodes
  int count = atoi(argv[1]);
  // declare the head node
  Node *head = malloc(sizeof(Node));
  // set the current node as the head node
  Node *cur = head;
  // iterate through the node values
  for (int i = 0; i < count - 1; i++) {
    // set the value of the current node to the given argument
    cur->Value = atoi(argv[i + 2]);
    // create the next node
    Node *next = malloc(sizeof(Node));
    cur->Next = next;
    // set the current node to its next node
    cur = cur->Next;
  }
  // set the tail node to have no next node
  cur->Value = atoi(argv[count + 1]);
  cur->Next = NULL;
  // return the head node
  return head;
}
// function for printing the values of all nodes in a linked list
void displayLinkedList(Node *head) {
  // set the current node to the head node
  Node *cur = head;
  // iterate through the linked list until the tail node is found
  while (cur != NULL) {
    // print the value of the current node
    printf("%d\n", cur->Value);
    cur = cur->Next;
  }
}

// function  for inserting a new node with value m after the existing node with
// value n in a linked list
void llInsert(LinkedList *linkedList, int n, int m) {
  // set current node to head of linked list
  Node *cur = linkedList->Head;
  // make a new node with value m
  Node *newNode = malloc(sizeof(Node));
  newNode->Value = m;
  // iterate through the linked list
  while (cur->Next != NULL) {
    // a node with the value of n is found
    if (cur->Value == n) {
      // set the next of the new node to the next of the current node
      newNode->Next = cur->Next;
      // set the previous of the new node to the current node
      newNode->Prev = cur;
      // set the previous of the current node's next to the new node
      cur->Next->Prev = newNode;
      // set the next of the current node to the new node
      cur->Next = newNode;
      // end the function
      return;
    }
    // set the current node to its next node
    cur = cur->Next;
  }
  // set the next of the new node to the next of the current node
  newNode->Next = cur->Next;
  // set the previous of the new node to the current node
  newNode->Prev = cur;
  // set the next of the current node to the new node
  cur->Next = newNode;
  // set linked list tail to new node
  linkedList->Tail = newNode;
}
