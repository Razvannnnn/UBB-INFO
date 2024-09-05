#_____________________________FUNCTII_GET_____________________________
def creeaza_cheltuiala(zi,suma,tip):
    """
    Functie ce creeaza o cheltuiala pe baza zi, suma, tip
    preconditii: zi: >0 si <32
                 suma: de tip int
                 tip: "mancare", "intretinere", "imbracaminte", "telefon", "altele"
    postconditii: cheltuiala: o cheltuiala cu ziua "zi", suma "suma" si tipul "tip"
    """
    return {"zi":zi, "suma":suma, "tip": tip}

def get_cheltuiala_zi(cheltuiala):
    """
    Functie care returneaza ziua cheltuielii
    preconditii: cheltuiala: o cheltuiala
    postcondtii: zi: >0 si <32
    """
    return cheltuiala["zi"]

def get_cheltuiala_suma(cheltuiala):
    """
    Functie care returneaza suma cheltuielii
    precondtii: cheltuiala: o cheltuiala
    postcondtii: suma: de tip int
    """
    return cheltuiala["suma"]

def get_cheltuiala_tip(cheltuiala):
    """
    Functie care returneaza tipul cheltuileii
    precondtii: cheltuiala: o cheltuiala
    postconditii: tip: "mancare", "intretinere", "imbracaminte", "telefon", "altele"
    """
    return cheltuiala["tip"]

#___________________________FUNCTII_DE_VALIDARE______________________________________
def validare_cheltuiala(cheltuiala):
    """
    Functie care verifica daca ziua este intre 0 si 32, daca suma este numar intreg si daca tip-ul este "mancare", "intretinere", "imbracaminte", "telefon", "altele"
    precondtii: cheltuiala: o cheltuiala
    postconditii: -
    raises:Exception cu mesajul: string
            "*Zi invalid\n" daca zi <=0 si >=32
            "*Suma invalid\n" daca nu este de tipul int
            "*Tip invalid\n" daca nu este "mancare", "intretinere", "imbracaminte", "telefon", "altele"
    """
    eroare = ""
    if get_cheltuiala_zi(cheltuiala)<=0 or get_cheltuiala_zi(cheltuiala)>=32:
        eroare += "*Zi invalid\n"
    if get_cheltuiala_suma(cheltuiala)<0:
        eroare += "*Suma invalid\n"
    if get_cheltuiala_tip(cheltuiala)!="mancare" and get_cheltuiala_tip(cheltuiala)!="intretinere" and get_cheltuiala_tip(cheltuiala)!="imbracaminte" and get_cheltuiala_tip(cheltuiala)!="telefon" and get_cheltuiala_tip(cheltuiala)!="altele":
        eroare += "*Tip invalid\n"
    if(len(eroare)>0):
        raise Exception(eroare)

def validare_daca_cheltuiala_exista_in_sir(lista_cheltuieli, cheltuiala):
    """
    Functie care verifica daca cheltuiala pe care vrem sa o actualizam exista in lista de cheltuieli
    preconditii: lista_cheltuieli: lista unde se afla cheltuielile
                 cheltuiala: cheltuiala pe care o cautam
    postconditii: Exception cu mesajul: string
                "*Cheltuiala nu exista" daca cheltuiala pe care vrem sa o actualizam nu exista in lista de cheltuieli
    """
    eroare = ""
    ok = 0
    for i in lista_cheltuieli:
        if get_cheltuiala_zi(i) == get_cheltuiala_zi(cheltuiala) and get_cheltuiala_suma(i) == get_cheltuiala_suma(cheltuiala) and  get_cheltuiala_tip(i) == get_cheltuiala_tip(cheltuiala):
            ok = 1
    if ok==0:
        eroare+="*Cheltuiala nu exista\n"
    if(len(eroare)>0):
        raise Exception(eroare)

def validare_daca_exista_cheltuieli_zi_interval(lista_cheltuieli,zi1,zi2):
    """
    Functie care verifica daca in intervalul ziua zi1 si ziua zi2 exista cheltuieli
    preconditii: lita_cheltuieli: lista unde se afla cheltuielile
                 zi1: prima parte a intervalului
                 zi2: a doua parte a intervalului
    postconditii: Exception cu mesajul: string
                "*Nu exista cheltuieli in acest interval de zile\n" daca nu exista cheltuieli intre zi1 si zi2
    """
    eroare = ""
    ok = 0
    for i in lista_cheltuieli:
        if get_cheltuiala_zi(i) >= zi1 and get_cheltuiala_zi(i) <= zi2:
            ok = 1
    if ok==0:
        eroare+="*Nu exista cheltuieli in acest interval de zile\n"
    if(len(eroare)>0):
        raise Exception(eroare)

def validare_daca_exista_cheltuieli_zi(lista_cheltuieli,zi):
    """
    Functie care verifica daca in ziua zi exista cheltuieli
    preconditii: lita_cheltuieli: lista unde se afla cheltuielile
                 zi: ziua in care se cauta daca sunt cheltuieli
    postconditii: Exception cu mesajul: string
                "*Nu exista cheltuieli in aceasta zi\n" daca nu exista cheltuieli in ziua zi
    """
    eroare = ""
    ok = 0
    for i in lista_cheltuieli:
        if get_cheltuiala_zi(i) == zi:
            ok = 1
    if ok==0:
        eroare+="*Nu exista cheltuieli in aceasta zi\n"
    if(len(eroare)>0):
        raise Exception(eroare)

