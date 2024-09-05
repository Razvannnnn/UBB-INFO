from domain.material import Material

class Console:
    def __init__(self, srv_materie):
        self.__srv_materie = srv_materie
        self.__comenzi = {
            "add_materie":self.__ui_adaugare,
            "del_materie":self.__ui_stergere,
            "modif_materie":self.__ui_modificare,
            "cautare_materie":self.__ui_cautare
        }

    def __ui_adaugare(self, params):
        if len(params)!=4:
            print("Nr parametri invalid")
            return
        try:
            cod = int(params[0])
            denumire = params[1]
            cantitate_pe_stoc = int(params[2])
            pret_unitar = int(params[3])
            self.__srv_materie.adaugare(cod, denumire, cantitate_pe_stoc, pret_unitar)
        except Exception as ex:
            print(ex)

    def __ui_stergere(self, params):
        if len(params)!=1:
            print("Nr parametri invalid")
            return
        try:
            cod = int(params[0])
            self.__srv_materie.stergere(cod)
        except Exception as ex:
            print(ex)

    def __ui_cautare(self, params):
        if len(params)!=1:
            print("Nr parametri invalid")
            return
        try:
            cod = int(params[0])
            self.__srv_materie.cautare(cod)
        except Exception as ex:
            print(ex)

    def __ui_modificare(self, params):
        if len(params)!=4:
            print("Nr parametri invalid")
            return
        try:
            cod = int(params[0])
            denumire = params[1]
            cantitate_pe_stoc = int(params[2])
            pret_unitar = int(params[3])
            material = Material(cod, denumire, cantitate_pe_stoc, pret_unitar)
            self.__srv_materie.modificare(material)
        except Exception as ex:
            print(ex)

    def run(self):
        while True:
            comanda = input(">>>")
            comanda = comanda.strip()
            if comanda == "":
                continue
            if comanda == "exit":
                return
            parts = comanda.split()
            comanda_name = parts[0]
            params = parts[1:]
            if comanda_name in self.__comenzi:
                try:
                    self.__comenzi[comanda_name](params)
                except Exception as ex:
                    print(ex)
            else:
                print("Comanda invalida")
