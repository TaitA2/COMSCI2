/*
Author: Adam Tait
Date: 7/11/25
Description: This program takes a feed of product information and prints the
total value of all products in stock, accounting for discounts

Approach:
- define a struct for a Product to contain all information
- convert the arguments to an array of Product structs
- iterate through the Product array and add up the collective values
- total value calculated as price * stock
- discount of 10% applied where relevent
- print the total value

*/

// include the libraries for input / output
#include <stdio.h>
// include the libraries for type conversions
#include <stdlib.h>
// include the libraries for the boolean type
#include <stdbool.h>

// struct definition of a Product
// using typedef to remove need for 'struct' keyword when used
typedef struct {
  char *Name;         // string for the product's name
  unsigned int Stock; // unsigned int for the product's stock
  float Price;        // float for the product's price
  bool Discount;      // boolean to show if the product is at a discount
} Product;

// function header for converting 4 string elements to a Product struct
// used by allToProd
Product toProd(char *elems[]);
// function header for converting an array of strings into an array of Products
Product *allToProd(int arrLen, char *elems[]);
// function header to calculate the total value of a given product
float prodVal(Product product);
// function header to calculate the total value of all products in an array
float allProdVals(int arrLen, Product *products);

// main function
int main(int argc, char *argv[]) {
  // declare number of products as the number of elements / 4
  int prodCount = (argc - 1) / 4;
  // convert the string arguments to an array of Products
  Product *prodArr = allToProd(prodCount, argv);
  // declare a total value
  float total;
  // calculate the total value of all products
  total = allProdVals(prodCount, prodArr);
  // print the total
  printf("%.2f\n", total);

  // unallocate the memory used by the product array
  free(prodArr);
  // exit without error
  return 0;
}

// function to convert an array of 4 string elements to a Product struct
Product toProd(char *elems[]) {
  // declare the new product struct
  Product newProduct;
  // populate the product attributes with each element
  newProduct.Name = elems[0];
  newProduct.Stock =
      (unsigned int)strtoul(elems[1], NULL, 10); // convert to unsigned int
  newProduct.Price = atof(elems[2]);             // convert to float
  newProduct.Discount = atoi(elems[3]) == 1;     // convert to boolean
  // return the new product struct
  return newProduct;
}

// function to convert an array of strings to an array of Product structs
Product *allToProd(int prodCount, char *elems[]) {
  // declare the array of products and allocate sufficient memory
  Product *prodArr = malloc(sizeof(Product) * prodCount);
  // convert the arguments to populate the product array
  for (int i = 1; i < prodCount * 4; i += 4) {
    // store the next 4 elements together since they are one product
    char *newElems[4];
    for (int j = 0; j < 4; j++) {
      newElems[j] = elems[i + j];
    }
    // use the elements to create a new product struct
    Product newProduct = toProd(newElems);
    // store new product in the product array
    prodArr[(i - 1) / 4] = newProduct;
  }

  // return the array of product structs
  return prodArr;
}

// function to calculate the total value of a given product
float prodVal(Product product) {
  // return the product price times the product stock
  // apply a disount of 10% if the product has a discount
  return product.Price * product.Stock * (product.Discount ? 0.9 : 1);
}
// function header to calculate the total value of all products in an array
float allProdVals(int arrLen, Product *products) {
  // initialise a total value of 0
  float total = 0;
  // iterate through the array of products
  for (int i = 0; i < arrLen; i++) {
    // increase the total value by the value of each product
    total += prodVal(products[i]);
  }
  return total;
}
