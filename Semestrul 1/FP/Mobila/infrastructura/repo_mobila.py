from domain.mobila import Mobila

class RepoMobila:
    def __init__(self):
        self._mobila = {}

    def adaugare(self, mobila):
        cod = mobila.get_cod()
        if cod in self._mobila:
            raise Exception("Mobila existenta")
        self._mobila[cod] = mobila

    def cautare(self, cod):
        if cod not in self._mobila:
            raise Exception("Mobila inexistenta")
        return self._mobila[cod]

    def cautare_tip(self, tip):
        mobila_tip = {}
        for mobila in self._mobila:
            if self._mobila[mobila].get_tip() == tip:
                mobila_tip[mobila] = self._mobila[mobila]
        return mobila_tip

    def modifcare(self, mobila):
        cod = mobila.get_cod()
        if cod not in self._mobila:
            raise Exception("Mobila inexistenta")
        self._mobila[cod] = mobila

    def stergere(self, cod):
        if cod not in self._mobila:
            raise Exception("Mobila inexistenta")
        del self._mobila[cod]

class FileRepoMobila(RepoMobila):
    def __init__(self, cale_fisier):
        RepoMobila.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_from_file(self):
        with open(self.__cale_fisier, "r") as f:
            self._mobila.clear()
            lines = f.readlines()
            for line in lines:
                if line != "":
                    parts = line.split(",")
                    cod = parts[0]
                    tip = parts[1]
                    nume = parts[2]
                    stock = parts[3]
                    pret = parts[4]
                    mobila = Mobila(cod, tip, nume, stock, pret)
                    self._mobila[cod] = mobila

    def __write_all_to_file(self):
        with open(self.__cale_fisier, "w") as f:
            for cod in self._mobila:
                f.write(str(self._mobila[cod])+"\n")

    def adaugare(self, mobila):
        self.__read_all_from_file()
        RepoMobila.adaugare(self, mobila)
        self.__write_all_to_file()

    def cautare(self, cod):
        self.__read_all_from_file()
        return RepoMobila.cautare(self, cod)

    def modifcare(self, mobila):
        self.__read_all_from_file()
        RepoMobila.modifcare(self, mobila)
        self.__write_all_to_file()

    def stergere(self, cod):
        self.__read_all_from_file()
        RepoMobila.stergere(self, cod)
        self.__write_all_to_file()

    def cautare_tip(self, tip):
        self.__read_all_from_file()
        return RepoMobila.cautare_tip(self, tip)
