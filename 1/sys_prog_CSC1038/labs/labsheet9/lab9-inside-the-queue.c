/*
Author: Adam Tait
Date: 7/11/25
Description: This program takes integers n and m as input. It inserts a node
with value m after the node with value n in a linked list

Approach:
- iterate through the arguments
- convert each integer into a node pointing to the next integer
- iterate through the nodes to find node with value n
- create a new node with value m
- set next node of m to the next node of n
- set next node of n to m
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
// function header for inserting a new node with value m after the existing node
// with value n in a linked list
void llInsert(LinkedList *linkedList, int n, int m);

// main function
int main(int argc, char *argv[]) {
  // array of strings of given unique numbers
  char *input[] = {"10", "8", "7", "3", "4", "5", "6", "9", "2", "14", "12"};
  // convert given numbers into linked list
  LinkedList *linkedList = getLinkedList(input);
  // set value of existing node
  int n = atoi(argv[1]);
  // set value of new node
  int m = atoi(argv[2]);
  // insert the new node after the existing one
  llInsert(linkedList, n, m);
  // print the values of all nodes in the linked list
  displayLinkedList(linkedList);
  // unallocate all used memory
  free(linkedList);
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
  for (int i = 0; i < count + 1; i++) {
    // set the value of the current node to the given argument
    cur->Value = atof(argv[i + 1]);
    // create the next node
    Node *next = malloc(sizeof(Node));
    // set current node as the previous of next node
    next->Prev = cur;
    cur->Next = next;
    // set the current node to its next node
    cur = cur->Next;
  }
  // set the tail node to have no next node
  cur->Value = atof(argv[count + 2]);
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
