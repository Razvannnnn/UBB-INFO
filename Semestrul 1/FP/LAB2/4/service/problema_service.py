from domain.entities import *
from domain.validators import *
from repository.problema_repo import *

class ServiceProblema:
    def __init__(self, repo, valid):
        self.__repo = repo
        self.__valid = valid

    def insert_problema(self, nr_lab, nr_prob, descriere, deadline):
        """
        Insereaza o problema in lista
        :param nr_lab:
        :param nr_prob:
        :param descriere:
        :param deadline:
        :return:
        """
        problem = Problema(nr_lab,nr_prob,descriere,deadline)
        validatorProblema.validate(problem)
        Problema_repo.add_problema(problem)