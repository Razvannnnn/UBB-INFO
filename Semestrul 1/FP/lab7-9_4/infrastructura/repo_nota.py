from domeniu.nota import Nota

class RepoNota:
    def __init__(self):
        self._note = {

        }

    def asign_problema(self, id_student, nr_lab_prob):
        nota = Nota(id_student, nr_lab_prob, 0)
        self._note[len(self._note)] = nota

    def asign_nota(self, id_student, nr_lab_prob, nota):
        ok = 0
        if nota < 0 or nota > 10:
            raise Exception("Nota invalida")
        for i in range(len(self._note)):
            if self._note[i].get_id() == int(id_student) and self._note[i].get_nr_lab == nr_lab_prob:
                self._note[i].set_nota(nota)


    def modif_nota(self, id_student, nr_lab_prob, nota):
        for i in range(len(self._note)):
            if self._note[i].get_id() == int(id_student) and self._note[i].get_nr_lab() == nr_lab_prob:
                self._note[i].set_nota(nota)


    def sterge_problema(self, id_student, nr_lab_prob):
        for i in range(len(self._note)):
            if self._note[i].get_id == int(id_student) and self._note[i].get_nr_lab == nr_lab_prob:
                self._note.pop(i)


    def sterge_nota(self, id_student, nr_lab_prob):
        for i in range(len(self._note)):
            if self._note[i].get_id == int(id_student) and self._note[i].get_nr_lab == nr_lab_prob:
                self._note[i].set_nota(0)

    def print_note_id(self, id_student):
        note = {}
        for i in range(len(self._note)):
            if self._note[i][0] == int(id_student):
                note[i] = self._note[i]
        return note

    def sort_note(self):
        note = sorted(self._note.values(), key=lambda x: x.get_nota())
        return note

    def media_sub_5_id(self, id_student):
        k=0
        suma=0
        for i in range(len(self._note)):
            if self._note[i][0] == id_student:
                suma += self._note[i][2]
                k+=1
        if k!=0 and (suma/k)<5:
            return 1
        return 0

    def get_all_note(self):
        return [self._note[x] for x in self._note]

class FileRepoNote(RepoNota):
    def __init__(self, cale_fisier):
        RepoNota.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_note_from_file(self):
        with open(self.__cale_fisier,"r") as f:
            self._note.clear()
            lines = f.readlines()
            for line in lines:
                if line != "":
                    parts = line.split(",")
                    id_student = int(parts[0])
                    nr_lab_prob = parts[1]
                    nota = int(parts[2])
                    notare = Nota(id_student, nr_lab_prob, nota)
                    self._note[len(self._note)] = notare

    def __write_all_note_to_file(self):
        with open(self.__cale_fisier,"w") as f:
            for i in range(len(self._note)):
                f.write(str(self._note[i])+"\n")

    def asign_problema(self, id_student, nr_lab_prob):
        self.__read_all_note_from_file()
        RepoNota.asign_problema(self, id_student, nr_lab_prob)
        self.__write_all_note_to_file()

    def asign_nota(self, id_student, nr_lab_prob, nota):
        self.__read_all_note_from_file()
        RepoNota.asign_nota(self, id_student, nr_lab_prob, nota)
        self.__write_all_note_to_file()

    def modif_nota(self, id_student, nr_lab_prob, nota):
        self.__read_all_note_from_file()
        RepoNota.modif_nota(self, id_student, nr_lab_prob, nota)
        self.__write_all_note_to_file()

    def sterge_problema(self, id_student, nr_lab_prob):
        self.__read_all_note_from_file()
        RepoNota.sterge_problema(self, id_student, nr_lab_prob)
        self.__write_all_note_to_file()

    def sterge_nota(self, id_student, nr_lab_prob):
        self.__read_all_note_from_file()
        RepoNota.sterge_nota(self, id_student, nr_lab_prob)
        self.__write_all_note_to_file()

    def print_note_id(self, id_student):
        self.__read_all_note_from_file()
        RepoNota.print_note_id(self, id_student)
        self.__write_all_note_to_file()

    def sort_note(self):
        self.__read_all_note_from_file()
        RepoNota.sort_note(self)
        self.__write_all_note_to_file()

    def media_sub_5_id(self, id_student):
        self.__read_all_note_from_file()
        RepoNota.media_sub_5_id(self, id_student)
        self.__write_all_note_to_file()

    def get_all_note(self):
        self.__read_all_note_from_file()
        return RepoNota.get_all_note(self)
