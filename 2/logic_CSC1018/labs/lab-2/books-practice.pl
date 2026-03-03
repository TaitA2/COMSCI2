book(illiad, homer, study, 500).
book(c, richie, study, 150).
book(nt_bible, sams, reference, 480).
book(monty_python, cleese, comedy, 300).
book(dune, herbert, fiction, 100).
book(hamlet, shakespeare, drama, 314).

holidays(_, []).
holidays(book(T1, A1, _, _), [book(T2, A2, G2, S2)|_]) :- T1 = T2, A1 = A2, S2 < 400, G2 \== study, G2 \== reference.
holidays(B, [_|Tail]) :- holidays(B, Tail).

revision(_, []).
revision(book(T1, A1, _, _), [book(T2, A2, G2, S2)|_]) :- T1 = T2, A1 = A2, S2 > 300, G2 == study.
revision(book(T1, A1, _, _), [book(T2, A2, G2, S2)|_]) :- T1 = T2, A1 = A2, S2 > 300, G2 == reference.
revision(B, [_|Tail]) :- revision(B, Tail).

literary(_, []).
literary(book(T1, A1, _, _), [book(T2, A2, G2, _)|_]) :- T1 = T2, A1 = A2, G2 == drama.
literary(B, [_|Tail]) :- literary(B, Tail).

leisure(_, []).
leisure(book(T1, A1, _, _), [book(T2, A2, G2, _)|_]) :- T1 = T2, A1 = A2, G2 == comedy.
leisure(book(T1, A1, _, _), [book(T2, A2, G2, _)|_]) :- T1 = T2, A1 = A2, G2 == fiction.
leisure(B, [_|Tail]) :- leisure(B, Tail).

buildLibrary(Lib) :- findall(book(Title, Author, Genre, Size), book(Title, Author, Genre, Size), Lib).
