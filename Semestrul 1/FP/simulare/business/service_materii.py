from domain.material import Material
class ServiceMaterii:
    def __init__(self, repo_materie, valid_materie):
        self.__repo_materie = repo_materie
        self.__valid_materie = valid_materie

    def adaugare(self, cod, denumire, cantitate_pe_stoc, pret_unitar):
        """
        Se adauga un material in lista de materiale
        :param cod: Cod unic al materialului
        :param denumire: Denumirea materialului
        :param cantitate_pe_stoc: Cantitate de pe stoc
        :param pret_unitar: Pretul per unitate
        :return:
        """
        material = Material(cod, denumire, cantitate_pe_stoc, pret_unitar)
        self.__valid_materie.validare_materie(material)
        self.__repo_materie.adaugare(material)

    def stergere(self, cod):
        """
        Se sterge un material in functie de cod
        :param cod: Codul unic al materialului
        :return:
        """
        self.__valid_materie.validare_existenta(cod)
        self.__repo_materie.stergere(cod)

    def modificare(self, cod, denumire, cantitate_pe_stoc, pret_unitar):
        """
        Se modifica un material
        :param cod: Codul unic al materialului
        :param denumire: Denumirea materialului nou
        :param cantitate_pe_stoc: Cantitatea noua de material
        :param pret_unitar: Pretul nou per unitate
        :return:
        """
        self.__valid_materie.validare_existenta(cod)
        material = Material(cod, denumire, cantitate_pe_stoc, pret_unitar)
        self.__repo_materie.modificare(material)

    def cautare(self, cod):
        """
        Se cauta un material in functie de cod
        :param cod: Codul unic al materialului
        :return: Materialul cautat
        """
        self.__valid_materie.validare_existentac(cod)
        return self.__repo_materie.cautare(cod)
