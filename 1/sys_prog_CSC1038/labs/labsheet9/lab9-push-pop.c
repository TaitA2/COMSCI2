/*
Author: Adam Tait
Date: 7/11/25
Description: This program converts an array of integers to a linked list, pops
the last 2 elements, pushes 2 new elements, then prints the value of all the
elements.

Approach:
- iterate through the arguments
- convert each integer into a node pointing to the next integer
- iterate through the nodes in reverse order to delete the last 2 nodes
- add the 2 new nodes to the tail
- print the new linked list values

*/

// include the libraries for input / output
#include <stdio.h>
// include the libraries for type conversions
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
LinkedList *getLinkedList(char *argv[]);
// function header for printing the values of all nodes in a linked list
void displayLinkedList(LinkedList *head);
// function header to pop last node from a linked list
void popN(LinkedList *linkedList, int n);
// function header to append a new node to the end of a linked list
void llPush(LinkedList *linkedList, int val);
// helper function header to append 2 new nodes to the end of a linked list
void llPushRemaining(LinkedList *linkedList, char *argv[]);

// main function
int main(int argc, char *argv[]) {
  // convert arguments into linked list
  LinkedList *linkedList = getLinkedList(argv);
  // pop the last 2 nodes from the linked list
  popN(linkedList, 2);
  // add the last 2 elements as nodes to the end of the linked list
  llPushRemaining(linkedList, argv);
  // print the values of all nodes in the linked list
  displayLinkedList(linkedList);
  // exit without error
  return 0;
}
// function for converting array of string numbers to nodes
// returns the tail of the linked list
LinkedList *getLinkedList(char *argv[]) {
  // declare a linked list struct
  LinkedList *linkedList = malloc(sizeof(LinkedList));
  // get the total number of nodes
  int count = atoi(argv[1]);
  // declare the head node
  Node *head = malloc(sizeof(Node));
  // set the head to have no previous node
  head->Prev = NULL;
  // set the current node as the head node
  Node *cur = head;
  // iterate through the node values
  for (int i = 0; i < count - 1; i++) {
    // set the value of the current node to the given argument
    cur->Value = atof(argv[i + 2]);
    // create the next node
    Node *next = malloc(sizeof(Node));
    // set current node as the previous of next node
    next->Prev = cur;
    cur->Next = next;
    // set the current node to its next node
    cur = cur->Next;
  }
  // set the tail node to have no next node
  cur->Value = atof(argv[count + 1]);
  cur->Next = NULL;
  // set the linked list head and tail nodes
  linkedList->Head = head;
  linkedList->Tail = cur;
  // return the linked list
  return linkedList;
}
// function for printing the values of all nodes in a linked list
void displayLinkedList(LinkedList *linkedList) {
  // set the current node to the head node
  Node *cur = linkedList->Head;
  // iterate through the linked list until the tail node is found
  while (cur != NULL) {
    // print the value of the current node
    printf("%d\n", cur->Value);
    cur = cur->Next;
  }
}

// function to remove last n nodes from a linked list
void popN(LinkedList *linkedList, int n) {
  // repeat n times
  for (int i = 0; i < n; i++) {
    // replace the tail node with its previous node
    linkedList->Tail = linkedList->Tail->Prev;
    // set the new tail's next node to null
    linkedList->Tail->Next = NULL;
  }
}
// function to append a new node to the end of a linked list
void llPush(LinkedList *linkedList, int val) {
  // create a new node for the tail and allocate sufficient memory
  Node *newTail = malloc(sizeof(Node));
  // set the new tail to have given value
  newTail->Value = val;
  // set new tails next node to NULL
  newTail->Next = NULL;
  // set the current tail node's next to the new tail
  linkedList->Tail->Next = newTail;
  // set the linked list tail node to the new node
  linkedList->Tail = newTail;
}

// function to append the remaining 2 nodes to the linked list
void llPushRemaining(LinkedList *linkedList, char *argv[]) {
  // get the count of the nodes
  int nodeCount = atoi(argv[1]);
  // push the 2 remaining arguments as nodes to the linked list
  llPush(linkedList, atoi(argv[nodeCount + 2]));
  llPush(linkedList, atoi(argv[nodeCount + 3]));
}
