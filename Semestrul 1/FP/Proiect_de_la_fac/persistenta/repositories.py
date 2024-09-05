from erori.exceptii import RepoError
from domain.Student import Student

class Repo:
    def __init__(self):
        self._entitati = {}
    
    def adauga(self,entitate):
        id_entitate = entitate.get_id()
        if id_entitate in self._entitati:
            raise RepoError("obiect existent!")
        self._entitati[id_entitate]= entitate
        
    def cauta_dupa_id(self,id_entitate):
        if id_entitate not in self._entitati:
            raise RepoError("obiect inexistent!")
        return self._entitati[id_entitate]
    
    def sterge_dupa_id(self,id_entitate):
        if id_entitate not in self._entitati:
            raise RepoError("obiect inexistent!")
        del self._entitati[id_entitate]
 
    def modifica(self,entitate):
        id_entitate = entitate.get_id()
        if id_entitate not in self._entitati:
            raise RepoError("obiect inexistent!")
        self._entitati[id_entitate]=entitate

    def __len__(self):
        return len(self._entitati)
    
    def get_all(self):
        return [self._entitati[id_entitate] for id_entitate in self._entitati]
    

class RepoStudenti(Repo):
    
    def __init__(self):
        Repo.__init__(self)
    
class RepoMaterii(Repo):
    def __init__(self):
        Repo.__init__(self)
    
class RepoNote(Repo):
    def __init__(self):
        Repo.__init__(self)
        
        
class FileRepo(Repo):
    
    
    def __init__(self, file_path,read_entity):
        Repo.__init__(self)
        self.__file_path = file_path
        self.__read_entity = read_entity
    

    def __read_all_from_file(self):
        with open(self.__file_path,"r") as f:
            lines = f.readlines()
            self._entitati.clear()
            for line in lines:
                line = line.strip()
                if line != "":
                    id_entitate,entitate = self.__read_entity(line)
                    self._entitati[id_entitate]=entitate
        

    def __append_entity_to_file(self, entitate):
        with open(self.__file_path,"a") as f:
            f.write(repr(entitate)+"\n")
    
    
    def adauga(self, entitate):
        self.__read_all_from_file()
        Repo.adauga(self, entitate)
        self.__append_entity_to_file(entitate)

    def cauta_dupa_id(self, id_entitate):
        self.__read_all_from_file()
        return Repo.cauta_dupa_id(self, id_entitate)


    def __write_all_to_file(self):
        with open(self.__file_path,"w") as f:
            for id_entitate in self._entitati:
                f.write(repr(self._entitati[id_entitate])+"\n")
    
    
    def sterge_dupa_id(self, id_entitate):
        self.__read_all_from_file()
        Repo.sterge_dupa_id(self, id_entitate)
        self.__write_all_to_file()
        
    def modifica(self, entitate):
        self.__read_all_from_file()
        Repo.modifica(self, entitate)
        self.__write_all_to_file()
        
    def get_all(self):
        self.__read_all_from_file()
        return Repo.get_all(self)
    
    def __len__(self):
        self.__read_all_from_file()
        return Repo.__len__(self)
    
class FileRepoStudenti(FileRepo):
    
    
    def __init__(self, file_path,read_entity):
        FileRepo.__init__(self, file_path, read_entity)
    

class FileRepoMaterii(FileRepo):
    def __init__(self, file_path,read_entity):
        FileRepo.__init__(self, file_path, read_entity)


class FileRepoNote(RepoNote):
    def __init__(self, file_path,read_entity):
        FileRepo.__init__(self, file_path, read_entity)




