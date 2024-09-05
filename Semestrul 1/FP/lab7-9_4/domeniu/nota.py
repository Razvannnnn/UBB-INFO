class Nota:
    def __init__(self, id_student, nr_lab_prob, nota):
        self.__id_student = id_student
        self.__nr_lab_prob = nr_lab_prob
        self.__nota = nota

    def get_id(self):
        return self.__id_student

    def get_nr_lab(self):
        return self.__nr_lab_prob

    def get_nota(self):
        return self.__nota

    def set_id(self, id_student):
        self.__id_student = id_student

    def set_nr_lab(self, nr_lab_prob):
        self.__nr_lab_prob = nr_lab_prob

    def set_nota(self, nota):
        self.__nota = nota

    def __str__(self):
        return f"{self.__id_student},{self.__nr_lab_prob},{self.__nota}"