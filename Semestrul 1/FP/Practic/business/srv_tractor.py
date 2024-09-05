class ServiceTractor:
    def __init__(self, repo_tractor, validare_tractor):
        self.__repo_tractor = repo_tractor
        self.__validare_tractor = validare_tractor

    def adaugare(self, tractor):
        """
        Functie ce adauga un tractor in lista de tractoare
        :param tractor: obiectul tractor
        :return:
        """
        self.__repo_tractor.adaugare(tractor)

    def stergere(self, cifra):
        """
        Functie ce sterge tractoarele a caror pret contine cifra cifra si returneaza numarul de tractoare sterse
        :param cifra: int
        :return: nr de tractoare sterse
        """
        return self.__repo_tractor.stergere(cifra)

    def filtrare(self, text, numar):
        return self.__repo_tractor.filtrare(text, numar)

    def get_all(self):
        """
        Functie ce returneaza toata lista de tractoare
        :return: lista de tractoare
        """
        return self.__repo_tractor.get_all()