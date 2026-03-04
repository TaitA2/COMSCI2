% Prolog Lab Exam 2024

% FACTS
parent(carol, paul).
parent(carol, jane).
parent(harry, tom).
parent(harry, mary).
parent(jim, tom).
parent(jim, mary).
parent(ann, tom).
parent(ann, mary).
parent(tim, harry).
parent(tim, carol).
parent(george, harry).
parent(george, carol).
parent(jenny, harry).
parent(jenny, carol).
parent(david, jim).
parent(david, joan).
parent(kate, jim).
parent(kate, joan).
parent(susan, dominic).
parent(susan, ann).

male(paul).
male(tom).
male(harry).
male(jim).
male(dominic).
male(tim).
male(george).
male(david).

female(jane).
female(mary).
female(carol).
female(joan).
female(ann).
female(jenny).
female(kate).
female(susan).

% Q1
mother(X,Y) :- female(X), parent(Y,X).
sibling(X,Y) :- parent(X, Z), parent(Y,Z), X \== Y.
uncle(X,Y) :- male(X), sibling(X,Z), parent(Y,Z).

% Q2
cousin(X,Y) :- sibling(P1, P2), parent(X, P1), parent(Y, P2).
paternalgrandmother(X,Y) :- mother(X, Z), male(Z), parent(Y,Z).

% Q3
oddsum(0, []) :- !.
oddsum(X, [Lh|Lt]) :- Lh mod 2 =:= 1, !, oddsum(Y, Lt), X is Y + Lh.
oddsum(X, [_|Lt]) :- oddsum(X, Lt).

maximum(0, []).
maximum(X, [X]):- !.
maximum(X, [Lh|Lt]) :- maximum(Y, Lt), X is max(Lh, Y).
