len([],0).
len([X|L],N):-len(L,N1),N is N1+1.
