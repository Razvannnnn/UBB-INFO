class ServiceExamen:
    def __init__(self, validare, repo_examen):
        self.__validare = validare
        self.__repo_examen = repo_examen

    def adaugare(self, examen):
        self.__validare.Validare(examen)
        self.__repo_examen.adaugare(examen)

    def stergere(self, examen):
        self.__validare.Validare(examen)
        self.__repo_examen.stergere(examen)

    def examene_maine(self, day, month):
        examene = self.__repo_examen.get_all_examene_maine(day, month)
        examene = sorted(examene, key=lambda x: x.get_ora)
        return examene
    def get_all(self):
        return self.__repo_examen.get_all()