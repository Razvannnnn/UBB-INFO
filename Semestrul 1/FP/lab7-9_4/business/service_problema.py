from domeniu.problema import Problema

class ServiceProblema:
    def __init__(self, repo_problema, valid_problema):
        self.__repo_problema = repo_problema
        self.__valid_problema = valid_problema

    def adauga_problema(self, nr_lab_prob, descriere, deadline):
        problema = Problema(nr_lab_prob, descriere, deadline)
        self.__valid_problema.valideaza(problema)
        self.__repo_problema.adauga_problema(problema)

    def sterge_problema(self, nr_lab_prob):
        self.__valid_problema.valideaza_nr_lab_prob(nr_lab_prob)
        self.__repo_problema.sterge_problema(nr_lab_prob)

    def modif_problema(self, nr_lab_prob, new_descriere, new_deadline):
        self.__valid_problema.valideaza_nr_lab_prob(nr_lab_prob)
        self.__repo_problema.modif_problema(nr_lab_prob, new_descriere, new_deadline)

    def cauta_problema(self, nr_lab_prob):
        self.__valid_problema.valideaza_nr_lab_prob(nr_lab_prob)
        return self.__repo_problema.cauta_problema(nr_lab_prob)

    def get_all_probleme(self):
        return self.__repo_problema.get_all()
