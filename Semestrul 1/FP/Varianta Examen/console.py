from domain.examen import Examen
from datetime import *
class Console:
    def __init__(self, service_examen):
        self.__service_examen = service_examen

    def run(self):
        while True:
            print("""
    1. Adaugare examen
    2. Stergere examen
    3. Examene programate in urmatoarele 3 zile
    4. Export examene in fisier 
    0. Exit
                          """)
            optiune = input("Optiune:")
            if optiune == "1":
                try:
                    data = input("Data:")
                    ora = input("Ora:")
                    materia = input("Materia:")
                    restanta = input("Restanta (da sau nu):")
                    examen = Examen(data, ora, materia, restanta)
                    self.__service_examen.adaugare(examen)
                except Exception as ex:
                    print(ex)
            elif optiune == "2":
                try:
                    data = input("Data:")
                    ora = input("Ora:")
                    materia = input("Materia:")
                    restanta = input("Restanta (da sau nu):")
                    examen = Examen(data, ora, materia, restanta)
                    self.__service_examen.stergere(examen)
                except Exception as ex:
                    print(ex)
            elif optiune == "3":
                try:
                    day_now = date.today().day
                    month_now = date.today().month
                    examene_maine = self.__service_examen.examene_maine(day_now, month_now)
                    for i in examene_maine:
                        print(i)
                except Exception as ex:
                    print(ex)

            elif optiune == "4":
                try:
                    cale_fisier = input("Nume fisier:")
                    with open(cale_fisier, "w") as f:
                        for examen in self.__service_examen.get_all():
                            f.write(str(examen) + "\n")
                except Exception as ex:
                    print(ex)
            elif optiune == "0":
                print("Programul s-a finalizat!")
                return
            else:
                print("Optiune invalida!")
