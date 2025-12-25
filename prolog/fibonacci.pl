fibo(0,0).
fibo(1,1).

fibo(N,F):-N>1,A is N-1,B is N-2,fibo(A,F1),fibo(B,F2),F is F1+F2.
