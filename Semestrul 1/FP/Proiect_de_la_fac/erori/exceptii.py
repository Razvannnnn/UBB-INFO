class RepoError(Exception):
    pass


class ValidError(Exception):
    
    
    def __init__(self, erori):
        self.__erori = erori
    
    
    def __str__(self):
        Exception.__str__(self)
        return "\n".join(self.__erori)


class ServiceError(Exception):
    pass


