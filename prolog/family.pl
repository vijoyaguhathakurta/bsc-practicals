male(raja).
male(prabhu).
male(samir).
male(bijoy).
male(ram).
male(shyam).
male(ajoy).

female(sudesna).
female(rani).
female(soma).
female(dipa).
female(pritha).
female(shymoli).

parent(raja,samir).
parent(sudesna,samir).
parent(prabhu,soma).
parent(rani,soma).
parent(samir,dipa).
parent(soma,dipa).
parent(samir,pritha).
parent(soma,pritha).
parent(samir,bijoy).
parent(soma,bijoy).
parent(shyam,shyamoli).
parent(pritha,shyamoli).
parent(ram,ajoy).
parent(dipa,ajoy).

mother(X,Y):-female(X),parent(X,Y).
father(X,Y):-male(X),parent(X,Y).
offspring(X,Y):-parent(Y,X).
daughter(X,Y):- offspring(X,Y),female(X).
son(X,Y):-offspring(X,Y),male(X).
sibling(X,Y):-parent(Z,X),parent(Z,Y),X\==Y.
sister(X,Y):-female(X),sibling(X,Y).
brother(X,Y):-male(X),sibling(X,Y).
cousin(X,Y):-parent(A,X),parent(B,Y),sibling(A,B).
aunt(X,Y):-female(X),parent(Z,Y),sibling(X,Z).
haschild(X):-parent(X,Y).
wife(X,Y):-female(X),male(Y),parent(X,Z),parent(Y,Z).
grandparent(X,Y):-parent(X,Z),parent(Z,Y).
grandfather(X,Y):-male(X),grandparent(X,Y).
grandmother(X,Y):-female(X),grandparent(X,Y).
predecessor(X,Y):-parent(X,Y).
predecessor(X,Y):-parent(Z,Y),predecessor(X,Z).
