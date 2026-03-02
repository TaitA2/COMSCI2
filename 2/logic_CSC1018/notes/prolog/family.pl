/* FACTS */

# parents
parent(pam, bob).
parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, mary).
parent(mary, jim).

# genders
female(pam).
male(tom).
male(bob).
female(liz).
female(mary).
female(ann).
male(jim).

/* RULES */
grandparent(X,Y) :- parent(X,Z), parent(Z, Y).

mother(X,Y) :- female(X), parent(X,Y).
sister(X,Y) :- female(X), parent(Z,X), parent(Z,Y), different(X,Y).