def validare_daca_exista_cheltuieli_mai_mari_ca_suma(lista_cheltuieli,suma):
    """
    Functie care verifica daca exista cheltuieli de suma suma
    preconditii: lista_cheltuieli: lista unde se afla cheltuielile
                 suma: suma dupa care cautam daca exista cheltuieli
    postconditii: Exception cu mesajul: string
                "*Nu exista cheltuieli mai mari decat aceasta suma\n" daca nu exista cheltuieli de suma suma
    """
    eroare = ""
    ok=0
    for i in lista_cheltuieli:
        if get_cheltuiala_suma(i) > suma:
            ok=1
    if ok==0:
        eroare+="*Nu exista cheltuieli mai mari decat aceasta suma\n"
    if(len(eroare)>0):
        raise Exception(eroare)

def validare_daca_exista_cheltuieli_tip(lista_cheltuieli,tip):
    """
    Functie care verifica daca exista cheltuieli de tipul tip
    preconditii: lista_cheltuieli: lista unde se afla cheltuielile
                 tip: tipul dupa care cautam daca exista cheltuieli
    postconditii: Exception cu mesajul: string
                "*Nu exista cheltuieli de acest tip\n" daca nu exista cheltuieli care sa fie de tipul tip
    """
    eroare = ""
    ok = 0
    for i in lista_cheltuieli:
        if get_cheltuiala_tip(i) == tip:
            ok = 1
    if ok==0:
        eroare+="*Nu exista cheltuieli de acest tip\n"
    if(len(eroare)>0):
        raise Exception(eroare)

def validare_daca_exista_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,zi,suma):
    """
    Functie care verifica daca exista cheltuieli realizate inainte de ziua zi si cu suma mai mica decat suma suma
    preconditii: lista_cheltuieli: lista unde se afla cheltuielile
                 zi: ziua maxima
                 suma: suma maxima
    postconditii: Exception cu mesajul:string
                "*Nu exista cheltuieli inainte de ziua zi si cu suma mai mica decat suma introdusa\n" daca nu exist cheltuieli inainte de ziua zi si cu suma mai
                mica deca suma suma
    """
    eroare = ""
    ok = 0
    for i in lista_cheltuieli:
        if get_cheltuiala_zi(i) < zi and get_cheltuiala_suma(i) < suma:
            ok = 1
    if ok == 0:
        eroare+="*Nu exista cheltuieli inainte de ziua zi si cu suma mai mica decat suma introdusa\n"
    if(len(eroare)>0):
        raise Exception(eroare)

#_____________________FUNCTII_ADAUGARE______________________________
def adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala):
    """
    Functie care adauga cheltuiala in lista cu cheltuieli
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
                 cheltuiala: cheltuiala pe care vrem sa o adaugam
    postconditii: lista_cheltuieli` = lista_cheltuieli U cheltuiala
    """
    lista_cheltuieli.append(cheltuiala)

def actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala,cheltuiala_act):
    """
    Functie care actualizeaza o cheltuiala din lista cu cheltuieli
    preconditii: cheltuiala: cheltuiala pe care vrem sa o actualizam
                 cheltuiala_act: cheltuiala cu care vrem sa o actualizam
    postconditii: lista_cheluteli` = lista_cheltuieli U cheltuiala_actualizata
    """
    for i in lista_cheltuieli:
        if get_cheltuiala_zi(i) == get_cheltuiala_zi(cheltuiala) and get_cheltuiala_suma(i) == get_cheltuiala_suma(cheltuiala) and get_cheltuiala_tip(i) == get_cheltuiala_tip(cheltuiala):
            i["zi"] = get_cheltuiala_zi(cheltuiala_act)
            i["suma"] = get_cheltuiala_suma(cheltuiala_act)
            i["tip"] = get_cheltuiala_tip(cheltuiala_act)

#___________________________FUNCTII_STERGERE___________________________________
def stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli,zi):
    """
    Functie care sterge o cheltuiala din lista cu cheltuieli
    preconditii: lista_cheltuieli: o lista in care ses afla toate cheltuielile
                 zi: ziua cheltuielii pe care vrem sa o stergem
    postconditii: -
    """
    cheltuieli_noi = []
    for i in lista_cheltuieli:
        if get_cheltuiala_zi(i) != zi:
            cheltuieli_noi.append(i)
    lista_cheltuieli.clear()
    lista_cheltuieli.extend(cheltuieli_noi)

def stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli,zi1,zi2):
    """
    Functie care sterge cheltuielile ce se afla in intervalul de zile zi1 si zi2 din lista cu cheltuieli
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
                 zi1: prima parte a intervalului
                 zi2: a doua parte a intervalului
    postconditii: -
    """
    if zi1>zi2:
        aux=zi1
        zi1=zi2
        zi2=aux
    cheltuieli_noi = []
    for i in lista_cheltuieli:
        if get_cheltuiala_zi(i) < zi1 or get_cheltuiala_zi(i) > zi2:
            cheltuieli_noi.append(i)
    lista_cheltuieli.clear()
    lista_cheltuieli.extend(cheltuieli_noi)

def stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli,tip):
    """
    Functe care sterge cheltuielile ce sunt de tipul tip
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
                 tip: tipul pe care il cautam
    postconditii: -
    """
    cheltuieli_noi = []
    for i in lista_cheltuieli:
        if get_cheltuiala_tip(i) != tip:
            cheltuieli_noi.append(i)
    lista_cheltuieli.clear()
    lista_cheltuieli.extend(cheltuieli_noi)

#_________________________FUNCTII_CAUTARI________________________________________
def afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli,cheltuieli_noi,suma):
    """
    Functie care modifica o lista in care se afla toate cheltuielile mai mari decat o suma suma
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
                 cheltuieli_noi: lista in care se afla cheltuielile dorite
                 suma: suma minima
    postconditii: -
    """
    for i in lista_cheltuieli:
        if get_cheltuiala_suma(i) > suma:
            cheltuieli_noi.append(i)

def afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,cheltuieli_noi,zi,suma):
    """
    Functie care modifica o lista in care se afla toate cheltuielile inainte de o zi si mai mici decat o suma
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
                 cheltuieli_noi: lista in care se afla cheltuielile dorite
                 zi: ziua maxima
                 suma: suma maxima
    postconditii: -
    """
    for i in lista_cheltuieli:
        if get_cheltuiala_suma(i) < suma and get_cheltuiala_zi(i) < zi:
            cheltuieli_noi.append(i)

def afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli,cheltuieli_noi,tip):
    """
    Functie care modifica o lista in care se afla toate cheltuielile de un anumit tip
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
                 cheltuieli: lista in care se afla cheltuielile dorite
                 tip: tipul dorit
    postconditii: -
    """
    for i in lista_cheltuieli:
        if get_cheltuiala_tip(i) == tip:
            cheltuieli_noi.append(i)

#_____________________________FUNCTII_RAPOARTE______________________________________

def afisare_suma_totala_un_anumit_tip(lista_cheltuieli,tip):
    """
    Functie care returneaza o variabila in care se afla totalul sumelor cheltuielilor de un anumit tip
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
                 tip: tipul dorit
    postconditii: suma: variabila in care se afla totalul sumelor
    """
    suma = 0
    for i in lista_cheltuieli:
        if get_cheltuiala_tip(i) == tip:
            suma+=get_cheltuiala_suma(i)
    return suma

def afisare_zi_maxima_in_care_suma_este_maxima(lista_cheltuieli):
    """
    Functie care returneaza ziua in care suma este maxima
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
    postconditii: zimax: variabila in care se afla totalul sumelor
    """
    summax = 0
    for i in lista_cheltuieli:
        if get_cheltuiala_suma(i) >= summax:
            summax = get_cheltuiala_suma(i)
    for i in lista_cheltuieli:
        if get_cheltuiala_suma(i) == summax:
            pass

#____________________________FUNCTII_FILTRARE____________________________________

def eliminare_cheltuieli_tip(lista_cheltuieli,cheltuieli_noi,tip):
    """
    Functie care elimina toate cheltuielile de un anumit tip si le afiseaza pe restul
    preconditii: lista_cheltuieli: o lista in care se afla toate cheltuielile
    postconditii: -
    """
    for i in lista_cheltuieli:
        if get_cheltuiala_tip(i) != tip:
            cheltuieli_noi.append(i)
    pass


#_____________________________FUNCTII_SERVICE_____________________________________

def service_eliminare_cheltuieli_tip(lista_cheltuieli,tip):
    """
    Functie care pe baza unui string tip ce este "mancare", "intretinere", "imbracaminte", "telefon" sau "altele", verifica daca in lista_cheltuieli
    exista cheltuieli de tipul tip si daca acestea exista le elimina si va afisa restul
    preconditii: lista_cheltuieli: o lista cu cheltuieli
                 tip: tipul dorit
    postconditii: -
    """
    cheltuieli_noi = []
    validare_daca_exista_cheltuieli_tip(lista_cheltuieli,tip)
    eliminare_cheltuieli_tip(lista_cheltuieli,cheltuieli_noi,tip)
    print("\nLista dupa eliminarea cheltuielilor")
    print(cheltuieli_noi)

def service_afisare_suma_totala_un_anumit_tip(lista_cheltuieli,tip):
    """
    Functie care pe baza unui intreg suma si a unui string tip ce este "mancare", "intretinere", "imbracaminte", "telefon" sau "altele", verifica daca in
    lista_cheltuieli exista cheltuieli de tipul tip si daca acestea exista va face suma cheltuielilor
    preconditii: lista_cheltuieli: o lista cu cheltuieli
                  tip: tipul dorit
    postconditii: -
    """
    validare_daca_exista_cheltuieli_tip(lista_cheltuieli,tip)
    suma = afisare_suma_totala_un_anumit_tip(lista_cheltuieli,tip)
    print("\nSuma totala a cheltuielilor de tipul introdus:")
    print(suma)

def service_afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli,tip):
    """
    Functie care pe baza unui string unui string tip ce este "mancare", "intretinere", "imbracaminte", "telefon" sau "altele", verifica daca in lista_cheltuieli
    exista cheltuieli de tipul tip, iar daca acest lucru este valid va afisa o lista cu acestea
    preconditii: lista_cheltuieli: o lista cu cheltuieli
                 tip: tipul dorit
    postconditii: -
    """
    validare_daca_exista_cheltuieli_tip(lista_cheltuieli,tip)
    cheltuieli_noi = []
    afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli,cheltuieli_noi,tip)
    print("\nCheltuielile de tip dorit sunt:")
    print(cheltuieli_noi)

