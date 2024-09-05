#include "teste.h"
#include "service.h"
#include <assert.h>

void testRepo(){
    Repo r("fisTest.txt");
    Produse p(5,"nume5","toip",88.3);
    r.adaugare(p);
}

void testService(){
    Repo r("");
    Produse p(5,"nume5","toip",88.3);
    r.adaugare(p);
    Service s(r);
    QString erori = s.adaugare(5,"nume5","toip",88.3);
    assert(erori!="");
    erori = s.adaugare(6,"nume5","toip",88.3);
    assert(erori=="");
}

void Teste::testAll(){
    testRepo();
    testService();
}
