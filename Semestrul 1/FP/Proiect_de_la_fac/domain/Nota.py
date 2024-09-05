class Nota:
    def __init__(self,id_nota,student,materie,valoare):
        self.__id_nota = id_nota
        self.__student = student
        self.__materie = materie
        self.__valoare = valoare

    def get_id_nota(self):
        return self.__id_nota


    def get_student(self):
        return self.__student


    def get_materie(self):
        return self.__materie


    def get_valoare(self):
        return self.__valoare


    def set_student(self, value):
        self.__student = value


    def set_materie(self, value):
        self.__materie = value


    def set_valoare(self, value):
        self.__valoare = value

    