def service_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,zi,suma):
    """
    Functie care pe baza unui numar intreg zi >0 si <32 si a unui numar intreg suma, verifica daca in lista_cheltuieli exista cheltuieli realizate inainte de ziua zi si
    mai mici decat suma suma, iar daca acest lucru este valid va afisa o lista cu acestea
    preconditii: lista_cheltuieli: o lista cu cheltuieli
                 zi: ziua maxima
                 suma: suma maxima
    postconditii: -
    """
    validare_daca_exista_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,zi,suma)
    cheltuieli_noi = []
    afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,cheltuieli_noi,zi,suma)
    print("\nCheltuielile inainte de ziua zi si cu suma mai mica decat suma introdusa:")
    print(cheltuieli_noi)

def service_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli,suma):
    """
    Functie care pe baza unui numar intreg suma, verifica daca exista in lista_cheltuieli cheltuieli cu suma mai mare deca suma suma, iar daca acest lucru este valid,
    va afisa o lista doar cu cheltuieli mai mari de suma suma
    preconditii: lista_cheltuieli: o lista cu cheltuieli
                 suma: suma minimia
    postconditii: -
    """
    validare_daca_exista_cheltuieli_mai_mari_ca_suma(lista_cheltuieli,suma)
    cheltuieli_noi = []
    afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli,cheltuieli_noi,suma)
    print("\nCheltuielile mai mari decat suma introdusa sunt:")
    print(cheltuieli_noi)

def service_stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli,tip):
    """
    Functie care pe baza unui element tip, verifica daca exista in lista_cheltuieli o cheltuiala care sa fie de tipul tip, iar daca acest lucru este valid
    va sterge toate aceste cheltuieli
    preconditii: lista_cheltuieli: lista cu cheltuieli
                 tip: tipul cheltuielilor pe care vrem sa le stergem
    posconditii: -
    """
    validare_daca_exista_cheltuieli_tip(lista_cheltuieli,tip)
    stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli,tip)

def service_stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli,zi1,zi2):
    """
    Functie care pe baza a doua numere intre 0 si 31 zi1 si zi2, verifica daca exista in lista_cheltuieli o cheltuiala care sa fie intre ziua zi1 si ziua z2, iar daca acest lucru este valid
    va sterge toate aceste cheltuieli
    preconditii: lista_cheltuieli: lista cu cheltuieli
                 zi1: prima parte a intervalului
                 zi2: a doua parte a intervalului
    postconditii: -
    """
    validare_daca_exista_cheltuieli_zi_interval(lista_cheltuieli,zi1,zi2)
    stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli,zi1,zi2)

def service_stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli,zi):
    """
    Functie care pe baza unui numar intre 0 si 31 zi verifica daca exista in lista_cheltuieli o cheltuiala care sa fie in ziua zi, iar daca acest lucru este valid
    va sterge toate aceste cheltuieli
    preconditii: lista_cheltuieli: lista cu cheltuieli
                 zi: ziua pe care o cautam
    postconditii: -
    """
    validare_daca_exista_cheltuieli_zi(lista_cheltuieli,zi)
    stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli,zi)

def service_adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,zi,suma,tip):
    """
    Functie care pe baza unui numar intre 0 si 31 zi, unui numar intreg suma si a unui string tip ce este "mancare", "intretinere", "imbracaminte", "telefon" sau "altele"
    va crea si valida o cheltuiala, iar daca cheltuiala este valida o va adauga in lista de cheltuieli list_cheltuieli.
    preconditii: lista_cheltuieli: lista de cheltuieli
                 zi: 0< si <32
                 suma: numar intreg
                 tip: "mancare", "intretinere", "imbracaminte", "telefon", "altele"
    postconditii: -
    """
    cheltuiala = creeaza_cheltuiala(zi,suma,tip)
    validare_cheltuiala(cheltuiala)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala)

def service_actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,zi,suma,tip,zi_act,suma_act,tip_act):
    """
    Functie care pe baza unui numar intre 0 si 32 zi, unui numar intreg suma si a unui string tip ce este "mancare", "intretinere", "imbracaminte", "telefon" sau "altele"
    va verifica daca in lista exista aceasta cheltuiala, iar daca aceasta exista o va actualiza cu variabilele zi_act, suma_act, tip_act
    preconditii: lista_cheltuieli: lista de cheltuieli
                 zi: 0< si <32
                 suma: numar intreg
                 tip: "mancare", "intretinere", "imbracaminte", "telefon", "altele"
                 zi_act: 0< si <32
                 suma_act: numar intreg
                 tip_act: "mancare", "intretinere", "imbracaminte", "telefon", "altele"
    postconditii:-
    """
    cheltuiala = creeaza_cheltuiala(zi,suma,tip)
    validare_cheltuiala(cheltuiala)
    validare_daca_cheltuiala_exista_in_sir(lista_cheltuieli,cheltuiala)
    cheltuiala_act = creeaza_cheltuiala(zi_act,suma_act,tip_act)
    validare_cheltuiala(cheltuiala_act)
    actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala,cheltuiala_act)

