# Arithmetic
* Prolog is a symbolic language, so
  * `?- X = 1 + 2`
  * X = 1+2, **NOT** X = 3
* This is because 1 + 2 is a Prolog term
  * The functor is +, the arguments are 1 and 2
* To enforce evaluation, use the keyword 'is'
  * `?- X is 1 + 2.`
  * X = 3

## Predefined Arithmetic Operators
* All the usual ones
* `mod` for modulus 

## Comparison Operators
* Comparison operators force evaluation
  * `=:=` is equal
  * `=\=` is not equal
  * `>=` and `=<`
