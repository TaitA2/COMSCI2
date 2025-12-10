/*
Author: Adam Tait
Date: 10/12/2025
Description:  This program accepts a list of integers as command line arguments,
              then stores them in a linked list, removes any duplicate values,
              then prints the duplicate free result.
Approach:
- Cast arguments as nodes and store in a singly linked list
- iterate through the linked list and check if the values have been seen before
- remove any nodes with already seen values
- print the resulting list
- free memory 
*/

// include relevant libraries
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
LinkedList *getLinkedList(int count, char *argv[]);
// function to remove nodes with duplicate values from linked list
void removeDuplicates(LinkedList *ll);
// function header for printing the values of all nodes in a linked list
void displayLinkedList(LinkedList *ll);

// main function
int main(int argc, char *argv[]){
  // convert arguments to a linked list
  LinkedList *ll = getLinkedList(argc-1, argv);
  // remove duplicates from linked list in place
  removeDuplicates(ll);
  // print resulting list
  displayLinkedList(ll);
  // free used memory
  free(ll);
  // exit without error
  return 0;
}

// function for converting array of string numbers to nodes
// returns the head of the linked list
LinkedList *getLinkedList(int count, char *argv[]) {
  // declare the head node
  Node *head = malloc(sizeof(Node));
  // set the current node as the head node
  Node *cur = head;
  // iterate through the node values
  for (int i = 1; i < count; i++) {
    // set the value of the current node to the given argument
    cur->Value = atoi(argv[i]);
    // create the next node
    Node *next = malloc(sizeof(Node));
    cur->Next = next;
    // set the current node to its next node
    cur = cur->Next;
  }
  // set the tail node to have no next node
  cur->Value = atoi(argv[count]);
  cur->Next = NULL;

  // declare linked list 
  LinkedList *ll = malloc(sizeof(LinkedList));

  // store head and tail nodes in the linked list
  ll->Head = head;
  ll->Tail = cur;

  // return the linked list
  return ll;
}

// function to remove nodes with duplicate values from linked list in place
void removeDuplicates(LinkedList *ll){
  // initialise array of seen values
  int seen[100];
  // initialise j for appending to seen
  int j = 0;
  // set current node to head of linked list
  Node *cur = ll->Head;
  // store head node value as seen
  seen[j] = cur->Value;
  j++;

  // iterate through linked list
  while (cur != NULL && cur->Next != NULL){
    // iterate throught seen to check for next nodes value
    int i = 0;
    while (i < j && cur->Next->Value != seen[i]){
      i++;
    }

    // value not seen before
    if (i == j){
      // add next node value to seen
      seen[j] = cur->Next->Value;
      // increment j
      j++;
      // set current node to next node
      cur = cur->Next;
    // value has been seen
    } else {
      // delete next node by setting current node next to the node after next
        cur->Next = cur->Next->Next;
      } 
  }

  return;
}

// function for printing the values of all nodes in a linked list
void displayLinkedList(LinkedList *ll) {
  // set the current node to the head node
  Node *cur = ll->Head;
  // iterate through the linked list until the tail node is found
  while (cur != NULL) {
    // print the value of the current node
    printf("%d\n", cur->Value);
    cur = cur->Next;
  }
}
