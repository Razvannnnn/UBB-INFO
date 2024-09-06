#inverseaza o lista de numere
def inverseaza(lista):
    if len(lista) == 1:
        lista[0]= lista[0] *2
        return lista

    else:
        mid = len(lista)//2
        st = inverseaza(lista[:mid])
        dr = inverseaza(lista[mid:])
        return dr + st


lista = [1,2,3,4,5,6,7]
print(inverseaza(lista))

