class Tractor:
    def __init__(self, id, denumire, pret, model, data_revizie):
        self.__id = id
        self.__denumire = denumire
        self.__pret = pret
        self.__model = model
        self.__data_revizie = data_revizie

    def get_id(self):
        """
        Se returneaza id-ul tractorului
        :return: id
        """
        return self.__id

    def get_denumire(self):
        """
        Se returneaza denumirea tractorului
        :return: denumire
        """
        return self.__denumire

    def get_pret(self):
        """
        Se returneaza pretul tractorului
        :return: pret
        """
        return self.__pret

    def get_model(self):
        """
        Se returneaza modelul tractorului
        :return: model
        """
        return self.__model

    def get_data_revizie(self):
        """
        Se returneaza data reviziei
        :return: data revizie
        """
        return self.__data_revizie

    def set_id(self, id):
        """
        Se seteaza id-ul tractorului
        :param id: noul id
        :return:
        """
        self.__id = id

    def set_denumire(self, denumire):
        """
        Se seteaza denumirea tractorului
        :param denumire: noua denumire
        :return:
        """
        self.__denumire = denumire

    def set_pret(self, pret):
        """
        Se seteaza pretul tractorului
        :param pret: noul pret
        :return:
        """
        self.__pret = pret

    def set_model(self, model):
        """
        Se seteaza modelul tractorului
        :param model: noul model
        :return:
        """
        self.__model = model

    def set_data_revizie(self, data_revizie):
        """
        Se seteaza data reviziei tractorului
        :param data_revizie: noua data de revizie
        :return:
        """
        self.__data_revizie = data_revizie

    def __str__(self):
        return (f"{self.__id},{self.__denumire},{self.__pret},{self.__model},{self.__data_revizie}")
