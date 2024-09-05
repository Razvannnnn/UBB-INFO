from domain.examen import Examen
from business.service_examen import ServiceExamen
from infrastructura.repo_examen import RepoExamen, FileRepoExamen
from validare.valid_examen import ValidExamen
from console import Console

valid_examen = ValidExamen()
cale_fisier_examene = "infrastructura/examene.txt"
repo_examen = FileRepoExamen(cale_fisier_examene)
srv_examen = ServiceExamen(valid_examen, repo_examen)
console = Console(srv_examen)

console.run()



