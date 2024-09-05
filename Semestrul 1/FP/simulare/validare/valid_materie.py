from domain.material import Material
class ValidMaterie:
    def validare_materie(self, materie):
        erori = ""
        if materie.get_cod() < 0:
            erori += "Cod invalid\n"
        if materie.get_denumire() == "":
            erori += "Denumire invalida\n"
        if materie.get_cantiate_pe_stoc() < 0:
            erori += "Cantitate pe stoc invalida\n"
        if materie.get_pret_unitar() < 0.0:
            erori += "Pret unitate invalid\n"
        if len(erori)!=0:
            raise Exception(erori)