#_______________________________FUNCTII_UI________________________________________________
def citeste_numar(prompt,f,msg):
    while True:
        try:
            return f(input(prompt))
        except ValueError:
            print(msg)

def ui_adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli):
    print()
    zi = citeste_numar("Introdu ziua:",int,"Valoare numerica invalida")
    suma = citeste_numar("Introdu suma:",int,"Valoare numerica invalida")
    tip = input("Introdu tip:")
    service_adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,zi,suma,tip)

def ui_actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli):
    print()
    zi = citeste_numar("Introdu ziua pe care o actualizam:", int, "Valoare numerica invalida")
    suma = citeste_numar("Introdu suma pe care o actualizam:", int, "Valoare numerica invalida")
    tip = input("Introdu tipul pe care il actualizam:")
    zi_act = citeste_numar("Introdu ziua actualizata:", int, "Valoare numerica invalida")
    suma_act = citeste_numar("Introdu suma actualizata:", int, "Valoare numerica invalida")
    tip_act = input("Introdu tipul actualizat:")
    service_actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, zi, suma, tip,zi_act,suma_act,tip_act)

def ui_stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli):
    print()
    zi = citeste_numar("Introdu ziua de unde se vor sterge cheltuielile:",int,"Valoare numerica invalida")
    service_stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli,zi)

def ui_stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli):
    print()
    zi1 = citeste_numar("Introdu primul element al intervalului dorit:",int,"Valoare numerica invalida")
    zi2 = citeste_numar("Introdu al doilea element al intervalului dorit:",int,"Valoare numerica invalida")
    service_stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli,zi1,zi2)

def ui_stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli):
    print()
    tip = input("Introdu tipul cheltuielilor pe care le stergem:")
    service_stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli,tip)

def ui_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli):
    print()
    suma = citeste_numar("Introdu suma minima a elementelor pe care le eleminam:",int,"Valoare numerica invalida")
    service_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli,suma)

def ui_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli):
    print()
    zi = citeste_numar("Introdu ziua maxima:",int,"Valoare numerica invalida")
    suma = citeste_numar("Introdu suma maxima:",int,"Valoare numerica invalida")
    service_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,zi,suma)

def ui_afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli):
    print()
    tip = input("Introdu tipul cheltuielilor pe care le afisam:")
    service_afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli,tip)

def ui_afisare_suma_totala_un_anumit_tip(lista_cheltuiala):
    print()
    tip = input("Introdu tipul la care se va face suma totala:")
    service_afisare_suma_totala_un_anumit_tip(lista_cheltuiala,tip)

def ui_eliminare_cheltuieli_tip(lista_cheltuieli):
    print()
    tip = input("Introdu tipul pe care sa-l eliminam:")
    service_eliminare_cheltuieli_tip(lista_cheltuieli,tip)

#_______________________________MENIURI________________________________________
def adaugare(lista_cheltuieli):
    while True:
        print("""
    1.Adauga o noua cheltuiala
    2 Actualizeaza cheltuiala
    0.Inapoi
        """)
        comanda = input("Alegeti optiunea:")
        if comanda == "1":
            try:
                ui_adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli)
                print("\nCheltuiala a fost adaugata cu succes!\n")
                return lista_cheltuieli
            except Exception as ex:
                print(ex)
        elif comanda == "2":
            try:
                ui_actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli)
                print("\nCheltuiala a fost actualizata cu succes!\n")
                return lista_cheltuieli
            except Exception as ex:
                print(ex)
        elif comanda == "0":
            return lista_cheltuieli
        else:
            print("\nIntroduceti o optiune corecta!\n")

def stergere(lista_cheltuieli):
    while True:
        print("""
    1.Stergere cheltuieli dintr-o zi
    2.Stergere cheltuieli dintr-un interval de timp
    3.Stergere cheltuieli de un anumit tip
    0.Inapoi
        """)
        comanda = input("Alegeti optiunea:")
        if comanda == "1":
            try:
                ui_stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli)
                print("\nCheltuielile din ziua aleasa au fost sterse cu succes!\n")
                return lista_cheltuieli
            except Exception as ex:
                print(ex)
        elif comanda == "2":
            try:
                ui_stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli)
                print("\nCheltuielile din intervalul dorit au fost sterse cu succes!\n")
                return  lista_cheltuieli
            except Exception as ex:
                print(ex)
        elif comanda == "3":
            try:
                ui_stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli)
                print("\nCheltuielile de tipul ales au fost sterse cu succes!\n")
                return lista_cheltuieli
            except Exception as ex:
                print(ex)
        elif comanda == "0":
            return lista_cheltuieli
        else:
            print("Introduceti o optiune corecta!\n")

def cautare(lista_cheltuieli):
    while True:
        print("""
    1.Tipărește toate cheltuielile mai mari decât o sumă dată   
    2 Tipărește toate cheltuielile efectuate înainte de o zi dată și mai mici decât o sumă
    3.Tipărește toate cheltuielile de un anumit tip
    0.Inapoi
        """)
        comanda = input("Alegeti optiunea:")
        if comanda == "1":
            try:
                ui_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli)
            except Exception as ex:
                print(ex)
        elif comanda == "2":
            try:
                ui_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli)
            except Exception as ex:
                print(ex)
        elif comanda == "3":
            try:
                ui_afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli)
            except Exception as ex:
                print(ex)
        elif comanda == "0":
            return lista_cheltuieli
        else:
            print("Introduceti o optiune corecta!\n")

