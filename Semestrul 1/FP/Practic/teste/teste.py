from domain.tractor import Tractor
from infrastructura.repo_tractor import RepoTractor, FileRepoTractor
from business.srv_tractor import ServiceTractor
from validare.validare_tractor import ValidareTractor

class Teste:
    def __test_get(self):
        id = 100
        denumire = "Audi"
        pret = 2000
        model = "A6"
        data_revizie = "15:08:2024"
        tractor = Tractor(id, denumire, pret, model, data_revizie)
        assert tractor.get_id() == id
        assert tractor.get_pret() == pret
        assert tractor.get_model() == model
        assert tractor.get_denumire() == denumire
        assert tractor.get_data_revizie() == data_revizie

    def __test_set(self):
        id = 100
        denumire = "Audi"
        pret = 2000
        model = "A6"
        data_revizie = "15:08:2024"
        tractor = Tractor(id, denumire, pret, model, data_revizie)
        id2 = 105
        denumire2 = "Opel"
        pret2 = 2600
        model2 = "Astra"
        data_revizie2 = "16:07:2024"
        tractor.set_id(id2)
        tractor.set_pret(pret2)
        tractor.set_denumire(denumire2)
        tractor.set_model(model2)
        tractor.set_data_revizie(data_revizie2)
        assert tractor.get_id() == id2
        assert tractor.get_pret() == pret2
        assert tractor.get_model() == model2
        assert tractor.get_denumire() == denumire2
        assert tractor.get_data_revizie() == data_revizie2

    def __test_adaugare(self):
        id = 100
        denumire = "Audi"
        pret = 2000
        model = "A6"
        data_revizie = "15:08:2024"
        tractor = Tractor(id, denumire, pret, model, data_revizie)
        repo_tractor = RepoTractor()
        lista = repo_tractor.get_all()
        assert len(lista)==0
        repo_tractor.adaugare(tractor)
        assert len(lista)==1

    def __test_srv_adaugare(self):
        id = 100
        denumire = "Audi"
        pret = 2000
        model = "A6"
        data_revizie = "15:08:2024"
        tractor = Tractor(id, denumire, pret, model, data_revizie)
        repo_tractor = RepoTractor()
        validare_tractor = ValidareTractor()
        srv_tractor = ServiceTractor(repo_tractor, validare_tractor)
        lista = srv_tractor.get_all()
        assert len(lista) == 0
        srv_tractor.adaugare(tractor)
        assert len(lista) == 1

    def __test_stergere(self):
        id = 100
        denumire = "Audi"
        pret = 2500
        model = "A6"
        data_revizie = "15:08:2024"
        tractor = Tractor(id, denumire, pret, model, data_revizie)
        id2 = 105
        denumire2 = "Opel"
        pret2 = 2600
        model2 = "Astra"
        data_revizie2 = "16:07:2024"
        tractor2 = Tractor(id2, denumire2, pret2, model2, data_revizie2)
        repo_tractor = RepoTractor()
        validare_tractor = ValidareTractor()
        srv_tractor = ServiceTractor(repo_tractor, validare_tractor)
        srv_tractor.adaugare(tractor)
        srv_tractor.adaugare(tractor2)
        lista = srv_tractor.get_all()
        assert len(lista) == 2
        k = srv_tractor.stergere(6)
        lista = srv_tractor.get_all()
        assert len(lista) == 1
        assert k == 1

    def __test_srv_stergere(self):
        id = 100
        denumire = "Audi"
        pret = 2500
        model = "A6"
        data_revizie = "15:08:2024"
        tractor = Tractor(id, denumire, pret, model, data_revizie)
        id2 = 105
        denumire2 = "Opel"
        pret2 = 2600
        model2 = "Astra"
        data_revizie2 = "16:07:2024"
        tractor2 = Tractor(id2, denumire2, pret2, model2, data_revizie2)
        repo_tractor = RepoTractor()
        repo_tractor.adaugare(tractor)
        repo_tractor.adaugare(tractor2)
        lista = repo_tractor.get_all()
        assert len(lista) == 2
        k = repo_tractor.stergere(6)
        lista = repo_tractor.get_all()
        assert len(lista) == 1
        assert k == 1

    def run_tests(self):
        print("Incepe rularea testelor...")
        self.__test_get()
        self.__test_set()
        self.__test_adaugare()
        self.__test_stergere()
        self.__test_srv_adaugare()
        self.__test_srv_stergere()
        print("Testele au fost rulate cu succes!")