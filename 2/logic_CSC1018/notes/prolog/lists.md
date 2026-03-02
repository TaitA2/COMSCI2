# Lists
* A sequence of atoms
* 2 forms:
  1. Empty, []
  2. **Head** (first list item) and **Tail** (rest of the list)
* The head and tail are combined by a special functor '.'
  * .( Head, Tail)
* `[tom, football, golf, harry, poker]` is represented internally as:
  * `.( tom, .( football, .( golf, .( harry, .( poker, [ ] )))))`
* Both notations `.( )` and `[]` can be used to represent lists.
* Lists can contain other lists
* The lists is a **recursive** data structure

## Tail
* Usually referred to as a single object
* Prolog uses `|` to represent the remainder of a list
  * `L = [ a | Tail]`
* Any number of atoms can be listed before `|`, so the following are all equivalent:
  * `[a | [b, c]]`
  * `[a, b | [c]]`
  * `[a, b, c | []]`

## List Operations
### Membership
* X is an element of a list if either:
  1. X is the *head* of the list (base case); or
  2. X is an element of the *tail* of the list
* In Prolog:
  * `member(X, [X|_]).` (base case)
  * `member(X, [_|Tail]) :- member(X, Tail).`

### Concatenation
* We define a relation `conc(L1, L2, L3)`, which is true if L3 is the concatenation of L1 and L2.
* L3 is a concatenation of L1 and L2 if either:
  1. L1 is empty and L2 == L3 (base case)
  2. The heads of L1 and L3 are the same and the tail of L3 is the tail of L1 concatenated with L2
* In Prolog:
  * `conc([], L, L).` (base case)
  * `conc([X|L1], L2, [X|L3]) :- conc(L1,L2,L3).`
* Now we can execute queries like:
  * `?- conc([a,b,c], [d,e], L).`
    * `L = [a,b,c,d,e]`

  * `?- conc(L, [d,e], [a,b,c,d,e]).`
    * `L = [a,b,c]`

  * `?- conc(_, [X, apr, Y], [jan,feb,mar,apr,may,jun, jul]).`
    * `X = mar,`
    * `B = may;`

## Adding and Deleting an Element
* Adding
  * `add(X, L, [X|L])`
* Deleting has 2 cases
  1. The item to delete is the head of the list (base case)
  2. The item to be deleted is in the tail
* In Prolog:
  * `delete(X, [X|L], L).`
  * `delete(X, [Y|Tail], [Y| Tail1]) :- delete(X, Tail, Tail1).`
* delete is *non-deterministic*
  * `insert(X, List, BiggerList) :- delete(X, BiggerList, List).`

## Sublist
* S is a sublist of L if
  * L can be split into two lists: L1 and L2; and
  * L2 can be split into two lists: S and L3
* `sublist(S, L) :- conc(L1, L2, L), conc(S, L3, L2).`

## Permutations
* Reordering the elements in the list
* We define a relation that is true if the second list is a reordering of the first list
* 2 cases
  1. If the first list is empty, the second list must also be empty (base case)
  2. If the first list has the form `[X|L]` then permute L to form a new list L1 and insert X into L1
* In Prolog:
  * `permutation([], []).` (base case)
  * `permutation([X|L], P) :- permutation(L, L1), insert(X, L1, P).`
