from ui.menu import *

def main():
    repo_student = Student_repo()
    valid_student = validatorStudent()
    repo_problema = Problema_repo()
    valid_problema = validatorProblema()
    service_student = ServiceStudent(repo_student, valid_student)
    service_problema = ServiceProblema(repo_problema, valid_problema)
    ui = UI(service_student, service_problema)
    ui.interfata()

if __name__=="__main__":
    main()