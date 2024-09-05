from domeniu.student import Student

class ServiceStudent:
    def __init__(self, repo_student, valid_student):
        self.__repo_student = repo_student
        self.__valid_student = valid_student

    def adauga_student(self, id_student, nume, grup):
        student = Student(id_student, nume, grup)
        self.__valid_student.valideaza(student)
        self.__repo_student.adauga_student(student)

    def sterge_student(self, id_student):
        self.__valid_student.valideaza_id(id_student)
        self.__repo_student.sterge_student(id_student)

    def modif_student(self, id_student, nume, grup):
        self.__valid_student.valideaza_id(id_student)
        self.__valid_student.valideaza_nume(nume)
        self.__valid_student.valideaza_grup(grup)
        self.__repo_student.modif_student(id_student, nume, grup)

    def cauta_student(self, id_student):
        self.__valid_student.valideaza_id(id_student)
        return self.__repo_student.cauta_student(id_student)

    def genereaza_student(self, nr):
        for i in range(nr):
            Student = self.__repo_student.genereaza_student()
            self.__valid_student.valideaza(Student)
            self.__repo_student.adauga_student(Student)

    def print_studenti_dupa_nume(self):
        return self.__repo_student.studenti_dupa_nume()

    def get_all_students(self):
        return self.__repo_student.get_all()
