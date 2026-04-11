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


% PREDICATES

% Fixture of HomeTeam vs AwayTeam. Both teams are in the same group and are different teams. 
fixture(HomeT, AwayT) :-  group(G, HomeT), group(G, AwayT), HomeT \== AwayT.

% count how many matches are on a given day
countDay(_, [], 0).
countDay(D, [(_,_,D)|L], N) :- !, countDay(D,L,N1), N is N1 + 1.
countDay(D, [_|L], N) :- countDay(D, L, N).

% count how many games a given team is the home team
countHome(_, [], 0).
countHome(T, [(T,_,_)|L], N) :- !, countHome(T,L,N1), N is N1 + 1.
countHome(T, [_|L], N) :- countHome(T, L, N).

% count how many games a given team is the away team
countAway(_, [], 0).
countAway(T, [(_,T,_)|L], N) :- !, countAway(T,L,N1), N is N1 + 1.
countAway(T, [_|L], N) :- countAway(T, L, N).

% no team in the schedule has too many more games as the home or away team
% used as an ongoing check that the schedule is balanceable
teamBalance(HT, AT, S) :-
		countHome(HT, S, HH), countAway(HT, S, HA),     % count the home and away games of the home team
		countHome(AT, S, AH), countAway(AT, S, AA),     % count the home and away games of the away team
		abs(HH + 1 - HA) =< 2, abs(AH - (AA + 1)) =< 2. % both teams have no more than 2 more games as either side

% a given team has the same number of home and away games
% used as a final check that the schedule is balanced
sameHomeAway(T, S) :- countHome(T, S, N), countAway(T, S, N). 

% find the day when a team last played a fixture
lastPlayed(T, [(T,_,D)|_], D) :- !. % base case for home team
lastPlayed(T, [(_,T,D)|_], D) :- !. % base case for away team
lastPlayed(T, [_|L], D) :- lastPlayed(T, L, D). % recurse

% check that a given team has at least 4 days rest since their last fixture
countRest(T, D, S) :- lastPlayed(T, S, Last), D >= Last + 5. % team T has played before so add 5 to their last day
countRest(T, _, S) :- \+ lastPlayed(T, S, _).                % team T has not played yet so any day D is ok

% pick a valid fixture from the remaining list
getFixture([(H, A)|L], D, S, (H,A), L) :-
		countDay(D, S, N), N < 3,               % no more than 3 matches on the same day
		countRest(H, D, S), countRest(A, D, S), % both teams have at least 4 rest days
		teamBalance(H, A, S).                   % both teams have a similar enough amount of home and away fixtures
getFixture([F|L], D, S, Fix, [F|L1]) :- getFixture(L, D, S, Fix, L1). % skip the head and try the rest

% assign a day to each fixture in the schedule
assignDays([], _, S, S).
assignDays(Fixtures, D, S, S1) :-
		Fixtures \= [], % fixtures is not an empty list
		getFixture(Fixtures, D, S, (H,A), L) -> % if there's a valid fixture for day D,
		assignDays(L, D, [(H,A,D)|S], S1) ;     % place it and recurse on the same day
		D1 is D + 1,                            % otherwise no fixture fits D so increment it
		assignDays(Fixtures, D1, S, S1).        % retry with next value of D

% schedule(S)
% S is a list of fixtures
% Every fixture has two different teams from the same group
% Every team has at least 4 days between fixtures
% Every team has the same number of home and away games
schedule(S) :-
		findall((HT,AT), fixture(HT,AT), Fixtures), % get all valid fixtures as Fixtures
		assignDays(Fixtures, 1, [], S),             % give each fixture a valid day
		forall(group(_, T), sameHomeAway(T, S)).    % check every team in the schedule has the same amount of home and away games
