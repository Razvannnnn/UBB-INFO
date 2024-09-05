#ifndef LAB6_UNDO_H
#define LAB6_UNDO_H

#include "produs.h"
#include "repo.h"

class ActiuneUndo {
public:
    virtual void doUndo() = 0;

    ~ActiuneUndo() = default;
};

class UndoAdauga: public ActiuneUndo {
    Produs produsAdaugat;
    RepoAbstract &repo;
public:
    UndoAdauga(RepoAbstract &repo, Produs &produs) : repo{repo}, produsAdaugat{produs} {}

    void doUndo() override {
        repo.del(produsAdaugat);
    }
};

class UndoModifica: public ActiuneUndo  {
    Produs produsVechi, produsNou;
    RepoAbstract &repo;
public:
    UndoModifica(RepoAbstract &repo, Produs &produsVechi, Produs &produsNou) : repo{repo}, produsVechi{produsVechi}, produsNou{produsNou} {}

    void doUndo() override {
        repo.del(produsVechi);
        repo.store(produsNou);
    }
};

class UndoSterge: public ActiuneUndo {
    Produs produsSters;
    RepoAbstract &repo;
public:
    UndoSterge(RepoAbstract &repo, Produs &produsSters) : repo{repo}, produsSters{produsSters} {}

    void doUndo() override {
        repo.store(produsSters);
    }
};

#endif //LAB6_UNDO_H
