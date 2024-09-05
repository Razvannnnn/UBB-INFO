class Mobila:
    def __init__(self, cod, tip, nume, stock, pret):
        self.__pret = pret #float
        self.__stock = stock #int
        self.__nume = nume #string
        self.__tip = tip #string
        self.__cod = cod #string

    def get_cod(self):
        return self.__cod

    def get_tip(self):
        return self.__tip

    def get_nume(self):
        return self.__nume

    def get_stock(self):
        return self.__stock

    def get_pret(self):
        return self.__pret

    def set_tip(self, tip):
        self.__tip = tip

    def set_nume(self, nume):
        self.__nume = nume

    def set_stock(self, stock):
        self.__stock = stock

    def set_pret(self, pret):
        self.__pret = pret

    def __str__(self):
        return f"{self.__cod},{self.__tip},{self.__nume},{self.__stock},{self.__pret}"