from erori.exceptii import ValidError
class ValidatorStudent:
    
    def valideaza_student(self,student):
        erori = []
        if student.get_id_student() <0:
            erori.append("id student invalid!")
        if student.get_nume() == "":
            erori.append("nume invalid!")
        if student.get_valoare()<=0.0:
            erori.append("valoare invalida!")
        if len(erori)>0:
            raise ValidError(erori)


class ValidatorMaterie:
    pass


class ValidatorNota:
    pass


