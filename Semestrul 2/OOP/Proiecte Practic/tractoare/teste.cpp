//
// Created by razva on 21.06.2024.
//

#include "repo.h"
#include "service.h"
#include "domain.h"
#include "assert.h"

void testRepo() {
    Repo repo{"C:\\Users\\razva\\Desktop\\tractoare\\test.txt"};
    assert(repo.getAll().size() == 1);
}
void testService() {
    Repo repo{"C:\\Users\\razva\\Desktop\\tractoare\\test.txt"};
    Service service{repo};
    assert(service.getAll().size() == 1);
}