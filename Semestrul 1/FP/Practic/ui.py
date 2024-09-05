from domain.tractor import Tractor
class UI:
    def __init__(self, srv_tractor):
        self.__srv_tractor = srv_tractor
        self.__tractoare = []

    def run(self):
        while True:
            if self.__tractoare != []:
                print("\nLista tractoare:\n")
                for i in self.__tractoare:
                    print(i)

            print("""
    1. Adaugare Tractor
    2. Stergere Tractor
    3. Filtrare Tractor
    4. Undo
    0. Exit
    """)
            comanda = input("Comanda aleasa:")
            if comanda == "1":
                try:
                    id = input("ID:")
                    denumire = input("Denumire:")
                    pret = input("Pret:")
                    model = input("Model:")
                    data_revizie = input("Data revizie (zi:luna:an):")
                    tractor = Tractor(id, denumire, pret, model, data_revizie)
                    self.__srv_tractor.adaugare(tractor)
                except Exception as ex:
                    print(ex)
            elif comanda == "2":
                try:
                    cifra = input("Cifra:")
                    k = self.__srv_tractor.stergere(cifra)
                    print(f"Au fost sterse {k} tractoare!")
                except Exception as ex:
                    print(ex)
            elif comanda == "3":
                try:
                    text = input("Text:")
                    numar = input("Numar:")
                    print(f"Filtru curent: TEXT={text} si NUMAR={numar}")
                    lista = self.__srv_tractor.filtrare(text, numar)
                    self.__tractoare = lista
                    for i in lista:
                        print(i)
                except Exception as ex:
                    print(ex)
            elif comanda == "4":
                try:
                    pass
                except Exception as ex:
                    print(ex)
            elif comanda == "0":
                return
            else:
                print("Comanda invalida!")

