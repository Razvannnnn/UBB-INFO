#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

#define INF 10000000

int matrice[251][251], distanta[1001], v, e, s, x, y, w;

void bellman_ford(int nod_sursa){
    for(int i=0;i<v;i++){
        distanta[i] = INF;
    }
    distanta[nod_sursa] = 0;

    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            if(matrice[i][j] != 0)
                if(distanta[j] > distanta[i] + matrice[i][j]) distanta[j] = distanta[i] + matrice[i][j];
}

int main(int argc, char* argv[]) {

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    fin>>v>>e>>s;

    for(int i=1;i<=e;i++) {
        fin>>x>>y>>w;
        matrice[x][y]=w;
    }

    bellman_ford(s);

    for(int i=0;i<v;i++) {
        if(distanta[i] != INF) fout << distanta[i] << " ";
        else fout << "INF ";
    }

    fin.close();
    fout.close();
    return 0;
}
