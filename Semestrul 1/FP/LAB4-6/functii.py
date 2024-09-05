import copy

#____________________1.ACTUALIZARI____________________
def add_cheltuiala(lista, zi,suma,tip):
    lista.append({"zi": zi,"suma": suma,"tip": tip})

def actualiz_cheltuiala(lista,zi,suma,tip,zinew,sumanew,tipnew):
    for cheltuieli in lista:
        if cheltuieli["zi"] == zi and cheltuieli["suma"] == suma and cheltuieli["tip"] == tip:
            cheltuieli["zi"] = zinew
            cheltuieli["suma"] = sumanew
            cheltuieli["tip"] = tipnew


#____________________2.STERGERE____________________

def sterge_cheltuieli_zi(lista,zi):
    for cheltuieli in lista:
        if cheltuieli["zi"] == zi:
            lista.remove(cheltuieli)


def sterge_cheltuieli_range_zi(lista, zi_inceput, zi_sfarsit):
    for cheltuieli in lista:
        if cheltuieli["zi"] >= zi_inceput and cheltuieli["zi"] <= zi_sfarsit:
            lista.remove(cheltuieli)

def sterge_cheltuieli_tip(lista, tip):
    for cheltuieli in lista:
        if cheltuieli["tip"] == tip:
            lista.remove(cheltuieli)


#____________________3.CAUTARI___________________
def print_cheltuieli_mai_mari_decat_suma(lista,suma):
    lista_cautata = []
    for cheltuieli in lista:
        if int(cheltuieli["suma"]) > int(suma):
            lista_cautata.append(cheltuieli)
    return lista_cautata

def print_cheltuieli_inainte_de_zi_si_mai_mici_decat_suma(lista,zi,suma):
    lista_cautata = []
    for cheltuieli in lista:
        if int(cheltuieli["zi"])<int(zi) and int(cheltuieli["suma"])<int(suma):
            lista_cautata.append(cheltuieli)
    return lista_cautata

def print_cheltuieli_tip(lista,tip):
    lista_cautata = []
    for cheltuieli in lista:
        if cheltuieli["tip"] == tip:
            lista_cautata.append(cheltuieli)
    return lista_cautata

"""
#____________________4.RAPOARTE____________________

def print_suma_totala_tip(tip):

def print_zi_cheltuieli_maxime(zi,suma):

def print_cheltuieli_dupa_suma(suma):

def print_cheltuieli_sortate_dupa_tip(tip):
"""

#____________________5.FILTRARE____________________
def elim_cheltuieli_tip(lista,tip):
    cheltuieli_familie_filtrate=copy.deepcopy(lista)
    for i in range(len(cheltuieli_familie_filtrate)):
        if cheltuieli_familie_filtrate[i]["tip"] == tip:
            del cheltuieli_familie_filtrate[i]
    print(cheltuieli_familie_filtrate)

"""
def elim_cheltuieli_mai_mici_decat_suma(suma):


#____________________6.UNDO____________________
"""

#____________________CAZURI DE TESTARE____________________
def test1():
    v = []
    add_cheltuiala(v,5,5,"telefon")
    assert v == [{"zi": 5, "suma": 5, "tip": "telefon"}]

def test2():
    v = [{"zi": 5, "suma": 5, "tip": "telefon"}]
    actualiz_cheltuiala(v,5,5,'telefon',10,12,'mancare')
    assert v == [{"zi": 10, "suma": 12, "tip": "mancare"}]

def test3():
    v = []
    add_cheltuiala(v, 5, 5, "telefon")
    add_cheltuiala(v, 10, 12, "mancare")
    sterge_cheltuieli_zi(v, 5)
    assert v == [{"zi": 10, "suma": 12, "tip": "mancare"}]

def test4():
    v = []
    add_cheltuiala(v,5,5,"telefon")
    add_cheltuiala(v,10,12,"mancare")
    add_cheltuiala(v, 15, 30, "intretinere")
    sterge_cheltuieli_range_zi(v,8,11)
    assert v == [{"zi": 5, "suma": 5, "tip": "telefon"}, {"zi": 15, "suma": 30, "tip": "intretinere"}]

def test5():
    v = []
    add_cheltuiala(v, 5, 5, "telefon")
    add_cheltuiala(v, 10, 12, "mancare")
    sterge_cheltuieli_tip(v,"telefon")
    assert v == [{"zi": 10, "suma": 12, "tip": "mancare"}]

def test6():
    v = []
    add_cheltuiala(v, 5, 5, "telefon")
    add_cheltuiala(v, 10, 15, "telefon")
    assert print_cheltuieli_mai_mari_decat_suma(v,7) == [{'zi': 10, 'suma': 15, 'tip': 'telefon'}]

#____________________RULAREA CAZURILOR DE TESTARE____________________

def rularea_testelor():
    print("Rularea testelor...")
    test1()
    test2()
    test3()
    test4()
    test5()
    test6()
    print("Teste rulate cu succes!")