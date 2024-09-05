class Student:
    def __init__(self, student_id, nume, grup):
        self.student_id = student_id
        self.nume = nume
        self.grup = grup

    def get_student_id(self):
        return self.student_id

    def get_nume(self):
        return self.nume

    def get_grup(self):
        return self.grup

    def set_student_id(self, new_student_id):
        self.student_id = new_student_id

    def set_nume(self, new_nume):
        self.nume = new_nume

    def set_grup(self, new_grup):
        self.grup = new_grup

class Problema:
    def __init__(self, nr_laborator, nr_problema, descriere, deadline):
        self.nr_laborator = nr_laborator
        self.nr_problema = nr_problema
        self.descriere = descriere
        self.deadline = deadline

    def get_nr_laborator(self):
        return self.nr_laborator

    def get_nr_problema(self):
        return self.nr_problema

    def get_descriere(self):
        return self.descriere

    def get_deadline(self):
        return self.deadline

    def set_nr_laborator(self, new_nr_laborator):
        self.nr_laborator = new_nr_laborator

    def set_nr_problema(self, new_nr_problema):
        self.nr_problema = new_nr_problema

    def set_descriere(self, new_descriere):
        self.descriere = new_descriere

    def set_deadline(self, new_deadline):
        self.deadline = new_deadline

