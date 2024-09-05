from exceptii.valid_error import ValidError

class ValidatorProblema:

    def valideaza_nr_lab_prob(self, nr_lab_prob):
        erori = ""
        if nr_lab_prob == "":
            erori += "nr lab_prob invalid\n"
        if len(erori) > 0:
            raise Exception(erori)

    def valideaza_descriere(self, descriere):
        erori = ""
        if len(descriere) > 1000:
            erori += "descriere prea mare\n"
        if len(erori) > 0:
            raise Exception(erori)

    def valideaza_deadline(self, deadline):
        erori = ""
        if deadline < 0 or deadline > 31:
            erori += "deadline invalid\n"
        if len(erori) > 0:
            raise Exception(erori)

    def valideaza(self, problema):
        erori = ""
        if problema.get_nr_lab_prob() == "":
            erori += "nr lab_prob invalid\n"
        if len(problema.get_descriere()) > 1000:
            erori += "descriere prea mare\n"
        if problema.get_deadline() < 0 or problema.get_deadline() > 31:
            erori += "deadline invalid\n"
        if len(erori) > 0:
            raise Exception(erori)
