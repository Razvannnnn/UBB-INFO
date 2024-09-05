class Console:
    def __init__(self, srv_mobila):
        self.__srv_mobila = srv_mobila
        self.__comenzi ={
            "add_mobila":self.__ui_adaugare,
            "del_mobila":self.__ui_stergere,
            "modif_mobila":self.__ui_modificare,
            "cauta_mobila":self.__ui_cautare,
            "cauta_tip":self.__ui_cautare_tip
        }

    def __ui_adaugare(self,params):
        if len(params) != 5:
            print("Nr parametri invalid")
            return
        try:
            cod = params[0]
            tip = params[1]
            nume = params[2]
            stock = int(params[3])
            pret = int(params[4])
            self.__srv_mobila.adaugare(cod, tip, nume, stock, pret)
        except Exception as ex:
            print(ex)

    def __ui_stergere(self,params):
        if len(params) != 1:
            print("Nr parametri invalid")
            return
        try:
            cod = params[0]
            self.__srv_mobila.stergere(cod)
        except Exception as ex:
            print(ex)

    def __ui_modificare(self,params):
        if len(params) != 5:
            print("Nr parametri invalid")
            return
        try:
            cod = params[0]
            tip = params[1]
            nume = params[2]
            stock = int(params[3])
            pret = int(params[4])
            self.__srv_mobila.modificare(cod, tip, nume, stock, pret)
        except Exception as ex:
            print(ex)

    def __ui_cautare(self,params):
        if len(params) != 1:
            print("Nr parametri invalid")
            return
        try:
            cod = params[0]
            print(self.__srv_mobila.cautare(cod))
        except Exception as ex:
            print(ex)

    def __ui_cautare_tip(self, params):
        if len(params) != 1:
            print("Nr parametri invalid")
            return
        try:
            tip = params[0]
            mobila_tip = self.__srv_mobila.cautare_tip(tip)
            for mobila in mobila_tip:
                print(mobila_tip[mobila])
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
            parts = comanda.split(' ', 1)
            comanda_nume = parts[0]
            params = parts[1]
            parti = params.split(', ')
            if comanda_nume in self.__comenzi:
                try:
                    self.__comenzi[comanda_nume](parti)
                except Exception as ex:
                    print(ex)
            else:
                print("Comanda invalida")
