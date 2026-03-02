# Facts
* Written as relations

## Example
* `parent(tom, bob).`
  * A relation called parent
  * The relation takes two arguments, tom and bob
  * tom and bob are symbols since they begin with a lowercase letter
* (more in ./family.pl)
  
# Querying Facts
* `?- parent(tom, bob).`
  * true
* `?- parent(ann, jim).`
  * false
* We can replace a symbol in a query by a variable.
  * **Variables start with an uppercase letter**
* `?- parent(X, bob).`
  * X = tom.

# Compound Queries
* We can construct complicated queries by combining simpler ones
* Who are Jim's grandparents?
  * `?- parent(Y, jim), parent(X,Y).`
  * Y = mary , (jim's parent)
  * X = bob ; (jim's grandparent)
  * false
* Who are Tom's grandchildren?
  * `?- parent(Tom, X), parent(X,Y).`  

# Clauses
* Prolog program consists of a series of clauses, each ending in '.'
* Clauses define relations by simply stating the objects that satisfy the relation
* The arguments of a query can be:
  * **Atoms**     - concrete objects or constants
  * **Variables** - general objects
* A query to the Prolog run-time system is a series of *goals*.
  * Query: `parent(tom, X), parent(X,Y).`
  * the *goals* are:
    1. `parent(tom, X)`
    2. `parent(X, Y)`
  * The query is satisfied if both *goals*
* If a *goal* is satisfied then it has succeeded, otherwise it has failed.
* If multiple answers satisfy the goals, then the Prolog run-time system will find as many as the user requests.
