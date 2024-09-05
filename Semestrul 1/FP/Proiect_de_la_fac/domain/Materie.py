class Materie:
    def __init__(self,id_materie,titlu):
        self.__id_materie = id_materie
        self.__titlu = titlu

    def get_id_materie(self):
        return self.__id_materie


    def get_titlu(self):
        return self.__titlu


    def set_titlu(self, value):
        self.__titlu = value

    @staticmethod
    def read_entity(line):
        parts = line.split(",")
        id_materie = int(parts[0])
        titlu = parts[1]
        return id_materie,Materie(id_materie,titlu)