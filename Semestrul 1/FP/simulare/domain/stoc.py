class Stoc:
    def __init__(self, cod, denumire,):
        self.__cantitate_pe_stoc = cantitate_pe_stoc
        self.__pret_unitar = pret_unitar
        self.__denumire = denumire
        self.__cod = cod

    def get_cod(self):
        return self.__cod

    def get_denumire(self):
        return self.__denumire

    def get_cantiate_pe_stoc(self):
        return self.__cantitate_pe_stoc

    def get_pret_unitar(self):
        return self.__pret_unitar

    def set_denumire(self, denumire):
        self.__denumire = denumire

    def set_canitate_pe_stoc(self, cantitate_pe_stoc):
        self.__cantitate_pe_stoc = cantitate_pe_stoc

    def set_pret_unitar(self, pret_unitar):
        self.__pret_unitar = pret_unitar

    def __str__(self):
        return f"{self.__cod},{self.__denumire},{self.__cantitate_pe_stoc},{self.__pret_unitar}"