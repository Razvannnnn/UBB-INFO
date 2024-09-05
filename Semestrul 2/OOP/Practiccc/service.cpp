#include "service.h"
#include "exception"

void Service::add(string titlu, string artist, string gen) {
    if(titlu != "" && artist != "" && (gen == "pop" || gen == "folk" || gen == "rock" || gen == "disco")) {
        repo.adauga(Melodie(repo.getAll().size() + 1, titlu, artist, gen));
    } else {
        throw SrvException("Melodie invalida!");
    }
}

void Service::remove(int id) {
    repo.sterge(id);
}
