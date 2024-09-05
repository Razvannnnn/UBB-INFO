import datetime

from domain.tractor import Tractor
from datetime import *

class ValidareTractor:
    def validare(self, tractor):
        """
        Functie de validare a tractorului
        :param tractor: obiectul tractor
        :return:
        """
        id = tractor.get_id()
        denumire = tractor.get_denumire()
        pret = tractor.get_pret()
        model = tractor.get_model()
        data_revizie = tractor.get_data_revizie()

        erori = ""
        if id < 0:
            erori+="Id invalid"
        if denumire == "":
            erori+="Denumire invalida"
        if pret < 0:
            erori+="Pret invalid"
        if model == "":
            erori+="Model invalid"
        if data_revizie == "":
            erori+="Data invalida"
        if len(erori) > 0:
            raise Exception(erori)