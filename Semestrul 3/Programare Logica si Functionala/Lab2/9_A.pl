%			  { True, daca E = L1
% apartine(E, L1L2..Ln) = {
%			  { apartine(E, L2L3...LN), altfel
%
% apartine(E:integer, L:lista)
% Verificam daca E apartine listei L

apartine(E,[E|_]).
apartine(E,[_|T]):-
         apartine(E,T).

%		       { [], daca L1 vida sau L2 vida
% intersectie(L1,L2) = { l1 (+) intersectie(l2l3..ln, L2), daca l1 apartine lui L2
%		       { intersectie(l2l3..ln, L2), altfel

% intersectie(L1:lista,L2:lista,R:lista)
% model flux: (i,i,o), (i,i,i)
% L1 - prima lista
% L2 - a doua lista
% R - lista ce contine intersectia L1 si L2

intersectie([],_,[]).
intersectie(_,[],[]).
intersectie([H|T],L2,[H|R]):-
    apartine(H,L2),
    intersectie(T,L2,R).
intersectie([_|T],L2,R):-
    intersectie(T,L2,R).
