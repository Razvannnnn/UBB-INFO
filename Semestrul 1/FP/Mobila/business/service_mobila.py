from domain.mobila import Mobila
class ServiceMobila:
    def __init__(self, repo_mobila, valid_mobila):
        self.__repo_mobila = repo_mobila
        self.__valid_mobila = valid_mobila

    def adaugare(self, cod, tip, nume, stock, pret):
        mobila = Mobila(cod, tip, nume, stock, pret)
        self.__repo_mobila.adaugare(mobila)

    def cautare(self, cod):
        return self.__repo_mobila.cautare(cod)

    def cautare_tip(self, tip):
        return self.__repo_mobila.cautare_tip(tip)

    def modificare(self, cod, tip, nume, stock, pret):
        mobila = Mobila(cod, tip, nume, stock, pret)
        self.__repo_mobila.modificare(mobila)

    def stergere(self, cod):
        self.__repo_mobila.stergere(cod)
