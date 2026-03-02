# Structures
* Relations and functors can be used to build data structures
* The functor is true if the data structure exists
  * `.(h, t)` is true if a list exists whose head is h and tail is t

## Binary Trees
* 2 cases
  1. An empty tree
  2. The tree has a **left** subtree, a **root**, and a **right** subtree
    * `bt(L,X,R).`

### Searching in a Binary Tree
* Clauses to test if an element is in a binary tree:
  * `in(X, bt(_, X, _)).` element is the root (base case)
  * `in(X, bt(L,Y,_)) :- X =< Y, in(X, L).` element is less than or equal the root (left side)
  * `in(X, bt(_,_,R)) :- in(X, R).`

### Adding an Element to a Binary Tree
* `addnode(nil, X, bt(nil, X, nil)).` empty tree (base case)
* `addnode(bt(L,Y,R), X, bt(L1, Y, R)) :- X =< Y, addnode(L,X,L1)`
* `addnode(bt(L,Y,R), X, bt(L,Y, R1)) :- addnode(R, X, R1)`

### Deleting an Element from a Binary Tree
* Deleting a leaf node:
  * `delLeaf(B, X, B1) :- addnode(B1, X, B).`
  * B-X = B1 is the same as B1+X = B.
* Deleting an internal node requires the node to be replaced with something else
