sum(0,0).
sum(N,S):-N>0,A is N-1,sum(A,S1),S is S1+N.
