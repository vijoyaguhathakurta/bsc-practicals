appen(X,[],[X]).
appen(X,[Y|L],[Y|R]):- appen(X,L,R).
