/*
Author: Adam Tait
Date: 17/10/25
Description: Print the largest city in each country given.
*/

#include <stdio.h>
#include <stdlib.h>

// type definition of a City struct
typedef struct {
  char *name;
  float size;
} City;
// type definition of a Country struct
typedef struct {
  char *name;
  City cities[3];
} Country;

// function header to format args into array of Country structs
void getCountries(Country countries[], int argc, char *argv[]);
// function header to format args into array of Country structs
void printCountries(Country *countries, int argc);

// main function
int main(int argc, char *argv[]) {
  // declare array of countries
  Country *countries = malloc(sizeof(Country) * ((argc - 1) / 7));
  // populate countries array
  getCountries(countries, argc, argv);
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
    for (int k = 0; k < 3; k++) {
      // declare city
      City city;
      city.name = argv[++i];
      city.size = atof(argv[++i]);
      country.cities[k] = city;
    }
    // add the new country to the array and increment j
    countries[j++] = country;
  }
}

// function to print each country and its smallest city
void printCountries(Country *countries, int argc) {
  // iterate over the countries array and print the info
  for (int i = 0; i < (argc - 1) / 7; i++) {
    // find the biggest city in the country
    // declare biggest as first city in array
    City biggest = countries[i].cities[0];
    // iterate over rest of array and replace biggest if any city is bigger
    for (int j = 1; j < 3; j++) {
      if (countries[i].cities[j].size > biggest.size) {
        biggest = countries[i].cities[j];
      }
    }
    // print Country: Biggest-City
    printf("%s: %s\n", countries[i].name, biggest.name);
  }
}
