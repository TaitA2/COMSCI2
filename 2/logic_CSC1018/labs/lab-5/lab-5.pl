% Lab 5 
%
% Q1
class(0,zero) :- !.
class(X,negative) :- X < 0, !.
class(X,positive) :- X > 0, !.

% Q2
split([], [], []) :- !.
split([Lh|Lt], [Lh|Pt], N) :- Lh >= 0, split(Lt, Pt, N), !.
split([Lh|Lt], P, [Lh|Nt]) :- Lh < 0, split(Lt, P, Nt), !.

% Q2
fib(0,1) :- !.
fib(1,1) :- !.
fib(X,Y) :- X1 is X-1, X2 is X-2, fib(X1, Y1), fib(X2,Y2), Y is Y1 + Y2, !.
