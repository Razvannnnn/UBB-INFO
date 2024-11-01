%			  { True, daca E = L1
% apartine(E, L1L2..Ln) = {
%			  { apartine(E, L2L3...LN), altfel
%
% apartine(E:integer, L:lista)
% Verificam daca E apartine listei L

apartine(E,[E|_]).
apartine(E,[_|T]):-
         apartine(E,T).

%                        { [], daca L1 vida sau L2 vida
% intersectie(L1,L2,V) = { l1 (+) intersectie(l2l3..ln, L2, V), daca l1
%                        {  apartine lui L2 si l1 nu apartine lui V
%	                 { intersectie(l2l3..ln, L2,V), altfel

% intersectie(L1:lista,L2:lista,R:lista,V:lista)
% model flux: (i,i,o,i), (i,i,i,i)
% L1 - prima lista
% L2 - a doua lista
% R - lista ce contine intersectia L1 si L2
% V - lista cu elemente deja verificate

intersectie([], _, [], _).
intersectie(_, [], [], _).
intersectie([H|T], L2, [H|R], V) :-
    apartine(H, L2),
    \+ apartine(H, V),
    intersectie(T, L2, R, [H|V]).
intersectie([_|T], L2, R, V) :-
    intersectie(T, L2, R, V).

intersectie(L1, L2, R) :-
    intersectie(L1, L2, R, []).