def rapoarte(lista_cheltuieli):
    while True:
        print("""
    1.Tipărește suma totală pentru un anumit tip de cheltuială
    2.Găsește ziua în care suma cheltuită e maximă
    3.Tipărește toate cheltuielile ce au o anumită sumă
    4.Tipărește cheltuielile sortate după tip
    0.Inapoi
        """)
        comanda = input("Alegeti optiunea:")
        if comanda == "1":
            try:
                ui_afisare_suma_totala_un_anumit_tip(lista_cheltuieli)
            except Exception as ex:
                print(ex)
        elif comanda == "2":
            pass
        elif comanda == "3":
            pass
        elif comanda == "4":
            pass
        elif comanda == "0":
            return lista_cheltuieli
        else:
            print("Introduceti o optiune corecta!\n")

def filtrare(lista_cheltuieli):
    while True:
        print("""
    1.Elimină toate cheltuielile de un anumit tip
    2.Elimină toate cheltuielile mai mici decât o sumă dată
    0.Inapoi
        """)
        comanda = input("Alegeti optiunea:")
        if comanda == "1":
            try:
                ui_eliminare_cheltuieli_tip(lista_cheltuieli)
            except Exception as ex:
                print(ex)
        elif comanda == "2":
            pass
        elif comanda == "0":
            return lista_cheltuieli
        else:
            print("Introduceti o optiune corecta!\n")

def menu():
    lista_cheltuieli = []
    while True:
        print("""
    1.Adauga cheltuiala
    2.Stergere
    3.Cautari
    4.Rapoarte
    5.Filtrare
    6.Undo
    7.AFISARE LISTA
    0.Exit
        """)
        comanda = input("Alegeti optiunea:")
        if comanda == "1":
            lista_cheltuieli=adaugare(lista_cheltuieli)
        elif comanda == "2":
            lista_cheltuieli=stergere(lista_cheltuieli)
        elif comanda == "3":
            cautare(lista_cheltuieli)
        elif comanda == "4":
            rapoarte(lista_cheltuieli)
        elif comanda == "5":
            filtrare(lista_cheltuieli)
        elif comanda == "6":
            pass
        elif comanda == "7":
            print(lista_cheltuieli)
        elif comanda == "0":
            return(False)
        else:
            print("Introduceti o optiune corecta!\n")

#____________________________TESTE_________________________________

def test_service_eliminare_cheltuieli_tip():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    cheltuieli_noi = []
    assert (len(cheltuieli_noi) == 0)
    eliminare_cheltuieli_tip(lista_cheltuieli, cheltuieli_noi, tip)
    assert (len(cheltuieli_noi) == 1)
    try:
        service_eliminare_cheltuieli_tip(lista_cheltuieli,"altele")
        assert (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli de acest tip\n")

def test_eliminare_cheltuieli_tip():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    cheltuieli_noi = []
    assert (len(cheltuieli_noi) == 0)
    eliminare_cheltuieli_tip(lista_cheltuieli,cheltuieli_noi,tip)
    assert (len(cheltuieli_noi) == 1)

def test_service_afisare_suma_totala_un_anumit_tip():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    suma_fin = afisare_suma_totala_un_anumit_tip(lista_cheltuieli, tip)
    assert (suma_fin == 35)
    try:
        service_afisare_suma_totala_un_anumit_tip(lista_cheltuieli,"altele")
        assert (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli de acest tip\n")
def test_afisare_suma_totala_un_anumit_tip():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    suma_fin=afisare_suma_totala_un_anumit_tip(lista_cheltuieli,tip)
    assert (suma_fin == 35)
def test_service_afisare_tuturor_cheltuielilor_de_un_anumit_tip():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    cheltuieli_noi = []
    assert (len(cheltuieli_noi) == 0)
    afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli, cheltuieli_noi, tip)
    assert (len(cheltuieli_noi) == 1)
    tip_test = "altele"
    try:
        service_afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli,tip_test)
        assert (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli de acest tip\n")

def test_afisare_tuturor_cheltuielilor_de_un_anumit_tip():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    cheltuieli_noi = []
    assert (len(cheltuieli_noi) == 0)
    afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli,cheltuieli_noi,tip)
    assert (len(cheltuieli_noi) == 1)
    afisare_tuturor_cheltuielilor_de_un_anumit_tip(lista_cheltuieli,cheltuieli_noi,tip_act)
    assert (len(cheltuieli_noi) == 2)

def test_service_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    cheltuieli_noi = []
    assert (len(cheltuieli_noi) == 0)
    afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli, cheltuieli_noi, zi_act, suma_act)
    assert (len(cheltuieli_noi) == 1)
    try:
        service_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,zi,suma)
        assert (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli inainte de ziua zi si cu suma mai mica decat suma introdusa\n")
def test_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    cheltuieli_noi = []
    assert (len(cheltuieli_noi) == 0)
    afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,cheltuieli_noi,zi_act,suma_act)
    assert (len(cheltuieli_noi) == 1)
def test_validare_daca_exista_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    try:
        validare_daca_exista_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma(lista_cheltuieli,zi,suma)
        assert (False)
    except Exception as ex:
        assert (str(ex) =="*Nu exista cheltuieli inainte de ziua zi si cu suma mai mica decat suma introdusa\n")
