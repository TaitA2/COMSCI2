parent(pam, bob).
parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, mary).
parent(mary, jim).
parent(liz, dave).

female(pam).
female(liz).
female(mary).
female(ann).
male(jim).
male(tom).
male(bob).

different(X,X) :- !, fail; true.

grandparent(X,Y) :- parent(X,Z), parent(Z,Y).

mother(X,Y) :- female(X), parent(X,Y).

sibling(X,Y) :- parent(Z,X), parent(Z,Y), different(X,Y).
sister(X,Y) :- female(X), sibling(X,Y).
brother(X,Y) :- male(X), sibling(X,Y).

uncle(X,Y) :- brother(X,Z), parent(Z,Y).
aunt(X,Y) :- sister(X,Z), parent(Z,Y).

cousin(X,Y) :- grandparent(Z,X), grandparent(Z,Y).
