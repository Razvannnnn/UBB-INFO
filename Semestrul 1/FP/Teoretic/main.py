def divide_et_impera(list):
    if len(list) == 0:
        return 0
    elif len(list) == 1:
        if list[0] < 0:
            return 1
        else:
            return 0

    mijloc = len(list)//2
    lista_stanga = list[:mijloc]
    lista_dreapta = list[mijloc:]

    lista_finala_stanga = divide_et_impera(lista_stanga)
    lista_finala_dreapta = divide_et_impera(lista_dreapta)

    return lista_finala_stanga + lista_finala_dreapta

input_list = [1,2,3,4, -2]
result = divide_et_impera(input_list)
print(result)

"""def f(n):
    if n<=0: raise ValueError()
    l = []
    while n>0:
        c = n %10
        n=n//10
        l.append(c)
    for i in range(len(l) - 1):
        l[i+1] += l[i]
    return l[-1]

print(f(2345))"""

def f(l):
    if l==None or l==[]: raise ValueError()
    aux = {1:0,0:0 }
    for e in l:
        aux[e % 2] += 1
    return aux[1]==0

l = [3,5,8,6,9,10]
print(f(l))