def test_service_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    cheltuieli_noi = []
    assert (len(cheltuieli_noi) == 0)
    afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli, cheltuieli_noi, suma)
    assert (len(cheltuieli_noi) == 1)
    try:
        service_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli,suma_act)
        assert (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli mai mari decat aceasta suma\n")
def test_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_act)
    cheltuieli_noi = []
    assert (len(cheltuieli_noi)==0)
    afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma(lista_cheltuieli,cheltuieli_noi,suma)
    assert (len(cheltuieli_noi)==1)

def test_service_stergere_cheltuiala_din_lista_cu_cheltuieli_tip():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala_act)
    assert (len(lista_cheltuieli) == 2)
    stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli, tip)
    assert (len(lista_cheltuieli) == 1)
    try:
        service_stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli,tip)
        assert (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli de acest tip\n")
def test_stergere_cheltuiala_din_lista_cu_cheltuieli_tip():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala)
    assert (len(lista_cheltuieli)==1)
    stergere_cheltuiala_din_lista_cu_cheltuieli_tip(lista_cheltuieli,tip)
    assert (len(lista_cheltuieli)==0)

def test_service_actualizare_cheltuiala_in_lista_cu_cheltuieli():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    assert (get_cheltuiala_zi(cheltuiala) == zi)
    assert (get_cheltuiala_suma(cheltuiala) == suma)
    assert (get_cheltuiala_tip(cheltuiala) == tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act, suma_act, tip_act)
    actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala, cheltuiala_act)
    assert (get_cheltuiala_zi(cheltuiala) == zi_act)
    assert (get_cheltuiala_suma(cheltuiala) == suma_act)
    assert (get_cheltuiala_tip(cheltuiala) == tip_act)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala)
    try:
        service_actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,zi,suma,tip,zi_act,suma_act,tip_act)
        assert(False)
    except Exception as ex:
        assert (str(ex)=="*Cheltuiala nu exista\n")


def test_actualizare_cheltuiala_in_lista_cu_cheltuieli():
    lista_cheltuieli = []
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala)
    zi_act = 30
    suma_act = 50
    tip_act = "telefon"
    cheltuiala_act = creeaza_cheltuiala(zi_act,suma_act,tip_act)
    actualizare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala,cheltuiala_act)
    assert (get_cheltuiala_zi(cheltuiala) == zi_act)
    assert (get_cheltuiala_suma(cheltuiala) == suma_act)
    assert (get_cheltuiala_tip(cheltuiala) == tip_act)

def test_service_adaugare_cheltuiala_in_lista_cu_cheltuieli():
    zi = 21
    suma = 35
    tip = "mancare"
    lista_cheltuieli = []
    assert(len(lista_cheltuieli) == 0)
    service_adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,zi,suma,tip)
    assert(len(lista_cheltuieli) == 1)
    zi_invalid = 33
    suma_invalid = -342
    tip_invalid = ""
    try:
        service_adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,zi_invalid,suma_invalid,tip_invalid)
        assert(False)
    except Exception as ex:
        assert (str(ex) == "*Zi invalid\n*Suma invalid\n*Tip invalid\n")

def test_adaugare_cheltuiala_in_lista_cu_cheltuieli():
    zi = 21
    suma = 35
    tip= "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    assert(len(lista_cheltuieli)==0)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala)
    assert(len(lista_cheltuieli)==1)

def test_stergere_cheltuiala_din_lista_cu_cheltuieli_zi():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala)
    zi_a = 30
    suma_a = 50
    tip_a = "telefon"
    cheltuiala_a = creeaza_cheltuiala(zi_a, suma_a, tip_a)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala_a)
    assert(len(lista_cheltuieli)==2)
    stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli,zi_a)
    assert(len(lista_cheltuieli)==1)

def test_stergere_cheltuiala_din_lista_cu_cheltuieli_interval():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_a = 30
    suma_a = 50
    tip_a = "telefon"
    cheltuiala_a = creeaza_cheltuiala(zi_a, suma_a, tip_a)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_a)
    zi1 = 20
    zi2 = 25
    assert(len(lista_cheltuieli)==2)
    stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli,zi1,zi2)
    assert(len(lista_cheltuieli)==1)

