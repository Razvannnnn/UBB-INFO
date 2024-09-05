from domain.material import Material
from business.service_materii import ServiceMaterii
from infrastructura.repo_materii import RepoMaterie, FileRepoMaterie
from validare.valid_materie import ValidMaterie
from console import Console

valid_materie = ValidMaterie()
cale_fisier = "C:\\Users\\razva\\PycharmProjects\\simulare\\infrastructura\\materiale.txt"
repo_materie = FileRepoMaterie(cale_fisier)
service_materie = ServiceMaterii(repo_materie, valid_materie)
ui = Console(service_materie)
ui.run()
