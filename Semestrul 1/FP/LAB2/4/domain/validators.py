from domain.entities import *

class validatorStudent:
    def validate(self,student):
        eroare = ""
        if student.get_student_id() == "":
            eroare += "ID-ul studentului nu poate fi vid\n"
        try:
            id = int(student.get_student_id())
        except:
            eroare += "ID-ul studetului trebuie sa fie format doar din cifre\n"
            id = 0
        if student.get_grup() == "":
            eroare += "Nr-ul grupului nu poate fi vid\n"
        try:
            nr = int(student.get_grup())
        except:
            eroare += "Nr-ul grupului trebuie sa fie format doar din cifre\n"
            nr = 0
        if student.get_nume() == "":
            eroare += "Numele studentului nu poate fi vid\n"

        if (len(eroare)>0):
            raise Exception(eroare)

class validatorProblema:
    def validate(self, problema):
        eroare = ""
        if problema.get_nr_laborator() == "":
            eroare += "Nr Laboratorului nu poate fi vid\n"
        try:
            nr_lab = int(problema.get_nr_laborator())
        except:
            eroare += "Nr Laboratorului trebuie sa fie format din cifre\n"
            nr_lab = 0
        if problema.get_nr_problema() == "":
            eroare += "Nr Problema nu poate fi vid\n"
        try:
            nr_prob = int(problema.get_nr_problema())
        except:
            eroare += "Nr Problema trebuie sa fie format din cifre\n"
            nr_prob = 0
        if problema.get_descriere() == "":
            eroare += "Descrierea nu poate sa fie vida\n"
        if len(problema.get_descriere())>10000:
            eroare += "Descrierea este prea mare\n"
        if problema.get_deadline() == "":
            eroare += "Deadline-ul nu poate fi vid\n"
        try:
            dline = int(problema.get_deadline())
        except:
            eroare += "Deadline-ul trebuie sa fie format din cifre\n"
            dline = 0

        if(len(eroare)>0):
            raise Exception(eroare)