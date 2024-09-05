#include <iostream>
#include <vector>

using namespace std;

template <typename TElem>

class Cos {
private:
    vector<string> cumparaturi;
public:
    Cos() = default;
    Cos & operator + (TElem produs) {
        cumparaturi.push_back(produs);
        return *this;
    }
    Cos & undo() {
        if(cumparaturi.size() > 0) cumparaturi.pop_back();
        return *this;
    }
    void tipareste(ostream & out) {
        for(auto prod : cumparaturi) {
            out<<prod<<" ";
        }
    }
    ~Cos() = default;
};

void cumparaturi() {
    Cos<string> cos;//creaza un cos de cumparaturi
    cos = cos + "Mere"; //adauga Mere in cos
    cos.undo();//elimina Mere din cos
    cos + "Mere"; //adauga Mere in cos
    cos = cos + "Paine" + "Lapte";//adauga Paine si Lapte in cos
    cos.undo().undo();//elimina ultimele doua produse adaugate
    cos.tipareste(cout);//tipareste elementele din cos (Mere)
}

int main() {
    cumparaturi();
    return 0;
}
