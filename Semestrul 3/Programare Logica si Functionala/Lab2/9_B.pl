%               { [], daca M>N
% constr(M,N) = {
%               { M (+) constr(M+1, N), altfel

% constr(M:integer, N:integer, R:lista)
% model flux: (i,i,o), (i,i,i)
% M - primul element al intervalului
% N - ultimul element al intervalului

constr(M,N,[]):- M>N.
constr(M,N,[M|R]):- M =< N,
    M1 is M + 1,
    constr(M1,N,R).
