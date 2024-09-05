from domain.material import Material
from infrastructura.repo_materii import RepoMaterie,FileRepoMaterie

class Teste:
    def test_adugare_fisier(self):
        test1 = open("C:\\Users\\razva\\PycharmProjects\\simulare\\teste\\test1.txt", "r")
        cod = "3555"
        nume = "Lemn"
        cantitate = 100
        pret_unit = 3
        material = Material(cod,nume,cantitate,pret_unit)
        repo_materie = RepoMaterie()
        fil_repo_materie = FileRepoMaterie(test1)
        assert len(repo_materie.__)
        fil_repo_materie.adaugare(material)