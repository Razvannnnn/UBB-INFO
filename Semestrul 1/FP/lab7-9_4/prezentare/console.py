
class Consola:
    def __init__(self, srv_student, srv_prob, srv_nota):
        self.__srv_student = srv_student
        self.__srv_prob = srv_prob
        self.__srv_nota = srv_nota
        self.__comenzi ={
            "add_student":self.__ui_add_student,
            "sterge_student":self.__ui_sterge_student,
            "modif_student":self.__ui_modif_student,
            "cauta_student":self.__ui_cauta_student,
            "print_studenti":self.__ui_print_students,
            "add_problema":self.__ui_add_problema,
            "sterge_problema":self.__ui_sterge_problema,
            "modif_problema":self.__ui_modif_problema,
            "cauta_problema":self.__ui_cauta_problema,
            "print_probleme":self.__ui_print_probleme,
            "genereaza_student":self.__ui_genereaza_student,
            "sort_nume":self.__ui_print_studenti_dupa_nume,
            "sort_nota":self.__ui_print_studenti_dupa_nota,
            "asign_problema":self.__ui_asign_problema,
            "asign_nota":self.__ui_asign_nota,
            "medie_sub_5":self.__ui_medie_sub_5,
            "print_note":self.__ui_get_all_note
        }

    def __ui_print_students(self, params):
        if len(params)!=0:
            print("Nr parametri invalid!")
            return
        students = self.__srv_student.get_all_students()
        for student in students:
            print(student)

    def __ui_add_student(self, params):
        if len(params)!=3:
            print("Nr parametri invalid!")
            return
        try:
            id_student = int(params[0])
            nume = params[1]
            grup = int(params[2])
            self.__srv_student.adauga_student(id_student,nume,grup)
        except Exception as ex:
            print(ex)

    def __ui_sterge_student(self,params):
        if(len(params)!=1):
            print("Nr parametri invalid!")
            return
        try:
            id_student = int(params[0])
            self.__srv_student.sterge_student(id_student)
        except Exception as ex:
            print(ex)

    def __ui_modif_student(self, params):
        if(len(params)!=3):
            print("Nr parametri invalid!")
            return
        try:
            id_student = int(params[0])
            nume = params[1]
            grup = int(params[2])
            self.__srv_student.modif_student(id_student, nume, grup)
        except Exception as ex:
            print(ex)

    def __ui_cauta_student(self, params):
        if(len(params)!=1):
            print("Nr parametri invalid!")
            return
        try:
            id_student = int(params[0])
            student = self.__srv_student.cauta_student(id_student)
            print(student)
        except Exception as ex:
            print(ex)

    def __ui_print_probleme(self, params):
        if len(params) != 0:
            print("Nr parametri invalid!")
            return
        probleme = self.__srv_prob.get_all_probleme()
        for problema in probleme:
            print(problema)

    def __ui_add_problema(self, params):
        if len(params) != 3:
            print("Nr parametri invalid!")
            return
        try:
            nr_lab_prob = params[0]
            descriere = params[1]
            deadline = int(params[2])
            self.__srv_prob.adauga_problema(nr_lab_prob, descriere, deadline)
        except Exception as ex:
            print(ex)

    def __ui_sterge_problema(self, params):
        if len(params) != 1:
            print("Nr parametri invalid!")
            return
        try:
            nr_lab_prob = params[0]
            self.__srv_prob.sterge_problema(nr_lab_prob)
        except Exception as ex:
            print(ex)

    def __ui_modif_problema(self, params):
        if(len(params) != 3):
            print("Nr parametri invalid!")
            return
        try:
            nr_lab_prob = params[0]
            new_descriere = params[1]
            new_deadline = int(params[2])
            self.__srv_prob.modif_problema(nr_lab_prob, new_descriere, new_deadline)
        except Exception as ex:
            print(ex)


    def __ui_cauta_problema(self, params):
        if(len(params)!=1):
            print("Nr parametri invalid!")
            return
        try:
            nr_lab_prob = params[0]
            problema = self.__srv_prob.cauta_problema(nr_lab_prob)
            print(problema)
        except Exception as ex:
            print(ex)

    def __ui_genereaza_student(self,params):
        if (len(params)!=1):
            print("Nr parametri invalid!")
            return
        try:
            nr = int(params[0])
            self.__srv_student.genereaza_student(nr)
            if(nr!=1):
                print(f"Au fost generati {params[0]} studenti.")
            else:
                print(f"A fost generat 1 student.")
        except Exception as ex:
            print(ex)

    def __ui_print_studenti_dupa_nume(self, params):
        if len(params)!=0:
            print("Nr parametri invalid")
            return
        try:
            students = self.__srv_student.print_studenti_dupa_nume()
            for student in students:
                print(student)
                id = student.get_id_student()
                note = self.__srv_nota.print_note_id(id)
                if len(note)!=0:
                    for i in range(len(note)):
                        print(f"Nr.laborator si problema:{note[i][1]} Nota:{note[i][2]}")
                else:
                    print("Studentul nu are probleme asignate")
        except Exception as ex:
            print(ex)

    def __ui_asign_problema(self, params):
        if len(params)!=2:
            print("Nr parametri invalid")
            return
        try:
            id_student = int(params[0])
            nr_lab_prob = params[1]
            problema = self.__srv_prob.cauta_problema(nr_lab_prob)
            student = self.__srv_student.cauta_student(id_student)
            self.__srv_nota.asign_problema(id_student, nr_lab_prob)
        except Exception as ex:
            print(ex)

    def __ui_asign_nota(self, params):
        if len(params)!=3:
            print("Nr parametri invalid")
            return
        try:
            id_student = int(params[0])
            nr_lab_prob = params[1]
            nota = int(params[2])
            problema = self.__srv_prob.cauta_problema(nr_lab_prob)
            student = self.__srv_student.cauta_student(id_student)
            self.__srv_nota.asign_nota(id_student, nr_lab_prob, nota)
        except Exception as ex:
            print(ex)

    def __ui_print_studenti_dupa_nota(self, params):
        if len(params)!=1:
            print("Nr parametri invalid")
            return
        try:
            nr_lab_prob = params[0]
            students = self.__srv_student.get_all_students()
            note = self.__srv_nota.sort_note()
            ok=0
            if len(note) != 0:
                for i in range(len(note)):
                    if note[i][1] == nr_lab_prob:
                        for student in students:
                            if student.get_id_student() == note[i][0]:
                                ok=1
                                print(student)
                        print(f"Nota:{note[i][2]}")
            if ok==0:
                print("Nu exista studenti la care sa fie asignata aceasta problema")
        except Exception as ex:
            print(ex)

    def __ui_medie_sub_5(self, params):
        if len(params) != 0:
            print("Nr parametri invalid")
            return
        try:
            students = self.__srv_student.get_all_students()
            ok = 0
            for student in students:
                if self.__srv_nota.media_sub_5_id(student.get_id_student()) == 1:
                    print(student)
                    ok=1
            if ok == 0:
                print("Nu exista studenti la care sa fie asignate laboratoare")
        except Exception as ex:
            print(ex)


    def __ui_get_all_note(self, params):
        if len(params)!=0:
            print("Nr parametri invalid")
            return
        try:
            note = self.__srv_nota.get_all_note()
            for nota in note:
                print(nota)
        except Exception as ex:
            print(ex)

    def run(self):
        while True:
            comanda = input(">>>")
            comanda = comanda.strip()
            if comanda == "":
                continue
            if comanda == "exit":
                return
            parts = comanda.split()
            comanda_name = parts[0]
            params = parts[1:]
            if comanda_name in self.__comenzi:
                try:
                    self.__comenzi[comanda_name](params)
                except Exception as ex:
                    print(ex)
            else:
                print("Comanda invalida!")