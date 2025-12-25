gcd(A,0,A).
gcd(A,B,G):-B>A,gcd(B,A,G).
gcd(A,B,G):-B>0,A>B, Z is A mod B, gcd(B,Z,G).
