edge(a,b).
edge(a,e).
edge(b,c).
edge(b,d).
edge(c,f).
edge(d,e).
edge(e,g).
is_path(X,Y):- edge(X,Y).
is_path(X,Y):- edge(Z,Y),is_path(X,Z).



