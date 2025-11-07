/*
Author: Adam Tait
Date: 7/11/25
Description: This program converts an array of floats to a doubly linked list
then prints the value of all the elements in reverse order.

Approach:
- iterate through the arguments
- convert each integer into a node pointing to the previous and next integers
- iterate through the nodes in reverse order and print their values


*/
// include the libraries for input / output
#include <stdio.h>
// include the libraries for type conversions
#include <stdlib.h>

// struct definition of a Node
typedef struct Node {
  float Value;       // the value stored in the node
  struct Node *Prev; // a pointer to the previous node in the linked list
  struct Node *Next; // a pointer to the next node in the linked list
} Node;

// function header for converting array of string numbers to nodes
// returns the head of the linked list
Node *getLinkedList(char *argv[]);
// function header for printing the values of all nodes in a linked list
void displayLinkedList(Node *head);

// main function
int main(int argc, char *argv[]) {
  // convert arguments into linked list
  Node tail = *getLinkedList(argv);
  // printf("main head: %d\n", head.Value);
  // print the values of all nodes in the linked list
  displayLinkedList(&tail);
  // exit without error
  return 0;
}
// function for converting array of string numbers to nodes
// returns the tail of the linked list
Node *getLinkedList(char *argv[]) {
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
  // return the head node
  return cur;
}
// function for printing the values of all nodes in a linked list
void displayLinkedList(Node *tail) {
  // set the current node to the head node
  Node *cur = tail;
  // iterate through the linked list until the tail node is found
  while (cur != NULL) {
    // print the value of the current node
    printf("%.2f\n", cur->Value);
    cur = cur->Prev;
  }
}
