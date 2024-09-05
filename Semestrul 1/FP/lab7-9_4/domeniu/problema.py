class Problema:
    def __init__(self, nr_lab_prob, descriere, deadline):
        self.__nr_lab_prob = nr_lab_prob
        self.__descriere = descriere
        self.__deadline = deadline

    def get_nr_lab_prob(self):
        return self.__nr_lab_prob

    def get_descriere(self):
        return self.__descriere

    def get_deadline(self):
        return self.__deadline

    def set_nr_lab_prob(self, new_nr_lab_prob):
        self.__nr_lab_prob  = new_nr_lab_prob

    def set_descriere(self, new_descriere):
        self.__descriere = new_descriere

    def set_deadline(self, new_deadline):
        self.__deadline = new_deadline


    def __str__(self):
        return f"{self.__nr_lab_prob},{self.__descriere},{self.__deadline}"
