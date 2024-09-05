from domain.tractor import Tractor
class RepoTractor:
    def __init__(self):
        self._tractoare = []

    def adaugare(self, tractor):
        """
        Functie de adaugare a unui tractor in lista de tractoare
        :param tractor: obiectul tractor
        :return:
        """
        for i in self._tractoare:
            if i.get_id() == tractor.get_id():
                raise Exception("Tractor existent!")
        self._tractoare.append(tractor)

    def stergere(self, cifra):
        """
        Functie ce sterge tractoarele a caror pret contin cifra cifra si returneaza nr de tractoare sterse
        :param cifra: int
        :return: k - nr de tractoare sterse
        """
        k=0
        for i in range(len(self._tractoare)-1, 0, -1):
            if self.cifra_in_pret(self._tractoare[i], cifra):
                del self._tractoare[i]
                k+=1
        return k

    def filtrare(self, text, numar):
        """
        Functie ce filtreaza tractoarele in functie de un text si un numar si returneaza o lista noua
        :param text: str
        :param numar: int
        :return: lista noua
        """
        lista_noua = []
        for i in self._tractoare:
            if int(numar) != -1 and text != "":
                if int(i.get_pret()) < int(numar) and self.contine_text(i.get_denumire(), text):
                    lista_noua.append(i)
            elif int(numar) == -1 and text != "":
                if self.contine_text(i.get_denumire(), text):
                    lista_noua.append(i)
            elif int(numar) != -1 and text == "":
                if int(i.get_pret()) < int(numar):
                    lista_noua.append(i)
            elif int(numar) == -1 and text == "":
                lista_noua.append(i)
        return lista_noua

    def contine_text(self, denumire, text):
        """
        Verifica daca un str contine alt str
        :param denumire: str
        :param text: str
        :return: 1 sau 0
        """
        if text in denumire:
            return 1
        return 0

    def cifra_in_pret(self, tractor, cifra):
        """
        Functie ce verifica daca in pretul tractorului exista cifra cifra
        :param tractor: obiect tractor
        :param cifra: int
        :return: 1 sau 0
        """
        pret = int(tractor.get_pret())
        while pret!=0:
            c= pret % 10
            pret=pret//10
            if int(c)==int(cifra):
                return 1
        return 0

    def get_all(self):
        """
        Functie ce returneaza lista de tractoare
        :return: lista tractoare
        """
        return self._tractoare

class FileRepoTractor(RepoTractor):
    def __init__(self, cale_fisier):
        RepoTractor.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_from_file(self):
        with (open(self.__cale_fisier, "r") as f):
            self._tractoare.clear()
            lines = f.readlines()
            for line in lines:
                if line != "" and line !="\n":
                    parts = line.split(",")
                    id = parts[0]
                    denumire = parts[1]
                    pret = parts[2]
                    model = parts[3]
                    data_revizie = parts[4]
                    tractor = Tractor(id, denumire, pret, model, data_revizie)
                    self._tractoare.append(tractor)

    def __write_to_file(self):
        with open(self.__cale_fisier, "w") as f:
            for i in self._tractoare:
                f.write(str(i) + "\n")

    def adaugare(self, tractor):
        self.__read_from_file()
        RepoTractor.adaugare(self, tractor)
        self.__write_to_file()

    def stergere(self, cifra):
        self.__read_from_file()
        k = RepoTractor.stergere(self, cifra)
        self.__write_to_file()
        return k

    def filtrare(self, text, numar):
        self.__read_from_file()
        return RepoTractor.filtrare(self, text, numar)

    def get_all(self):
        self.__read_from_file()
        return RepoTractor.get_all(self)