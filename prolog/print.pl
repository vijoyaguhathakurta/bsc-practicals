
printing(1):-write(1),nl.
printing(X):-Y is X-1,printing(Y),write(X),nl.
