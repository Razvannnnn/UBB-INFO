import datetime

from domain.tractor import Tractor
from business.srv_tractor import ServiceTractor
from infrastructura.repo_tractor import RepoTractor, FileRepoTractor
from validare.validare_tractor import ValidareTractor
from teste.teste import Teste
from ui import UI

cale_fisier = "infrastructura/tractoare.txt"
repo_tractor = FileRepoTractor(cale_fisier)
valid_tractor = ValidareTractor()
srv_tractor = ServiceTractor(repo_tractor, valid_tractor)
ui = UI(srv_tractor)

teste = Teste()

teste.run_tests()

ui.run()