class NotaDTO:
    
    def __init__(self,id_nota, id_student,id_materie,valoare):
        self.__id_nota = id_nota
        self.__id_student = id_student
        self.__id_materie = id_materie
        self.__valoare = valoare

    def get_id_nota(self):
        return self.__id_nota


    def get_id_student(self):
        return self.__id_student


    def get_id_materie(self):
        return self.__id_materie


    def get_valoare(self):
        return self.__valoare

    def __repr__(self):
        return f"{self.__id_nota},{self.__id_student},{self.__id_materie},{self.__valoare}"
    
    @staticmethod
    def read_entity(line):
        parts = line.split(",")
        id_nota = int(parts[0])
        id_student = int(parts[1])
        id_materie = int(parts[2])
        valoare = float(parts[3])
        return id_nota,NotaDTO(id_nota,id_student,id_materie,valoare)