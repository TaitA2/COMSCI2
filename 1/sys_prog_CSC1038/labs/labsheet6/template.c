/*
Author: Adam Tait
Date: 17/10/25
Description:
*/

#include <stdio.h>
#include <stdlib.h>

// type definition of a Country struct
typedef struct {
  char *name;
  char *city;
  char *population;
  char *size;
} Country;

// function header to format args into array of Country structs
void getCountries(Country countries[], int argc, char *argv[]);
// function header to format args into array of Country structs
void printCountries(Country *countries, int argc);

// main function
int main(int argc, char *argv[]) {
  //
  return 0;
}

// function to format args into an array of Country structs
void getCountries(Country countries[], int argc, char *argv[]) {
  // initialise countries index j
  int j = 0;
  // initialise args index i
  int i = 0;
  // iterate over all arguments
  while (i < argc - 1) {
    // initialise a new Country struct
    Country country;
    // set the country attribute to the given argument, incrementing i
    country.name = argv[++i];
    country.city = argv[++i];
    country.population = argv[++i];
    country.size = argv[++i];
    // add the new country to the array and increment j
    countries[j++] = country;
  }
}

// function to print header row and each country smaller than 10000 km2
void printCountries(Country *countries, int argc) {
  // print table header row
  printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
  // iterate over the countries array and print the info
  for (int i = 0; i < (argc - 1) / 4; i++) {
    // only print country info if the size is smaller than 100000 km2
    if (atoi(countries[i].size) < 100000) {
      printf("%s\t\t\t%s\t\t\t%s\t\t\t%s\n", countries[i].name,
             countries[i].city, countries[i].size, countries[i].population);
    }
  }
}
