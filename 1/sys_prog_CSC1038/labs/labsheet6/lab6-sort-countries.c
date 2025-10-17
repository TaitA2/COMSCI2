/*
Author: Adam Tait
Date: 17/10/25
Description: Sort a list of countries based on their population in descend order
and print result.
*/

#include <stdio.h>
#include <stdlib.h>

// type definition of a Country struct
typedef struct {
  char *name;
  char *city;
  char *size;
  float population;
} Country;

// function header to format args into array of Country structs
void getCountries(Country countries[], int argc, char *argv[]);
// function header to format args into array of Country structs
void sortCountries(Country *countries, int low, int high);
// function header to format args into array of Country structs
void printCountries(Country *countries, int argc);

int main(int argc, char *argv[]) {
  // declare array of countries
  Country *countries = malloc(sizeof(Country) * ((argc - 1) / 4));
  // populate countries array
  getCountries(countries, argc, argv);
  // sort the countries array
  sortCountries(countries, 0, (argc - 1) / 4);
  // print the results
  printCountries(countries, argc);
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
    country.population = atof(argv[++i]);
    country.size = argv[++i];
    // add the new country to the array and increment j
    countries[j++] = country;
  }
}

// function to sort the countries in descending order by population using quick
// sort
void sortCountries(Country *countries, int low, int high) {
  // base case
  if (low >= high) {
    return;
  }
  // define pivot value as population of last country in arr
  float pivot = countries[high].population;
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (countries[j].population > pivot) {
      i++;
      Country temp = countries[j];
      countries[j] = countries[i];
      countries[i] = temp;
    }
  }
  i++;
  Country temp = countries[high];
  countries[high] = countries[i];
  countries[i] = temp;
  sortCountries(countries, i + 1, high);
  sortCountries(countries, low, i - 1);
}

// function to print header row and each country
void printCountries(Country *countries, int argc) {
  // print table header row
  printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
  // iterate over the countries array and print the info
  for (int i = 0; i < (argc - 1) / 4; i++) {
    printf("%s\t\t\t%s\t\t\t%s\t\t\t%.2f\n", countries[i].name,
           countries[i].city, countries[i].size, countries[i].population);
  }
}
