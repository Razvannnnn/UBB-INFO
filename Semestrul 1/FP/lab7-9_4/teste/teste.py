from business.service_student import ServiceStudent
from domeniu.problema import Problema
from domeniu.student import Student
from infrastructura.repo_problema import RepoProbleme
from infrastructura.repo_studenti import RepoStudenti


class Teste:
    def test_adauga_student(self):
        id_student = 50
        nume = "Bercea"
        grup = 201
        student = Student(id_student, nume, grup)
        repo_student = RepoStudenti()
        students = repo_student.get_all()
        assert len(students) == 0
        repo_student.adauga_student(student)
        students = repo_student.get_all()
        assert len(students) == 1

    def test_adauga_problema(self):
        nr_lab_prob = "10_3"
        descriere = "Misto"
        deadline = 30
        problema = Problema(nr_lab_prob, descriere, deadline)
        repo_problema = RepoProbleme()
        probleme = repo_problema.get_all()
        assert len(probleme) == 0
        repo_problema.adauga_problema(problema)
        probleme = repo_problema.get_all()
        assert len(probleme) == 1

    def test_sterge_student(self):
        id_student = 50
        nume = "Bercea"
        grup = 201
        id_student_2 = 45
        nume_2 = "Lectura"
        grup_2 = 203
        student = Student(id_student, nume, grup)
        student_2 = Student(id_student_2, nume_2, grup_2)
        repo_student = RepoStudenti()
        students = repo_student.get_all()
        assert len(students) == 0
        repo_student.adauga_student(student)
        repo_student.adauga_student(student_2)
        students = repo_student.get_all()
        assert len(students) == 2
        repo_student.sterge_student(id_student)
        students = repo_student.get_all()
        assert len(students) == 1

    def test_sterge_problema(self):
        nr_lab_prob = "10_3"
        descriere = "Misto"
        deadline = 30
        nr_lab_prob_2  = "11_5"
        descriere_2 = "Tare"
        deadline_2 = 23
        problema = Problema(nr_lab_prob, descriere, deadline)
        problema_2 = Problema(nr_lab_prob_2, descriere_2, deadline_2)
        repo_problema = RepoProbleme()
        probleme = repo_problema.get_all()
        assert len(probleme) == 0
        repo_problema.adauga_problema(problema)
        repo_problema.adauga_problema(problema_2)
        probleme = repo_problema.get_all()
        assert len(probleme) == 2
        repo_problema.sterge_problema(nr_lab_prob)
        probleme = repo_problema.get_all()
        assert len(probleme) == 1

    def test_modif_student(self):
        id_student = 50
        nume = "Bercea"
        grup = 201
        nume_2 = "Lectura"
        grup_2 = 203
        student = Student(id_student, nume, grup)
        repo_student = RepoStudenti()
        students = repo_student.get_all()
        assert len(students) == 0
        repo_student.adauga_student(student)
        students = repo_student.get_all()
        assert len(students) == 1
        repo_student.modif_student(id_student, nume_2, grup_2)
        students = repo_student.get_all()
        assert len(students) == 1


    def test_modif_problema(self):
        nr_lab_prob = "10_3"
        descriere = "Misto"
        deadline = 30
        descriere_2 = "Tare"
        deadline_2 = 23
        problema = Problema(nr_lab_prob, descriere, deadline)
        repo_problema = RepoProbleme()
        probleme = repo_problema.get_all()
        assert len(probleme) == 0
        repo_problema.adauga_problema(problema)
        probleme = repo_problema.get_all()
        assert len(probleme) == 1
        repo_problema.modif_problema(nr_lab_prob, descriere_2, deadline_2)
        probleme = repo_problema.get_all()
        assert len(probleme) == 1

    def test_asign_problema(self):
        id_student = 50
        nume = "Bercea"
        grup = 201
        nr_lab_prob = "10_3"
        descriere = "Misto"
        deadline = 30
        pass

    def test_asign_nota(self):
        id_student = 50
        nume = "Bercea"
        grup = 201
        nr_lab_prob = "10_3"
        descriere = "Misto"
        deadline = 30
        pass

    def run_all_tests(self):
        print("Incepe rularea testelor...")
        self.test_adauga_student()
        self.test_adauga_problema()
        self.test_sterge_student()
        self.test_sterge_problema()
        self.test_modif_student()
        self.test_modif_problema()
        self.test_asign_problema()
        self.test_asign_nota()
        print("Rulare teste finalizata cu succes!")
