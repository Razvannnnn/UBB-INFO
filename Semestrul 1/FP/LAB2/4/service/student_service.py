from domain.entities import *
from domain.validators import *
from repository.student_repo import *

class ServiceStudent:

    def __init__(self, repo, valid):
        self.__repo = repo
        self.__valid = valid

    def insert_student(self, id, nume, grup):
        """
        Insereaza un student in lista
        :param id:
        :param nume:
        :param grup:
        :return:
        """
        student = Student(id,nume,grup)
        self.__valid.validate(student)
        self.__repo.add_student(student)
        return student

    def all_students(self):
        return self.__repo.all_students()