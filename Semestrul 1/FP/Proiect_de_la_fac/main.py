'''
Created on 2023 Dec 12

@author: Ale
'''
from validare.validatori import ValidatorStudent,ValidatorMaterie,ValidatorNota
from persistenta.repositories import RepoStudenti,FileRepoStudenti,RepoMaterii,FileRepoMaterii,RepoNote,FileRepoNote
from business.services import ServiceStudenti 
from domain.Student import Student
from domain.Materie import Materie
if __name__ == '__main__':
    validator_student = ValidatorStudent()
    file_path = "C:\\Users\\Ale\\My Documents\\LiClipse Workspace\\proiect_gabi\\studenti.txt"
    repo_studenti = FileRepoStudenti(file_path,Student.read_entity)
    service_studenti = ServiceStudenti(validator_student,repo_studenti)
    validator_materie = ValidatorMaterie()
    file_path = "C:\\Users\\Ale\\My Documents\\LiClipse Workspace\\proiect_gabi\\materii.txt"
    repo_materii = FileRepoMaterii(file_path,Materie.read_entity)
    #service_materii = ServiceMaterii(validator_materie,repo_materii)
    validator_nota = ValidatorNota()
    file_path = "C:\\Users\\Ale\\My Documents\\LiClipse Workspace\\proiect_gabi\\note.txt"
    repo_note = FileRepoNote(file_path,Nota.read_entity)
    #service_note = ServiceNote(validator_nota,repo_note,repo_studenti,repo_materii)
     
    ui = Console()