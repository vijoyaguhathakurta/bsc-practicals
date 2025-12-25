concat([],L2,L2).
concat([X|L1],L2,[X|L3]):-concat(L1,L2,L3).
