from functii import *

cheltuieli_familie = []

def menu():
    """
    Afiseaza meniul aplicatiei si optiunile sale
    Conform functiei alese, aplicatia va apela subprogramul dorit
    """

    print("************Calculator_cheltuieli_familie************")

    choise = int(input("""
    1.Adauga cheltuiala
    2.Stergere
    3.Cautari
    4.Rapoarte
    5.Filtrare
    6.Undo
    7.Exit

      Alegeti optiunea:"""))

    if choise == 1:
        opt1()
        menu()
    elif choise == 2:
        opt2()
        menu()
    elif choise == 3:
        opt3()
        menu()
    elif choise == 4:

        menu()
    elif choise == 5:
        opt5()
        menu()
    elif choise == 6:

        menu()
    elif choise == 7:
        exit()
    elif choise ==8:
        print(cheltuieli_familie)
        menu()
    else:
        print()
        print("Trebuie sa selectati o optiune existenta")
        print("Va rugam sa incercati din nou")
        print()
        menu()

def opt1():
    """
    Aceasta functe afiseaza sub-optiunile primei categorii "Adauga cheltuiala"
    Se permit 3 input-uri
    1 - Adauga o noua cheltuiala
    2 - Actualizeaza o cheltuiala
    3 - Revine la meniul principal
    """

    choise = int(input("""
*****************************************************

    1.Adauga o noua cheltuiala
    2 Actualizeaza cheltuiala
    3.Inapoi

      Alegeti optiunea:"""))

    if choise == 1:
        print()
        print("Informatii despre noua cheltuiala:")
        add_cheltuiala(cheltuieli_familie,input("Zi="),input("Suma="),input("\nSe admit doar urmatoarele categorii de cheltuieli:"
                       "\nmâncare, întreținere, îmbrăcăminte, telefon, altele \n\nTip="))
    elif choise == 2:
        print()
        print("Informatii despre cheltuiala pe care vrem sa o actualizam:")
        actualiz_cheltuiala(cheltuieli_familie,input("Zi="),input("Suma="),input("\nSe admit doar urmatoarele categorii de cheltuieli:"
                            "\nmâncare, întreținere, îmbrăcăminte, telefon, altele \n\nTip="),
                            input("Informatiile pe care vrem sa le actualizam:\nNoua zi="),input("Noua suma="),
                            input("\nSe admit doar urmatoarele categorii de cheltuieli:"
                            "\nmâncare, întreținere, îmbrăcăminte, telefon, altele \n\nNoul tip="))
    elif choise == 3:
        print()
        menu()
    else:
        print()
        print("Trebuie sa selectati o optiune existenta")
        print("Va rugam sa incercati din nou")
        print()
        opt1()

def opt2():
    """
    Aceasta functe afiseaza sub-optiunile celei de a treia categorie "Stergere"
    Se permit 4 input-uri
    1 - Șterge toate cheltuielile pentru ziua dată
    2 - Șterge cheltuielile pentru un interval de timp - zi_inceput si zi_sfarsit
    3 - Șterge toate cheltuielile de un anumit tip
    4 - Revine la meniul principal
    """

    choise = int(input("""
*****************************************************
    
    1.Șterge toate cheltuielile pentru ziua dată
    2 Șterge cheltuielile pentru un interval de timp 
    3.Șterge toate cheltuielile de un anumit tip
    4.Inapoi

      Alegeti optiunea:"""))

    afisare = []

    if choise == 1:
        print()
        sterge_cheltuieli_zi(cheltuieli_familie,input("Zi="))
    elif choise == 2:
        print()
        sterge_cheltuieli_range_zi(cheltuieli_familie,input("Zi inceput="),input("Zi sfarsit="))
    elif choise == 3:
        print()
        sterge_cheltuieli_tip(cheltuieli_familie,input("Tip="))
    elif choise == 4:
        print()
        menu()
    else:
        print()
        print("Trebuie sa selectati o optiune existenta")
        print("Va rugam sa incercati din nou")
        print()
        opt2()

def opt3():
    """
    Aceasta functe afiseaza sub-optiunile celei de a treia categorie "Cautari"
    Se permit 4 input-uri
    1 - Afiseaza toate cheltuielile mai mari decat o suma data
    2 - Afiseaza toate cheltuielile efectuate inainte de o zi data si mai mici decat o suma
    3 - Afiseaza toate cheltuielile de un anumit tip
    4 - Revine la meniul principal
    """

    choise = int(input("""
*****************************************************

    1.Tipărește toate cheltuielile mai mari decât o sumă dată   
    2 Tipărește toate cheltuielile efectuate înainte de o zi dată și mai mici decât o sumă
    3.Tipărește toate cheltuielile de un anumit tip
    4.Inapoi

      Alegeti optiunea:"""))

    afisare = []

    if choise == 1:
        print("\nAfiseaza toate cheltuielile mai mari decat o suma aleasa\n")
        afisare = print_cheltuieli_mai_mari_decat_suma(cheltuieli_familie, input("Suma="))
        print(afisare)
        print()
    elif choise == 2:
        print("\nAfiseaza toate cheltuielile efectuate înainte de o zi dată și mai mici decât o sumă\n")
        afisare = print_cheltuieli_inainte_de_zi_si_mai_mici_decat_suma(cheltuieli_familie, input("Zi="),
                                                                        input("Suma="))
        print(afisare)
        print()
    elif choise == 3:
        print("\nAfiseaza toate cheltuielile de un tip ales\n")
        afisare = print_cheltuieli_tip(cheltuieli_familie, input("Tip="))
        print(afisare)
        print()
    elif choise == 4:
        print()
        menu()
    else:
        print()
        print("Trebuie sa selectati o optiune existenta")
        print("Va rugam sa incercati din nou")
        print()
        opt3()

def opt5():
    """
        Aceasta functe afiseaza sub-optiunile celei de a cincea categorie "Filtrare"
        Se permit 3 input-uri
        1 - Elimină toate cheltuielile de un anumit tip
        2 - Elimină toate cheltuielile mai mici decât o sumă dată
        3 - Revine la meniul principal
        """

    choise = int(input("""
*****************************************************

    1.Elimină toate cheltuielile de un anumit tip 
    2 Elimină toate cheltuielile mai mici decât o sumă dată
    3.Inapoi

          Alegeti optiunea:"""))

    if choise == 1:
        print("\nAfiseaza toate cheltuielile, de unde, sunt eliminate cele de un tip ales\n")
        elim_cheltuieli_tip(cheltuieli_familie,input("Tip="))
        print()
    elif choise == 2:

        print()
    elif choise == 3:
        print()
        menu()
    else:
        print()
        print("Trebuie sa selectati o optiune existenta")
        print("Va rugam sa incercati din nou")
        print()
        opt5()