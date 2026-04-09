% FACTS
% team group assignments
% group(Group, Team).

group(a, aa).
group(a, ab).
group(a, ac).
group(a, ad).
group(a, ae).

group(b, ba).
group(b, bb).
group(b, bc).
group(b, bd).
group(b, be).

group(c, ca).
group(c, cb).
group(c, cc).
group(c, cd).
group(c, ce).

group(d, da).
group(d, db).
group(d, dc).
group(d, dd).
group(d, de).

group(e, ea).
group(e, eb).
group(e, ec).
group(e, ed).
group(e, ee).

group(f, fa).
group(f, fb).
group(f, fc).
group(f, fd).
group(f, fe).

% count how many matches are on a given day
countDay(_, [], 0) :- !.
countDay(D, [(_,_,D)|L], N) :- countDay(D,L,N1), N is N1 + 1, !.
countDay(D, [_|L], N) :- countDay(D, L, N).

% count how many games a given team is the home team
countHome(_, [], 0) :- !.
countHome(T, [(T,_,_)|L], N) :- countHome(T,L,N1), N is N1 + 1.
countHome(D, [_|L], N) :- countHome(D, L, N).

% count how many games a given team is the away team
countAway(_, [], 0) :- !.
countAway(T, [(_,T,_)|L], N) :- countAway(T,L,N1), N is N1 + 1.
countAway(D, [_|L], N) :- countAway(D, L, N).

% a given team has the same number of home and away games
sameHomeAway(T, S) :- countHome(T, S, N), countAway(T, S, N). 

fixture(HomeT, AwayT) :-  group(G, HomeT), group(G, AwayT), HomeT \== AwayT.

% schedule(S)
% S is a list of fixtures
% fixture is (homeTeam, awayTeam, day)

schedule([(HomeT, AwayT, _)]) :- fixture(HomeT, AwayT).
schedule([(HomeT, AwayT, Day) | L]) :-  sameHomeAway(HomeT, [(HomeT, _, _)|L]), sameHomeAway(AwayT, [(_, AwayT, _)|L]), countDay(Day, [(_, _, Day)|L], N2), !, N2 =< 3, fixture(HomeT, AwayT), schedule(L).
