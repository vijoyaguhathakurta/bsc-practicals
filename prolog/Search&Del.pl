del(X,[X|L],L).
del(X,[Y|L],[Y|R]):-del(X,L,R).
