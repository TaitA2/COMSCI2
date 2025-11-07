/*
Author: Adam Tait
Date: 7/11/25
Description: This program converts a feed of product information into formatted
output as:
          Product Name (string)
          Stock (uint)
          Price (float)
          Discount (1 or 0)
Approach:
- define a struct for a Product to contain all information
- convert the arguments to an array of Product structs
- iterate through the Product array and print formatted information

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
// function header to format the info of a product
char *displayProduct(Product product);
// function header to print the formatted info of all products in an array
void displayAllProducts(int arrLen, Product *products);

// main function
int main(int argc, char *argv[]) {
  // declare number of products as the number of elements / 4
  int prodCount = (argc - 1) / 4;
  // convert the string arguments to an array of Products
  Product *prodArr = allToProd(prodCount, argv);
  // print the formatted information of all products
  displayAllProducts(prodCount, prodArr);
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

// function to format the info of a product
char *displayProduct(Product product) {
  // print the product info in the format: name, stock, price, discount
  char *formatted = malloc(sizeof(char) * 100);
  sprintf(formatted, "%s,%d,%.2f,%s\n", product.Name, product.Stock,
          product.Price, product.Discount ? "Discounted" : "No Discount");
  // return the formatted string
  return formatted;
}
// function to print the formatted info of all products in an array
void displayAllProducts(int arrLen, Product *products) {
  // iterate through the array of products
  for (int i = 0; i < arrLen; i++) {
    // get a formatted string of the product info
    char *prodInfo = displayProduct(products[i]);
    // print the formatted info of each product
    printf("%s", prodInfo);
    // unallocated the memory used by the string buffer
    free(prodInfo);
  }
}
