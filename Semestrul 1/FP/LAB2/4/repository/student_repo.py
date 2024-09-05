from domain.entities import *

class Student_repo:
    def __init__(self):
        self.__studenti = []

    def add_student(self, new_student):
        """
        Adauga un student
        :param new_student: Noul student
        """
        self.__studenti.append(new_student)

    def delete_student(self, id):
        """
        Sterge un student
        :param id: ID-ul studentului pe care il stergem
        :return:
        """
        new_studenti = []
        for i in self.__studenti:
            if i.get_student_id() != id:
                new_studenti.append(i)
        self.__studenti = new_studenti

    def modify_student(self, id, new_nume, new_grup):
        """
        Modifica un student
        :param id: ID-ul studentului pe care il modificam
        :param new_nume: Noul nume
        :param new_grup: Noua grupa
        :return:
        """
        new_studenti = []
        for i in self.__studenti:
            if i.get_student_id() == id:
                i.set_nume(new_nume)
                i.set_grup(new_grup)
            new_studenti.append(i)
        self.__studenti = new_studenti

    def all_students(self):
        """
        Returneaza toata lista de studenti
        :return:
        """
        return self.__studenti