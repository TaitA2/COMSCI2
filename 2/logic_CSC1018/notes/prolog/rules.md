# Rules

* New relations can be specified using **rules**.

### **Facts** Vs **Rules**
* **Fact** - *Unconditionally* true.
* **Rule** - Only true if some *condition* is true about other rules and facts.

## Definition
* `child(X,Y) :- parent(Y,X)`
  * **Head** - A consequence (left-hand side of the rule)
  * **Body** - A condition (right-hand side of the rule)
  * If all goals in the body succeed, the *head* succeeds.
  * Variables can be read as 'for all'.
    * `hasChild(X) :- parent(X,Y).`
    * "**for all** X and Y: X has a child **if** X is the parent of Y."

## Recursive Rules
* The rule's definition depends on the rule itself.
* 2 components
  1. Base case
  2. Recursive case

### Recursive Example
* `predecessor(X,Y) :- parent(X,Y).` (base case)
* `predecessor(X,Y) :- parent(X,Z), predecessor(Z,Y).` (recursive case)
