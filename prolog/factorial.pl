fact(1,1).

fact(N,F):-N>1,Y is N-1,fact(Y,Z),F is Z*N.
