from validare.validator_student import ValidatorStudent
from validare.validator_problema import ValidatorProblema
from infrastructura.repo_studenti import RepoStudenti, FileRepoStudenti
from infrastructura.repo_problema import RepoProbleme, FileRepoProbleme
from business.service_student import ServiceStudent
from business.service_problema import ServiceProblema
from prezentare.console import Consola
from teste.teste import Teste
from business.service_nota import ServiceNota
from infrastructura.repo_nota import RepoNota, FileRepoNote
from validare.validator_nota import ValidatorNota

teste = Teste()
teste.run_all_tests()

valid_student = ValidatorStudent()
valid_prob = ValidatorProblema()
valid_nota = ValidatorNota()
repo_student = FileRepoStudenti("C:\\Users\\razva\PycharmProjects\lab79 - Copy - Copy\infrastructura\studenti.txt")
repo_prob = FileRepoProbleme("C:\\Users\\razva\PycharmProjects\lab79 - Copy - Copy\infrastructura\probleme.txt")
repo_nota = FileRepoNote("C:\\Users\\razva\PycharmProjects\lab79 - Copy - Copy\infrastructura\\note.txt")
srv_student = ServiceStudent(repo_student, valid_student)
srv_prob = ServiceProblema(repo_prob, valid_prob)
srv_nota = ServiceNota(repo_nota, valid_nota, repo_student, repo_prob)
ui = Consola(srv_student, srv_prob, srv_nota)
ui.run()