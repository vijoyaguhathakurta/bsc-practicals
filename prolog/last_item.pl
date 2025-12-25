last([X],X).
last([X|L],R):- last(L,R).
