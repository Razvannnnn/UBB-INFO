from operator import itemgetter
from domeniu.student import Student
from random import *
from exceptii.repo_error import RepoError

class RepoStudenti:
    def __init__(self):
        self._studenti = {

        }

    def adauga_student(self, student):
        id_student = student.get_id_student()
        if id_student in self._studenti:
            raise Exception("Student existent!")
        else:
            self._studenti[id_student] = student

    def sterge_student(self, id_student):
        if id_student in self._studenti:
            del self._studenti[id_student]
        else:
            raise Exception("Student inexistent!")


    def modif_student(self, id_student, nume, grup):
        if id_student in self._studenti:
            self._studenti[id_student].set_nume(nume)
            self._studenti[id_student].set_grup(grup)
        else:
            raise Exception("Student inexistent!")


    def cauta_student(self, id_student):
        if id_student in self._studenti:
            return self._studenti[id_student]
        else:
            raise Exception("Student inexistent!")

    def genereaza_student(self):
        lista_nume = ["Mihai", "Ion", "Bercea", "Maria", "Ilie", "Florin", "Dragos", "Elena", "George", "Miruna", "Dorian", "Alex", "Andrei", "Diana", "Razvan", "Stefan", "Alin"]
        id_student = randrange(1,9999)
        nume = choice(lista_nume)
        grup = randrange(1, 999)
        student = Student(id_student, nume, grup)
        return student

    def existenta_id(self, id_student):
        if not id_student in self._studenti:
            raise Exception("Student inexistent!")

    def get_all(self):
        return [self._studenti[x] for x in self._studenti]

    def studenti_dupa_nume(self):
        students = sorted(self._studenti.values(), key=lambda x: x.get_nume(), reverse=True)
        return students


class FileRepoStudenti(RepoStudenti):
    def __init__(self, cale_fisier):
        RepoStudenti.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_studenti_from_file(self):
        with open(self.__cale_fisier,"r") as f:
            self._studenti.clear()
            lines = f.readlines()
            for line in lines:
                if line != "":
                    parts = line.split(",")
                    id_student = int(parts[0])
                    nume = parts[1]
                    grup = int(parts[2])
                    student = Student(id_student, nume, grup)
                    self._studenti[id_student] = student

    def __write_all_studenti_to_file(self):
        with open(self.__cale_fisier,"w") as f:
            for id_student in self._studenti:
                f.write(str(self._studenti[id_student])+"\n")

    def adauga_student(self, student):
        self.__read_all_studenti_from_file()
        RepoStudenti.adauga_student(self, student)
        self.__write_all_studenti_to_file()

    def modif_student(self, id_student, nume, grup):
        self.__read_all_studenti_from_file()
        RepoStudenti.modif_student(self, id_student, nume, grup)
        self.__write_all_studenti_to_file()

    def sterge_student(self, id_student):
        self.__read_all_studenti_from_file()
        RepoStudenti.sterge_student(self, id_student)
        self.__write_all_studenti_to_file()

    def cauta_student(self, id_student):
        self.__read_all_studenti_from_file()
        RepoStudenti.cauta_student(self, id_student)
        self.__write_all_studenti_to_file()

    def get_all(self):
        self.__read_all_studenti_from_file()
        return RepoStudenti.get_all(self)

    def studenti_dupa_nume(self):
        self.__read_all_studenti_from_file()
        return RepoStudenti.studenti_dupa_nume(self)