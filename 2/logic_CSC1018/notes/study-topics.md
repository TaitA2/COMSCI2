# Section A - Logic
## Q1
* convert a statement into a set of **predicate** or **propositional** formulae
  * predicate for exam, propositional for resit
* convert the above set into **(Prenex) Conjunctive Normal Form**
  * PCNF for exam, CNF for resit
* using **(General) Resolution**, prove something
  * general resolution for exam, resolution for resit

## Q2
* **without using truth tables**, prove `(p -> q) ^ ¬q = ¬(p V q)` (or something similar)
  * clearly indicate which **logical equivalence** is used at each step

## Q3
* **SEMANTIC TABLEAUX**
  * Using semantic tableaux, prove the following **propositional formula** is valid
  * clearly indicate which **inference rule** is used at each step

## Q4
* **GENTZEN SYSTEM G**
  * Use the gentzen system G to prove something
  * clearly indicate which **inference rule** is used at each step

## Q5
* Similar to Q1 but formula has **∃** and **∀**
* **SEMANTIC TABLEAUX**
  * Using semantic tableaux, prove the following **first-order statement** is valid
* **Prenex Conjunctive Normal Form**
  * Convert following formula to PCNF

## Q6
* Similar to Q4 but formula has **∃** and **∀**
* **GENTZEN SYSTEM G**
  * Use the gentzen system G to prove predicate formula

# Section B - Prolog
## Q7
* Check something recursively?
  * split(N, Pos, Neg)        - True if all positive numbers in N are in Pos and all negatives are in Neg **2 exams**
  * south(X, Y) or east(X, Y) - True if X directly south / east of Y given a grid of points
  * union(A,B,C)              - C is all even numbers in either A or B or both
  * intersection(A,B,C)       - C is all even numbers in both A and B
  * calculate length of a list
  * append a list to another list

## Q8
* Arithmetic operations
  * sum all the squares of all the odd numbers in a list **3 exams**
  * sum elements in a list of integers 
  * find the maximum in a list of elements

## Q9
* Describe **cuts** in Prolog. Why are they used? Illustrate your answer with examples **4 EXAMS**
* Describe the procedural interpretation of a Prolog exam **2 exams**
