class Nod:
    def __init__(self, e):
        self.e = e
        self.urm = None
class Lista:
    def __init__(self):
        self.prim = None


'''
crearea unei liste din valori citite pana la 0
'''
def creareLista():
    lista = Lista()
    lista.prim = creareLista_rec()
    return lista

def creareListaVida():
    lista = Lista()
    return lista

def creareLista_rec():
    x = int(input("x="))
    if x == 0:
        return None
    else:
        nod = Nod(x)
        nod.urm = creareLista_rec()
        return nod
'''
tiparirea elementelor unei liste
'''
def tipar(lista):
    tipar_rec(lista.prim)

def tipar_rec(nod):
    if nod != None:
        print(nod.e)
        tipar_rec(nod.urm)


def substitutie(k, i, nod, new):
    if nod.e == None:
        return
    if k is i:
        return substitutie(k+1, i, nod.urm, new)
    else:
        new.e = nod.e
        return substitutie(k+1, i, nod.urm, new.urm)



'''
program pentru test
'''
def main():
    list = creareLista()
    tipar(list)
    print(".........")
    lista = creareListaVida()
    substitutie(1, 3, list.prim, lista.prim)
    tipar(lista)

main()

#                                    { l1 (+) substitutie(k++, l2...ln), daca k != i
# 3.    substitutie(i, k, l1...ln) = {
#              k = 0                 { substitutie(k++, l2..ln), altfel
#
#
#
#
#