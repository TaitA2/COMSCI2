/*
Author: Adam Tait
Date: 10/10/2025
Description:
Using structs, format arguments into a table of country info
*/
#include <stdio.h>

// type definition of a Country struct
typedef struct {
  char *name;
  char *city;
  char *population;
  char *size;
} Country;

// function header to format args into array of Country structs
void getCountries(Country countries[], int argc, char *argv[]);

int main(int argc, char *argv[]) {
  // declare array of countries
  Country countries[(argc - 1) / 4];
  // populate cuntries array
  getCountries(countries, argc, argv);
  // print table header row
  printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
  // iterate over the countries array and print the info
  for (int i = 0; i < sizeof(countries) / sizeof(countries[0]); i++) {
    printf("%s\t\t\t%s\t\t\t%s\t\t\t%s\n", countries[i].name, countries[i].city,
           countries[i].size, countries[i].population);
  }
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
