from exceptii.repo_error import RepoError
from domeniu.problema import Problema
class RepoProbleme:
    def __init__(self):
        self._probleme = {

        }

    def adauga_problema(self, problema):
        nr_lab_prob = problema.get_nr_lab_prob()
        if nr_lab_prob in self._probleme:
            raise Exception("Problema existenta!")
        self._probleme[nr_lab_prob] = problema

    def sterge_problema(self, nr_lab_prob):
        if nr_lab_prob in self._probleme:
            del self._probleme[nr_lab_prob]
        else:
            raise Exception("Problema inexistenta!")

    def modif_problema(self, nr_lab_prob, new_descriere, new_deadline):
        if nr_lab_prob in self._probleme:
            self._probleme[nr_lab_prob].set_descriere(new_descriere)
            self._probleme[nr_lab_prob].set_deadline(new_deadline)
        else:
            raise Exception("Problema inexistenta!")

    def cauta_problema(self, nr_lab_prob):
        if nr_lab_prob in self._probleme:
            return self._probleme[nr_lab_prob]
        else:
            raise Exception("Problema inexistenta!")

    def existenta_problema(self, nr_lab_prob):
        if nr_lab_prob not in self._probleme:
            raise Exception("Problema inexistenta!")

    def get_all(self):
        return [self._probleme[x] for x in self._probleme]

class FileRepoProbleme(RepoProbleme):
    def __init__(self, cale_fisier):
        RepoProbleme.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_probleme_from_file(self):
        with open(self.__cale_fisier, "r") as f:
            self._probleme.clear()
            lines = f.readlines()
            for line in lines:
                if line != "":
                    parts = line.split(",")
                    nr_lab_prob = parts[0]
                    descriere = parts[1]
                    deadline = int(parts[2])
                    prob = Problema(nr_lab_prob, descriere, deadline)
                    self._probleme[nr_lab_prob] = prob

    def __write_all_probleme_to_file(self):
        with open(self.__cale_fisier,"w") as f:
            for nr_lab_prob in self._probleme:
                f.write(str(self._probleme[nr_lab_prob])+"\n")

    def adauga_problema(self, prob):
        self.__read_all_probleme_from_file()
        RepoProbleme.adauga_problema(self, prob)
        self.__write_all_probleme_to_file()

    def sterge_problema(self, nr_lab_prob):
        self.__read_all_probleme_from_file()
        RepoProbleme.sterge_problema(self, nr_lab_prob)
        self.__write_all_probleme_to_file()

    def modif_problema(self, nr_lab_prob, new_descriere, new_deadline):
        self.__read_all_probleme_from_file()
        RepoProbleme.modif_problema(self, nr_lab_prob, new_descriere, new_deadline)
        self.__write_all_probleme_to_file()

    def cauta_problema(self, nr_lab_prob):
        self.__read_all_probleme_from_file()
        RepoProbleme.cauta_problema(self, nr_lab_prob)
        self.__write_all_probleme_to_file()

    def get_all(self):
        self.__read_all_probleme_from_file()
        return RepoProbleme.get_all(self)