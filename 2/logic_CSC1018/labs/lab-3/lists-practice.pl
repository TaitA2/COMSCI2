myElem(_,[]).
myElem(X, [X|_]) :- !.
myElem(X, [_|L]) :- myElem(X, L).

myHead(_, []).
myHead(X, [X|_]).

myLast(_, []).
myLast(X, [_|X]) :- !.
myLast(X, [_|L]) :- myLast(X, L), !.

myTail(_, []).
myTail(X, [_|X]).

myAppend([], B, B).
myAppend([Ah|At],B,[Ah|Ct]) :- myAppend(At,B,Ct).

myReverse([], []).
myReverse([Ah|At], B) :- myReverse(At,C), myAppend(C, [Ah], B).

myDelete(_, [], []).
myDelete(X, [X|At], At) :- !.
myDelete(X, [Ah|At], [Ah|Bt]) :- myDelete(X, At, Bt), !.

