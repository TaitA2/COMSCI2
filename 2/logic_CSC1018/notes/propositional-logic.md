# Propositional Logic Notes

## Boolean operators
### Types of operators
* Unary
  * one argument
* Binary
  * two arguments
### Operators
* ¬ (not)
  * unary
  * True iff the argument is False
* ^ (Conjunction)
  * Binary
  * True iff both are true
* ∨ (Disjunction) 
  * Binary
  * True if either is true
* ⊕ (XOR)
  * Binary
  * True iff exactly one is True
* -> (Implication)
  * Binary
  * x -> y 
  * True unless x is True and y is False
* <-> (Equivalence)
  * Binary
  * True iff both are True or both are False
* ↑ (Nand)
  * Binary
  * Negation of AND
  * x ↑ y <-> ¬(x ^ y)
* ↓ (Nor)
  * Binary
  * Negation of OR
  * x ↓ y <-> ¬(x v y)

## Ambiguity
* Formulae can be ambiguous
  * eg. p -> q <-> ¬p -> ¬q
  * p implies that q is equal to ...
  * p implies q is an equal statement to ...
* Solutions
  * brackets
  * precedence
  * assume operators associate to the right

## Precedence
1. not
2. and, nand
3. or, nor
4. ->
5. <->, xor
