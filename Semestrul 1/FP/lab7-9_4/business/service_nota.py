class ServiceNota:
    def __init__(self, repo_nota, valid_nota, repo_stud, repo_prob):
        self.__repo_nota = repo_nota
        self.__valid_nota = valid_nota
        self.__repo_stud = repo_stud
        self.__repo_prob = repo_prob

    def asign_problema(self, id_student, nr_lab_prob):
        self.__repo_nota.asign_problema(id_student, nr_lab_prob)

    def asign_nota(self, id_student, nr_lab_prob, nota):
        self.__repo_nota.asign_nota(id_student, nr_lab_prob, nota)

    def sterge_problema(self, id_student, nr_lab_prob):
        self.__repo_nota.sterge_problema(id_student, nr_lab_prob)

    def modif_nota(self, id_student, nr_lab_prob, new_nota):
        self.__repo_nota.modif_nota(id_student, nr_lab_prob, new_nota)

    def sort_nume(self, nr_lab_prob):
        students = self.__repo_prob.sort_nume()

    def print_note_id(self, id_student):
        return self.__repo_nota.print_note_id(id_student)

    def sort_note(self):
        return self.__repo_nota.sort_note()

    def media_sub_5_id(self, id_student):
        return self.__repo_nota.media_sub_5_id(id_student)

    def get_all_note(self):
        return self.__repo_nota.get_all_note()
