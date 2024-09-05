from domain import Student
from erori.exceptii import ServiceError
class ServiceStudenti:
    
    
    def __init__(self, validator_student, repo_studenti):
        self.__validator_student = validator_student
        self.__repo_studenti = repo_studenti
        
    def adauga_student(self,id_student,nume,valoare):
        student = Student(id_student,nume,valoare)
        self.__validator_student.valideaza_student(student)
        self.__repo_studenti.adauga(student)
    
    def cauta_dupa_id(self,id_student):
        if id_student<0:
            raise ServiceError("id student invalid!")
        return self.__repo_studenti.cauta_dupa_id(id_student)
    
    def modifica_student(self,id_student,nume,valoare):
        student = Student(id_student,nume,valoare)
        self.__validator_student.valideaza_student(student)
        self.__repo_studenti.modifica(student)
    
    def sterge_dupa_id(self,id_student):
        if id_student<0:
            raise ServiceError("id student invalid!")
        self.__repo_studenti.sterge_dupa_id(id_student)
        
    def get_all_studenti(self):
        return self.__repo_studenti.get_all()
    
    def get_numar_studenti(self):
        return len(self.__repo_studenti)
    
    def get_studenti_sortati_crescator_dupa_valoare(self):
        studenti = self.__repo_studenti.get_all()
        studenti.sort(key = lambda x:x.get_valoare())
        return studenti
    
    def get_studenti_sortati_descrescator_dupa_valoare(self):
        studenti = self.__repo_studenti.get_all()
        studenti.sort(key = lambda x:x.get_valoare(),reverse = True)
        return studenti
    
    def get_studenti_sortati_crescator_dupa_nume(self):
        studenti = self.__repo_studenti.get_all()
        studenti.sort(key = lambda x:x.get_nume())
        return studenti
    
    def get_studenti_sortati_descrescator_dupa_nume(self):
        studenti = self.__repo_studenti.get_all()
        studenti.sort(key = lambda x:x.get_nume(),reverse = True)
        return studenti
    
    def get_studenti_sortati_crescator_dupa_nume_si_valoare(self):
        studenti = self.__repo_studenti.get_all()
        studenti.sort(cmp = lambda x,y: x if x.get_nume()<y.get_nume() else y if x.get_nume()>y.get_nume() else x if x.get_valoare()<y.get_valoare() else y )
        return studenti
    
    def get_studenti_cu_nume_prefix(self,prefix):
        studenti = self.__repo_studenti.get_all()
        return [student for student in studenti if student.get_nume().startswith(prefix)]
    
    