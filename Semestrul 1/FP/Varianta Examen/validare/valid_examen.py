from domain.examen import Examen

class ValidExamen:
    def Validare(self, examen):
        data = examen.get_data()
        ora = examen.get_ora()
        materia = examen.get_materia()
        restanta = examen.get_restanta()
        erori = ""

        date = data.split(".")
        if len(date) == 2:
            zi = date[0]
            luna = date[1]
            if int(zi) < 1 or int(zi) > 31:
                erori += "Ziua este invalida!\n"
            if int(luna) < 1 or int(luna) > 12:
                erori += "Luna este invalida!\n"
        else:
            erori+="Data invalida!\n"

        ceas = ora.split(":")
        if len(ceas) == 2:
            ore = ceas[0]
            minute = ceas[1]
            if int(ore) < 1 or int(ore) > 24 or int(minute) < 0 or int(minute) > 59:
                erori+="Ora este invalida!\n"
        else:
            erori += "Ora este invalida!\n"

        if materia == "":
            erori+="Materia invalida!\n"

        if str(restanta).lower() != "da" and str(restanta).lower() != "nu":
            erori+="Restanta invalida!\n"

        if len(erori) > 0:
            raise Exception(erori)