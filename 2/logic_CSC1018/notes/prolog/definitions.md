# The Declarative Meaning of a Prolog Program
* A *goal* is true iff there is a *clause* where:
  * The **head** of the clause is **identical** to the goal
  * *All goals in the body* of the clause are true

## Lists of Goals
* Separated by commas
  * `Q :- R,S,T`
  * The list of goals is true if *all* goals are true 
  * **Conjunctive** (and)
* Separated by semicolons
  * `Q :- R;S;T`
  * The list of goals is true if *any* goal are true 
  * **Disjunctive** (or)

# The Procedural Meaning of a Prolog Program
* The process the run-time system uses to determine if goals are satisfied
* Important for improving efficiency

## Definition
* Given a list of goals,
  * If the list is empty, return success (base case)
* Search the program *top to bottom* for a clause whose *head* matches the first goal in the list
  * If there is no such clause, return failure
* **Replace** the first goal in the list with all the goals from the *body* of the matching clause
  * Replace the clause's variables with the goal's variables i.e. hasChild(X) becomes hasChild(tom)
* Repeat on the new goal list

# Guidelines for Writing Prolog Programs
* Due to the recursive nature of how Prolog is executed, its generally suggested to:
  * Check base cases first
  * Try the simplest idea first
