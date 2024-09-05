v = []
n = 0
result = []

5,5


def citire():

    """
    Citirea unei liste de numere intregi
    Se citeste 'n' semnificand numarul de numere intregi din sir
    Se citeste 'x', sirul propriu-zis
    String-ul 'x' se transfera sub forma de int in 'v'
    """

    print()
    print("Cate elemente contine lista?")
    global n
    global v
    n = int(input("n="))
    print("Introdu elementele:")
    x = input()
    x = x.split()
    v = [int(i) for i in x]

def propr1(v,n):

    """
    Programul returneaza cel mai lung sir unde diferentele dintre 2 numere consecutive sa fie de semn opus
    Parcurgem sirul si retinem in 'maxp' si 'maxu' pozitiile de inceput si de sfarsit a sirului dorit
    Pe baza celor doua variabile se va afisa acest sir
    """
    maxi = 0
    p=0
    u=0
    maxp=0
    maxu=0
    global result
    for j in range(0,n-2):
        if((int(v[j+1]-v[j])>=0 and int(v[j+2]-v[j+1])<0) or (int(v[j+1]-v[j])<0 and int(v[j+2]-v[j+1])>=0)):
            u=j+2
            if u - p > maxi:
                maxi = u - p
                maxp = p
                maxu = u
        else:
            p = j
            u = j
    result = v[maxp:maxu + 1]
    if(maxp==0 and maxu==0):
        return 0
    else:
        return result

def propr2(v,n):

    """
    Afiseaza cel mai lung sir de tip munte
    Subprogramul parcurge sirul de numere intregi 'v'
    Se memoreaza in 'maxp' si 'maxu' prima si ultima valoare a celui mai lung sir de tip munte
    Pe baza celor doua variabile se va afisa acest sir
    """

    ok = 0
    p = 0
    maxi = -1
    maxp = 0
    maxu = 0
    global result
    for i in range(0, n-1):
        if v[i] > v[i + 1]:
            ok = 1
            u = i + 1
        elif v[i] < v[i + 1] and ok == 0:
            u = i + 1
        elif v[i] > v[i + 1] and ok == 1:
            u = i + 1
        elif v[i] < v[i + 1] and ok == 1:
            ok = 0
            p = i
        if u - p > maxi:
            maxi = u - p
            maxp = p
            maxu = u
    result=v[maxp:maxu+1]
    if(maxp==0 and maxu==0):
        return 0
    else:
        return result

def propr3(v,n):
    """
        Afiseaza cel mai lung sir unde in oricare 3 numere consecutive exista o valoare care se repeta
        Subprogramul parcurge sirul de numere intregi 'v'
        Se memoreaza in 'maxp' si 'maxu' prima si ultima valoare a celui mai lung sir de tipul cerut
        Pe baza celor doua variabile se va afisa acest sir
    """

    p=0
    maxi=0
    maxp=0
    maxu=0
    global result
    for i in range(n-3):
        if(v[i]==v[i+1] or v[i]==v[i+2] or v[i+1]==v[i+2]):
            u=i+2
            if u - p > maxi:
                maxi = u - p
                maxp = p
                maxu = u
    result = v[maxp:maxu + 1]
    if (maxp == 0 and maxu == 0):
        return 0
    else:
        return result

def menu():

    """
    Afiseaza meniul aplicatiei si optiunile sale
    Conform functiei alese, aplicatia va apela subprogramul dorit
    """

    print("************Aplicatie_Laborator_3************")
    print()

    choise = int(input("""
      1.Citire lista de numere intregi
      2.Proprietatea 1 (10)
      3.Proprietatea 2 (15)
      4.Proprietatea 3 (9)
      5.Iesire din aplicatie
                
      Alegeti optiunea:"""))

    if choise == 1:
        citire()
        menu()
    elif choise == 2:
        if(propr1(v,n)==0):
            print("Nu exista un astfel de sir")
        else:
            print("Cel mai lung sir de elemente cu diferente de semne contrare este:", propr1(v,n))
        menu()
    elif choise == 3:
        if(propr2(v,n)==0):
            print("Nu exista un astfel de sir")
        else:
            print("Cel mai lung sir de tip munte este:", propr2(v,n))
        menu()
    elif choise == 4:
        if(propr3(v,n)==0):
            print("Nu exista un astfel de sir")
        else:
            print("Cel mai lung sir unde in oricare 3 numere consecutive exista o valoare care se repeta este:", propr3(v,n))
        menu()
    elif choise == 5:
        exit()
    else:
        print()
        print("Trebuie sa selectati o optiune existenta")
        print("Va rugam sa incercati din nou")
        print()
        menu()


if __name__ == "__main__":
    main()



#Cazuri de testare

def test_propr1():
    assert propr1([2,3,4,3,2,4],6)==[2,3,4,3]
    assert propr1([5,6,5,4],4)==[5,6,5]
    assert propr1([3,5,6,5,4,3,2],7)==[3, 5, 6, 5]
    assert propr1([3,4,5,4,7],5)==[3,4,5,4,7]

def test_propr2():
    assert propr1([2, 3, 4, 3, 2, 4], 6)==[2,3,4,3,2]
    assert propr1([5, 6, 5, 4], 4)==[5,6,5,4]
    assert propr1([3, 5, 6, 5, 4, 3, 2], 7)==[3,5,6,5,4,3,2]
    assert propr1([3, 4, 5, 4, 7], 5)==[3,4,5,4]

def test_propr3():
    assert propr1([2, 3, 4, 3, 2, 4], 6)==[2,3,4,3]
    assert propr1([5, 6, 5, 4], 4)==[5, 6, 5]
    assert propr1([3, 5, 6, 5, 4, 3, 2], 7)==[3, 5, 6, 5]
    assert propr1([3, 4, 5, 4, 7], 5)==[3, 4, 5, 4]

#Rularea cazurilor de testare

test_propr1()
test_propr2()
test_propr3()