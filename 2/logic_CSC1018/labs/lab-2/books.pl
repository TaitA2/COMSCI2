book(illiad,homer,study,500).
book(c,richie,study, 150).
book(ntbible,sams,reference,480).
book(ntfordummies,bob, reference,200).
book(pythonalgorithms,david,study, 225).
book(masacre,dillenger,crime,180).
book(dramaticTitle,dramaticAuthor,drama,180).
book(lilacbus,binchey,fiction,200).

holiday(_, []).
holiday(book(T1,A1,_,_), [book(T2,A2,G2,S2)|_]) :- T1 = T2, A1 = A2, S2 < 400, G2 \== study, G2 \== reference.
holiday(B, [_|Tail]) :- holiday(B, Tail).

revision(_, []).
revision(book(T1,A1,_,_), [book(T2,A2,G2,S2)|_]) :- T1 = T2, A1 = A2, S2 > 300, G2 == study.
revision(book(T1,A1,_,_), [book(T2,A2,G2,S2)|_]) :- T1 = T2, A1 = A2, S2 > 300, G2 == reference.
revision(B, [_|Tail]) :- revision(B, Tail).

literary(_, []).
literary(book(T1,A1,_,_), [book(T2,A2,G2,_)|_]) :- T1 = T2, A1 = A2, G2 == drama.
literary(B, [_|Tail]) :- literary(B, Tail).

leisure(_, []).
leisure(book(T1,A1,_,_), [book(T2,A2,G2,_)|_]) :- T1 = T2, A1 = A2, G2  = comedy.
leisure(book(T1,A1,_,_), [book(T2,A2,G2,_)|_]) :- T1 = T2, A1 = A2, G2  = fiction.
leisure(B, [_|Tail]) :- leisure(B, Tail).

buildLibrary(Lib) :- findall(book(Title, Author, Genre, Size), book(Title, Author, Genre, Size), Lib).
