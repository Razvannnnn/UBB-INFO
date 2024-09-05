class Examen:
    def __init__(self, data, ora, materia, restanta):
        self.__data = data
        self.__ora = ora
        self.__materia = materia
        self.__restanta = restanta

    def get_zi(self):
        date = self.__data.strip(".")
        return date[0]

    def get_luna(self):
        date = self.__data.strip(".")
        return date[1]

    def get_data(self):
        return self.__data

    def get_ora(self):
        return self.__ora

    def get_materia(self):
        return self.__materia

    def get_restanta(self):
        return self.__restanta

    def set_data(self, data):
        self.__data = data

    def set_ora(self, ora):
        self.__ora = ora

    def set_materia(self, materia):
        self.__materia = materia

    def set_restanta(self, restanta):
        self.__restanta = restanta

    def __eq__(self, examen):
        if self.__data == examen.get_data() and self.__ora == examen.get_ora() and self.__materia == examen.get_materia() and self.__restanta == examen.get_restanta():
            return True
        return False

    def __str__(self):
        return f"{self.__data},{self.__ora},{self.__materia},{self.__restanta}"