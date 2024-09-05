class Student:
    
    
    def __init__(self, id_student, nume, valoare):
        self.__id_student = id_student
        self.__nume = nume
        self.__valoare = valoare

    def get_id_student(self):
        return self.__id_student


    def get_nume(self):
        return self.__nume


    def get_valoare(self):
        return self.__valoare


    def set_nume(self, value):
        self.__nume = value


    def set_valoare(self, value):
        self.__valoare = value

    def __repr__(self):
        return f"{self.__id_student},{self.__nume},{self.__valoare}"
    
    @staticmethod
    def read_entity(line):
        parts = line.split(",")
        id_student = int(parts[0])
        nume = parts[1]
        valoare = float(parts[2])
        return id_student,Student(id_student,nume,valoare)



