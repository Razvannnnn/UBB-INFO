#ifndef LAB6_COSPRODUSE_H
#define LAB6_COSPRODUSE_H

#include "produs.h"
#include "repo.h"
#include <vector>
#include "observer.h"
#include "random"
#include "time.h"
#include "chrono"

using std::vector;

class CosProduse : public Observable{
private:
    vector<Produs> cosProduse;
    RepoAbstract& repo;
public:
    /**
     * Constructorul cosului
     */
    explicit CosProduse(RepoAbstract& repo): repo{ repo } {

    };

    void adaugaProdusCos(const Produs &p);

    void adaugaRandomProdusCos(vector<Produs> produse,int nr);

    vector<Produs> &getAllCos();

    void stergeCos();

    void fill(int nr) {
        vector<Produs> produse = repo.getAll();
        int seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::shuffle(produse.begin(), produse.end(), std::default_random_engine(seed));
        while (cosProduse.size() < nr && produse.size() > 0) {
            cosProduse.push_back(produse.back());
            produse.pop_back();
        }

        notify();
    }
};


#endif //LAB6_COSPRODUSE_H
