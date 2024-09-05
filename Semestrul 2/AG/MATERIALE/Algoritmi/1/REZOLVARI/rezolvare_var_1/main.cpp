#include <iostream>
#include <climits>
#include <fstream>

using namespace std;

ifstream fin("graf.in");

int matrice[20][20], parinte[20], distanta[20],maxim=INT_MIN,n;

int distante_minime(int distanta[], bool vizitat[])
{
    int minim=INT_MAX,ind;
    for(int i=0;i<=n;i++)
    {
        if(!vizitat[i] && distanta[i] <= minim)
        {
            minim=distanta[i];
            ind=i;
        }
    }
    return ind;
}

void dijkstra(int radacina)
{
    bool vizitat[n+2];

    for(int k = 0; k<=n; k++)
    {
        distanta[k] = INT_MAX;
        vizitat[k] = false;
        parinte[k]= -1;
    }

    distanta[radacina] = 0;
    parinte[radacina] = -1;

    for(int i=0;i<=n;i++) {
        int m = distante_minime(distanta, vizitat);
        vizitat[m] = true;
        for (int j = 0; j <= n; j++) {
            if (!vizitat[j] && matrice[m][j] && distanta[m] != INT_MAX && distanta[m] + matrice[m][j] < distanta[j]) {
                distanta[j] = distanta[m] + matrice[m][j];
                parinte[j] = m;
                cout<<1;
            }
        }
    }
}


int main() {
    int ci, cj, cx, cy, n, L;
    fin>>n;
    fin>>cx>>cy;
    while(fin>>ci>>cj>>L) {
        matrice[ci][cj] = L;
    }
    dijkstra(cx);
    if(distanta[cy] == INT_MAX)
        cout<<"Nu exista un drum intre aceste atractii."<<endl;
    else
    {   cout<<cy<<" ";
        while(parinte[cy] != -1)
        {   cy = parinte[cy];
            cout<<cy<< " ";
        }
    }
    return 0;
}

