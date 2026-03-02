myElem(X, [X|_]).
myElem(X, [_|Tail]) :- myElem(X,Tail).

myHead(X, [X|_]).

myLast(X, [X]).
myLast(X, [_|Tail]) :- myLast(X, Tail).

myTail(A, [_|A]).

myAppend([], B, B).
myAppend([Ah|At],B,[Ah|Ct]) :- myAppend(At,B,Ct).

myReverse([],[]).
myReverse([Ah|At],B) :- myReverse(At, C), myAppend(C, [Ah], B).

myDelete(X, [X|L1], L1).
myDelete(X, [Y|L1], [Y|L2]) :- myDelete(X, L1, L2).
