from infrastructura.repo_studenti import RepoStudenti
class ValidatorStudent:

    def valideaza_id(self, id_student):
        erori = ""
        if id_student < 0:
            erori += "id student invalid\n"
        if len(erori) > 0:
            raise Exception(erori)

    def valideaza_nume(self, nume):
        erori = ""
        if nume == "":
            erori += "nume student invalid\n"
        if len(erori) > 0:
            raise Exception(erori)

    def valideaza_grup(self, grup):
        erori = ""
        if grup <= 0:
            erori += "grup student invalid\n"
        if len(erori) > 0:
            raise Exception(erori)


    def valideaza(self, student):
        erori = ""
        if student.get_id_student()<0:
            erori+="id student invalid\n"
        if student.get_nume() == "":
            erori+="nume student invalid\n"
        if student.get_grup()<=0:
            erori+="grup student invalid\n"
        if len(erori) > 0:
            raise Exception(erori)