from domain.mobila import Mobila
from infrastructura.repo_mobila import RepoMobila, FileRepoMobila
from validare.valid_mobila import ValidMobila
from business.service_mobila import ServiceMobila
from console import Console

cale_fisier = "C:\Users\razva\Desktop\GitHub\UBB-FMI\Semestrul 1\FP\Mobila\infrastructura\mobila.txt"
repo_mobila = FileRepoMobila(cale_fisier)
valid_mobila = ValidMobila()
srv_mobila = ServiceMobila(repo_mobila, valid_mobila)
ui = Console(srv_mobila)
ui.run()