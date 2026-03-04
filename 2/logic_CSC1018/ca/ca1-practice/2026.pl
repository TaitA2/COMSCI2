% FACTS

road(north,south, 3).
road(south,east, 5).
road(east,west, 2).
road(west,newtown, 1).
road(newtown,differburg, 4).
road(differburg,otherville, 4).

% Q1
myBetween(X,Y,Z) :- road(X,Y,_), !, road(Y,Z,_).
closeTo(X,Y) :- road(X,Y,N), !, N =< 4.


% Q3
route(X, Y) :- road(X,Y,_), !.
route(X, Y) :- route(X,Z), route(Z,Y), !.

routen(X, Y, N) :- road(X,Y,N), !.
routen(X, Y, N) :- routen(X,Z, N1), routen(Z,Y, N2), !, N is N1 + N2.

canwalk(X,Y) :- routen(X,Y,N), !, N < 3.
cancycle(X,Y) :- routen(X,Y,N), !, N < 6.

