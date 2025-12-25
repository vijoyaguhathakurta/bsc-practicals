print_r(X,X):-write(X),nl.
print_r(X,Y):-X<Y,Z is Y-1,print_r(X,Z),write(Y),nl.