def test_service_stergere_cheltuiala_din_lista_cu_cheltuieli_interval():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_a = 30
    suma_a = 50
    tip_a = "telefon"
    cheltuiala_a = creeaza_cheltuiala(zi_a, suma_a, tip_a)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_a)
    zi1 = 20
    zi2 = 25
    assert (len(lista_cheltuieli) == 2)
    stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli, zi1, zi2)
    assert (len(lista_cheltuieli) == 1)
    zi1a = 10
    zi2a = 15
    try:
        service_stergere_cheltuiala_din_lista_cu_cheltuieli_interval(lista_cheltuieli,zi1a,zi2a)
        assert (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli in acest interval de zile\n")
def test_service_stergere_cheltuiala_din_lista_cu_cheltuieli_zi():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_a = 30
    suma_a = 50
    tip_a = "telefon"
    cheltuiala_a = creeaza_cheltuiala(zi_a, suma_a, tip_a)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala_a)
    assert (len(lista_cheltuieli) == 2)
    stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli, zi_a)
    assert (len(lista_cheltuieli) == 1)
    try:
        service_stergere_cheltuiala_din_lista_cu_cheltuieli_zi(lista_cheltuieli,zi_a)
        assert (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli in aceasta zi\n" )

def test_validare_cheltuiala():
    zi_valid = 21
    suma_valid = 35
    tip_valid = "mancare"
    cheltuiala_valida = creeaza_cheltuiala(zi_valid, suma_valid, tip_valid)
    validare_cheltuiala(cheltuiala_valida)
    zi_invalid = 33
    suma_invalid = -342
    tip_invalid = ""
    cheltuiala_invalida = creeaza_cheltuiala(zi_invalid, suma_invalid, tip_invalid)
    try:
        validare_cheltuiala(cheltuiala_invalida)
        assert(False)
    except Exception as ex:
        assert (str(ex) == "*Zi invalid\n*Suma invalid\n*Tip invalid\n")

def test_validare_daca_cheltuiala_exista_in_sir():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi,suma,tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala)
    zi_a = 30
    suma_a = 50
    tip_a = "telefon"
    cheltuiala_a = creeaza_cheltuiala(zi_a, suma_a, tip_a)
    try:
        validare_daca_cheltuiala_exista_in_sir(lista_cheltuieli,cheltuiala_a)
        return (False)
    except Exception as ex:
        assert (str(ex) == "*Cheltuiala nu exista\n")


def test_validare_daca_exista_cheltuieli_zi():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_a = 22
    try:
        validare_daca_exista_cheltuieli_zi(lista_cheltuieli,zi_a)
        return (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli in aceasta zi\n")

def test_validare_daca_exista_cheltuieli_mai_mari_ca_suma():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    suma_a = 40
    try:
        validare_daca_exista_cheltuieli_mai_mari_ca_suma(lista_cheltuieli,suma_a)
        return(False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli mai mari decat aceasta suma\n")

def test_validare_daca_exista_cheltuieli_tip():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    tip_a = "telefon"
    try:
        validare_daca_exista_cheltuieli_tip(lista_cheltuieli,tip_a)
        return (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli de acest tip\n")

def test_validare_daca_exista_cheltuieli_zi_interval():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    lista_cheltuieli = []
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli, cheltuiala)
    zi_a = 30
    suma_a = 50
    tip_a = "telefon"
    cheltuiala_a = creeaza_cheltuiala(zi_a, suma_a, tip_a)
    adaugare_cheltuiala_in_lista_cu_cheltuieli(lista_cheltuieli,cheltuiala_a)
    zi1 = 10
    zi2 = 15
    try:
        validare_daca_exista_cheltuieli_zi_interval(lista_cheltuieli,zi1,zi2)
        return (False)
    except Exception as ex:
        assert (str(ex) == "*Nu exista cheltuieli in acest interval de zile\n")

def test_creeaza_cheltuiala():
    zi = 21
    suma = 35
    tip = "mancare"
    cheltuiala = creeaza_cheltuiala(zi, suma, tip)
    assert (get_cheltuiala_zi(cheltuiala) == zi)
    assert (get_cheltuiala_suma(cheltuiala) == suma)
    assert (get_cheltuiala_tip(cheltuiala) == tip)

def rularea_testelor():
    test_creeaza_cheltuiala()
    test_validare_cheltuiala()
    test_validare_daca_cheltuiala_exista_in_sir()
    test_validare_daca_exista_cheltuieli_zi()
    test_validare_daca_exista_cheltuieli_mai_mari_ca_suma()
    test_validare_daca_exista_cheltuieli_tip()
    test_validare_daca_exista_cheltuieli_zi_interval()
    test_validare_daca_exista_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma()
    test_adaugare_cheltuiala_in_lista_cu_cheltuieli()
    test_service_adaugare_cheltuiala_in_lista_cu_cheltuieli()
    test_actualizare_cheltuiala_in_lista_cu_cheltuieli()
    test_service_actualizare_cheltuiala_in_lista_cu_cheltuieli()
    test_stergere_cheltuiala_din_lista_cu_cheltuieli_zi()
    test_service_stergere_cheltuiala_din_lista_cu_cheltuieli_zi()
    test_stergere_cheltuiala_din_lista_cu_cheltuieli_interval()
    test_service_stergere_cheltuiala_din_lista_cu_cheltuieli_interval()
    test_stergere_cheltuiala_din_lista_cu_cheltuieli_tip()
    test_service_stergere_cheltuiala_din_lista_cu_cheltuieli_tip()
    test_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma()
    test_service_afisare_tuturor_cheltuielilor_mai_mari_ca_o_suma()
    test_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma()
    test_service_afisare_cheltuieli_inainte_de_o_zi_si_mai_mici_decat_o_suma()
    test_afisare_tuturor_cheltuielilor_de_un_anumit_tip()
    test_service_afisare_tuturor_cheltuielilor_de_un_anumit_tip()
    test_afisare_suma_totala_un_anumit_tip()
    test_service_afisare_suma_totala_un_anumit_tip()
    test_eliminare_cheltuieli_tip()
    test_service_eliminare_cheltuieli_tip()


#_____________________MAIN____________________________
def main():
    rularea_testelor()
    menu()

main()
