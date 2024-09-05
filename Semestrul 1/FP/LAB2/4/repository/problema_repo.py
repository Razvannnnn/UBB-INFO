from domain.entities import *

class Problema_repo:
    def __init__(self):
        self.__probleme = []

    def add_problema(self, new_problema):
        """
        Adauga o problema
        :param new_problema: Noua problema
        :return:
        """
        self.__probleme.append(new_problema)

    def delete_problema(self, nr_lab, nr_prob):
        """
        Sterge o problema
        :param nr_lab: Numarul laboratorului
        :param nr_prob: Numarul problemei
        :return:
        """
        new_probleme = []
        for i in self.__probleme:
            if i.get_nr_laborator() != nr_lab:
                if i.get_nr_problema() != nr_prob:
                    new_probleme.append(i)
        self.__probleme = new_probleme

    def modify_problema(self, nr_lab, nr_prob, new_descriere, new_deadline):
        """
        Modifica o problema
        :param nr_lab: Numarul laboratorului problemei
        :param nr_prob: Numarul problemei
        :param new_descriere: Noua descriere
        :param new_deadline: Noul deadline
        :return:
        """
        new_probleme = []
        for i in self.__probleme:
            if i.get_nr_laborator() == nr_lab and i.get_nr_problema() == nr_prob:
                i.set_descriere(new_descriere)
                i.set_deadline(new_deadline)
            new_probleme.append(i)
        self.__probleme = new_probleme

    def all_probleme(self):
        """
        Returneaza lista cu probleme
        :return:
        """
        return self.__probleme