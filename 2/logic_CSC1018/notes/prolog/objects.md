# Data Objects in Prolog
* data objects
  * structures
  * simple objects
    * variables
    * constants
      * numbers
      * atoms

## Atoms and Numbers
### Atoms
* Strings of letters, digits '0'-'9', or underscores, *starting with a lowercase char*
* Strings composed of special chars (+-*/<>=:.&_).
  * Some sequences like ':-' are already reserved by Prolog.
* Strings *enclosed in single quotes* like 'Tom', 'Mr_Smith'

### Numbers
* Ints or floats
* 12 and -123 are ints
* 0.123 and 10.987 are floats
  * Prolog is designed for symbolic computation so its best to avoid heavy numeric computation

## Variables
* A string of letters, digits, or underscores that start with either **uppercase** char or an **underscore**
* If a variable occurs only once in a clause, you can use the *anonymous variable* '_'.
  * `hasChild(X) :- parent(X,Y).` is equivalent to `hasChild(X) :- parent(X,_).`
* A variables **scope** is limited to the clause that mentions it

## Structures
* Objects with **several components** 
* Components can be other structures or variables

### Breakdown
* Each structure is composed of:
  * A **Functor** - name of the structure
  * A set of components

### Structure Example
* A structure for recording the date could be
  * `date(1,may,2012).`
  * **Functor** - date
  * Components - day, month, and year
* To represent a triangle
  * `triangle(point(1,2), point(6,3), point(4,5)).`

## Matching
* Prolog finds the *most general* instantiation of variables in an expression.

### Rules for Matching
* If X and Y are constants, they match iff they are the same object
* If X is a variable and Y is anything, they match and X is instantiated to Y and vice versa if Y is a variable.
* If X and Y are structures, they match iff:
  * X and Y have the same principle functor
  * all their corresponding components match
