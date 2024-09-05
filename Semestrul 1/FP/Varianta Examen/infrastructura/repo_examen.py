from domain.examen import Examen
class RepoExamen:
    def __init__(self):
        self._examene = []

    def adaugare(self, examen):
        if examen not in self._examene:
            self._examene.append(examen)
        else:
            raise Exception("Examen existent")

    def stergere(self, examen):
        for i in self._examene:
            if self._examene[i] == examen:
                del self._examene[i]
                return
        raise Exception("Examen inexistent")

    def get_all(self):
        return self._examene

    def get_all_examene_maine(self, zi, luna):
        examene_maine = []
        for i in self._examene:
            if i.get_zi() == zi and i.get_luna() == luna:
                examene_maine.append(i)
        return examene_maine

class FileRepoExamen(RepoExamen):
    def __init__(self, cale_fisier):
        RepoExamen.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_from_file(self):
        with open(self.__cale_fisier, "r") as f:
            self._examene.clear()
            lines = f.readlines()
            for line in lines:
                if line != "":
                    parts = line.split(",")
                    data = parts[0]
                    ora = parts[1]
                    materia = parts[2]
                    restanta = str(parts[3])
                    examen = Examen(data, ora, materia, restanta)
                    self._examene.append(examen)

    def __write_to_file(self):
        with open(self.__cale_fisier, "w") as f:
            for i in self._examene:
                f.write(str(i) + "\n")

    def adaugare(self, examen):
        self.__read_from_file()
        RepoExamen.adaugare(self, examen)
        self.__write_to_file()

    def stergere(self, examen):
        self.__read_from_file()
        RepoExamen.stergere(self, examen)
        self.__write_to_file()

    def get_all(self):
        self.__read_from_file()
        RepoExamen.get_all(self)