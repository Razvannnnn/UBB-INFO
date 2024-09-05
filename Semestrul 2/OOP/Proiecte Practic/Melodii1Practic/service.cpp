//
// Created by razva on 21.06.2024.
//

#include "service.h"

void Service::add(int id, string titlu, string artist, int rank) {
    for(auto &mel : repo.getAll()) {
        if(mel.getID() == id) {
            throw SrvException("Id invalid!");
        }
    }
    if(titlu == "" || artist == "") throw SrvException("Melodie invalida!");
    if(rank < 1 || rank > 10) throw SrvException("Rank invalid!");
    repo.add(Melodie(id,titlu,artist,rank));
}
