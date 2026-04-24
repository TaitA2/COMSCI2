% split(N, Positive, Negative).
split([],[],[]).
split([H|T], [H|T1], Negative) :- H >= 0, split(T, T1, Negative).
split([H|T], Positive, [H|T1]) :- H < 0, split(T, Positive, T1).

% oddsquaresum(X, S).
oddsquaresum([], _) :- !.
oddsquaresum([H], X) :- integer(H), divmod(H, 2, _, 1), X is H*H.
oddsquaresum([H|T], X) :- integer(H), divmod(H, 2, _, 1), oddsquaresum(T, X1), X is X1+(H*H).
oddsquaresum([_|T], X) :- oddsquaresum(T, X).
