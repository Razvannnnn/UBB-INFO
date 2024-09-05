//
// Created by razva on 21.06.2024.
//

#include "service.h"

void Service::adauga(int id, string descriere, vector<string> programatori, string stare) {
    for(auto &task : repo.getAll()) {
        if(task.getId() == id) {
            throw SrvException("Id invalid!");
        }
    }
    if(descriere == "") throw SrvException("Descriere invalida!");
    if(programatori.size() == 0) throw SrvException("Numar invalid de programatori!");
    if(stare != "open" && stare != "inprogress" && stare != "closed") throw SrvException("Stare invalida!");
    repo.add(Task(id,descriere,programatori,stare));
}
