from domain.entities import Student, Problema
from service.student_service import *
from service.problema_service import *


class UI:
    def __init__(self, service1, service2):
        self.__service1 = service1
        self.__service2 = service2

    def __add_student(self):
        studentID = input("ID student:")
        nume = input("Nume:")
        grupa = input("Grupa:")
        try:
            student = self.__service1.insert_student(studentID,nume,grupa)
        except Exception as ex:
            print(ex)

    def __all_students(self):
        students = self.__service1.all_students()
        for i in range(len(students)):
            print(students[i])


    def interfata(self):
        while True:
            print("""
        1.Adaugare student
        2.Adaugare problema laborator
        3.Sterge student
        4.Sterge problema laborator
        5.Modificare student
        6.Modificare problema laborator
        7.Cautare student
        8.Cautare problema laborator
        9.Asignare laborator
        10.Notare laboarator
        11.Lista studenti si notele lor ordonate dupa nume
        12.Lista studenti si notele lor ordonate dupa note
        13.Studentii cu media de laborator mai mica de 5\n
                    """)
            comanda = input("Comanda este:")
            if comanda == '1':
                self.__add_student()
            elif comanda == '2':
                pass
            elif comanda == '3':
                pass
            elif comanda == '4':
                pass
            elif comanda == '5':
                pass
            elif comanda == '6':
                pass
            elif comanda == '7':
                pass
            elif comanda == '8':
                pass
            elif comanda == '9':
                pass
            elif comanda == '10':
                pass
            elif comanda == '11':
                pass
            elif comanda == '12':
                pass
            elif comanda == '13':
                pass
            elif comanda == '14':
                self.__all_students()
            else:
                return 0

