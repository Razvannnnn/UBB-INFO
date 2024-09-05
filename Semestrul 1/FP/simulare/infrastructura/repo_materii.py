from domain.material import Material
class RepoMaterie:
    def __init__(self):
        self._materii = {}

    def adaugare(self, materie):
        cod = materie.get_cod()
        if cod in self._materii:
            raise Exception("Material existent")
        self._materii[cod] = materie

    def stergere(self, cod):
        if cod not in self._materii:
            raise Exception("Material inexistent")
        del self._materii[cod]

    def modificare(self, materie):
        cod = materie.get_cod()
        if cod not in self._materii:
            raise Exception("Material inexistent")
        self._materii[cod] = materie

    def cautare(self, cod):
        if cod not in self._materii:
            raise Exception("Material inexistent")
        return self._materii[cod]


class FileRepoMaterie(RepoMaterie):

    def __init__(self, cale_fisier):
        RepoMaterie.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_from_file(self):
        with open(self.__cale_fisier, "r") as f:
            lines = f.readline()
            self._materii.clear()
            for line in lines:
                if line != "":
                    parts = line.split(",")
                    cod = int(parts[0])
                    denumire = parts[1]
                    cantitate_pe_stoc = int(parts[2])
                    pret_unitar = int(parts[3])
                    materie = Material(cod, denumire, cantitate_pe_stoc, pret_unitar)
                    self._materii[cod] = materie

    def __write_all_to_file(self):
        with open(self.__cale_fisier, "w") as f:
            for cod in self._materii:
                f.write(str(self._materii[cod])+"\n")

    def adaugare(self, materie):
        self.__read_all_from_file()
        RepoMaterie.adaugare(self, materie)
        self.__write_all_to_file()

    def cautare(self, cod):
        self.__read_all_from_file()
        return RepoMaterie.cautare(self, cod)
