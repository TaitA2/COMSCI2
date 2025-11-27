/*
Author: Adam Tait
Date: 27/11/25
Description:

  This program will use a linked list to
  accept a number of patients and their details,
  automatically assign IDs in the order they are inserted,
  Display the full queue in order of arrival in the format:

  ID: <id>,
  Name: <name>,
  Priority: <priority>

  It will then count and display how many patients have priority 4 or 5 (high priority) in the format:

  High priority count: <number>
  

*/

// import relevant libraries
#include <stdio.h>
#include <stdlib.h>

// struct definition of a patient
typedef struct Patient{
  int ID; // patient ID automatically assigned in order they appear
  char Name[50]; // name of patient as given
  int Priority; // priority of patient as given 1-5 where 5 is the highest priority
  struct Patient* Next; // pointer to next patient in the linked list
} Patient;

// function header to convert command line arguments to linked list of patient structs
Patient *parsePatients(int numPatients, char *argv[]);
// function header to convert array of strings into a single patient struct
Patient *parsePatient(int ID, char* Name, int Priority);
// function header to print info of all patients in linked list
void printPatients(Patient *headPatient);

// main function
int main(int argc, char *argv[]){

  // assign number of patients
  int numPatients = atoi(argv[1]);

  // generate linked list of patients and get a pointer to the head node
  Patient *headPatient = parsePatients(numPatients, argv);

  // print all patient info
  printPatients(headPatient);

  // exit without error
  return 0;
}

// function to convert command line arguments to linked list of patient structs
Patient *parsePatients(int numPatients, char *argv[]){
  // initialise the ID to 1
  int ID = 1;

  // initialise j for parsing arguments
  int j = 2;
  // create the headPatient from the arguments
  Patient *headPatient = parsePatient(ID++,argv[j], atoi(argv[j+1]));
  j+=2;
  Patient *cur = headPatient;

  // parse remaining patients into linked list
  while (ID <= numPatients){
    struct Patient *next = parsePatient(ID++, argv[j], atoi(argv[j+1]));
    j+=2;
    cur->Next = next;
    cur = cur->Next;
   }

  // return the pointer to the head of the linked list
  return headPatient;
}

// function to convert array of strings into a single patient struct
Patient *parsePatient(int ID, char* Name, int Priority){

  // initialise a pointer to the new patient struct and allocate necessary memory
  Patient *newPatient = malloc(sizeof(Patient));

  // set the patient parameteres as provided
  newPatient->ID = ID;
  sprintf(newPatient->Name,"%s", Name);
  newPatient->Priority = Priority;
  newPatient->Next = NULL;

  // return the pointer to the new patient
  return newPatient;
}

// funtion to iterate through linked list of patients and print their info in the specified format
void printPatients(Patient *headPatient){
  // initialise high priority count
  int highPriority = 0;

  // set current patient to head patient
  Patient *cur = headPatient;

  // iterate until the tail node
  while (cur->Next){
    // increase high priority if relevent
    if (cur->Priority > 3){
      highPriority++;
    }
    // print current patient info
    printf("ID: %d, Name: %s, Priority: %d\n", cur->ID, cur->Name, cur->Priority);
    // move onto next node
    cur = cur->Next;
  }
    // increase high priority if relevent
    if (cur->Priority > 3){
      highPriority++;
    }
  // print info of the tail node patient
  printf("ID: %d, Name: %s, Priority: %d\n", cur->ID, cur->Name, cur->Priority);
  // print count of high priority patients
  printf("High priority count: %d\n", highPriority);
}
