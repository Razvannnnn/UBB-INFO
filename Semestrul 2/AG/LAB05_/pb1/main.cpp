#include <bits/stdc++.h>

using namespace std;

const int NMAX = 10000;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector <int> graf[NMAX];
int cost[NMAX][NMAX], reziduri[NMAX][NMAX];
int viz[NMAX] , pred[NMAX];

int bfs()
{
    for(int i=0;i<=n;i++)
        viz[i] = 0;
    queue <int> noduri;
    noduri.push(1);
    viz[1] = 1;
    while(!noduri.empty()){
        int ncurent = noduri.front();
        cout << "nod_curent: " << ncurent << " | ";
        //in cazul in care nodul curent este
        //chiar nodul destinatie pe care dorim sa-l atingem
        //nu mai are rost sa-l vizitam, asa ca continuam algoritmul

        //incepem sa vizitam vecinii
        for(int i=0; i<graf[ncurent].size() && ncurent!=n; i++){
            int nvecin = graf[ncurent][i];        //nod vecin
            //in cazul in care fluxul pe care il avem pe muchie este atins
            //adica nu mai putem sa trecem ceva prin flux , nu ne dorim sa-l parcurgem
            //asa ca ne continuam aventura in gasirea fluxului maxim
            if(reziduri[ncurent][nvecin]==cost[ncurent][nvecin] || viz[nvecin]==1) continue;
            cout << nvecin << " ";
            viz[nvecin] = 1;
            noduri.push(nvecin);
            pred[nvecin] = ncurent;             //salvam si drumul inapoi
        }
        cout << '\n';
        noduri.pop();       //eliminam nodul din lista
    }
    //returnam viz[n] deoarece dorim sa stim daca am reusit
    //sa atingem nodul n adica nodul destinatie cu parcurgerea bfs pe care am facut-o
    return viz[n];
}

int edmonds_karp(){
    int noduri, flux_minim, flux;                   //algoritmul continua parcurgerea cat timp putem ajunge la nodul nostru
    flux = 0;
    while(bfs()==1){
        for(int i=0;i<graf[n].size();i++)           //traseul invers
        {
            int ncurent = graf[n][i];
            //in cazul in care vecinul este full
            //pe muchie , nu putem sa-l luam in calcul
            //pentru transport
            if(cost[ncurent][n]==reziduri[ncurent][n] || viz[ncurent]==0)         //daca vecinul este plin pe
                continue;
            pred[n] = ncurent;
            flux_minim = 550000005;
            for(noduri = n; noduri != 1; noduri = pred[noduri]){
                flux_minim = min(flux_minim, cost[pred[noduri]][noduri] - reziduri[pred[noduri]][noduri]);
            }
            if(flux_minim == 0)
                continue;
            for(noduri = n; noduri != 1; noduri = pred[noduri]){
                reziduri[pred[noduri]][noduri] += flux_minim;
                reziduri[noduri][pred[noduri]] -= flux_minim;
            }
            flux += flux_minim;
        }
    }
    return flux;
}

int main()
{
    int x, y, z;
    fin>>n>>m;
    for(int i=1;i<=m;i++) {
        fin>>x>>y>>z;
        x++;
        y++;
        cost[x][y] += z;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    fout << edmonds_karp();
    return 0;
}