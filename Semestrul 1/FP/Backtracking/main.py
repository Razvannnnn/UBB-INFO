def consistent(S, n):
    if S < 0 or n <= 0:
        return 0
    return 1

def solution(S, solutie):
    if S == 0:
        print("Modalitate de plata:", solutie)
        return 1
    return 0

def backtracking_recursiv(monede, n, S, solutie = [], ok=[0]):
    if solution(S, solutie):
        ok[0] = 1
        return
    if consistent(S, n):
        backtracking_recursiv(monede, n-1, S-monede[n-1], solutie + [monede[n-1]], ok)
        backtracking_recursiv(monede, n-1, S, solutie, ok)

def backtracking_iterativ(monede, S, ok=[0]):
    lista = [(len(monede), S, [])]
    while lista:
        n, suma, solutie = lista.pop()
        if consistent(suma, n) == 0:
            if solution(suma, solutie):
                ok[0] = 1
                continue
            continue
        lista.append((n-1, suma - monede[n-1], solutie + [monede[n-1]]))
        lista.append((n-1, suma, solutie))

"""
def backIter(monede, n, ok=[0]):
    x = [-1]
    while len(x) > 0:
        choosed = False
        while not choosed and x[-1] < monede[n - 1]:
            x[-1] = x[-1] + 1
            choosed = consistent(x, n)
        if choosed:
            if solution(x, n):
                ok[0] = 1
            x.append(-1)
        else:
            x = x[:-1]
"""

def main():
    """
    Problema: Gasirea modurilor in care se poate plati o suma data utilizand monede date

    solutie candidat: x = (x1, x2, ... , xk), xi apartine listei de monede
    conditie consistent: x = (x1, x2, ... , xk), suma >= 0 si n > 0
    conditie solutie: x e consistent si se obtine suma x1+x2+..dorita.

    """
    monede = [1, 2, 2, 5, 10, 20, 50, 50]
    suma = 23
    ok_recursiv = [0]
    ok_iterativ = [0]

    print("Recursiv:")
    backtracking_recursiv(monede, len(monede), suma, ok=ok_recursiv)
    if not ok_recursiv[0]:
        print("\nNu exista solutii utilizand metoda de backtracking recursiv.")

    print("\nIterativ:")
    backtracking_iterativ(monede, suma, ok=ok_iterativ)
    if not ok_iterativ[0]:
        print("\nNu exista solutii utilizand metoda de backtracking iterativ.")


main()
