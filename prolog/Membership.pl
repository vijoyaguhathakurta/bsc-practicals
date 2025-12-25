member(X,[X|L]).
member(X,[Y|L]):-X\==Y,member(X,L).
