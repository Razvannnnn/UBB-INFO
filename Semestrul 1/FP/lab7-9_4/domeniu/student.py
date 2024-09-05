class Student:
    def __init__(self, id_student, nume, grup):
        self.__id_student = id_student
        self.__nume = nume
        self.__grup = grup

    def get_id_student(self):
        return self.__id_student

    def get_nume(self):
        return self.__nume

    def get_grup(self):
        return self.__grup

    def set_id_student(self, id_student_new):
        self.__id_student = id_student_new

    def set_nume(self, nume_new):
        self.__nume = nume_new

    def set_grup(self, grup_new):
        self.__grup = grup_new

    def __str__(self):
        return f"{self.__id_student},{self.__nume},{self.__grup}"

